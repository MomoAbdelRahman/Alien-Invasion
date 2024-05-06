#include "EarthTank.h"
#include "game.h"
EarthTank::EarthTank(int id, int health, int jointime, int power, int attackcapacity) :ArmyUnit(id, TANK, health, jointime, power, attackcapacity) {

}

bool EarthTank::attack()
{
	cout << "ET " << this->get_id() << ":"; //prints the id of the tank attacking
	LinkedQueue<ArmyUnit*>* enemies=gameptr->get_enemies(TANK, this->attack_capacity);
	ArmyUnit* enemy = nullptr;
	ArmyUnit* temp = nullptr;
	ArmyUnit* temp2 = nullptr;
	LinkedQueue<ArmyUnit*> shot;
	int shots = 0;
	int n = this->attack_capacity;
	
	while (!enemies->isEmpty())
	{
		if (!this->get_first_attack_time()) this->set_first_attack_time(gameptr->time);
		enemies->dequeue(enemy);
		if (enemy) {
			enemy->set_health(enemy->get_health() - (this->get_power() * this->get_health()) / (100 * sqrt(enemy->get_health()))); //Damage done is (attacking unit power * attacking unit health)/(100*sqrt(attacked unit health))
			if (enemy->get_health() <= 0) {
				enemy->set_health(0);
				gameptr->Aliens.removeunit(enemy->get_type(), temp, temp2);
				gameptr->kill_unit(temp);
			}
			shot.enqueue(enemy);
			shots++;
		}
	}

	cout << shots << " Shots" << "[";
	while (!shot.isEmpty()) {
		shot.dequeue(temp2);
		cout << temp2->get_id();
		if (!shot.isEmpty()) {
			cout << ",";
		}
	}
	cout << "]" << endl;
	return true;
}
