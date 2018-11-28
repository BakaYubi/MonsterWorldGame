#include "Human.h"

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
void Human::move(int** map, int maxx, int maxy) {
	
	if (_kbhit()) {
		char ch = getDirKey();
		
		if (ch == Left) x--;
		else if (ch == Right) x++;
		else if (ch == Up) y--;
		else if (ch == Down) y++;
		else return;

		clip(maxx, maxy);
		eat(map);
	}
}

void Tuman::moveHuman(int** map, int maxx, int maxy, char ch) {

	if (ch == 'a' || ch == Left) x--;
	else if (ch == 'd' || ch == Right) x++;
	else if (ch == 'w' || ch == Up) y--;
	else if (ch == 's' || ch == Down) y++;
	else return;

	clip(maxx, maxy);
	eat(map);
}