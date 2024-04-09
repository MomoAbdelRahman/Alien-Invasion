#pragma once
#include "ArrayStack.h"
#include"EarthTank.h"
//EarthTankStack class is a stack of EarthTank objects that inherits from ArrayStack class
class EarthTankStack: public ArrayStack<EarthTank*>
{
private:
	int count=0; //count of the number of tank units in the stack
public:
	EarthTankStack() : ArrayStack() {
	}
	bool AddTank(EarthTank* tank) { //AddTank function to add a tank to the stack 
		if(push(tank)) {
			count++; //increment the count of the number of tank units
			return true;
		}
		else {
			return false;
		}
	}
	EarthTank* removeTank() { //removeTank function to remove a tank from the stack
		EarthTank* toberemoved;
		pop(toberemoved);
		count--;
		return toberemoved; //Returns a pointer to the tank that was removed
		
	}
	void print() { //print function to print the ID of the tank units in the stack
		cout << "======================Earth Tanks Units========================" << endl;
		cout << "Total Number of Tank Units: " << count << " [";
		EarthTankStack temp;//temporary stack to store the tank units
		while (!isEmpty()) {
			EarthTank* tank;
			pop(tank);
			cout << tank->get_id();
			temp.push(tank);
			if (!isEmpty()) {
				cout << ",";
			}
		}
		cout << "]" << endl;
		while (!temp.isEmpty()) {//push the tank units back to the original stack
			EarthTank* tank;
			temp.pop(tank);
			push(tank);
		}
	}
	int get_count() { //get_count function to return the count of the number of tank units
		return count;
	}
};