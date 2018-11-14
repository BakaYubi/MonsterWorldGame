#pragma once
#include "Monster.h"
#include <conio.h>

class Human : public Monster {
public:
	Human(string n = "우미래인간", string i = "우", int x = 0, int y = 0) :Monster(n, i, x, y){}
	~Human() { cout << " [Human]"; }

	void move(int** map,int maxx,int maxy,char ch);
	int getDirKey() { return _getwche() == 224 ? _getwche() : 0; }
};