#include "EarthSoldierQ.h"

EarthSoldierQueue::EarthSoldierQueue()
{
	count = 0;
}

void EarthSoldierQueue::add_earthsoldier(EarthSoldier* soldier)
{
	soldiers.enqueue(soldier);
	count++;
}

void EarthSoldierQueue::remove_earthsoldier(EarthSoldier*& soldier)
{
	if (soldiers.dequeue(soldier)) {
		count--;
	}
}

void EarthSoldierQueue::print()
{
	//cout << "======================Earth Soldier Units========================" << endl;
	cout << "ES: " << count << " [";
	EarthSoldierQueue temp; //Temporary queue to store EarthSoldier objects
	EarthSoldier* soldier;
	while (!soldiers.isEmpty()) {
		soldiers.dequeue(soldier);
		cout << soldier->get_id();
		if (!soldiers.isEmpty()) {
			cout << ",";
		}
		temp.add_earthsoldier(soldier);
	}
	cout << "]" << endl;
	while (!temp.isempty()) { //Re-enqueues the EarthSoldier objects back to the original queue
		temp.remove_earthsoldier(soldier);
		soldiers.enqueue(soldier);
	}
}

int EarthSoldierQueue::get_count()
{
	return count;
}

void EarthSoldierQueue::select_soldier(EarthSoldier* &soldier)
{
	soldiers.peek(soldier);
}

bool EarthSoldierQueue::isempty()
{
	return soldiers.isEmpty();
}
