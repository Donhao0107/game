#pragma once
#include<graphics.h>
#include<string>
class Image {
public:
	//����һ�����ͱ��������ڴ洢�ļ�·��
	using FilePath = std::string;
	Image(LPCTSTR imagePath);
	operator IMAGE();
private:
	IMAGE image;
};

