#pragma once 
//引入easyx库
#include <easyx.h>
#include<cmath>
//定义Bullet类
class Bullet {
public:
	//定义一个类型别名，表示存储坐标值的类型为int
	using Coordinate = int;
	//默认构造函数，接受子弹的初始位置、角度、速度、半径和颜色
	Bullet(Coordinate x, Coordinate y, double angle, double speed, int radius, COLORREF color);
	//移动函数，根据速度和角度更新子弹的位置，并重绘子弹
	void move();
	//检测碰撞函数，接受一个 Player 对象作为参数，并判断子弹是否与玩家相交
	//bool collide(Player& player);
private:
	//擦除函数，擦除子弹的图像
	void eraseBullet();
	//绘制函数，绘制子弹的图像
	void placeBullet();

	//保存子弹所在的坐标值和其他属性
	Coordinate x; //子弹在x轴上的坐标
	Coordinate y; //子弹在y轴上的坐标
	double angle; //子弹的飞行角度
	double speed; //子弹的速度
	int radius;   //子弹的半径长度
	COLORREF color; //子弹的颜色
};