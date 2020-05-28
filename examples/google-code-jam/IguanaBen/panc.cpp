#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>
#include <iomanip>
#include <math.h>

#define ll long long

using namespace std;

pair<double, double> prs[10000];

void solve(int t) {

	double result = 0.0f;

	int n, k;
	cin>>n>>k;
	for (int i=0; i<n; ++i) {
		double r, h;
		cin>>r>>h;
		double field = 2.0* r *h;
		prs[i].first = r;
		prs[i].second = field;
		// cout<<r << "   | "<<field<<"\n";
	}

	sort(prs, prs + n, std::greater<pair<double, double> > ());

	for (int i=0; i<n-k+1; ++i){

		vector<double> dd;
		// dd.push_back(prs[i].second);


		// cout<<" test " << prs[i].first<<"\n";

		for(int j=i+1; j<n; ++j) {
			// cout<< prs[i].first << " ... "<<prs[i].second<<"\n";
			dd.push_back(prs[j].second);
		}

		sort(dd.begin(), dd.end());


		double cmax = 0.0;

		int added = 0;
		for(int j=dd.size()-1; j>=0 && added < k-1; --j) {
			cmax += dd[j];
			// cout<<dd[j]<<"\n";
			added++;
			// cout<<"add: "<<dd[j]<<"\n";
		}

		cmax += prs[i].second;
		cmax += prs[i].first*prs[i].first;
		// cout<< prs[i].first*prs[i].first*(long double)(M_PI) <<"\n";
		result = max(cmax, result);
		// cout<<cmax<<"\n";

	}


	cout << fixed << setprecision(10);
	cout<<"Case #"<<t<<": "<<result*(double)(M_PI)<<"\n";
	// cout<<"\n\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	int t = 1;
	while(T--)
		solve(t++);

	return 0;

}