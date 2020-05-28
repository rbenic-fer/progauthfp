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
	int test = 0, N = 0;
	scanf("%d",&N);
	string L[4], L2, L3, L4;
	for(test= 1; test<= N; test++){
		L[0].clear();
		L[1].clear();
		L[2].clear();
		L[3].clear();
		cin>>L[0];
		cin>>L[1];
		cin>>L[2];
		cin>>L[3];
/*
		cout<<L[0]<<endl<<flush;
		cout<<L[1]<<endl<<flush;
		cout<<L[2]<<endl<<flush;
		cout<<L[3]<<endl<<flush;
*/
		int count_x = 0, count_o = 0, count_t = 0, count_dot = 0;
		bool flag_x = false, flag_o = false,flag_dot = false;
/*
		cout<<"flag_x : "<<flag_x<<" count_x = "<<count_x<<endl<<flush;
		cout<<"flag_o : "<<flag_o<<" count_o = "<<count_o<<endl<<flush;
		cout<<"count_t = "<<count_t<<endl<<flush;
		cout<<"flag_dot = "<<flag_dot<<" count_dot = "<<count_dot<<endl<<flush;
*/
		for(int i = 0; i<4; i++){
			count_x = 0, count_o = 0, count_t = 0, count_dot = 0;
			flag_x = false, flag_o = false,flag_dot = false;
			for(int j = 0; j<4; j++){

				switch(L[i][j]){
					case 'X' : count_x++; break;
					case 'O' : count_o++; break;
					case 'T' : count_t++; break;
					case '.' : count_dot++; flag_dot = true; break;
					default:;
				}
			}
			if(count_x == 4 || (count_x ==3 &&count_t ==1)){
				flag_x = true; 
				break;
			}
			else if(count_o == 4 || (count_o ==3 &&count_t ==1)){
				flag_o = true; 
				break;
			}
		}
/*
		cout<<"flag_x : "<<flag_x<<" count_x = "<<count_x<<endl<<flush;
		cout<<"flag_o : "<<flag_o<<" count_o = "<<count_o<<endl<<flush;
		cout<<"count_t = "<<count_t<<endl<<flush;
		cout<<"flag_dot = "<<flag_dot<<" count_dot = "<<count_dot<<endl<<flush;
*/
		if(flag_x == false && flag_o == false){
			count_x = 0, count_o = 0, count_t = 0, count_dot = 0;
			for(int i = 0; i<4; i++){
				count_x = 0, count_o = 0, count_t = 0, count_dot = 0;
				flag_x = false, flag_o = false,flag_dot = false;
				for(int j = 0; j<4; j++){
					switch(L[j][i]){
						case 'X' : count_x++; break;
						case 'O' : count_o++; break;
						case 'T' : count_t++; break;
						case '.' : count_dot++; flag_dot = true; break;
						default:;
					}
				}
				if(count_x == 4 || (count_x ==3 &&count_t ==1)){
					flag_x = true; 
					break;
				}
				else if(count_o == 4 || (count_o ==3 &&count_t ==1)){
					flag_o = true; 
					break;
				}
			}
		}
/*
		cout<<"flag_x : "<<flag_x<<" count_x = "<<count_x<<endl<<flush;
		cout<<"flag_o : "<<flag_o<<" count_o = "<<count_o<<endl<<flush;
		cout<<"count_t = "<<count_t<<endl<<flush;
		cout<<"flag_dot = "<<flag_dot<<" count_dot = "<<count_dot<<endl<<flush;
*/
		if(flag_x == false && flag_o == false){
			count_x = 0, count_o = 0, count_t = 0, count_dot = 0;
			for(int i = 0; i<4; i++){
				switch(L[i][i]){
						case 'X' : count_x++; break;
						case 'O' : count_o++; break;
						case 'T' : count_t++; break;
						case '.' : count_dot++; flag_dot = true; break;
						default:;
				}
				
				if(count_x == 4 || (count_x ==3 &&count_t ==1)){
					flag_x = true; 
					break;
				}
				else if(count_o == 4 || (count_o ==3 &&count_t ==1)){
					flag_o = true; 
					break;
				}
			}
		}
/*
		cout<<"flag_x : "<<flag_x<<" count_x = "<<count_x<<endl<<flush;
		cout<<"flag_o : "<<flag_o<<" count_o = "<<count_o<<endl<<flush;
		cout<<"count_t = "<<count_t<<endl<<flush;
		cout<<"flag_dot = "<<flag_dot<<" count_dot = "<<count_dot<<endl<<flush;
*/
		if(flag_x == false && flag_o == false){
			count_x = 0, count_o = 0, count_t = 0, count_dot = 0;
			for(int i = 0; i<4; i++){
				switch(L[i][3-i]){
						case 'X' : count_x++; break;
						case 'O' : count_o++; break;
						case 'T' : count_t++; break;
						case '.' : count_dot++; flag_dot = true; break;
						default:;
				}
				
				if(count_x == 4 || (count_x ==3 &&count_t ==1)){
					flag_x = true; 
					break;
				}
				else if(count_o == 4 || (count_o ==3 &&count_t ==1)){
					flag_o = true; 
					break;
				}
			}
		}
/*
		cout<<"flag_x : "<<flag_x<<" count_x = "<<count_x<<endl<<flush;
		cout<<"flag_o : "<<flag_o<<" count_o = "<<count_o<<endl<<flush;
		cout<<"count_t = "<<count_t<<endl<<flush;
		cout<<"flag_dot = "<<flag_dot<<" count_dot = "<<count_dot<<endl<<flush;
*/
		if(flag_x == true)
			printf("Case #%d: X won\n",test);
		else if(flag_o == true)
			printf("Case #%d: O won\n",test);
		else if(flag_dot == true)
			printf("Case #%d: Game has not completed\n",test);
		else
			printf("Case #%d: Draw\n",test);
		//cout<<endl<<endl<<flush;
	}
	return(0);
}
