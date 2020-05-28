#include <iostream>

using namespace std;

int a[1002];

int run() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int min = 1002;
	for (int i=1; i<=1000; i++) {
		int cnt = 0;
		for (int j=0; j<n; j++) cnt += (a[j]-1) / i;
		if (i + cnt < min) min = i + cnt;
	}
	return min;
}

int main() {
	int T;
	cin >> T;
	for (int i=1; i<=T; i++) {
		cout << "Case #" << i << ": " << run() << endl;
	}
	return 0;
}
