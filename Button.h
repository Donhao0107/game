#pragma once //防止头文件重复包含
#include<graphics.h> //引入easyX图形库
#include<thread> //引入线程库
#include<functional> //引入函数对象库
#include<string> //引入字符串库
#include<iostream> //引入输入输出流库
#include"Mouse.h" //引入自定义的Mouse(鼠标)类

//定义一个Button类，用于表示一个图形按钮，可以响应鼠标点击事件
class Button {
public:
	//定义一个类型别名，用于存储坐标x或y的值
	using Coordinate = int;
	//定义一个类型别名，用于存储文件路径
	using filePath = std::string;
	//构造函数，用于创建Button类的对象
	//参数分别是按钮的左上右下坐标、图片文件路径和执行函数
	Button(Coordinate le, Coordinate to, Coordinate ri, Coordinate bo,
		   LPCTSTR fi, std::function<void()> ex);
	static Mouse mouse; //声明静态成员mouse保持鼠标信息
	bool isClink();
private:
	Coordinate left;				//按钮图标左边界
	Coordinate top;					//按钮图标上边界
	Coordinate right;				//按钮图标右边界
	Coordinate bottom;				//按钮图标下边界
	IMAGE image;					//按钮图片文件地址
	std::function<void()> execute;	//按钮的行为
};












//代码监狱
/*
//线程1：用于确定按钮是否被单击
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

		//线程2：用于在按钮被单击时执行与按钮相关联的函数
		std::thread run([&]()->void {
			while (true) {
				if (is_Clink) {
					execute();
				}
			}
						});
		run.detach();

*/
