#include <queue>
#include <iostream>
#include <string>

using namespace std;

typedef pair <long long int, int> ii;
priority_queue <ii> q;

int ba[1000], aux[1000], b;

long long int calc (int n){
	long long int max = (long long int)n*ba[0], res = n+1;
	int  j, aux;
	for (j=1; j<b; j++){
		res += ((max)/ba[j])+1;
		if (max % ba[j]==0) res --;
	}
	return res;
}

int main() {
 int i, j, t, n, cont=1, naux, v, aux2, ini, fin, mid;
 long long int resf;
	ii c;
	cin >>t;

	for (i=0; i<t; i++){
		while (!q.empty()) q.pop();
		cout << "Case #" << cont++ << ": ";
		cin >> b >> n;
		for (j=0; j<b; j++){
			cin >> ba[j];
			aux[j]=0;
		}
		if (n==1) cout << 1 << endl;
		else{
			fin = n;
			resf = calc (fin);
			ini = 0;
			while (fin-ini >1){
				mid = (fin+ini) /2;
				resf = calc (mid);
				if (resf > n) fin = mid;
				else ini = mid;
			}
			naux = calc(fin);
			v = (fin-1)*ba[0];
			if (calc (fin) == n) cout << 1 << endl;
			else{
				q.push(ii(v,0));
				for (j=1; j<b; j++){
					aux2 = v- (v%ba[j]);
					if (aux2 == v) aux2 -= ba[j];
					q.push (ii(aux2, j));
				}
				while (naux > n){
					c = q.top();
					q.pop();
					c.first-= ba[c.second];
					q.push (c);
					naux --;
				}
				cout << q.top().second+1 << endl;
			}
		}
	}
    return 0;
}
/*

*/

