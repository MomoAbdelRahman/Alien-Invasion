#include "EarthSoldier.h"
#include "game.h"
EarthSoldier::EarthSoldier(int id, int health, int jointime, int power, int attack_capacity):ArmyUnit(id, EARTHSOLDIER, health, jointime, power, attack_capacity)
{
}

bool EarthSoldier::attack()
{
	LinkedQueue<ArmyUnit*> enemies = gameptr->Aliens.get_soldiers(this->attack_capacity);
	ArmyUnit* enemy = nullptr;
	ArmyUnit* temp = nullptr;
	ArmyUnit* temp2 = nullptr;
	while (enemies.dequeue(enemy)) {
		enemy->set_health(enemy->get_health() - this->get_power());
		if (enemy->get_health() <= 0) {
			enemy->set_health(0);
		}
		gameptr->Aliens.removeunit(enemy->get_type(),temp,temp2);
		gameptr->Aliens.killunit(enemy);
	}
	return true;
}
