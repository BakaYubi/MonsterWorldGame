#pragma once
#include "Canvas.h"
#define DIM 40
#define INIT_ENERGY 50
#define ITEM_ENERGY 2

class Point {
	int x, y;
	friend class Monster;
	friend class Canvas;
public:
	Point(int xx = 0, int yy = 0) :x(xx), y(yy) {}
	int& operator[](int id) {
		if (id == 0)return x;
		else if (id == 1) return y;
		else exit(0);
	}
	operator double() { return sqrt((double)x*x + y*y); }
	void operator()(int maxx, int maxy) {
		if (x < 0)x = 0;
		if (x >= maxx)x = maxx - 1;
		if (y < 0)y = 0;
		if (y >= maxy)y = maxy - 1;
	}
	Point operator- () { return Point(-x, -y); }
	bool operator== (Point &p) { return x == p.x&&y == p.y; }
	bool operator!= (Point &p) { return x != p.x || y != p.y; }
	Point operator- (Point &p) { return Point(x - p.x, y - p.y); }
	Point operator+ (Point &p) { return Point(x + p.x, y + p.y); }
	void operator+= (Point &p) { x += p.x, y += p.y; }
	void operator-= (Point &p) { x -= p.x, y -= p.y; }
};

class Monster {
protected:
	string name, icon;	// ���� �̸��� ȭ�� ��¿� ������
//	int x, y, nItem;		// ���� ��ġ�� ���� ������ ��
	int nItem;
	Point p, q;	// x, y�� ���ְ� Point �� ����.	// q = ������ġ p = ������ġ
	int nSleep;	// ���� �����̴� ���ʹ� ī��Ʈ�� �ؼ� �������̰� �Ѵ�	// ����� �ϴ� Ƚ��
	int dist; // ���� �������� �̵��� �Ÿ�	// ���� �� ���� ������ �Ÿ�
	int total; // p, q�� �۵��ǵ���	// �� ������ �Ÿ�
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