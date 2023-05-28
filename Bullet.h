#pragma once 
//����easyx��
#include <easyx.h>
#include<cmath>
//����Bullet��
class Bullet {
public:
	//����һ�����ͱ�������ʾ�洢����ֵ������Ϊint
	using Coordinate = int;
	//Ĭ�Ϲ��캯���������ӵ��ĳ�ʼλ�á��Ƕȡ��ٶȡ��뾶����ɫ
	Bullet(Coordinate x, Coordinate y, double angle, double speed, int radius, COLORREF color);
	//�ƶ������������ٶȺͽǶȸ����ӵ���λ�ã����ػ��ӵ�
	void move();
	//�����ײ����������һ�� Player ������Ϊ���������ж��ӵ��Ƿ�������ཻ
	//bool collide(Player& player);
private:
	//���������������ӵ���ͼ��
	void eraseBullet();
	//���ƺ����������ӵ���ͼ��
	void placeBullet();

	//�����ӵ����ڵ�����ֵ����������
	Coordinate x; //�ӵ���x���ϵ�����
	Coordinate y; //�ӵ���y���ϵ�����
	double angle; //�ӵ��ķ��нǶ�
	double speed; //�ӵ����ٶ�
	int radius;   //�ӵ��İ뾶����
	COLORREF color; //�ӵ�����ɫ
};