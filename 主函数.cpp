#include "绘图逻辑.h"

int main() {
	bool 空格键被按下 = false;
	clock_t 刷新周期毫秒 = 4; //250FPS
	clock_t 时间戳 = 0;
	绘图逻辑 逻辑;
	while (1) {
		if (逻辑.鸟死了()) {
			逻辑.死亡画面();
			if (GetAsyncKeyState(VK_RETURN) & 0x8000)逻辑.重置();
			else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)return 0;
		}
		else
		{
			if (空格键被按下 == false && (GetAsyncKeyState(' ') & 0x8000)) {
				逻辑.设置鸟上升();
				空格键被按下 = true;
			}
			else if (空格键被按下 == true && !(GetAsyncKeyState(' ') & 0x8000)) {
				逻辑.设置鸟下降();
				空格键被按下 = false;
			}
			逻辑.鸟的处理();
			逻辑.水管处理();
			逻辑.碰撞处理();
			逻辑.绘制一帧();
		}
		while (clock() < 时间戳);
		时间戳 = clock() + 刷新周期毫秒;
	}
	return 0;
}