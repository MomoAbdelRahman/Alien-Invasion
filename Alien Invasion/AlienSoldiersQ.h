#pragma once
#include "LinkedQueue.h"
#include "AlienSoldier.h"
#include <iostream>
using namespace std;
//This Class inherits from LinkedQueue and is used to store AlienSoldier objects
class AlienSoldierQueue : public LinkedQueue < AlienSoldier* >
{
private:
	int count; //Keeps track of the number of AlienSoldier objects in the queue
public:
	AlienSoldierQueue() :LinkedQueue() {
		count = 0;
	}
	void add_aliensoldier(AlienSoldier *soldier) { //Adds an AlienSoldier object to the queue which is passed as a parameter
		enqueue(soldier);
		count++;
	}

	AlienSoldier* remove_aliensoldier() { //Dequeues an AlienSoldier object from the queue and returns a pointer to it
		AlienSoldier* soldier;
		dequeue(soldier);
		count--;
		return soldier;
	}
	void print() { //Prints the ID of all AlienSoldier objects in the queue along with the total number of EarthSoldier objects
		cout << "======================Earth Soldier Units========================" << endl;
		cout << "Total Number of Earth Soldier Units: " << count << " [";
		AlienSoldierQueue temp; //Temporary queue to store AlienSoldier objects
		AlienSoldier* soldier;
		while (!isEmpty()) {
			dequeue(soldier);
			cout << soldier->get_id() << " ";
			temp.enqueue(soldier);
		}
		cout << "]" << endl;
		while (!temp.isEmpty()) { //Re-enqueues the AlienSoldier objects back to the original queue
			temp.dequeue(soldier);
			enqueue(soldier);
		}
	}
};