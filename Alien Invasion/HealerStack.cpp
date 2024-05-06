#include "HealerStack.h"

EarthHealerStack::EarthHealerStack()
{
	count = 0;
}

bool EarthHealerStack::AddHealer(EarthHealer* healer)
{
	if (healerStack.push(healer)) {
		count++; //increment the count of the number of tank units
		return true;
	}
	else {
		return false;
	}
}

void EarthHealerStack::removeHealer(EarthHealer*& healer)
{
	if (healerStack.pop(healer)) {
		count--;
	}
}

void EarthHealerStack::print()
{
	cout << "EH: " << count << " [";
	healerStack.printstack();
	cout << "]" << endl;
}

int EarthHealerStack::get_count()
{
	return count;
}

void EarthHealerStack::selecthealer(EarthHealer*& healer)
{
	healerStack.peek(healer);
}

bool EarthHealerStack::isEmpty()
{
	return healerStack.isEmpty();
}

LinkedQueue<ArmyUnit*>* EarthHealerStack::get_healers(int n)
{
	LinkedQueue<ArmyUnit*>* returned = new LinkedQueue<ArmyUnit*>;
	EarthHealerStack temp;
	EarthHealer* unit;
	int count = 0;
	while (!isEmpty()) {
		removeHealer(unit);
		if (count < n) {
			if (unit) {
				returned->enqueue(unit);
				count++;
			}
		}
		temp.AddHealer(unit);
	}
	while (!temp.isEmpty()) {
		temp.removeHealer(unit);
		AddHealer(unit);
	}
	return returned;
}
