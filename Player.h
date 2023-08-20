#pragma once
#include<iostream>
#include<easyx.h>  // ���� easyx ��
#include <cmath>
#include"Mouse.h" //�����Զ����Mouse(���)��
#include<vector>  // ���� vector ��
#include "Bullet.h"
#include"Timer.h"
class Player {
public:
    using Coordinate = int;  // Coordinate ��������Ϊ int
    using Health = int;  // Health ��������Ϊ int
    // ����һ��ö���� Direction������ LEFT��UP��RIGHT��DOWN �ĸ�����
    enum class Direction { LEFT, UP, RIGHT, DOWN };
    // ���캯������������ left��top��right��bottom ������ֵ health
    Player(Coordinate le, Coordinate to, Coordinate ri, Coordinate bo, Health he) :
        left(le), top(to), right(ri), bottom(bo), health(he) { }
    // �ƶ�����������һ���������(direction)�������ݲ����ƶ���Һ��ػ����
    void move(Direction direction);

    void shoot(Mouse &monse);

    void clearBullets();

    Coordinate rLeft()const { return left; }
    Coordinate rTop()const { return top; }
    Coordinate rRight()const { return right; }
    Coordinate rBottom()const { return bottom; }
    std::vector<Bullet> bullets;// ����һ��ȫ�ֵ� vector�����ڴ洢���е��ӵ�
private:
    // �������ͼ����
    void erasePlayer();
    // �������ͼ����
    void placePlayer();
    
    Health health;  // ��ҵĽ���ֵ
    Coordinate left;  // �������
    Coordinate top;  // �Ϸ�����
    Coordinate right;  // �Ҳ�����
    Coordinate bottom;  // �ײ�����
};