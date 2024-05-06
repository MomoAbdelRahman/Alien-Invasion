#include "EarthHealer.h"
#include"game.h"
EarthHealer::EarthHealer(int id, int health, int jointime, int power, int attackcapacity) :ArmyUnit(id, HEALER, health, jointime, power, attackcapacity) {
}

bool EarthHealer::attack()
{
	cout << "EH " << this->get_id() << ":"; //prints the id of the healer healing
	LinkedQueue<ArmyUnit*>* injured = gameptr->get_enemies(HEALER, this->attack_capacity); //gets the injured soldiers and tanks that should be healed
	LinkedQueue<ArmyUnit*> troops_healed;
	ArmyUnit* hurt = nullptr;
	ArmyUnit* temp = nullptr;
	EarthSoldier* tempS = nullptr;
	EarthTank* tempT = nullptr;
	int healed = 0;
	int n = this->attack_capacity;

	while (!injured->isEmpty())
	{
		injured->dequeue(hurt);
		if (hurt) {
			if (!this->get_first_attack_time()) this->set_first_attack_time(gameptr->time);
 			if ((gameptr->time - hurt->get_UML_time()) >= 10) {
				gameptr->kill_unit(hurt);
			}
			else {
				hurt->set_health(hurt->get_health() + ((this->power) * (this->health)) / (100 * sqrt(hurt->get_health()))); //Health added is (healer power * healer health)/(100*sqrt(hurt health))
				if (hurt->get_health() >= 0.2 * (gameptr->config.max_earth_health)) { //if unit is healed over 20% it is dropped back into battle, otherwise stays in UML
					gameptr->Humans.addunit(hurt);
					healed_successfully++;
				}
				else {
					gameptr->UML.add_unit(hurt);
				}
				troops_healed.enqueue(hurt);
				healed++;
			}
		}
	}

	cout << healed << " Heals" << "[";
	while (!troops_healed.isEmpty()) {
		troops_healed.dequeue(temp);
		cout << temp->get_id();
		if (!troops_healed.isEmpty()) {
			cout << ",";
		}
	}
	cout << "]" << endl;

	return healed;
}
