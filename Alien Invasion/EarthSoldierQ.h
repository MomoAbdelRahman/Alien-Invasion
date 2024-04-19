#pragma once
#include "LinkedQueue.h"
#include "EarthSoldier.h"
#include <iostream>
using namespace std;
//This Class inherits from LinkedQueue and is used to store EarthSoldier objects
class EarthSoldierQueue
{
private:
	int count; //Keeps track of the number of EarthSoldier objects in the queue
	LinkedQueue<EarthSoldier*> soldiers; //Queue to store EarthSoldier objects
public:
	EarthSoldierQueue(){
		count = 0;
	}
	void add_earthsoldier(EarthSoldier* soldier){ //Adds an EarthSoldier object to the queue which is passed as a parameter
		soldiers.enqueue(soldier);
		count++;
	}

	void remove_earthsoldier(EarthSoldier* &soldier){ //Dequeues an EarthSoldier object from the queue and returns a pointer to it
		if(soldiers.dequeue(soldier)){
			count--;
		}
	}
	void print() { //Prints the ID of all EarthSoldier objects in the queue along with the total number of EarthSoldier objects
		//cout << "======================Earth Soldier Units========================" << endl;
		cout << "ES: " << count << " [";
		EarthSoldierQueue temp; //Temporary queue to store EarthSoldier objects
		EarthSoldier* soldier;
		while (!soldiers.isEmpty()) {
			soldiers.dequeue(soldier);
			cout << soldier->get_id();
			if (!soldiers.isEmpty()) {
				cout << ",";
			}
			temp.add_earthsoldier(soldier);
		}
		cout << "]" << endl;
		while (!temp.isempty()) { //Re-enqueues the EarthSoldier objects back to the original queue
			temp.remove_earthsoldier(soldier);
			soldiers.enqueue(soldier);
		}
	}
	int get_count() { //Returns the total number of EarthSoldier objects in the queue
		return count;
	}
	void select_soldier(EarthSoldier* soldier) {
		soldiers.peek(soldier);
	}
	bool isempty() {
		return soldiers.isEmpty();
	}
};