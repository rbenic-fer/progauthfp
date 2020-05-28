#include <iostream>
#include <algorithm>

using namespace std;

int s[100005];

void solve() {
	int n,x;
	cin >> n >> x;
	for (int i=0; i<n; i++) cin >> s[i];
	sort(s,s+n);
	int h = 0, t = n-1;
	int cnt = 0;
	while (h<=t) {
		cnt++;
		if (s[h]+s[t]<=x) {
			h++;
			t--;
		} 
		else t--;	
	}
	cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i<=T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
