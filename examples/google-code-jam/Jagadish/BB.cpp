#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

#define MEM(v,i) memset(v,i,sizeof(v))

typedef long long int LL;

int main(){
	int test = 0;
	int len = 0;
	int i = 0, x = 0, y = 0;
	string s1, s2;
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		s1.clear();
		s2.clear();
		cin>>s1;
		cin>>s2;
		len = s1.length();
		x = 0;
		y = 0;
//		int x1 = 0, y1 = 0;
		for(i = 0; i<len; i++){
			if(s1[i]!='?' && s2[i]!='?'){
				x = (int)(s1[i]-'0');
				y = (int)(s2[i]-'0');
				if(x==y){
					continue;
				}
				if(x<y){
					if(y-x>5){
						x = 0, y = 1;
						break;
					}
					else{x = 0, y = 0;
						break;
					}
				}
				else{
					if(x-y>5){
						x = 1, y = 0;
						break;
					}
					else{x = 0, y = 0;}
				}
			}
		}
		for(i = 0; i<len; i++){
			if(s1[i]!='?' && s2[i]!='?'){
				if(x==y){
					x = (int)(s1[i]-'0');
					y = (int)(s2[i]-'0');
					continue;
				}
				continue;
			}
			if(s1[i]=='?' && s2[i]!='?'){
//				if(i==0){
//					s1[i] = s2[i];
//					x = (int)(s1[i]-'0');
//					y = x;
//					continue;
//				}
//				x = (int)(s1[i-1]-'0');
//				y = (int)(s2[i-1]-'0');
				if(x==y){
					s1[i] = s2[i];
					x = (int)(s1[i]-'0');
					y = x;
					continue;
				}
				if(x<y){
					s1[i] = '9';
					continue;
				}
				if(x>y){
					s1[i] = '0';
					continue;
				}
				
			}
			if(s1[i]!='?' && s2[i]=='?'){
//				if(i == 0){
//					s2[i] = s1[i];
//					x = (int)(s1[i]-'0');
//					y = x;
//					continue;
//				}
//				x = (int)(s1[i-1]-'0');
//				y = (int)(s2[i-1]-'0');
				if(x==y){
					s2[i] = s1[i];
					continue;
				}
				if(x<y){
					s2[i] = '0';
					continue;
				}
				if(x>y){
					s2[i] = '9';
					continue;
				}

			}
			if(s1[i]=='?' && s2[i]=='?'){
//				if(i==0){
//					s1[i] = '0';
//					s2[i] = '0';
//					x = 0, y = 0;
//					continue;
//				}
//				x = (int)(s1[i-1]-'0');
//				y = (int)(s2[i-1]-'0');
				if(x==y){
					s1[i] = '0';
					s2[i] = '0';
					continue;
				}
				if(x<y){
					s1[i] = '9';
					s2[i] = '0';
					continue;
				}
				if(x>y){
					s1[i] = '0';
					s2[i] = '9';
					continue;
				}
			}
		}			
		printf("Case #%d: ",x_test);
		cout<<s1<<" "<<s2<<endl;
	}
	return(0);
}
