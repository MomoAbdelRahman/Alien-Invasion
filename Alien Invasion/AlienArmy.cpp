#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
}

bool AlienArmy::Attack()
{
	return false;
}

bool AlienArmy::addunit(ArmyUnit* unit)
{
	if (!unit)
		return false;
	ArmyUnit* unit2 = nullptr;
	switch (unit->get_type()) {
	case ALIENSOLDIER:
		AlienSoldiers.add_aliensoldier((AlienSoldier*)unit);
		break;
	case DRONE:
		unit2 = new AlienDrone(unit->get_id() + 1, unit->get_health(), unit->get_join_time(), unit->get_power(), unit->get_attack_capacity());
		unit2->set_game(unit->get_game());
		AlienDrones.insertDrone((AlienDrone*)unit, (AlienDrone*)unit2);
		break;
	case MONSTER:
		AlienMonsters.add((AlienMonster*)unit);
		break;
	}
	return true;
}

void AlienArmy::removeunit(TYPE t, ArmyUnit*& unit, ArmyUnit*& unit2)
{
	AlienDrone* temp = nullptr;
	AlienDrone* temp4 = nullptr;
	AlienSoldier* temp2 = nullptr;
	AlienMonster* temp3 = nullptr;
	switch (t) {
	case ALIENSOLDIER:
		AlienSoldiers.remove_aliensoldier(temp2);
		unit = temp2;
		unit2 = nullptr;
		break;
	case DRONE:
		AlienDrones.removeDrones(temp, temp4);
		unit = temp;
		unit2 = temp4;
		break;
	case MONSTER:
		AlienMonsters.remove(temp3);
		unit = temp3;
		unit2 = nullptr;
		break;
	}
}

void AlienArmy::killunit(ArmyUnit* unit)
{
	if (unit) {
		KilledAliens.enqueue(unit); //Enqueues the killed unit to the KilledAliens queue
		killcount++; //Increments the killcount
	}
}

void AlienArmy::print()
{
	AlienSoldiers.print(); //Prints all the units of the AlienArmy
	AlienDrones.print(); //Prints all the units of the AlienArmy
	AlienMonsters.print(); //Prints all the units of the AlienArmy
}

int AlienArmy::get_soldier_id()
{
	return AlienSoldiers.get_count();
}

int AlienArmy::get_drone_id()
{
	return AlienDrones.get_count();
}

int AlienArmy::get_monster_id()
{
	return AlienMonsters.get_count();
}

int AlienArmy::get_next_id()
{
	return (AlienSoldiers.get_count() + AlienDrones.get_count() + AlienMonsters.get_count() + 1);
}

int AlienArmy::get_killcount()
{
	return killcount;
}

void AlienArmy::print_killed()
{
	LinkedQueue<ArmyUnit*> temp;
	while (!KilledAliens.isEmpty()) {
		ArmyUnit* temp2;
		KilledAliens.dequeue(temp2);
		temp.enqueue(temp2);
		cout << temp2->get_id();
		if (!KilledAliens.isEmpty()) {
			cout << ",";
		}
	}
	while (!temp.isEmpty()) {
		ArmyUnit* temp3;
		temp.dequeue(temp3);
		KilledAliens.enqueue(temp3);
	}
}

LinkedQueue<ArmyUnit*> AlienArmy::get_soldiers(int n)
{
	return AlienSoldiers.get_soldiers(n);
}
