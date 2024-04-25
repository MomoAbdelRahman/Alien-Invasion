#include "EarthArmy.h"

EarthArmy::EarthArmy()
{
}

bool EarthArmy::attack()
{
	EarthSoldier* attacksoldier = nullptr;
	EarthSoldiers.select_soldier(attacksoldier);
	if (attacksoldier) { attacksoldier->attack(); }

	EarthTank* attacktank = nullptr;
	EarthTanks.selecttank(attacktank);
	if(attacktank) { attacktank->attack(); }

	EarthGunnery* attackgunnery = nullptr;
	EarthGunneries.select_gunnery(attackgunnery);
	if(attackgunnery) { attackgunnery->attack(); }

	return true;
}

bool EarthArmy::addunit(ArmyUnit* unit)
{
	if (!unit)
		return false;
	switch (unit->get_type()) {
	case EARTHSOLDIER:
		EarthSoldiers.add_earthsoldier((EarthSoldier*)unit);
		current_id++;
		break;
	case TANK:
		EarthTanks.AddTank((EarthTank*)unit);
		current_id++;
		break;
	case GUNNERY:
		int priority = ((EarthGunnery*)unit)->get_health() + ((EarthGunnery*)unit)->get_power();
		EarthGunneries.AddGunnery((EarthGunnery*)unit);
		current_id++;
		break;
	}
	return true;
}

void EarthArmy::removeunit(TYPE t, ArmyUnit*& unit)
{
	EarthSoldier* temp = nullptr;
	EarthTank* temp2 = nullptr;
	EarthGunnery* temp3 = nullptr;
	switch (t) {
	case EARTHSOLDIER:
		EarthSoldiers.remove_earthsoldier(temp);
		unit = temp;
		break;
	case TANK:
		EarthTanks.removeTank(temp2);
		unit = temp2;
		break;
	case GUNNERY:
		EarthGunneries.RemoveGunnery(temp3);
		unit = temp3;
		break;
	}
}

void EarthArmy::killunit(ArmyUnit* unit)
{
	if (unit) {
		KilledEarth.enqueue(unit);
		killcount++;
	}
}

void EarthArmy::print()
{
	EarthSoldiers.print(); //Prints the soldiers in the army
	EarthTanks.print(); //Prints the tanks in the army
	EarthGunneries.print(); //Prints the gunnery in the army
}

int EarthArmy::get_soldier_id()
{
	return EarthSoldiers.get_count();
}

int EarthArmy::get_tank_id()
{
	return EarthTanks.get_count();
}

int EarthArmy::get_gunnery_id()
{
	return EarthGunneries.get_count();
}

int EarthArmy::get_next_id()
{
	return current_id+1;
}

int EarthArmy::get_killcount()
{
	return killcount;
}

void EarthArmy::print_killed()
{
	LinkedQueue<ArmyUnit*> temp;
	while (!KilledEarth.isEmpty()) {
		ArmyUnit* temp2;
		KilledEarth.dequeue(temp2);
		temp.enqueue(temp2);
		cout << temp2->get_id();
		if (!KilledEarth.isEmpty()) {
			cout << ",";
		}
	}
	while (!temp.isEmpty()) {
		ArmyUnit* temp3;
		temp.dequeue(temp3);
		KilledEarth.enqueue(temp3);
	}
	
}

LinkedQueue<ArmyUnit*>* EarthArmy::get_soldiers(int n)
{
	return EarthSoldiers.get_soldiers(n);
}

LinkedQueue<ArmyUnit*>* EarthArmy::get_tanks(int n)
{
	return EarthTanks.get_tanks(n);
}

LinkedQueue<ArmyUnit*>* EarthArmy::get_gunneries(int n)
{
	return EarthGunneries.get_gunneries(n);
}

