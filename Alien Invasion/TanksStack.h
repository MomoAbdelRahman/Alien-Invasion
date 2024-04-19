#pragma once
#include "ArrayStack.h"
#include"EarthTank.h"
//EarthTankStack class is a stack of EarthTank objects that inherits from ArrayStack class
class EarthTankStack
{
private:
	int count; //count of the number of tank units in the stack
	ArrayStack <EarthTank*> tankStack; //stack of EarthTank objects
public:
	EarthTankStack() { //constructor
		count = 0;
	}
	bool AddTank(EarthTank* tank) { //AddTank function to add a tank to the stack 
		if(tankStack.push(tank)) {
			count++; //increment the count of the number of tank units
			return true;
		}
		else {
			return false;
		}
	}
	void removeTank(EarthTank* &tank) { //removeTank function to remove a tank from the stack
		if (tankStack.pop(tank)) {
			count--;
		}
	}

	void print() { //print function to print the ID of the tank units in the stack
		//cout << "======================Earth Tanks Units========================" << endl;
		cout << "ET: " << count << " [";
		EarthTankStack temp;//temporary stack to store the tank units
		while (!isEmpty()) {
			EarthTank* tank;
			removeTank(tank);
			cout << tank->get_id();
			temp.AddTank(tank);
			if (!isEmpty()) {
				cout << ",";
			}
		}
		cout << "]" << endl;
		while (!temp.isEmpty()) {//push the tank units back to the original stack
			EarthTank* tank;
			temp.removeTank(tank);
			AddTank(tank);
		}
	}
	int get_count() { //get_count function to return the count of the number of tank units
		return count;
	}
	void selecttank(EarthTank* tank) {
		tankStack.peek(tank);
	}
	bool isEmpty() { //isEmpty function to check if the stack is empty
		return tankStack.isEmpty();
	}
};
