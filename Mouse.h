#pragma once
#include<graphics.h>
// 一个简单的鼠标类
class Mouse {
public:
    // 构造函数，初始化鼠标
    Mouse() = default;
    // 获取鼠标的横坐标
    int getX();
    // 获取鼠标的纵坐标
    int getY();
    // 获取鼠标左键是否按下
    bool isLeftDown();
    // 获取鼠标右键是否按下
    bool isRightDown();
    // 更新鼠标的状态
    void update();
private:
    int x = 0; // 鼠标横坐标
    int y  = 0; // 鼠标纵坐标
    bool left = 0; // 鼠标左键状态
    bool right = 0; // 鼠标右键状态
};


