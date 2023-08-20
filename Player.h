#pragma once
#include<iostream>
#include<easyx.h>  // 引入 easyx 库
#include <cmath>
#include"Mouse.h" //引入自定义的Mouse(鼠标)类
#include<vector>  // 引入 vector 库
#include "Bullet.h"
#include"Timer.h"
class Player {
public:
    using Coordinate = int;  // Coordinate 别名定义为 int
    using Health = int;  // Health 别名定义为 int
    // 定义一个枚举类 Direction，包含 LEFT、UP、RIGHT、DOWN 四个方向
    enum class Direction { LEFT, UP, RIGHT, DOWN };
    // 构造函数，接受坐标 left、top、right、bottom 及健康值 health
    Player(Coordinate le, Coordinate to, Coordinate ri, Coordinate bo, Health he) :
        left(le), top(to), right(ri), bottom(bo), health(he) { }
    // 移动函数，接受一个方向参数(direction)，并根据参数移动玩家和重绘玩家
    void move(Direction direction);

    void shoot(Mouse &monse);

    void clearBullets();

    Coordinate rLeft()const { return left; }
    Coordinate rTop()const { return top; }
    Coordinate rRight()const { return right; }
    Coordinate rBottom()const { return bottom; }
    std::vector<Bullet> bullets;// 定义一个全局的 vector，用于存储所有的子弹
private:
    // 擦除玩家图像函数
    void erasePlayer();
    // 绘制玩家图像函数
    void placePlayer();
    
    Health health;  // 玩家的健康值
    Coordinate left;  // 左侧坐标
    Coordinate top;  // 上方坐标
    Coordinate right;  // 右侧坐标
    Coordinate bottom;  // 底部坐标
};