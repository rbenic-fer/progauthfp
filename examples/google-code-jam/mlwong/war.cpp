#include <iostream>
#include <algorithm>

using namespace std;

double a[1002], b[1002];

int main() {
	int C;
	cin >> C;
	for (int T=1; T<=C; T++) {
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n; i++) cin >> b[i];
		
		cout << "Case #" << T << ": ";
		
		sort(a, a+n);
		sort(b, b+n);
		
		int p=0;
		for (int i=0; i<n; i++) {
			if (a[i] > b[p]) p++;
		}
		cout << p << " ";
		p=0;
		for (int i=0; i<n; i++) {
			if (b[i] > a[p]) p++;
		}
		cout << n-p << endl;
	}
	return 0;
}
