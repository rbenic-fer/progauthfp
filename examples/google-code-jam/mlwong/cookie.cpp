#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
	int C;
	cin >> C;
	for (int T=1; T<=C; T++) {
		// c = price of farm
		// f = farm production rate
		// x = target
		double c, f, x;
		double t=0, r=2;
				
		cin >> c >> f >> x;
		cout << "Case #" << T << ": ";
		
		while (c*(r+f) < x*f) {
			t += c/r;
			r += f;
		}
		
		cout << setprecision(7) << fixed << t+x/r << endl;
	}
	return 0;
}
