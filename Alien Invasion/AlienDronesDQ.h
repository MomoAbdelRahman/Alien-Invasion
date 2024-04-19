#pragma once
#include "AlienDrone.h"
#include "Deque.h"
//A class that stores the AlienDrone units in a Deque data structure
class AlienDronesDequeue{
private:
	int count;
	Deque<AlienDrone*> alienDD;
public:
	AlienDronesDequeue(){
		count = 0;
	}
	void insertDrone(AlienDrone* alienDrone1,AlienDrone* alienDrone2){
		alienDD.enqueue_front(alienDrone1); //Inserting the AlienDrone1 unit in the front of the Deque
		alienDD.enqueue_back(alienDrone2); //Inserting the AlienDrone2 unit in the back of the Deque
		count = count + 2;
	}

	void removeDrones(AlienDrone* &removed1, AlienDrone* &removed2){
		if (alienDD.double_dequeue(removed1, removed2)) //Removing the AlienDrone units from the front and back of the Deque
  		count = count - 2;
	}

	void print(){
		//cout << "======================Alien Drone Units========================" << endl; //Printing the AlienDrone units
		cout << "AD:" << count << " [";
		AlienDronesDequeue temp;
		AlienDrone* temp1;
		AlienDrone* temp2;
		while(!isEmpty()){
			removeDrones(temp1, temp2);
			temp.insertDrone(temp1, temp2);
			cout << temp1->get_id() << "," << temp2->get_id();
			if(!isEmpty()){
				cout << ",";
			}
		}
		while(!temp.isEmpty()){ //Restoring the AlienDrone units back to the original Deque
			temp.removeDrones(temp1, temp2);
			insertDrone(temp1, temp2);
		}
		cout << "]" << endl;
	}
	int get_count(){
		return count;
	}

	void select_drone(AlienDrone* ad1, AlienDrone* ad2) {
		alienDD.peek_front(ad1);
		alienDD.peek_back(ad2);
	}
	bool isEmpty(){
		return alienDD.isEmpty();
	}
};
