#include "game.h"
#include "priQueue.h"
using namespace std;
int main()
{
	game g;
	cout<<"Press 0 for interactive mode and 1 for silent mode"<<endl;
	cin>>g.silent;
	if (!g.silent) {
		while (g.time < 50) {
			g.steptime();
			system("pause");
		}
		g.generate_output_file();
		cout<< "Game Over" << endl;
	}
	else {
		while (g.time < 50) {
			g.silent_step();
		}
		g.generate_output_file();
		cout<< "Game Over" << endl;
	}
}
