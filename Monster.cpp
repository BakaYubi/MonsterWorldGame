#include "Monster.h"

void Monster::clip(int maxx, int maxy) {
	if (p[0] < 0) p[0] = 0;
	if (p[0] >= maxx) p[0] = maxx - 1;
	if (p[1] < 0) p[1] = 0;
	if (p[1] >= maxy) p[1] = maxy - 1;
}
void Monster::eat(int** map) {
	if (map[p[1]][p[0]] == 1) {
		map[p[1]][p[0]] = 0;
		nItem++;
		nEnergy += ITEM_ENERGY;
	}
	else {
		if(nEnergy > 0) nEnergy--;
	}
	dist += (double)(p - q);
	total += (double)(p - q);
	q = p;
	if (dist > 20) {
		dist = 0;
		nSleep = 10;
	}
}

bool Monster::isSleep()
{
	if(nSleep > 0)
	{
		nSleep--;
		return true;
	}
	return false;
}
 
void Monster::draw(Canvas &canvas) { canvas.draw(p[0], p[1], icon); }
void Monster::move(int** map, int maxx, int maxy) {
	if (!isSleep()) {
		switch (rand() % 8) {
		case 0: p[1]--; break;
		case 1: p[0]++; p[1]--; break;
		case 2: p[0]++; break;
		case 3: p[0]++; p[1]++; break;
		case 4: p[1]++; break;
		case 5: p[0]--; p[1]++; break;
		case 6: p[0]--; break;
		case 7: p[0]--; p[1]--; break;
		
		clip(maxx, maxy);
		eat(map);
		}
	}
}

void Monster::
print() { cout << "\t" << name << icon << ":" << nItem << " 에너지 : " << nEnergy <<" 쉬는시간 : "<<nSleep<< endl; }