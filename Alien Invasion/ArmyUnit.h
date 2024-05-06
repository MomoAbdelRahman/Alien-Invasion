#pragma once
#include <iostream>
using namespace std;
//This class is the base class for all the army units
//This includes both Earth and Alien army units
enum TYPE
{
	EARTHSOLDIER,
	TANK,
	GUNNERY,
	HEALER,
	ALIENSOLDIER,
	MONSTER,
	DRONE
};
class game;
class ArmyUnit {
protected:
	//Data members
	int id;
	TYPE type;
	int health;
	int join_time;
	int power;
	int attack_capacity;
	int time_of_death;
	int first_attack_time;
	int UML_time; //time spent in UML (resets when taken back to battle)
	game* gameptr=nullptr;
public:
	//Parameterized constructor
	ArmyUnit(int id, TYPE type, int health, int join_time, int power, int attack_capacity);

	//Getters for Data members
	int get_id() const;
	TYPE get_type() const;
	int get_health() const;
	int get_join_time() const;
	int get_power() const;
	int get_attack_capacity() const;
	int get_time_of_death() const;
	int get_first_attack_time() const;
	int get_UML_time() const;

	//Setters for Data members
	void set_id(int id);
	void set_type(TYPE type);
	void set_health(int health);
	void set_join_time(int join_time);
	void set_power(int power);
	void set_attack_capacity(int attack_capacity);
	void set_time_of_death(int time_of_death);
	void set_first_attack_time(int first_attack_time);
	void set_UML_time(int UML_time);

	//Print function
	void print();
	
	void set_game(game* g); //sets the game pointer

	game* get_game(); //returns the game pointer

	//Pure virtual function for attack that will be different for each derived class
	virtual bool attack() = 0;
	friend ostream& operator<<(ostream& os, const ArmyUnit* dt);
};
