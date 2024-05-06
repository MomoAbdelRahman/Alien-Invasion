#include "UnitMaintenanceList.h"
#include "game.h"

UnitMaintenanceList::UnitMaintenanceList()
{
}

UnitMaintenanceList::UnitMaintenanceList(int max_health) : maxH(max_health)
{
}

void UnitMaintenanceList::set_max_health(int max) 
{
	maxH = max;
}

void UnitMaintenanceList::add_tank(EarthTank* unit)
{
	tanks.enqueue(unit);
	count++;
	tanks_count++;
}

void UnitMaintenanceList::add_soldier(EarthSoldier* unit)
{
	soldiers.enqueue(unit,maxH-unit->get_health());
	count++;
	soldiers_count++;
}

void UnitMaintenanceList::add_unit(ArmyUnit* unit)
{
	if (unit->get_type() == EARTHSOLDIER) add_soldier((EarthSoldier*)unit);
	else add_tank((EarthTank*)unit);
}

bool UnitMaintenanceList::remove_tank(EarthTank*& unit)
{
	if (tanks.dequeue(unit)) {
		count--;
		tanks_count--;
		return true;
	}
	return false;
}

bool UnitMaintenanceList::remove_soldier(EarthSoldier*& unit)
{
	int pri;
	if (soldiers.dequeue(unit,pri)) {
		count--;
		soldiers_count--;
		return true;
	}
	return false;
}

bool UnitMaintenanceList::remove_unit(ArmyUnit*& unit)
{
	if (!is_soldiers_empty()) {
		remove_soldier((EarthSoldier*&)unit);
		return true;
	}
	else if(!is_empty()){
		remove_tank((EarthTank*&)unit);
		return true;
	}
	return false;
}



bool UnitMaintenanceList::is_empty()
{
	return !count;
}

bool UnitMaintenanceList::is_soldiers_empty()
{
	return !soldiers_count;
}

LinkedQueue<ArmyUnit*>* UnitMaintenanceList::get_injured(int n)
{
	LinkedQueue<ArmyUnit*>* injured = new LinkedQueue<ArmyUnit*>;
	EarthSoldier* tempS;
	EarthTank* tempT;
	int cnt = 0;
	while (!is_empty() &&cnt<n) {
			if (!is_soldiers_empty()) {
				remove_soldier(tempS);
				injured->enqueue(tempS);
				cnt++;
			}
			else {
				remove_tank(tempT);
				injured->enqueue(tempT);
				cnt++;
			}
	}
	return injured;
}

int UnitMaintenanceList::get_count() const
{
	return count;
}

int UnitMaintenanceList::get_soldier_count() const
{
	return soldiers_count;
}

int UnitMaintenanceList::get_tank_count() const
{
	return tanks_count;
}

void UnitMaintenanceList::print()
{
	cout << "UML: " << count << " [";
	soldiers.printpriQ();
	cout << ",";
	tanks.printQ();
	cout << "] ";
}








