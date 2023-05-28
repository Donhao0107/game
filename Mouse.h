#pragma once
#include<graphics.h>
// һ���򵥵������
class Mouse {
public:
    // ���캯������ʼ�����
    Mouse() = default;
    // ��ȡ���ĺ�����
    int getX();
    // ��ȡ����������
    int getY();
    // ��ȡ�������Ƿ���
    bool isLeftDown();
    // ��ȡ����Ҽ��Ƿ���
    bool isRightDown();
    // ��������״̬
    void update();
private:
    int x = 0; // ��������
    int y  = 0; // ���������
    bool left = 0; // ������״̬
    bool right = 0; // ����Ҽ�״̬
};


