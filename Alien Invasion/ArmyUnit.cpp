#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(int id, TYPE type, int health, int join_time, int power, int attack_capacity):id(id), type(type), health(health), join_time(join_time), power(power), attack_capacity(attack_capacity)
{
	gameptr = nullptr;
}

int ArmyUnit::get_id()
{
	return id;
}

TYPE ArmyUnit::get_type()
{
	return type;
}

int ArmyUnit::get_health()
{
	return health;
}

int ArmyUnit::get_join_time()
{
	return join_time;
}

int ArmyUnit::get_power()
{
	return power;
}

int ArmyUnit::get_attack_capacity()
{
	return attack_capacity;
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

game* ArmyUnit::get_game()
{
	return gameptr;
}




