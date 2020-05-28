#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
	int Tn;
	scanf("%d", &Tn);

	for (int Tc = 1; Tc <= Tn; ++Tc) {
		char s[100];
		scanf("%s", s);


		int l = strlen(s);
//		bool found = 0;
		for (int i = 1; i < l; ++i) {
			if (s[i] < s[i-1]) {
//				found = 1;
				int j = i;
				while (j > 0 && s[j] < s[j-1]) {
					--s[j-1];
					--j;
				}
				for (int k = j + 1; k < l; ++k)
					s[k] = '9';
				break;
			}
		}


		printf("Case #%d: ", Tc);

		printf("%lld\n", atoll(s));
	}
	return 0;
}
