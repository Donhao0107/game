#pragma once //��ֹͷ�ļ��ظ�����
#include<graphics.h> //����easyXͼ�ο�
#include<thread> //�����߳̿�
#include<functional> //���뺯�������
#include<string> //�����ַ�����
#include<iostream> //���������������
#include"Mouse.h" //�����Զ����Mouse(���)��
class JudgmentButton {
public:
	//����һ�����ͱ��������ڴ洢����x��y��ֵ
	using Coordinate = int;
	//����һ�����ͱ��������ڴ洢�ļ�·��
	using FilePath = std::string;
	//���캯�������ڴ���Button��Ķ���
	//�����ֱ��ǰ�ť�������������ꡢͼƬ�ļ�·����ִ�к���
	JudgmentButton(Coordinate le, Coordinate to, Coordinate ri, Coordinate bo,
		   LPCTSTR fi, std::function<void()> ex);
	static Mouse mouse; //������̬��Աmouse���������Ϣ
	bool isClink();
private:
	Coordinate left;				//��ťͼ����߽�
	Coordinate top;					//��ťͼ���ϱ߽�
	Coordinate right;				//��ťͼ���ұ߽�
	Coordinate bottom;				//��ťͼ���±߽�
	IMAGE image;					//��ťͼƬ�ļ���ַ
	std::function<void()> execute;	//��ť����Ϊ				//��ťͼƬ�ļ���ַ
};

