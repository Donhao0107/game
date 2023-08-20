#pragma once
#include<graphics.h>
#include<string>
class Image {
public:
	//定义一个类型别名，用于存储文件路径
	using FilePath = std::string;
	Image(LPCTSTR imagePath);
	operator IMAGE();
private:
	IMAGE image;
};

