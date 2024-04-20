#pragma once
using namespace std;
//This class is the base class for all the army units
//This includes both Earth and Alien army units
enum TYPE
{
	EARTHSOLDIER,
	TANK,
	GUNNERY,
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
	game* gameptr=nullptr;
public:
	//Parameterized constructor
	ArmyUnit(int id, TYPE type, int health, int join_time, int power, int attack_capacity) :id(id), type(type), health(health), join_time(join_time), power(power), attack_capacity(attack_capacity) { gameptr = nullptr; }

	//Getters for Data members
	int get_id() {
		return id;
	}

	TYPE get_type() {
		return type; 
	}

	int get_health() {
		return health;
	}

	int get_join_time() {
		return join_time;
	}

	int get_power() {
		return power;
	}

	int get_attack_capacity(){
		return attack_capacity;
	}

	//Setters for Data members
	void set_id(int id) {
		this->id = id;
	}

	void set_type(TYPE type) {
		this->type = type;
	}

	void set_health(int health) {
		this->health = health;	
	}

	void set_join_time(int join_time) {
		this->join_time = join_time;
	
	}
	void set_power(int power) {
		this->power = power;
	}	

	void set_attack_capacity(int attack_capacity) {
		this->attack_capacity = attack_capacity;
	}

	//Print function
	void print() {
		cout << "ID: " << id << endl;
		cout << "Type: " << type << endl;
		cout << "Health: " << health << endl;
		cout << "Join Time: " << join_time << endl;
		cout << "Power: " << power << endl;
		cout << "Attack Capacity: " << attack_capacity << endl;
		cout << endl;
	}
	
	void set_game(game* g) {
		gameptr = g;
	}

	game* get_game() {
		return gameptr;
	}
	
	//Pure virtual function for attack that will be different for each derived class
	virtual bool attack()=0;

};