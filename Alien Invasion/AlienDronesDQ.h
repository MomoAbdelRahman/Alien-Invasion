#pragma once
#include "AlienDrone.h"
#include "Deque.h"
//A class that stores the AlienDrone units in a Deque data structure
class AlienDronesDequeue:public Deque<AlienDrone*>{
private:
	int count;
public:
	AlienDronesDequeue():Deque<AlienDrone*>(){
		count = 0;
	}
	void insertDrone(AlienDrone* alienDrone1,AlienDrone* alienDrone2){
		enqueue_front(alienDrone1); //Inserting the AlienDrone1 unit in the front of the Deque
		enqueue_back(alienDrone2); //Inserting the AlienDrone2 unit in the back of the Deque
		count = count + 2;
	}

	void removeDrones(AlienDrone* &removed1, AlienDrone* &removed2){
		if (double_dequeue(removed1, removed2)) //Removing the AlienDrone units from the front and back of the Deque
  		count = count - 2;
	}

	void print(){
		//cout << "======================Alien Drone Units========================" << endl; //Printing the AlienDrone units
		cout << "AD:" << count << " [";
		AlienDronesDequeue temp;
		AlienDrone* temp1;
		AlienDrone* temp2;
		while(!isEmpty()){
			double_dequeue(temp1, temp2);
			temp.enqueue_front(temp1); //Storing the AlienDrone units in a temporary Deque
			temp.enqueue_back(temp2);
			cout << temp1->get_id() << "," << temp2->get_id();
			if(!isEmpty()){
				cout << ",";
			}
		}
		while(!temp.isEmpty()){ //Restoring the AlienDrone units back to the original Deque
			temp.double_dequeue(temp1, temp2);
			enqueue_front(temp1);
			enqueue_back(temp2);
		}
		cout << "]" << endl;
	}
	int get_count(){
		return count;
	}

	void select_drone(AlienDrone* ad1, AlienDrone* ad2) {
		peek_front(ad1);
		peek_back(ad2);
	}
};
