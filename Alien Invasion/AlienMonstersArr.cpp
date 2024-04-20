#include "AlienMonstersArr.h"

AlienMonstersArray::AlienMonstersArray(int size)
{
	this->size = size;
	this->count = 0;
	this->alienMonsters = new AlienMonster * [size];
}

void AlienMonstersArray::add(AlienMonster* alienMonster)
{
	if (count < size) {
		alienMonsters[count] = alienMonster;
		count++;
	}
	else
	{
		return;
	}
}

void AlienMonstersArray::remove(AlienMonster*& monster)
{
	if (next == -1 && count) {
		next = rand() % count;
	}
	if (count > 0) {
		monster = alienMonsters[next];
		for (int i = next; i < count - 1; i++) { //Shifts the elements to the left
			alienMonsters[i] = alienMonsters[i + 1];
		}
		count--;
		// next = rand() % count;
		if (count)
			next = rand() % count;
	}
}

void AlienMonstersArray::print()
{
	// cout << "======================Alien Monster Units========================" << endl;
	cout << "AM:" << count << " [";
	for (int i = 0; i < count; i++) {
		cout << alienMonsters[i]->get_id();
		if (i < count - 1)
			cout << ",";
	}
	cout << "]" << endl;
}

int AlienMonstersArray::get_count()
{
	return count;
}

void AlienMonstersArray::select_monster(AlienMonster* &monster)
{
	if (next == -1) {
		next = rand() % count;
	}
	monster = alienMonsters[next];
}

