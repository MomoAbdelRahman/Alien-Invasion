#include <iostream>
#include "game.h"
using namespace std;
int main()
{
	game g;
	g.add_aliens();
	g.add_humans();
	g.printstate();
	int X = rand() % 100;
	X = abs(X);
	/*if (X < 10) {
		ArmyUnit* e = nullptr;
		g.Humans.removeunit(EARTHSOLDIER, e);
		cout << "Removed ES" << endl;
		g.printstate();
		g.Humans.addunit(e);
		cout<< "Added ES" << endl;
		g.printstate();
	}*/
	ArmyUnit* t = nullptr;
	g.Humans.removeunit(TANK, t);
	g.printstate();
	
}
