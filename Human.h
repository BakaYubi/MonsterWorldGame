#pragma once
#include "Monster.h"
#include <conio.h>

class Human : public Monster {
public:
	Human(string n = "��̷��ΰ�", string i = "��", int x = 0, int y = 0) :Monster(n, i, x, y){}
	~Human() { cout << " [Human]"; }

	void move(int** map,int maxx,int maxy,char ch);
	int getDirKey() { return _getwche() == 224 ? _getwche() : 0; }
};