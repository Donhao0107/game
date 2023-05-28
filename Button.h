#pragma once //��ֹͷ�ļ��ظ�����
#include<graphics.h> //����easyXͼ�ο�
#include<thread> //�����߳̿�
#include<functional> //���뺯�������
#include<string> //�����ַ�����
#include<iostream> //���������������
#include"Mouse.h" //�����Զ����Mouse(���)��

//����һ��Button�࣬���ڱ�ʾһ��ͼ�ΰ�ť��������Ӧ������¼�
class Button {
public:
	//����һ�����ͱ��������ڴ洢����x��y��ֵ
	using Coordinate = int;
	//����һ�����ͱ��������ڴ洢�ļ�·��
	using filePath = std::string;
	//���캯�������ڴ���Button��Ķ���
	//�����ֱ��ǰ�ť�������������ꡢͼƬ�ļ�·����ִ�к���
	Button(Coordinate le, Coordinate to, Coordinate ri, Coordinate bo,
		   LPCTSTR fi, std::function<void()> ex);
	static Mouse mouse; //������̬��Աmouse���������Ϣ
	bool isClink();
private:
	Coordinate left;				//��ťͼ����߽�
	Coordinate top;					//��ťͼ���ϱ߽�
	Coordinate right;				//��ťͼ���ұ߽�
	Coordinate bottom;				//��ťͼ���±߽�
	IMAGE image;					//��ťͼƬ�ļ���ַ
	std::function<void()> execute;	//��ť����Ϊ
};












//�������
/*
//�߳�1������ȷ����ť�Ƿ񱻵���
		std::thread determineStatus([&]()->void {
			while (true) {
				//message = getmessage(EX_MOUSE | EX_KEY);
				if (message.x >= left && message.x <= right &&
					message.y >= top && message.y <= bottom &&
					message.lbutton) {
					is_Clink = true;
					message = getmessage(EX_MOUSE | EX_KEY);
				}
				
				else {
					is_Clink = false;
				}
			}
									});
		determineStatus.detach();

		//�߳�2�������ڰ�ť������ʱִ���밴ť������ĺ���
		std::thread run([&]()->void {
			while (true) {
				if (is_Clink) {
					execute();
				}
			}
						});
		run.detach();

*/
