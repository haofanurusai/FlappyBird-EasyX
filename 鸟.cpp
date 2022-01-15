#include "鸟.h"

鸟::鸟(int 横, int 纵) :图形基类(横, 纵) {
	碰撞类型 = 圆;
	宽度 = 高度 = 鸟半径 * 2;
}
void 鸟::绘制() {
	setfillcolor(鸟颜色);
	solidcircle(横坐标, 纵坐标, 宽度 / 2);
}