#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool a[1000000];

vector <int> p;

int main() {
	for (int i=2; i<1000000; i++) a[i] = 1;
	for (int i=2; i<1000; i++)
		if (a[i]){
  			int b = 2;
  			while (i*b < 1000000){
  		   		a[i*b] = 0;
	 			b++;
			}
		}
	for (int i=2; i<1000000; i++) if (a[i]) p.push_back(i);
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) printf("Case #%d: 0\n", i);
		else {
			int out = 1;
			for (int j=0; j<p.size(); j++) {
				if (p[j] > t) break;
				int t2 = p[j];
				out--;
				while (t2 <= t) {
					t2 *= p[j];
					out++;
				}
			}
			printf("Case #%d: %d\n", i, out);
		}
	}
   	return 0;
}
