#include "game.h"
using namespace std;
int main()
{
	game g;
	while (g.time < 50) {
		g.steptime();
		system("pause");
	}
}
