#include "朝下水管.h"

void 朝下水管::绘制() {
	setlinecolor(水管边框色);
	setfillcolor(水管填充色);
	fillrectangle(
		横坐标 - 水管宽度 / 2,
		纵坐标 - 水管高度 / 2,
		横坐标 + 水管宽度 / 2,
		纵坐标 + 水管高度 / 2 - 水管口高度
	);	
	fillrectangle(
		横坐标 - 水管口宽度 / 2,
		纵坐标 + 水管高度 / 2 - 水管口高度,
		横坐标 + 水管口宽度 / 2,
		纵坐标 + 水管高度 / 2
	);
}