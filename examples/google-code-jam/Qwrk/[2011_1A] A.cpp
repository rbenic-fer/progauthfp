#include <iostream>
#include <string>

std::string opt[2] = { "Broken", "Possible" };
long long C, N, Pd, Pg;

int NWD (int a, int b)
{
	int tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

#define odp(x) std::cout << "Case #" << Case << ": " << opt[x] << "\n"

int main()
{
	std::cin >> C;
	for (int Case = 1; Case <= C; ++Case) {
		std::cin >> N >> Pd >> Pg;
		//std::cout << N << "  " << Pd << "  " << Pg << "\n";
		if (Pd == 100 && Pg == 100)
			odp (1);
		else if (Pd != 100 && Pg == 100)
			odp (0);
		else if (Pd > 0 && Pg == 0)
			odp (0);
		else if (Pd == 0 && Pg == 0)
			odp (1);
		else {
			int a = NWD (Pd, 100);
			int b = 100 / a;
			//std::cout << a << "   " << b << '\n';
			if (b <= N) odp (1);
			else odp (0);
		}
	}
}