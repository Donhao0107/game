#pragma once //防止头文件重复包含
#include<graphics.h> //引入easyX图形库
#include<thread> //引入线程库
#include<functional> //引入函数对象库
#include<string> //引入字符串库
#include<iostream> //引入输入输出流库
#include"Mouse.h" //引入自定义的Mouse(鼠标)类
class JudgmentButton {
public:
	//定义一个类型别名，用于存储坐标x或y的值
	using Coordinate = int;
	//定义一个类型别名，用于存储文件路径
	using FilePath = std::string;
	//构造函数，用于创建Button类的对象
	//参数分别是按钮的左上右下坐标、图片文件路径和执行函数
	JudgmentButton(Coordinate le, Coordinate to, Coordinate ri, Coordinate bo,
		   LPCTSTR fi, std::function<void()> ex);
	static Mouse mouse; //声明静态成员mouse保持鼠标信息
	bool isClink();
private:
	Coordinate left;				//按钮图标左边界
	Coordinate top;					//按钮图标上边界
	Coordinate right;				//按钮图标右边界
	Coordinate bottom;				//按钮图标下边界
	IMAGE image;					//按钮图片文件地址
	std::function<void()> execute;	//按钮的行为				//按钮图片文件地址
};

