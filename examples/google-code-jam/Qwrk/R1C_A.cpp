#include <iostream>
#include <algorithm>

typedef unsigned long long ull;
typedef long long ll;

ll gdc(ll a, ll b, ll &p, ll &q)
{
	ll a0 = a;
	ll b0 = b;
	p = 1; q = 0;
	ll r = 0, s = 1, c, quot;
	ll new_r, new_s;
 
	while (b != 0) {
		c = a % b;
		quot = a / b;
		a = b;
		b = c;
		new_r = p - quot * r;
		new_s = q - quot * s;
		p = r; q = s;
		r = new_r;
		s = new_s;
	}
	return p * a0 + q * b0;
}

int main()
{
	int T;
	std::cin >> T;
	for (int cases = 1; cases <= T; ++cases) {
		char ignore;
		ll p, q, res = 0;
		std::cin >> p >> ignore >> q;
		while (q % 2 == 0) {
			 ++res; q /= 2;
		}
		while (p != 1) { 
			--res; p /= 2;
		}

		std::cout << "Case #" << cases << ": ";
		if (res > 0 ) {
			std::cout << res << '\n';
		} else {
			std::cout << "impossible\n";
		}
	}

	
	return 0;
}