#include "EarthSoldier.h"
#include "game.h"
EarthSoldier::EarthSoldier(int id, int health, int jointime, int power, int attack_capacity):ArmyUnit(id, EARTHSOLDIER, health, jointime, power, attack_capacity)
{
}

bool EarthSoldier::attack()
{
	cout << "ES " << this->get_id()<<":"; //prints the id of the soldier attacking
	LinkedQueue<ArmyUnit*> enemies = gameptr->Aliens.get_soldiers(this->attack_capacity);//gets the enemies that the soldier can attack
	ArmyUnit* enemy = nullptr; //pointer to the enemy
	ArmyUnit* temp = nullptr; //pointer to the enemy
	ArmyUnit* temp2 = nullptr; //pointer to the enemy
	LinkedQueue<ArmyUnit*> shot;
	int shots = 0; //number of shots by the soldier
	while (enemies.dequeue(enemy)) {
		enemy->set_health(enemy->get_health() - this->get_power()); //decreases the health of the enemy by the power of the soldier
		if (enemy->get_health() <= 0) {
			enemy->set_health(0);
			gameptr->Aliens.removeunit(enemy->get_type(),temp,temp2);
			gameptr->Aliens.killunit(temp);
		}
		shot.enqueue(enemy);
		shots++;
	}
	cout << shots << " Shots"<<"[";
	while (!shot.isEmpty()) {
		shot.dequeue(temp2);
		cout << temp2->get_id();
		if (!shot.isEmpty()) {
			cout << ",";
		}
	}
	cout << "]"<<endl;
	return true;
}
