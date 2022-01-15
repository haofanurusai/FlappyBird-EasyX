#pragma once
#include "图形基类.h"

#define 鸟半径 16
#define 鸟颜色 0x00FFFF

class 鸟 :public 图形基类 {
public:
	鸟(int, int);
	virtual void 绘制();
};