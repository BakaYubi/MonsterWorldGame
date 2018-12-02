#include "Human.h"

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
void Human::move(int** map, int maxx, int maxy) {
	
	if (_kbhit()) {
		char ch = getDirKey();
		
		if (ch == Left) p[0]--;
		else if (ch == Right) p[0]++;
		else if (ch == Up) p[1]--;
		else if (ch == Down) p[1]++;
		else return;

		clip(maxx, maxy);
		eat(map);
	}
}

void Tuman::moveHuman(int** map, int maxx, int maxy, char ch) {

	if (ch == 'a' || ch == Left) p[0]--;
	else if (ch == 'd' || ch == Right) p[0]++;
	else if (ch == 'w' || ch == Up) p[1]--;
	else if (ch == 's' || ch == Down) p[1]++;
	else return;

	clip(maxx, maxy);
	eat(map);
}