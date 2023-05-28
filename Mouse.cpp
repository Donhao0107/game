#include "Mouse.h"

int Mouse::getX() {
    return x;
}

int Mouse::getY() {
    return y;
}

bool Mouse::isLeftDown() {
    return left;
}

bool Mouse::isRightDown() {
    return right;
}

void Mouse::update() {
    ExMessage msg; // ��Ϣ�ṹ��
    if (peekmessage(&msg)) { // �������Ϣ
        if (msg.message == WM_MOUSEMOVE) { // ���������ƶ��¼�
            x = msg.x; // ���º�����
            y = msg.y; // ����������
        }
        else if (msg.message == WM_LBUTTONDOWN) { // �������������¼�
            left = true; // �������״̬
        }
        else if (msg.message == WM_LBUTTONUP) { // �������������¼�
            left = false; // �������״̬
        }
        else if (msg.message == WM_RBUTTONDOWN) { // ������Ҽ������¼�
            right = true; // �����Ҽ�״̬
        }
        else if (msg.message == WM_RBUTTONUP) { // ������Ҽ������¼�
            right = false; // �����Ҽ�״̬
        }
        flushmessage(); // �����Ϣ����
    }
}
