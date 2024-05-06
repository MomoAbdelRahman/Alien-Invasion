#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(int id, TYPE type, int health, int join_time, int power, int attack_capacity):id(id), type(type), health(health), join_time(join_time), power(power), attack_capacity(attack_capacity)
{
	gameptr = nullptr;
}

int ArmyUnit::get_id() const
{
	return id;
}

TYPE ArmyUnit::get_type() const
{
	return type;
}

int ArmyUnit::get_health() const 
{
	return health;
}

int ArmyUnit::get_join_time() const 
{
	return join_time;
}

int ArmyUnit::get_power() const
{
	return power;
}

int ArmyUnit::get_attack_capacity() const 
{
	return attack_capacity;
}

int ArmyUnit::get_time_of_death() const
{
	return time_of_death;
}

int ArmyUnit::get_first_attack_time() const 
{
	return first_attack_time;
}

int ArmyUnit::get_UML_time() const
{
	return UML_time;
}

void ArmyUnit::set_id(int id)
{
	this->id = id;
}



void ArmyUnit::set_type(TYPE type)
{
	this->type = type;
}



void ArmyUnit::set_health(int health)
{
	this->health = health;
}

void ArmyUnit::set_join_time(int join_time)
{
	this->join_time = join_time;
}

void ArmyUnit::set_power(int power)
{
	this->power = power;
}

void ArmyUnit::set_attack_capacity(int attack_capacity)
{
	this->attack_capacity = attack_capacity;
}

void ArmyUnit::print()
{
	cout << "ID: " << id << endl;
	cout << "Type: " << type << endl;
	cout << "Health: " << health << endl;
	cout << "Join Time: " << join_time << endl;
	cout << "Power: " << power << endl;
	cout << "Attack Capacity: " << attack_capacity << endl;
	cout << endl;
}

void ArmyUnit::set_game(game* g)
{
	gameptr = g;
}

void ArmyUnit::set_time_of_death(int time_of_death)
{
	this->time_of_death=time_of_death;
}

void ArmyUnit::set_first_attack_time(int first_attack_time)
{
	this->first_attack_time=first_attack_time;
}

void ArmyUnit::set_UML_time(int UML_time)
{
	this->UML_time=UML_time;
}

game* ArmyUnit::get_game()
{
	return gameptr;
}


ostream& operator<<(ostream& os, const ArmyUnit* dt)
{
	os<<dt->id;
	return os;
}
