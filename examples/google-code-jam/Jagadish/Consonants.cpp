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

string input;
int len_input = 0;
int array[1000010];
int main(){
	int test = 0, N = 0, i = 0;
	int count = 0;
	scanf("%d",&test);

	for(int x = 1; x<= test; x++){
		cin>>input>>N;
		len_input = input.length();
		count = 0;
		//cout<<input<<" "<<len_input<<" "<<N<<endl<<flush;
		for(i =0; i<len_input; i++){
			for(int j = i; j<len_input; j++){
				int cons = 0, count_temp = 0, count_temp_2 = 0;
				for(int k = i; k<=j; k++){
				if(input[k] != 'a' && input[k]!= 'e' && input[k]!= 'i'&& input[k]!='o' &&input[k]!='u'){
					if(cons == 0){
						cons = 1;
						count_temp_2++;
						
					}
					else{
						count_temp_2++;
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<count_temp_2<<endl<<flush;
				}
				else {
					if(cons == 1){
						if(count_temp<count_temp_2){
							count_temp = count_temp_2;
						}
						cons = 0;
						count_temp_2 = 0;
					}
				}
				if(count_temp<count_temp_2)
					count_temp = count_temp_2;
				//cout<<i<<" "<<j<<" "<<k<<" "<<count_temp_2<<" "<<count_temp<<endl<<flush;
				}
				
				if(N<= count_temp)
					count++;
			}
		}

		printf("Case #%d: %d\n",x,count);
	}
	return(0);
}
