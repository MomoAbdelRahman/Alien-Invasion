#include "AlienSoldier.h"
#include "game.h"
AlienSoldier::AlienSoldier(int id, int health, int jointime, int power, int attackcapacity):ArmyUnit(id, ALIENSOLDIER, health, jointime, power, attackcapacity) {

}

bool AlienSoldier::attack()
{
	
	LinkedQueue<ArmyUnit*>* enemies = gameptr->get_enemies(ALIENSOLDIER, this->attack_capacity);//gets the enemies that the soldier can attack
	ArmyUnit* enemy = nullptr; //pointer to the enemy
	ArmyUnit* temp = nullptr; //pointer to the enemy
	ArmyUnit* temp2 = nullptr; //pointer to the enemy
	LinkedQueue<ArmyUnit*> shot;
	int shots = 0; //number of shots by the soldier
	int n = this->attack_capacity;
	while (!enemies->isEmpty())
	{
		enemies->dequeue(enemy);
		if (enemy) {
			if (!(enemy->get_first_attack_time())) { enemy->set_first_attack_time(gameptr->time); }			
			enemy->set_health(enemy->get_health() - (this->get_power() * this->get_health()) / (100 * sqrt(enemy->get_health()))); //Damage done is (attacking unit power * attacking unit health)/(100*sqrt(attacked unit health))
			if (enemy->get_health() <= 0) {
				enemy->set_health(0);
				gameptr->Humans.removeunit(enemy->get_type(), temp);
				gameptr->kill_unit(temp);
			}
			shot.enqueue(enemy);
			shots++;
		}
	}
	if (!gameptr->silent) {
		cout << "AS " << this->get_id() << ":"; //prints the id of the soldier attacking
		cout << shots << " Shots" << "[";
		while (!shot.isEmpty()) {
			shot.dequeue(temp2);
			cout << temp2->get_id();
			if (!shot.isEmpty()) {
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
	return true;
}
