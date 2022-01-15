#pragma once
#include "图形基类.h"

#define 水管边框色 0x000000
#define 水管填充色 0x007F00
#define 水管高度 768
#define 水管宽度 64
#define 水管口高度 12
#define 水管口宽度 68

class 水管 :public 图形基类 {
public:
	水管(int, int);
};