#include "JudgmentButton.h"


JudgmentButton::JudgmentButton(Coordinate le, Coordinate to, Coordinate ri,
			   Coordinate bo, LPCTSTR fi, std::function<void()> ex) :
	left(le), top(to), right(ri), bottom(bo), execute(ex) {
	//加载图片
	loadimage(&image, fi, right - left, bottom - top);
	//在窗口上放置图片
	putimage(left, top, &image);
}

bool JudgmentButton::isClink() {
	//更新鼠标信息
	mouse.update();
	//判断鼠标是否在按钮范围内，并且按下了左键
	if (mouse.getX() >= left && mouse.getX() <= right &&
		mouse.getY() >= top && mouse.getY() <= bottom &&
		mouse.isLeftDown()) {
		execute(); //执行按钮的行为
		return true; //返回 true表示按钮被单击了
	}

	else {
		return false; //返回 false表示按钮没有被单击
	}

}