#pragma once
#include "ArrayStack.h"
#include"EarthHealer.h"
//EarthHealerStack class is a stack of EarthHealer objects that inherits from ArrayStack class
class EarthHealerStack
{
private:
	int count; //count of the number of healer units in the stack
	ArrayStack <EarthHealer*> healerStack; //stack of EarthHealer objects
public:
	EarthHealerStack(); //constructor
	bool AddHealer(EarthHealer* healer); //AddHealer function to add a healer to the stack 
	void removeHealer(EarthHealer*& healer); //removeHealer function to remove a healer from the stack
	void print(); //print function to print the ID of the healer units in the stack
	int get_count(); //get_count function to return the count of the number of healer units
	void selecthealer(EarthHealer*& healer); //selecthealer function to select the healer unit at the top of the stack
	bool isEmpty(); //isEmpty function to check if the stack is empty
	LinkedQueue<ArmyUnit*>* get_healers(int n);
};
