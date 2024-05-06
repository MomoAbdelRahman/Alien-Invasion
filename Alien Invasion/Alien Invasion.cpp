#include "game.h"
#include "priQueue.h"
using namespace std;
int main()
{
	game g;
	while (g.time < 50) {
		g.steptime();
		system("pause");
	}
	g.generate_output_file();
}
