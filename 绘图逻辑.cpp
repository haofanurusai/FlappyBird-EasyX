#include "绘图逻辑.h"

绘图逻辑::绘图逻辑() {
	initgraph(窗口宽度, 窗口高度);
	setbkcolor(天空颜色);
	settextcolor(字体颜色);
	srand(time(NULL));
	小鸟 = NULL;
	重置();
}

void 绘图逻辑::生成水管() {
	int 下管高度 = rand() % (水管最大高度 - 水管最小高度) + 水管最小高度;
	int 上管高度 = 下管高度 + 缝隙高度;
	朝上水管* 下管 = new 朝上水管(窗口宽度 + 水管宽度, 窗口高度 - 下管高度 + 水管高度 / 2);
	朝下水管* 上管 = new 朝下水管(窗口宽度 + 水管宽度, 窗口高度 - 上管高度 - 水管高度 / 2);
	水管链表.push_back(上管);
	水管链表.push_back(下管);
}

void 绘图逻辑::设置鸟上升() {
	鸟运动状态 = 上升;
}

void 绘图逻辑::设置鸟下降() {
	鸟运动状态 = 下降;
	鸟下降速度 = 0;
}

void 绘图逻辑::鸟的处理() {
	static int 帧计数变量 = 0;
	if (鸟运动状态 == 上升) {
		if (小鸟->取纵坐标() < 鸟半径)
			小鸟->平移(0, -小鸟->取纵坐标());
		else 小鸟->平移(0, -鸟上升速度);
	}
	else {
		if (小鸟->取纵坐标() > 窗口高度)鸟死亡 = true;//鸟撞地面
		else if((++帧计数变量)==重力加速度分母) {
			鸟下降速度 += 重力加速度分子;
			小鸟->平移(0, 鸟下降速度);
			帧计数变量 = 0;
		}
	}
}

void 绘图逻辑::水管处理() {
	const static clock_t 水管生成周期毫秒 = 800;
	static clock_t 时间戳 = 0;
	if (clock() > 时间戳) {
		时间戳 = clock() + 水管生成周期毫秒;
		生成水管();
	}
	for (list<图形基类*>::iterator it = 水管链表.begin();
		it != 水管链表.end();)
	{
		if ((*it)->取横坐标() < -水管宽度) {
			delete (*it);
			it = 水管链表.erase(it);
		}
		else {
			(*it)->平移(-1, 0);
			++it;
		}
	}
}

void 绘图逻辑::碰撞处理() {
	for (list<图形基类*>::iterator it = 水管链表.begin();
		it != 水管链表.end(); ++it) 
	{
		if ((*it)->碰撞检测(小鸟))鸟死亡 = true;
	}
}

void 绘图逻辑::绘制一帧() {
	TCHAR str[20];
	BeginBatchDraw();
	cleardevice();
	for (list<图形基类*>::iterator it = 水管链表.begin();
		it != 水管链表.end();
		++it) {
		(*it)->绘制();
	}
	小鸟->绘制();
	_stprintf_s(str, L"分数:%d", ++分数);
	outtextxy(8,8,str);
	EndBatchDraw();
}

void 绘图逻辑::死亡画面() {
	const static TCHAR str[] = L"鸟 不行了! 回车键重开, ESC退出";
	outtextxy(500, 350, str);
}

void 绘图逻辑::重置() {
	if (小鸟 != NULL)delete 小鸟;
	水管链表.clear();
	小鸟 = new 鸟(窗口宽度 / 2, 窗口高度 / 2);
	鸟运动状态 = 下降; 
	鸟下降速度 = 0;
	鸟死亡 = false;
	分数 = 0;
}

bool 绘图逻辑::鸟死了() {
	return 鸟死亡;
}

绘图逻辑::~绘图逻辑() {
	delete 小鸟;
	closegraph();
}