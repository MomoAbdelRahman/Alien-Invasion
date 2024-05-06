#include "AlienDronesDQ.h"

AlienDronesDequeue::AlienDronesDequeue()
{
	count = 0;
}

void AlienDronesDequeue::insertDrone(AlienDrone* alienDrone1, AlienDrone* alienDrone2)
{
	alienDD.enqueue_front(alienDrone1); //Inserting the AlienDrone1 unit in the front of the Deque
	alienDD.enqueue_back(alienDrone2); //Inserting the AlienDrone2 unit in the back of the Deque
	count = count + 2;
}

void AlienDronesDequeue::removeDrones(AlienDrone*& removed1, AlienDrone*& removed2)
{
	if (alienDD.double_dequeue(removed1, removed2)) //Removing the AlienDrone units from the front and back of the Deque
		count = count - 2;
}

void AlienDronesDequeue::print()
{
	//cout << "======================Alien Drone Units========================" << endl; //Printing the AlienDrone units
	cout << "AD: " << count << " [";
	alienDD.printDQ();
	cout << "]"<<endl;

	//AlienDronesDequeue temp;
	//AlienDrone* temp1;
	//AlienDrone* temp2;
	//while (!isEmpty()) {
	//	removeDrones(temp1, temp2);
	//	temp.insertDrone(temp1, temp2);
	//	cout << temp1->get_id() << "," << temp2->get_id();
	//	if (!isEmpty()) {
	//		cout << ",";
	//	}
	//}
	//while (!temp.isEmpty()) { //Restoring the AlienDrone units back to the original Deque
	//	temp.removeDrones(temp1, temp2);
	//	insertDrone(temp1, temp2);
	//}
	//cout << "]" << endl;
}

int AlienDronesDequeue::get_count()
{
	return count;
}

void AlienDronesDequeue::select_drone(AlienDrone* &ad1, AlienDrone* &ad2)
{
	alienDD.peek_front(ad1);
	alienDD.peek_back(ad2);
}

bool AlienDronesDequeue::isEmpty()
{
	return alienDD.isEmpty();
}

LinkedQueue<ArmyUnit*>* AlienDronesDequeue::get_drones(int n)
{
	LinkedQueue<ArmyUnit*>* temp = new LinkedQueue<ArmyUnit*>;
	AlienDronesDequeue temp1;
	AlienDrone* tempunit;
	AlienDrone* tempunit2;
	int count = 0;
	while (!isEmpty()) {
		removeDrones(tempunit, tempunit2);
		if (count < n) {
			if (tempunit != nullptr) {
				temp->enqueue(tempunit);
				count++;
			}
			if (tempunit2 != nullptr) {
				temp->enqueue(tempunit2);
				count++;
			}
			
		}
		temp1.insertDrone(tempunit, tempunit2);
		
	}
	while (!temp1.isEmpty()) {
		temp1.removeDrones(tempunit, tempunit2);
		insertDrone(tempunit, tempunit2);
	}
	return temp;
}
