#pragma once
#include<graphics.h>
#include<map>
#include"Mouse.h"
class Keyboard {
public:
	enum class Key { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, };
	Keyboard();
	bool isKeyDown(Key key);
	bool isADown();
	bool isDDown();
	bool isSDown();
	bool isWDown();
private:
	ExMessage key{};
};
/*


bool isDown(Key key);
	void update();



std::map<Key, bool> keyStates;







*/
