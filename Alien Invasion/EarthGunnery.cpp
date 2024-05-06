#include "EarthGunnery.h"
#include <iostream>
#include "LinkedQueue.h"
#include"game.h"
using namespace std;
EarthGunnery::EarthGunnery(int id, int health, int jointime, int power, int attackcapacity) :ArmyUnit(id, GUNNERY, health, jointime, power, attackcapacity) {
}

bool EarthGunnery::attack()
{
	cout << "EG " << this->get_id()<<":";

	LinkedQueue<ArmyUnit*>* enemies = gameptr->get_enemies(GUNNERY, this->attack_capacity);
	ArmyUnit* enemy=nullptr;
	ArmyUnit* enemy2=nullptr;
	LinkedQueue<ArmyUnit*>shot;
	int shots=0;
	while(!enemies->isEmpty())
	{
		enemies->dequeue(enemy);
		if(enemy){
			if (!this->get_first_attack_time()) this->set_first_attack_time(gameptr->time);
			shot.enqueue(enemy);
			shots++;
			enemy->set_health(enemy->get_health() - (this->get_power() * this->get_health()) / (100 * sqrt(enemy->get_health()))); //Damage done is (attacking unit power * attacking unit health)/(100*sqrt(attacked unit health))
			if (enemy->get_health() <= 0)
			{
				enemy->set_health(0);
				gameptr->kill_unit(enemy);
				gameptr->Aliens.removeunit(enemy->get_type(), enemy, enemy2);
			}
		
		}
	}
	cout << shots << " Shots" << "[";
	while(!shot.isEmpty())
	{
		shot.dequeue(enemy);
		cout << enemy->get_id();
		if(!shot.isEmpty())
		{
			cout << ",";
		}
	}
	cout << "]" << endl;
	return true;
}

