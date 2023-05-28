#include"game.h" //引入头文件，包含了Button类和CsMove类的定义
int main() {
	const int length(800), wide(500); //定义常量，表示图形窗口的长度和宽度
	initgraph(length, wide); //初始化图形窗口
	setfillcolor(WHITE); //设置填充颜色为白色
	solidrectangle(0, 0, length, wide); //绘制一个白色的矩形，覆盖整个窗口
	Player cm(10, 30, 30, 50,1); //创建一个CsMove对象，用于表示一个可以移动的方块，参数是方块的初始坐标
	//创建四个Button对象，用于表示上下左右移动按钮，参数是按钮的坐标、图片路径和执行函数
	//执行函数中调用了CsMove对象的相应方法，并延时10毫秒
	//Button	leftButton(20, 400, 70, 450, _T("image\\left.png"), 
	//				   [&]() {cm.move(Player::Direction::LEFT); Sleep(10); });
	//Button  upButton(70, 350, 120, 400, _T("F:\\projects\\cpp\\game\\image\\down.png"), 
	//				 [&]() {cm.move(Player::Direction::UP); Sleep(10); });
	//Button	rightButton(120, 400, 170, 450, _T("image\\right.png"), 
	//					[&]() {cm.move(Player::Direction::RIGHT); Sleep(10); });
	//Button	downButton(70, 450, 120, 500, _T("image\\down.png"), 
	//				   [&]() {cm.move(Player::Direction::DOWN); Sleep(10); });
	Keyboard keyboard{};
	while (true) { //进入一个无限循环
		//检查每个按钮是否被单击，如果是，就执行相应的移动操作，并延时10毫秒
		//leftButton.isClink();
		//upButton.isClink();
		//rightButton.isClink();
		//downButton.isClink();
		
		if (keyboard.isDown(Keyboard::Key::A)) {
			cm.move(Player::Direction::LEFT);
		}
		if (keyboard.isDown(Keyboard::Key::W)) {
			cm.move(Player::Direction::UP);
		}
		if (keyboard.isDown(Keyboard::Key::D)) {
			cm.move(Player::Direction::RIGHT);
		}
		if (keyboard.isDown(Keyboard::Key::S)) {
			cm.move(Player::Direction::DOWN);
		}
		
		Button::mouse.update(); // 更新鼠标的状态
		if (Button::mouse.isLeftDown()) {
			std::cout << "1";// 判断鼠标左键是否按下
			cm.shoot(Button::mouse); // 调用 player 的 shoot 方法，传入 mouse 作为参数
		}
		for (auto& bullet : cm.bullets) {
			bullet.move();
		}
	}
	return 0; //程序结束
}