#include "MonsterWorld.h"
#include "VariousMonster.h"

bool MonsterWorld::isDone()
{
	if (countItems() == 0) {
		cout << "������ = 0 --------> ���� ���� ..... \n\n";
		return true;
	}
	if (nMon == 0) {
		cout << "���� = 0 --------> ���� ���� ..... \n\n";
		return true;
	}
	return false;
}

int MonsterWorld::countItems() {
	int nItems = 0;
	for (int y = 0; y < yMax; y++)
		for (int x = 0; x < xMax; x++)
			if (Map(x, y) > 0) nItems++;
	return nItems;
}
void MonsterWorld::print() {
	canvas.clear();
	for (int y = 0; y < yMax; y++)
		for (int x = 0; x < xMax; x++)
			if (Map(x, y) > 0) canvas.draw(x, y, "��");
	for (int i = 0; i < nMon; i++)
	//	mon[i].draw(canvas);
		pMon[i]->draw(canvas);
	canvas.print("[ Monster World (���͵��� ����) ]");

	cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
	cerr << " ���� ������ �� = " << countItems() << endl;
	for (int i = 0; i < nMon; i++)
	//	mon[i].print();
		pMon[i]->print();
}

MonsterWorld::MonsterWorld(int w, int h, int n) : world(h, w), canvas(w, h), xMax(w), yMax(h), nItemCnt(n) {
	nMon = 0;
	nMove = 0;

	for (int y = 0; y < yMax; y++)
		for (int x = 0; x < xMax; x++) Map(x, y) = 0;

	int x, y, cnt;
	cnt = nItemCnt;
	while (cnt) {
		x = (rand() % xMax);
		y = (rand() % yMax);
		if (Map(x, y) == 0) {
			Map(x, y) = 1;	
			cnt--;
		}
	}
}
 
//void MonsterWorld::add(Monster& m) {
void MonsterWorld::add(Monster* m) {
	//cout << "���� �̸� = " << m->getName() << endl;
	//	if (nMon < MAXMONS) mon[nMon++] = m;
	if (nMon < MAXMONS) pMon[nMon++] = m;
}
#include <assert.h>
void MonsterWorld::play(int maxwalk, int wait) {
	print();
	cerr << " ���͸� ��������...";
	getchar();
	for (int i = 0; i < maxwalk; i++) {
		for (int k = 0; k < nMon; k++) {
			//	mon[k].move(map, xMax, yMax);
			pMon[k]->move(world.Data(), xMax, yMax);
		}
		nMove++;
		print();
		checkEnergy();
		if (isDone()) break;
		Sleep(wait);
	}
}

void MonsterWorld::checkEnergy()
{
	for (size_t i = 0; i < nMon; i++)
	{
		if (pMon[i]->getEnergy() == 0) {
			string str = pMon[i]->getName();
			cout << "\t" << str << " Monster�� ���� �׾����ϴ�." << endl;
			delete pMon[i];
			if (i != (nMon - 1)) {
				pMon[i] = pMon[nMon - 1];
			}
			nMon--;
		}
	}
}
