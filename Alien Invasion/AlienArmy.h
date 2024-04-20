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
	int killcount = 0; //Counter for the number of killed aliens
public:
	AlienArmy(){ //Default Constructor
		}
	bool Attack(); //Attack function that attacks the human army

	bool addunit(ArmyUnit* unit) {//Adds any army unit to the AlienArmy based on the enum type
		if (!unit)
      return false;
    ArmyUnit* unit2 = nullptr;
		switch (unit->get_type()) {
		case ALIENSOLDIER:
			AlienSoldiers.add_aliensoldier((AlienSoldier*)unit);
			break;
		case DRONE:
			unit2=new AlienDrone(unit->get_id()+1,unit->get_health(),unit->get_join_time(),unit->get_power(),unit->get_attack_capacity());
			unit2->set_game(unit->get_game());
			AlienDrones.insertDrone((AlienDrone*)unit, (AlienDrone*)unit2);
			break;
		case MONSTER:
			AlienMonsters.add((AlienMonster*)unit);
			break;
		}
		return true;
	
	}
	void removeunit(TYPE t, ArmyUnit* &unit,ArmyUnit* &unit2) {//Removes any army unit from the AlienArmy based on the enum type
		AlienDrone* temp = nullptr;
		AlienDrone* temp4= nullptr;
		AlienSoldier* temp2 = nullptr;
		AlienMonster* temp3 = nullptr;
		switch (t) {
		case ALIENSOLDIER:
			AlienSoldiers.remove_aliensoldier(temp2);
			unit = temp2;
			unit2=nullptr;
			break;
		case DRONE:
			AlienDrones.removeDrones(temp,temp4);
			unit = temp;
			unit2 = temp4;
			break;
		case MONSTER:
			AlienMonsters.remove(temp3);
			unit = temp3;
			unit2=nullptr;
			break;
		}
	
	}

	void killunit(ArmyUnit* unit) {//Kills any army unit from the AlienArmy
		if (unit) {
			KilledAliens.enqueue(unit); //Enqueues the killed unit to the KilledAliens queue
			killcount++; //Increments the killcount
		}
	}

	void print() { //Prints all the units of the AlienArmy
		AlienSoldiers.print(); //Prints all the units of the AlienArmy
		AlienDrones.print(); //Prints all the units of the AlienArmy
		AlienMonsters.print(); //Prints all the units of the AlienArmy
	} 
	
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
	int get_killcount() {
		return killcount;
	}

	void print_killed() {
		LinkedQueue<ArmyUnit*> temp;
		while(!KilledAliens.isEmpty()) {
			ArmyUnit* temp2;
			KilledAliens.dequeue(temp2);
			temp.enqueue(temp2);
			cout << temp2->get_id();
			if(!KilledAliens.isEmpty()) {
				cout << ",";
			}
		}
		while(!temp.isEmpty()) {
			ArmyUnit* temp3;
			temp.dequeue(temp3);
			KilledAliens.enqueue(temp3);
		}
	}
};
