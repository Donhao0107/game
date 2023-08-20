#include "Player.h"

void Player::move(Direction direction) {
    
    // ���ݲ�ͬ�ķ����ƶ���ң����� erasePlayer(), placePlayer() �������ڲ����ɵ�λ�á������µ�λ��
    switch (direction) {
    case Direction::LEFT:
        erasePlayer();  // ������λ��
        --left;  // ���λ�ü���
        --right;  // �Ҳ�λ�ü���
        placePlayer();  // �ػ���λ��
        break;
    case Direction::UP:
        erasePlayer();  // ������λ��
        --top;  // �Ϸ�λ�ü���
        --bottom;  // �ײ�λ�ü���
        placePlayer();  // �ػ���λ��
        break;
    case Direction::RIGHT:
        erasePlayer();  // ������λ��
        ++left;  // ���λ������
        ++right;  // �Ҳ�λ������
        placePlayer();  // �ػ���λ��
        break;
    case Direction::DOWN:
        erasePlayer();  // ������λ��
        ++top;  // �Ϸ�λ������
        ++bottom;  // �ײ�λ������
        placePlayer();  // �ػ���λ��
        break;
    default:  // �������
        // invalid direction
        break;
    }
}

void Player::erasePlayer() {
    // �԰�ɫ���в��������������ϽǺ����½�֮��ľ����������Ϊ��ɫ
    setfillcolor(WHITE);
    solidrectangle(left, top, right, bottom);
}

void Player::placePlayer() {
    // �Ժ�ɫ���л��Ʋ����������ϽǺ����½�֮��ľ����������Ϊ��ɫ
    setfillcolor(RED);
    solidrectangle(left, top, right, bottom);
}



// �����ӵ�����������һ�� Mouse �����������Ϊ����
void Player::shoot(Mouse &mouse) {
 {
        clearBullets();
        std::cout << bullets.size() << std::endl;
        // �����ӵ��ĳ�ʼλ�ã�����ҵ�����
        Coordinate x = (left + right) / 2;
        Coordinate y = (top + bottom) / 2;
        // �����ӵ��ķ��򣬼����λ�������������ĵĽǶ�
        double angle = std::atan2(mouse.getY() - y, mouse.getX() - x);
        // �����ӵ����ٶȺͰ뾶Ϊ����
        const double speed = 10.0;
        const int radius = 5;
        // ����һ�� Bullet ���󣬲�������ӵ� bullets ��
        bullets.emplace_back(x, y, angle, speed, radius, BLACK);
    }
}

void Player::clearBullets() {
    // ɾ��������Ļ���ӵ�
    if (!bullets.empty()) {
        bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet& bullet)->bool {
            // ��ȡ�ӵ�������
            double x = bullet.getX();
            double y = bullet.getY();
            // ����ӵ������곬������Ļ�ķ�Χ������ true
            if (x < 0 || x > 800 || y < 0 || y > 600) {
                return true;
            }
            // ���򷵻� false
            return false;
                                     }),bullets.end());
    }
}

