#pragma once
#include "Canvas.h"
#define DIM 40
#define INIT_ENERGY 50
#define ITEM_ENERGY 2

class Monster {
protected:
	string name, icon;	// ���� �̸��� ȭ�� ��¿� ������
	int x, y, nItem;		// ���� ��ġ�� ���� ������ ��
	int nEnergy;

	void clip(int maxx, int maxy);  
//	void eat(int map[DIM][DIM]); 
	void eat(int** map);
public:
	Monster(string n = "���̱���", string i = "��", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(INIT_ENERGY) {
		cout << "���� �̸� = " << n << endl;
		system("pause");
	}
	~Monster() { 
		cout << "\t" << name << icon << " �������ϴ�~~~\n";
		system("pause");
	}

	void draw(Canvas &canvas);  
//	void move(int map[DIM][DIM], int maxx, int maxy);  
	virtual void move(int** map, int maxx, int maxy);
	void print();  
	int getEnergy() { return nEnergy; }
	string getName() { return name; }
};