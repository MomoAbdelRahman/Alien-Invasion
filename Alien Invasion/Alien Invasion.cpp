#include <iostream>
#include "game.h"
using namespace std;
int main()
{
	game g;
	g.add_aliens();
	g.add_humans();
	// g.printstate();

	while (g.time < 50) {
	g.steptime();
	g.printstate();
	int X=rand() % 100;
	X=abs(X);
	if (X < 10) {
		ArmyUnit* e = nullptr;
		g.Humans.removeunit(EARTHSOLDIER, e);
		//cout << "Removed ES" << endl;
		//g.printstate();
		g.Humans.addunit(e);
		//cout<< "Added ES" << endl;
		//g.printstate();
	}
	else if(X>10 && X<20)
	{
		ArmyUnit* t = nullptr;
		//cout<<"Tank is removed"<<endl;
		g.Humans.removeunit(TANK, t);
		if (t) {
			g.Humans.killunit(t);
		}
		//g.printstate();
	}
	else if (X > 20 && X<30) {
		ArmyUnit* u = nullptr;
		g.Humans.removeunit(GUNNERY, u);
		//cout << "Unit is removed" << endl;
		//g.printstate();
		u->set_health(u->get_health() / 2);
		g.Humans.addunit(u);
		//cout << "Unit is added and updated" << endl;
		//g.printstate();
	}
	 
	else if (X > 30 && X < 40) {
		ArmyUnit* temp[5];
		for (int i = 0; i < 5; i++) {
			temp[i] = nullptr;
		}
		for (int i = 0; i < 5; i++) {
			ArmyUnit* unit2 = nullptr;
			g.Aliens.removeunit(ALIENSOLDIER, temp[i], unit2);
			g.Aliens.removeunit(ALIENSOLDIER, temp[i], unit2);
		}
		for (int i = 0; i < 5; i++) {
			temp[i]->set_health(temp[i]->get_health() - 20);
		}
		for (int i = 0; i < 5; i++) {
			g.Aliens.addunit(temp[i]);
		}
		//cout << "Aliens updated" << endl;
		//g.printstate();
	}
	else if(X > 40 && X < 50){
		ArmyUnit* unit = nullptr;
		ArmyUnit* unit2 = nullptr;
		for (int i = 0; i < 5; i++) {
			g.Aliens.removeunit(MONSTER, unit, unit2);
			g.Aliens.addunit(unit);
		}
		//cout<<"Aliens updated"<<endl;
		//g.printstate();
	}
	else if( X > 50 && X < 60) { 
		ArmyUnit *unit = nullptr;
		ArmyUnit *unit2 = nullptr;
		for (int i = 0; i < 3; i++){
			g.Aliens.removeunit(DRONE, unit, unit2);
			g.Aliens.killunit(unit);
			g.Aliens.killunit(unit2);
		}
		//cout << "Aliens updated" << endl << endl;
    }
	system("pause");

	}
}
