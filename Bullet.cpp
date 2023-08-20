#include "Bullet.h"

Bullet::Bullet(Coordinate x,Coordinate y,double angle,double speed,int radius, COLORREF color):
	x(x), y(y), angle(angle), speed(speed), radius(radius), color(color) {
}

// 移动函数，根据速度和角度更新子弹的位置，并重绘子弹
void Bullet::move() {
	eraseBullet(); // 擦除原来的图像
	x += speed * std::cos(angle); // 更新 x 坐标
	y += speed * std::sin(angle); // 更新 y 坐标
	placeBullet(); // 绘制新的图像
}

Bullet::Coordinate Bullet::getX() {
	return x;
}

Bullet::Coordinate Bullet::getY() {
	return y;
}


// 擦除函数，擦除子弹的图像
void Bullet::eraseBullet() {
	setfillcolor(WHITE); // 设置填充颜色为黑色
	solidcircle(x, y, radius); // 画一个实心圆覆盖原来的图像
}

// 绘制函数，绘制子弹的图像
void Bullet::placeBullet() {
	setfillcolor(color); // 设置填充颜色为子弹的颜色
	solidcircle(x, y, radius); // 画一个实心圆表示子弹的图像
}

