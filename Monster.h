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
	string name, icon;	// 몬스터 이름과 화면 출력용 아이콘
//	int x, y, nItem;		// 현재 위치와 먹은 아이템 수
	int nItem;
	Point p, q;	// x, y를 없애고 Point 를 쓴다.	// q = 이전위치 p = 현재위치
	int nSleep;	// 많이 움직이는 몬스터는 카운트를 해서 못움직이게 한다	// 쉬어야 하는 횟수
	int dist; // 현재 지점에서 이동한 거리	// 쉬고 난 다음 움직인 거리
	int total; // p, q로 작동되도록	// 총 움직인 거리
	int nEnergy;

	void clip(int maxx, int maxy);  
//	void eat(int map[DIM][DIM]); 
	void eat(int** map);
public:
	Monster(string n = "더미괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(INIT_ENERGY) {
		cout << "몬스터 이름 = " << n << endl;
		system("pause");
	}
	~Monster() { 
		cout << "\t" << name << icon << " 물러갑니다~~~\n";
		system("pause");
	}

	void draw(Canvas &canvas);  
//	void move(int map[DIM][DIM], int maxx, int maxy);  
	virtual void move(int** map, int maxx, int maxy);
	void print();  
	int getEnergy() { return nEnergy; }
	string getName() { return name; }
};