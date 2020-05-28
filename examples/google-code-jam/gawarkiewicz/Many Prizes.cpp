#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

//void play(vector<long long>& v) {
//	if(v.size() == 1)
//		return;
//	vector<long long> a(v.size()/2), b(v.size()/2);
//	for (int i=0; i<v.size(); i+=2) {
//		a[i/2] = min(v[i], v[i+1]);
//		b[i/2] = max(v[i], v[i+1]);
//	}
//	if (v.size() < 8) {
//		play(a);
//		play(b);
//	}
//	else {
//		thread t1([&](){play(a);});
//		thread t2([&](){play(b);});
//		t1.join();
//		t2.join();
//	}
//	for (int i=0; i<a.size(); ++i) v[i] = a[i];
//	for (int i=0; i<a.size(); ++i) v[i+a.size()] = b[i];
//}

int main() {
	//vector<long long> v;
	//int ile = 1 << 2;
	//vector<int> maxPos(ile, ile);
	//vector<int> minPos(ile, 0);
	//for (int i=0; i<ile; ++i) v.push_back(i);
	//int cnt = 0;
	//do {
	//	if (++cnt % 1000 == 0) {
	//		for (auto tt : v) cout << tt << " "; cout << endl;
	//	}
	//	auto t(v);
	//	play(t);
	//	for (int i=0; i<ile; ++i) maxPos[t[i]] = min(maxPos[t[i]], i);
	//	for (int i=0; i<ile; ++i) minPos[t[i]] = max(minPos[t[i]], i);
	//}
	//while(next_permutation(v.begin(), v.end()));
	//for (int i=0; i<ile; ++i) cout << i << ": " << maxPos[i] << " " << minPos[i] << endl;
	//return 0;

	int T; cin >> T;
	for (int t=1; t<=T; ++t) {
		cerr << t << endl;
		long long N, P;
		cin >> N >> P;
		long long a1 = 0, a2 = (1ll<<N)-1;

		long long ile = 1ll<<(N-1), cnt = 1, pos = 2;
		if (P == 1ll<<N) a1 = a2 = P-1;
		else if (P == 1) a1 = a2 = 0;
		else{
			for (; pos-1<P; cnt += ile, ile >>= 1, pos <<= 1);
			a2 = cnt-1;

			ile = 2, cnt = 1, pos = 1ll<<(N-1);
			for (; (1ll<<N)-pos<P; cnt += ile, ile <<= 1, pos >>= 1);
			a1 = cnt-1;
		}

		cout << "Case #" << t << ": " << a1 << " " << a2 << endl;
	}
	return 0;
}