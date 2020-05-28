#include <iostream>

using namespace std;

int main()
{
	int count;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		long double farm_cost, farm_rate, target;
		cin >> farm_cost;
		cin >> farm_rate;
		cin >> target;

		long double time1, time2;
		long double rate = 2.0;
		long double time_till_now = 0;

		do
		{
			time1 = time_till_now + target/rate;
			time2 = time_till_now + target/(rate + farm_rate) + farm_cost/rate;
			time_till_now += (farm_cost/rate);
			rate += farm_rate;
		}
		while(time1 > time2);

		cout.precision(7);
		cout << fixed;
		cout << "Case #" << (i + 1) << ": " << time1 << endl;
	}
}
