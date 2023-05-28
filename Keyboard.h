#pragma once
#include<graphics.h>
#include<map>
class Keyboard {
public:
	enum class Key { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, };
	Keyboard();
	bool isDown(Key key);
	void update();
private:
	std::map<Key, bool> keyStates;
};

