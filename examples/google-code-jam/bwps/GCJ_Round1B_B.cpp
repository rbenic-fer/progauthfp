#include <iostream>
#include <string>
#include <set>
using namespace std;

const int MAX = 1000000;

int C;
long long A, B, P;
bool prime[MAX+1];
long long primes[MAX];
int nprimes;

int N;
int parent[MAX+1];
int height[MAX+1];

set<int> nums;

void init() {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        height[i] = 0;
    }
}

int find(int x) {
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

bool Union(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (height[x] > height[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        if (height[x] == height[y]) height[y]++;
    }
    return true;
}

void eratosthenes() {
	prime[0] = prime[1] = false;
	for (int i = 2; i <= MAX; i++) prime[i] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (!prime[i]) continue;
		for (int j = i*i; j <= MAX; j += i) prime[j] = false;
	}
}

int main() {
	eratosthenes();
	cin >> C;
	for (int tcs = 1; tcs <= C; tcs++) {
		cin >> A >> B >> P;
		nprimes = 0;
		for (long long i = P; i <= B-A; i++) {
			if (prime[i]) primes[nprimes++] = i;
		}
		N = B-A+1;
		init();
		for (int i = 0; i < nprimes; i++) {
			long long p = primes[i];
			long long last = (p - A % p) % p + A, akt;
			while (1) {
				akt = last + p;
				if (akt > B) break;
				Union(last - A, akt - A);
				last = akt;
			}
		}
		nums.clear();
		for (int i = 0; i < N; i++) nums.insert(find(i));
		cout << "Case #" << tcs << ": " << nums.size() << endl;
	}
	return 0;
}
