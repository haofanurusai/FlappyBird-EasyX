#pragma once
#include <list>
#include <ctime>
#include <cstdlib>
#include "朝上水管.h"
#include "朝下水管.h"
#include "鸟.h"
using namespace std;

#define 天空颜色 0xFFCC66
#define 字体颜色 0xFF0000

#define 窗口宽度 1024
#define 窗口高度 768
#define 缝隙高度 250
#define 水管最小高度 50
#define 水管最大高度 500

#define 上升 true
#define 下降 false

class 绘图逻辑 {
private:
	list<图形基类*> 水管链表;
	鸟* 小鸟;
	const static int 鸟上升速度 = 3;
	const static int 重力加速度分子 = 1;
	const static int 重力加速度分母 = 5;
	int 鸟下降速度;
	bool 鸟运动状态;
	bool 鸟死亡;
	int 分数;
	void 生成水管();
public:
	绘图逻辑();
	void 设置鸟上升();
	void 设置鸟下降();
	void 鸟的处理();
	void 水管处理();
	void 碰撞处理();
	void 绘制一帧();
	void 死亡画面();
	void 重置();
	bool 鸟死了();
	~绘图逻辑();
};