#include "Player.h"

void Player::move(Direction direction) {
    // 根据不同的方向移动玩家，其中 erasePlayer(), placePlayer() 函数用于擦除旧的位置、绘制新的位置
    switch (direction) {
    case Direction::LEFT:
        erasePlayer();  // 擦除旧位置
        --left;  // 左侧位置减少
        --right;  // 右侧位置减少
        placePlayer();  // 重绘新位置
        break;
    case Direction::UP:
        erasePlayer();  // 擦除旧位置
        --top;  // 上方位置减少
        --bottom;  // 底部位置减少
        placePlayer();  // 重绘新位置
        break;
    case Direction::RIGHT:
        erasePlayer();  // 擦除旧位置
        ++left;  // 左侧位置增加
        ++right;  // 右侧位置增加
        placePlayer();  // 重绘新位置
        break;
    case Direction::DOWN:
        erasePlayer();  // 擦除旧位置
        ++top;  // 上方位置增加
        ++bottom;  // 底部位置增加
        placePlayer();  // 重绘新位置
        break;
    default:  // 方向错误
        // invalid direction
        break;
    }
}

void Player::erasePlayer() {
    // 以白色进行擦除操作，将左上角和右下角之间的矩形区域填充为白色
    setfillcolor(WHITE);
    solidrectangle(left, top, right, bottom);
}

void Player::placePlayer() {
    // 以红色进行绘制操作，将左上角和右下角之间的矩形区域填充为红色
    setfillcolor(RED);
    solidrectangle(left, top, right, bottom);
}

// 发射子弹函数，接受一个 Mouse 对象的引用作为参数
void Player::shoot(Mouse& mouse) {
    // 计算子弹的初始位置，即玩家的中心
    Coordinate x = (left + right) / 2;
    Coordinate y = (top + bottom) / 2;
    // 计算子弹的方向，即鼠标位置相对于玩家中心的角度
    double angle = std::atan2(mouse.getY() - y, mouse.getX() - x);
    // 定义子弹的速度和半径为常量
    const double speed = 10.0;
    const int radius = 5;
    // 创建一个 Bullet 对象，并将其添加到 bullets 中
    bullets.emplace_back(x, y, angle, speed, radius, BLACK);
}