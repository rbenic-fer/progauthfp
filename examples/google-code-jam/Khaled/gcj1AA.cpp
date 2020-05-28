#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main(){
	
	
	int x,k,n,i;
	
	string st,res;
	cin >> n;
	
	for(k=1;k<=n;k++){
	
		cin >> st;
		res="";
		for(i=0;i<st.length();i++){
		
			if(res==""){
				res = st[i];
			}
			else{
			
				if(st[i] >= res[0]){
					res = st[i] + res;
				}
				else{
					res = res + st[i];
				}
			}
		}
		
		cout << "Case #" << k << ": " << res << endl;
	}
	
	return 0;
}
