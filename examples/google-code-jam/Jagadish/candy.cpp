#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;

int max_value = 0;
vector <int> iV;
int sum(int a, int b)
{
	int value_2 = 1;
	int rem_a = a, rem_b =b, value = 0;
	while((a!=0)||(b!=0)){
		rem_a = a%2;
		rem_b = b%2;
		a = a/2;
		b = b/2;
		value += ((rem_a+rem_b)%2)*value_2;
		value_2 *= 2;
	}
	return(value);
}

void next_main()
{
	
	int num;
	
	sort(iV.begin(),iV.end());
	vector <int> M;
	for(int i = 0; i<iV.size();i++)
		M.push_back(0);
	
	
	for(int i = 0; i<pow(2,iV.size())-2;i++)
	{
		for(int j =0,carry=1;( j<iV.size())&&(carry == 1);j++)
		{
			M[j] =(M[j]+carry)%2;
			
			if(M[j]==0)
				carry = 1;
			else carry = 0;
		}
		int sum_value_1 = 0,sum_value_0 = 0,natural_sum_1 = 0,natural_sum_0 = 0;
		for(int j =0 ; j< iV.size();j++)
		{
			if(M[j]==1){
				/* change should be here*/
				sum_value_1 = sum(sum_value_1, iV[j]);
				natural_sum_1 += iV[j];
				//cout<<iV[j];
			}
			else{
				sum_value_0 = sum(sum_value_0, iV[j]);
				natural_sum_0 += iV[j];
				}
					
		}
/*
		cout<<"sum_value_1 = "<<sum_value_1<<" sum_value_0 = "<<sum_value_0<<" natural_sum_1 = "<<natural_sum_1<<" natural_sum_0 = "<<natural_sum_0<<endl;
*/
		if(sum_value_1 == sum_value_0){
			int max_10 = (natural_sum_1>= natural_sum_0)? natural_sum_1: natural_sum_0;
			if(max_10 > max_value) max_value = max_10;
		}

		//cout<<endl;

	}

	//return(0);

}

int main(){
	int T = 0,C = 0;
	int a = 0,i = 0,value = 0;
	scanf("%d\n",&T);
	for(a = 1; a<= T; a++){
		scanf("%d\n",&C);
		
		for(i = 0; i<C;i++){
			scanf("%d",&value);
			iV.push_back(value);
		}
		max_value = 0;
		next_main();
		if(max_value != 0)
			printf("Case #%d: %d\n",a,max_value);
		else printf("Case #%d: NO\n",a);
		iV.clear();	
	}
	return(0);
}
