#pragma once
#include "Human.h"
class Tuman :public Human
{
public:
	Tuman(string n = "�¹̷��ΰ�", string i = "��", int x = 0, int y = 0) :Human(n, i, x, y) {}
	~Tuman() { cout << " [Tuman]"; }

	void move(int** map, int maxx, int maxy,char ch);
	//int getDirKey() { return _getwche(); }
};

