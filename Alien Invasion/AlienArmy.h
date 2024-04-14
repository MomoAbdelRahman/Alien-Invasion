#pragma once
#include "AlienSoldiersQ.h"
#include "AlienDronesDQ.h"
#include "AlienMonstersArr.h"
#include "LinkedQueue.h"

//AlienArmy class that holds all the units of aliens army
class AlienArmy {
private:
	AlienSoldierQueue AlienSoldiers; //Queue of AlienSoldiers
	AlienDronesDequeue AlienDrones; //Deque of AlienDrones
	AlienMonstersArray AlienMonsters;//Dynamic Array of AlienMonsters
	LinkedQueue<ArmyUnit*> KilledAliens; //Queue of KilledAliens
public:
	AlienArmy(){ //Default Constructor
		}
	bool Attack(); //Attack function that attacks the human army

	bool addunit(ArmyUnit* unit) {//Adds any army unit to the AlienArmy based on the enum type
		ArmyUnit* unit2 = nullptr;
		switch (unit->get_type()) {
		case ALIENSOLDIER:
			AlienSoldiers.add_aliensoldier((AlienSoldier*)unit);
			break;
		case DRONE:
			unit2=new AlienDrone(unit->get_id()+1,unit->get_health(),unit->get_join_time(),unit->get_power(),unit->get_attack_capacity());
			AlienDrones.insertDrone((AlienDrone*)unit, (AlienDrone*)unit2);
			break;
		case MONSTER:
			AlienMonsters.add((AlienMonster*)unit);
			break;
		}
		return true;
	
	}
	bool removeunit(ArmyUnit* unit); //Removes any army unit from the AlienArmy based on the enum type
	void print(); //Prints all the units of the AlienArmy
	int get_soldier_id(){
		return AlienSoldiers.get_count();
	}
	int get_drone_id(){
		return AlienDrones.get_count();
	}
	int get_monster_id(){
		return AlienMonsters.get_count();
	}

	int get_next_id() {
		return (AlienSoldiers.get_count() + AlienDrones.get_count() + AlienMonsters.get_count() + 1);
	}
};