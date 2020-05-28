#include <iostream>

using namespace std;

int main() {
	int C;
	cin >> C;
	for (int T=1; T<=C; T++) {
		int r, c, m;
		cin >> r >> c >> m;
		cout << "Case #" << T << ":\n";	
		// cout << r << " " << c << " " << m << endl;
		if (m > 0 && r*c > m+1 && r > 1 && c > 1) {	 
			if (r*c-4 < m) {
				cout << "Impossible\n";
				continue;
			}
		}
		
		for (int i=1; i<=r; i++) {
			for (int j=1; j<=c; j++) {
				if (i == r && j == c) cout << 'c';
				else if (r*c == m+1) cout << '*';
				else if (i >= r-1 && j >= c-1) cout << '.';
				else if (m) {
					cout << '*';
					m--;
				}
				else cout << '.';
			}
			cout << endl;
		}
	}
	return 0;
}
