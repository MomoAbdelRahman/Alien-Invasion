#pragma once
#include "priQueue.h"
#include"EarthGunnery.h"
#include <iostream>
using namespace std;
//This class is a priority queue of EarthGunnery objects. It is used to store the EarthGunnery objects in a priority queue based on their health and power.
class GunneryPriQueue : public priQueue<EarthGunnery*>
{
private:
	int count = 0; //Total number of Gunnery Units
	int next = 0; //Priority of the next Gunnery Unit to be removed
public:
	GunneryPriQueue() :priQueue() { //Constructor
		count = 0;
		next = 0;

	}

	void AddGunnery(EarthGunnery* gunnery) { //Add a new Gunnery Unit to the priority queue
		int priority = (gunnery->get_health() + gunnery->get_power());
		enqueue(gunnery, priority);
		if (priority > next) //Update the priority of the next Gunnery Unit to be removed
			next = priority;
		count++;
	}
	void RemoveGunnery(EarthGunnery* &gunner) {
		if (dequeue(gunner, next)) {//Remove the Gunnery Unit with the highest priority
			count--;
		}
    cout << count << endl;
	}

	void print() { //Print the Gunnery Units in the priority queue
		//cout << "======================Earth Gunnery Units========================" << endl;
		cout << "EG: " << count << " [";
		GunneryPriQueue t; //Temporary priority queue to store the Gunnery Units
		while(!isEmpty()) {
			EarthGunnery* temp;
			dequeue(temp, next);
			cout << temp->get_id();
			if(!isEmpty())
				cout << ",";
			t.enqueue(temp, next);
		}
		cout<< "]" << endl;
		while (!t.isEmpty()) { //Restore the Gunnery Units to the original priority queue
			EarthGunnery* temp;
			t.dequeue(temp, next);
			enqueue(temp, next);
		}
	}
	int get_count() { //Return the total number of Gunnery Units
		return count;
	}

	void select_gunnery(EarthGunnery* gunnery) {
		this->peek(gunnery,next);
	}
};
