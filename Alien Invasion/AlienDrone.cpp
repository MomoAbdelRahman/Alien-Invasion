#include "AlienDrone.h"
#include "game.h"
AlienDrone::AlienDrone(int id, int health, int power, int jointime, int attackcapcity):ArmyUnit(id, DRONE, health, jointime, power, attackcapcity)
{
}

bool AlienDrone::attack()
{
	cout << "AD " << this->get_id() << ":"; //prints the id of the soldier attacking
	LinkedQueue<ArmyUnit*>* enemies = gameptr->get_enemies(DRONE, this->attack_capacity);//gets the enemies that the soldier can attack
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
			enemy->set_health(enemy->get_health() - this->get_power());
			if (enemy->get_health() <= 0) {
				enemy->set_health(0);
				gameptr->Humans.removeunit(enemy->get_type(), temp);
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
