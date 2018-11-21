#pragma once
#include "Canvas.h"
#include "Monster.h"
#include "Matrix.h"
#include <windows.h>
#define DIM  40
#define MAXMONS 8

class MonsterWorld {
//	int map[DIM][DIM];      // MonsterWorld 按眉 积己矫 map[40][40] 皋葛府 且寸
	Matrix world;
	int xMax, yMax, nMon, nMove, nItemCnt;
//	Monster mon[MAXMONS];    // MonsterWorld 按眉 积己矫 Monster按眉 积己
	Monster* pMon[MAXMONS];
	Canvas	canvas;          

	int& Map(int x, int y) { return world.elem(x, y); }
	bool isDone();
	int countItems();  
	void print(); 
public:
	MonsterWorld(int w, int h, int n);
	~MonsterWorld() { 
		for (int i = 0; i < nMon; i++) {
			delete pMon[i];
		}
	}
	void add(Monster* m);  
	void play(int maxwalk, int wait);  
	void checkEnergy();
};