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
		
	}
	if (count)
		next = rand() % count;
	else {
		next = -1;
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
	if (count == 0) {
		return;
	}
	if (next == -1) {
		next = rand() % count;
	}
	monster = alienMonsters[next];
}

LinkedQueue<ArmyUnit*>* AlienMonstersArray::get_monsters(int n) {
	LinkedQueue<ArmyUnit*>* returned = new LinkedQueue<ArmyUnit*>;
	AlienMonster* monster;
	AlienMonstersArray temp;
	int count = 0;
	while (!isEmpty()) {
		remove(monster);
		if (count < n) {
			returned->enqueue(monster);
			count++;
		}
		temp.add(monster);
	}
	while (!temp.isEmpty()) {
		temp.remove(monster);
		add(monster);
	}
	return returned;
	//ArmyUnit** temp=new ArmyUnit*[n];
	//for (int i = 0; i < n; i++) { temp[i] = nullptr; }
	//AlienMonstersArray m;
	//AlienMonster* monster;
	//int count = 0;
	//while (!isEmpty()) {
	//	remove(monster);
	//	if (count < n) {
	//		if(monster)
	//		temp[count]=(monster);
	//		count++;
	//	}
	//	m.add(monster);
	//}
	//while (!m.isEmpty()) {
	//	m.remove(monster);
	//	add(monster);
	//}
	//return temp;
}

bool AlienMonstersArray::isEmpty()
{
	return count==0;
}
