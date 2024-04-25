#include "TanksStack.h"

EarthTankStack::EarthTankStack()
{
	count = 0;
}

bool EarthTankStack::AddTank(EarthTank* tank)
{
	if (tankStack.push(tank)) {
		count++; //increment the count of the number of tank units
		return true;
	}
	else {
		return false;
	}
}

void EarthTankStack::removeTank(EarthTank*& tank)
{
	if (tankStack.pop(tank)) {
		count--;
	}
}

void EarthTankStack::print()
{
	//cout << "======================Earth Tanks Units========================" << endl;
	cout << "ET: " << count << " [";
	EarthTankStack temp;//temporary stack to store the tank units
	while (!isEmpty()) {
		EarthTank* tank;
		removeTank(tank);
		cout << tank->get_id();
		temp.AddTank(tank);
		if (!isEmpty()) {
			cout << ",";
		}
	}
	cout << "]" << endl;
	while (!temp.isEmpty()) {//push the tank units back to the original stack
		EarthTank* tank;
		temp.removeTank(tank);
		AddTank(tank);
	}
}

int EarthTankStack::get_count()
{
	return count;
}

void EarthTankStack::selecttank(EarthTank* &tank)
{
	tankStack.peek(tank);
}

bool EarthTankStack::isEmpty()
{
	return tankStack.isEmpty();
}

LinkedQueue<ArmyUnit*>* EarthTankStack::get_tanks(int n)
{
	LinkedQueue<ArmyUnit*>* returned = new LinkedQueue<ArmyUnit*>;
	EarthTankStack temp;
	EarthTank* unit;
	int count = 0;
	while (!isEmpty()) {
		removeTank(unit);
		if (count < n) {
			if (unit) {
				returned->enqueue(unit);
				count++;
			}
		}
		temp.AddTank(unit);
	}
	while (!temp.isEmpty()) {
		temp.removeTank(unit);
		AddTank(unit);
	}
	return returned;
}
