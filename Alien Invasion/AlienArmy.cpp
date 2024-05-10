#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
}

bool AlienArmy::Attack()
{
	AlienSoldier* attackingsolder = nullptr;
	AlienSoldiers.select_soldier(attackingsolder);
	if (attackingsolder) { attackingsolder->attack(); }

	AlienMonster* attackingmonster = nullptr;
	AlienMonsters.select_monster(attackingmonster);
	if (attackingmonster) { attackingmonster->attack(); }
	
	AlienDrone* attackingdrone = nullptr;
	AlienDrone* attackingdrone2 = nullptr;
	AlienDrones.select_drone(attackingdrone, attackingdrone2);
	if(attackingdrone) { attackingdrone->attack(); }
	if(attackingdrone2) { attackingdrone2->attack(); }
	return true;

}

bool AlienArmy::addunit(ArmyUnit* unit)
{
	if (!unit)
		return false;
	ArmyUnit* unit2 = nullptr;
	switch (unit->get_type()) {
	case ALIENSOLDIER:
		AlienSoldiers.add_aliensoldier((AlienSoldier*)unit);
		current_id++;
		break;
	case DRONE:
		unit2 = new AlienDrone(unit->get_id() + 1 , unit->get_health(), unit->get_join_time(), unit->get_power(), unit->get_attack_capacity());
		unit2->set_game(unit->get_game());
		AlienDrones.insertDrone((AlienDrone*)unit, (AlienDrone*)unit2);
		current_id = current_id + 2;
		break;
	case MONSTER:
		AlienMonsters.add((AlienMonster*)unit);
		current_id++;
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

bool AlienArmy::isEmpty()
{
	if (AlienDrones.isEmpty() && AlienMonsters.isEmpty() && AlienSoldiers.isEmpty()) return true;
	return false;
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
	return current_id + 1;
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

LinkedQueue<ArmyUnit*>* AlienArmy::get_soldiers(int n)
{
	return AlienSoldiers.get_soldiers(n);
}

LinkedQueue<ArmyUnit*>* AlienArmy::get_monsters(int n)
{
	return AlienMonsters.get_monsters(n);
}

LinkedQueue<ArmyUnit*>* AlienArmy::get_drones(int n)
{
	return AlienDrones.get_drones(n);
}
