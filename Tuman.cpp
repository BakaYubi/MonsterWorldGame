#include "Tuman.h"

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
void Tuman::move(int** map, int maxx, int maxy,char ch) {

	if (ch == Left) x--;
	else if (ch == Right) x++;
	else if (ch == Up) y--;
	else if (ch == Down) y++;

	if (ch == 'a') x--;
	else if (ch == 'd') x++;
	else if (ch == 'w') y--;
	else if (ch == 's') y++;

	clip(maxx, maxy);
	eat(map);
}