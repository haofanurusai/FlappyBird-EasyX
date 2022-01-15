#pragma once
#include <easyx.h>

#define 圆 false
#define 矩形 true

class 图形基类 {
protected:
	int 横坐标;
	int 纵坐标;
	bool 碰撞类型;
	int 宽度;
	int 高度;
public:
	图形基类(int,int);
	int 取横坐标();
	int 取纵坐标();
	bool 取碰撞类型();
	int 取宽度();
	int 取高度();
	void 平移(int,int);
	bool 碰撞检测(图形基类*);
	virtual void 绘制() = 0;
};