#pragma once
#include "LinkedQueue.h"
#include "EarthSoldier.h"
#include <iostream>
using namespace std;
//This Class inherits from LinkedQueue and is used to store EarthSoldier objects
class EarthSoldierQueue : public LinkedQueue<EarthSoldier*>
{
private:
	int count; //Keeps track of the number of EarthSoldier objects in the queue
	public:
	EarthSoldierQueue():LinkedQueue(){
		count = 0;
	}
	void add_earthsoldier(EarthSoldier* soldier){ //Adds an EarthSoldier object to the queue which is passed as a parameter
		enqueue(soldier);
		count++;
	}

	EarthSoldier* remove_earthsoldier(){ //Dequeues an EarthSoldier object from the queue and returns a pointer to it
		EarthSoldier* soldier;
		dequeue(soldier);
		count--;
		return soldier;
	}
	void print() { //Prints the ID of all EarthSoldier objects in the queue along with the total number of EarthSoldier objects
		//cout << "======================Earth Soldier Units========================" << endl;
		cout << "ES: " << count << " [";
		EarthSoldierQueue temp; //Temporary queue to store EarthSoldier objects
		EarthSoldier* soldier;
		while (!isEmpty()) {
			dequeue(soldier);
			cout << soldier->get_id() << " ";
			temp.enqueue(soldier);
		}
		cout << "]" << endl;
		while (!temp.isEmpty()) { //Re-enqueues the EarthSoldier objects back to the original queue
			temp.dequeue(soldier);
			enqueue(soldier);
		}
	}
	int get_count() { //Returns the total number of EarthSoldier objects in the queue
		return count;
	}
};