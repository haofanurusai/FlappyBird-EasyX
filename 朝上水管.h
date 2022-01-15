#pragma once
#include "水管.h"

class 朝上水管 :public 水管 {
public:
	朝上水管(int 横, int 纵) :水管(横, 纵) {}
	virtual void 绘制();
};