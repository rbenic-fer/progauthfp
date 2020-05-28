#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> //max...
#include <utility> //pair
#include <complex>
#include <climits> //int, ll...
#include <limits> //double...
#include <cmath> //abs, atan...

#include <cstring> //memset
#include <string>

using namespace std;

typedef long long ll;

typedef pair<int,int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int t, n, a[6], aux, r, y, b;
bool q[3];
int max_i = 0;

int next(int last){
	if (last == 0){
		if (a[2] <= 0 && a[4] <= 0)
			return -1;
		if (a[2] > a[4])
			return 2;
		if (a[2] < a[4])
			return 4;
		if (max_i == 4)
			return 4;
		return 2;
	}
	if (last == 2){
		if (a[4] <= 0 && a[0] <= 0)
			return -1;
		if (a[4] > a[0])
			return 4;
		if (a[4] < a[0])
			return 0;
		if (a[4] == 0)
			return -1;
		if (max_i == 0)
			return 0;
		return 4;
	}
	if (last == 4){
		if (a[2] <= 0 && a[0] <= 0)
			return -1;
		if (a[0] > a[2])
			return 0;
		if (a[0] < a[2])
			return 2;
		if (a[0] == 0)
			return -1;
		if (max_i == 2)
			return 2;
		return 0;
	}
}

string ch(int i){
	switch(i){
		case 0:
			if (q[0]){
				q[0] = false;
				string aux = "R";
				for (int i = 0; i< a[1]; i++){
					aux += "GR";
				}
			}
			return "R";
		case 1: return "O";
		case 2:
			if (q[1]){
				q[1] = false;
				string aux = "Y";
				for (int i = 0; i< a[3]; i++){
					aux += "VY";
				}
			}
			return "Y";
		case 3: return "G";
		case 4:
			if (q[2]){
				q[2] = false;
				string aux = "B";
				for (int i = 0; i< a[5]; i++){
					aux += "OB";
				}
			}
			return "B";
		case 5: return "V";
	}
	return 0;
}

bool fin(){
	return a[0] <= 0 && a[2] <= 0 && a[4] <= 0;
}

int main (){

	cin >> t;
	string sol;
	for (int i =0 ; i<t; i++){
		bool impos = false;
		sol = "";
		cin >> n >> a[0] >>a[1] >>a[2] >>a[3] >>a[4] >>a[5];

		q[0] = true;
		q[1] = true;
		q[2] = true;
		if (!((a[0] >= a[3]+1 || a[3] == 0) &&
				(a[2] >= a[5]+1  || a[5] == 0)&&
				(a[4] >= a[1]+1  || a[1] == 0))){
			impos = true;
			if (a[0] == 0 && a[3] == 0 && a[1] == 0 && a[4] == 0 && (a[2] == a[5])){
				impos = false;
				sol = "";
				for (int i = 0; i< a[5]; i++){
					sol += "YV";
				}
			}
			if (a[2] == 0 && a[5] == 0 && a[1] == 0 && a[4] == 0 && (a[0] == a[3])){
				impos = false;
				sol = "";
				for (int i = 0; i< a[3]; i++){
					sol += "RG";
				}
			}
			if (a[0] == 0 && a[3] == 0 && a[2] == 0 && a[5] == 0 && (a[1] == a[4])){
				impos = false;
				sol = "";
				for (int i = 0; i< a[1]; i++){
					sol += "BO";
				}
			}
		}
		else{
			if (a[0] <= 0 && a[2] <=0 && a[4]<= 0){
				impos = true;
			}
			else{
				a[0]-=a[3];
				a[2]-=a[5];
				a[4]-=a[1];
				if(a[0] < a[2])
					max_i = 2;
				if(a[0] < a[4])
					max_i = 4;
				if (max_i != 0){
					if (a[2] < a[4])
						max_i = 4;
					else
						max_i = 2;
				}
				sol += ch(max_i);
				a[max_i]--;

				int last = max_i;
				while (!fin()){
					int ind = next(last);
					if (ind == -1){
						impos = true;
						break;
					}
					last = ind;
					a[ind]--;
					sol += ch(ind);
				}
			}
		}
		cout << "Case #" << i+1  << ": ";
		if (sol[0] == sol[sol.size()-1])
			impos = true;
		if (impos)
			cout << "IMPOSSIBLE";
		else{
			cout << sol;
		}
		cout << endl;
	}
	return 0;
}
