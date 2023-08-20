#include"game.h" 
void beginGame();
bool GOON = true;

int main() {
	Window window{ 800,500,225,225,225 };

	Keyboard keyboard{};
	while (true) {
		if (GOON) {
			GOON = false;
			beginGame();

		}
	}
	return 0; //程序结束
}

void beginGame() {
	Player cm(390, 240, 410, 260, 1); //创建一个CsMove对象，用于表示一个可以移动的方块，参数是方块的初始坐标
	auto dir = Player::Direction::RIGHT;
	//创建按钮
	Button	leftButton(20, 400, 70, 450, _T("image\\left.png"), [&]() {dir = Player::Direction::LEFT; });
	Button  upButton(70, 350, 120, 400, _T("F:\\projects\\cpp\\game\\image\\down.png"), [&]() {dir = Player::Direction::UP; });
	Button	rightButton(120, 400, 170, 450, _T("image\\right.png"), [&]() {dir = Player::Direction::RIGHT; });
	Button	downButton(70, 450, 120, 500, _T("image\\down.png"), [&]() {dir = Player::Direction::DOWN; });

	while (true) { //进入一个无限循环
		leftButton.isClink();
		upButton.isClink();
		rightButton.isClink();
		downButton.isClink();
		cm.move(dir);

		auto gameOver = [&]() ->bool {
			if (cm.rLeft() < 0 || cm.rRight() > 800 || cm.rTop() < 0 || cm.rBottom() > 500) {
				return true;
			} else {
				return false;
			}
		};

		if (gameOver()) {
			settextstyle(100, 30, L"楷书");
			outtextxy(290, 170, L"游戏结束");
			Button close(230, 310, 320, 370, _T("image\\left.png"), [&]()->bool {return true; });
			Button goOn(480, 310, 580, 370, _T("image\\lef.png"), [&]() {GOON = true; return true; });
			while (goOn.isClink() || close.isClink()) {}
			break;

		}
		Sleep(10);
	}
}














/*
Button	leftButton(20, 400, 70, 450, _T("image\\left.png"),
				   [&]() {cm.move(Player::Direction::LEFT); Sleep(10); });
Button  upButton(70, 350, 120, 400, _T("F:\\projects\\cpp\\game\\image\\down.png"),
				 [&]() {cm.move(Player::Direction::UP); Sleep(10); });
Button	rightButton(120, 400, 170, 450, _T("image\\right.png"),
					[&]() {cm.move(Player::Direction::RIGHT); Sleep(10); });
Button	downButton(70, 450, 120, 500, _T("image\\down.png"),
				   [&]() {cm.move(Player::Direction::DOWN); Sleep(10); });










						leftButton.isClink();
		upButton.isClink();
		rightButton.isClink();
		downButton.isClink();
		/*if (keyboard.isADown()) {
			cm.move(Player::Direction::LEFT);
		}
		if (keyboard.isWDown()) {
			cm.move(Player::Direction::UP);
		}
		if (keyboard.isDDown()) {
			cm.move(Player::Direction::RIGHT);
		}
		if (keyboard.isSDown()) {
			cm.move(Player::Direction::DOWN);
		}*/
		//Button::mouse.update(); // 更新鼠标的状态
		//if (Button::mouse.isLeftDown()) {
		//	cm.shoot(Button::mouse); // 调用 player 的 shoot 方法，传入 mouse 作为参数
		//}
		//for (auto &bullet : cm.bullets) {
		//	bullet.move();
		//}*/


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
//检查每个按钮是否被单击，如果是，就执行相应的移动操作，并延时10毫秒
		//leftButton.isClink();
		//upButton.isClink();
		//rightButton.isClink();
		//downButton.isClink();
