#pragma once
#include "Monster.h"
#include <conio.h>

class Human : public Monster {
public:
	Human(string n = "미래인간", string i = "♣", int x = 0, int y = 0) :Monster(n, i, x, y){}
	~Human() { cout << " [Human]"; }

	void move(int** map,int maxx,int maxy);
	int getDirKey() { return _getwche() == 224 ? _getwche() : 0; }
};

class Tuman : public Human {
public:
	Tuman(string n = "미래투맨", string i = "♣", int x = 0, int y = 0) :Human(n, i, x, y) {}
	~Tuman() { cout << " [Tuman]"; }

	void moveHuman(int** map, int maxx, int maxy, char ch);
};