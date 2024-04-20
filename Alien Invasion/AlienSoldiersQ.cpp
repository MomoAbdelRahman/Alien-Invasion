#include "AlienSoldiersQ.h"

AlienSoldierQueue::AlienSoldierQueue()
{
	count = 0;
}

void AlienSoldierQueue::add_aliensoldier(AlienSoldier* soldier)
{
	soldiers.enqueue(soldier);
	count++;
}

void AlienSoldierQueue::remove_aliensoldier(AlienSoldier*& soldier)
{
	if (soldiers.dequeue(soldier)) {
		count--;
	}
}

void AlienSoldierQueue::print()
{
	//cout << "======================Alien Soldier Units========================" << endl;
	cout << "AS: " << count << " [";
	AlienSoldierQueue temp; //Temporary queue to store AlienSoldier objects
	AlienSoldier* soldier;
	while (!isEmpty()) {
		remove_aliensoldier(soldier);
		cout << soldier->get_id();
		if (!isEmpty())
			cout << ",";
		temp.add_aliensoldier(soldier);
	}
	cout << "]" << endl;
	while (!temp.isEmpty()) { //Re-enqueues the AlienSoldier objects back to the original queue
		temp.remove_aliensoldier(soldier);
		add_aliensoldier(soldier);
	}
}

int AlienSoldierQueue::get_count()
{
	return count;
}

void AlienSoldierQueue::select_soldier(AlienSoldier* &soldier)
{
	soldiers.peek(soldier);
}

bool AlienSoldierQueue::isEmpty()
{
	return soldiers.isEmpty();
}

LinkedQueue<ArmyUnit*> AlienSoldierQueue::get_soldiers(int n)
{
	LinkedQueue<ArmyUnit*> temp;
	AlienSoldierQueue temp2;
	AlienSoldier* soldier;
	int c = 0;
	while (!isEmpty()) {
		remove_aliensoldier(soldier);
		if (c < n) {
			temp.enqueue(soldier);
			c++;
		}
		temp2.add_aliensoldier(soldier);
	}
	while (!temp2.isEmpty()) {
		temp2.remove_aliensoldier(soldier);
		add_aliensoldier(soldier);
	}
	return temp;
}
