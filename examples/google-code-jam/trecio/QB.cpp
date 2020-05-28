#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		double c, f, x;
		cin >> c >> f >> x;

		double time = 0;
		double production = 2;
		double gathered = 0;
		while (true) {
			double toNewFarm = (c - gathered) / production;
			double toEndGame = (x - gathered) / production;
			double productionWithNewFarm = production + f;
			double toEndGameWithNewFarm = (x + c - production * toNewFarm) / productionWithNewFarm + toNewFarm;

			if (toEndGame > toEndGameWithNewFarm) {
				time += toNewFarm;
				gathered += production * toNewFarm - c;
				production += f;
			} else {
				cout << "Case #" << t << ": " << setprecision(9) << time + toEndGame << endl;
				break;
			}
		}
	}
	return 0;
}