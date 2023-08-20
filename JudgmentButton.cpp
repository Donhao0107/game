#include "JudgmentButton.h"


JudgmentButton::JudgmentButton(Coordinate le, Coordinate to, Coordinate ri,
			   Coordinate bo, LPCTSTR fi, std::function<void()> ex) :
	left(le), top(to), right(ri), bottom(bo), execute(ex) {
	//����ͼƬ
	loadimage(&image, fi, right - left, bottom - top);
	//�ڴ����Ϸ���ͼƬ
	putimage(left, top, &image);
}

bool JudgmentButton::isClink() {
	//���������Ϣ
	mouse.update();
	//�ж�����Ƿ��ڰ�ť��Χ�ڣ����Ұ��������
	if (mouse.getX() >= left && mouse.getX() <= right &&
		mouse.getY() >= top && mouse.getY() <= bottom &&
		mouse.isLeftDown()) {
		execute(); //ִ�а�ť����Ϊ
		return true; //���� true��ʾ��ť��������
	}

	else {
		return false; //���� false��ʾ��ťû�б�����
	}

}