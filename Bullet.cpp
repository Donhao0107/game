#include "Bullet.h"

Bullet::Bullet(Coordinate x,Coordinate y,double angle,double speed,int radius, COLORREF color):
	x(x), y(y), angle(angle), speed(speed), radius(radius), color(color) {
}

// �ƶ������������ٶȺͽǶȸ����ӵ���λ�ã����ػ��ӵ�
void Bullet::move() {
	eraseBullet(); // ����ԭ����ͼ��
	x += speed * std::cos(angle); // ���� x ����
	y += speed * std::sin(angle); // ���� y ����
	placeBullet(); // �����µ�ͼ��
}

Bullet::Coordinate Bullet::getX() {
	return x;
}

Bullet::Coordinate Bullet::getY() {
	return y;
}


// ���������������ӵ���ͼ��
void Bullet::eraseBullet() {
	setfillcolor(WHITE); // ���������ɫΪ��ɫ
	solidcircle(x, y, radius); // ��һ��ʵ��Բ����ԭ����ͼ��
}

// ���ƺ����������ӵ���ͼ��
void Bullet::placeBullet() {
	setfillcolor(color); // ���������ɫΪ�ӵ�����ɫ
	solidcircle(x, y, radius); // ��һ��ʵ��Բ��ʾ�ӵ���ͼ��
}

