#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <omp.h>
#include <queue>
using namespace std;

//int main() {
//	int Tn;
//	scanf("%d", &Tn);
//
//	for (int Tc = 1; Tc <= Tn; ++Tc) {
//		int n, k;
//		scanf("%d%d", &n, &k);
//
//		priority_queue<int> q;
//		q.push(n);
//
//		int lasta = -1, lastb = -1;
//		for (int i = 0; i < k; ++i) {
//			int v = q.top();
//			q.pop();
//			lasta = v / 2;
//			lastb = (v - 1) / 2;
//			q.push(lasta);
//			q.push(lastb);
//		}
//
//		printf("Case #%d: ", Tc);
//		printf("%d %d\n", lasta, lastb);
//
//	}
//	return 0;
//}


int main() {
	int Tn;
	scanf("%d", &Tn);

	for (int Tc = 1; Tc <= Tn; ++Tc) {
		long long n, k;
		scanf("%lld%lld", &n, &k);

		long long max = n, min = 0, cmax = 1, cmin = 0;
		long long lasta = -1, lastb = -1;

		while (k > 0) {
			if (k <= cmax) {
				lasta = max / 2;
				lastb = (max - 1) / 2;
				break;
			}
			k -= cmax;
			if (k <= cmin) {
				lasta = min / 2;
				lastb = (min - 1) / 2;
				break;
			}
			k -= cmin;

			long long newmax, newmin, newcmax, newcmin;

			newmax = max / 2;
			newmin = newmax - 1;
			if (max % 2) {
				newcmax = cmax * 2 + cmin;
				newcmin = cmin;
			} else {
				newcmax = cmax;
				newcmin = cmin * 2 + cmax;
			}
			max = newmax;
			min = newmin;
			cmax = newcmax;
			cmin = newcmin;
		}
		printf("Case #%d: ", Tc);
		printf("%lld %lld\n", lasta, lastb);

	}
	return 0;
}
