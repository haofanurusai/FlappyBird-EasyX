#include "图形基类.h"

图形基类::图形基类(int 横, int 纵) {
	横坐标 = 横;
	纵坐标 = 纵;
}

int 图形基类::取横坐标() { return 横坐标; }
int 图形基类::取纵坐标() { return 纵坐标; }
bool 图形基类::取碰撞类型() { return 碰撞类型; }
int 图形基类::取宽度() { return 宽度; }
int 图形基类::取高度() { return 高度; }

void 图形基类::平移(int 横坐标偏移量, int 纵坐标偏移量) {
	横坐标 += 横坐标偏移量;
	纵坐标 += 纵坐标偏移量;
}

bool 图形基类::碰撞检测(图形基类* 图形2) {
	图形基类* 图形1 = this;
	if (图形1->取碰撞类型() == 矩形 && 图形2->取碰撞类型() == 矩形) {//两个矩形
		int 横坐标差 = abs(图形1->取横坐标() - 图形2->取横坐标());
		int 纵坐标差 = abs(图形1->取纵坐标() - 图形2->取纵坐标());
		if (2 * 横坐标差 < 图形1->取宽度() + 图形2->取宽度()) return true;
		if (2 * 纵坐标差 < 图形1->取高度() + 图形2->取高度()) return true;
		return false;
	}
	else if (图形1->取碰撞类型() == 圆 && 图形2->取碰撞类型() == 圆) {//两个圆
		int 半径相加的平方
			= (图形1->取宽度() + 图形2->取宽度())
			* (图形1->取宽度() + 图形2->取宽度()) / 4;
		int 圆心距的平方
			= (图形1->取横坐标() - 图形2->取横坐标()) * (图形1->取横坐标() - 图形2->取横坐标())
			+ (图形1->取纵坐标() - 图形2->取纵坐标()) * (图形1->取纵坐标() - 图形2->取纵坐标());
		return (圆心距的平方 < 半径相加的平方);
	}
	else {//一圆一矩
		if (图形2->取碰撞类型() == 圆) {
			图形基类* 临时指针 = 图形2;
			图形2 = 图形1;
			图形1 = 临时指针;
		}//此时图形1必是圆，图形2必是矩形
		int 横向相对距离 = abs(图形1->取横坐标() - 图形2->取横坐标());
		int 纵向相对距离 = abs(图形1->取纵坐标() - 图形2->取纵坐标());
		int 横坐标差 = min(横向相对距离, 图形2->取宽度() / 2);
		int 纵坐标差 = min(纵向相对距离, 图形2->取高度() / 2);
		return (
			(横坐标差 - 横向相对距离) * (横坐标差 - 横向相对距离)
			+ (纵坐标差 - 纵向相对距离) * (纵坐标差 - 纵向相对距离)
			< 图形1->取宽度() * 图形1->取宽度() / 4
			);
	}
}