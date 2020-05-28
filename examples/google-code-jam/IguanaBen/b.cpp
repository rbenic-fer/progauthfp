#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>

#define ll long long

using namespace std;

// LOOOOOOOOOOOL solve_br doesnt even works, but im leaving it

string flip(string s, int b){
	string res = s;
	for(int i=0; i<=b; ++i)
		if(res[i] == '+')
			res[i] = '-';
		else
			res[i] = '+';

	for(int i=0; i<=b-i; ++i)
	{
		char c = res[i];
		res[i] = res[b-i];
		res[b-i] = c;
	}

	return res;

}

map<string, int> dp;

int solve_br(string str){

	if(dp.find(str) != dp.end()){
		return dp[str];
	}

	int x = 0;
	for(int i=0; i<str.length(); ++i)
		if(str[i] == '-') x++;

	if(!x){
		dp[str] = 0;
		return 0;
	}

	int mn = 1000000;
	dp[str] = mn;
	for(int i=0; i<str.size(); ++i){
		string s = flip(str, i);
		mn = min(solve_br(s) + 1, mn);
	}
	dp[str] = mn;
	return mn;
}

int solve_non_br(string str){
	int cnt = 0;
	// -+-
	// "+-+-+++++----"
	for(int i=0; i<str.length()-1; ++i){
		if(str[i] == '+' && str[i+1] == '-'){
			cnt++;
		}
	}

	// if(str[str.length()-1] == '-')
		// cnt++;

	if(str[0] == '+'){
		return 2*cnt;		
	} else {
		return 2*cnt + 1;
	}
}

string gen_str(int seed){

	string res;
	while(seed){
		if(seed % 2)
			res += "+";
		else
			res += "-";
		seed /= 2;
	}

	return res;
}

void solve(int t) {

	string str;
	cin>>str;
	// for(int i=1; i<40; ++i){
		// string str = gen_str(i);
		// dp.clear();
	cout<<"Case #"<<t<<": "<<solve_non_br(str)<<"\n";
	
	// cout<<"Case #"<<t<<": "<<str<<" "<<solve_br(str)<<" "<<solve_non_br(str)<<" "<<solve_non_br(str)-solve_br(str)<<"\n";

		// cout<<"Case #"<<t<<": "<<str<<" "<<solve_br(str)<<" "<<solve_non_br(str)<<" "<<solve_non_br(str)-solve_br(str)<<"\n";
	// }

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