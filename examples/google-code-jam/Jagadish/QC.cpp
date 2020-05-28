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
typedef unsigned long long int ULL;
int a[50];
int N = 0, J = 0;

void next_a(){
	int i = 0;
	if(a[N-2] == 0){
		a[N-2] = 1;
		return;
	}
	for(i = N-2; i>0; i--){
		if(a[i]==0){
			a[i] = 1;
			return;
		}
		else{
			a[i] = 0;
		}
	}
}

ULL value_with_base_b(int b){
	int i = 0;
	ULL result = 0, mul = 1;
	for(i = N-1; i>=0; i--, mul = mul*b){
		result += a[i]*mul;
	}
	return result;
}

bool is_prime(ULL K){
	ULL i= 3;
	double t = sqrt(K);
//	cout<<"t = "<<t<<endl<<flush;
	for(i = 3; i<=t; i++){
		if(K%i==0){
//			cout<<"returning false"<<endl<<flush;
			return false;
		}
	}
//	cout<<"returning true"<<endl<<flush;
	return true;
}

ULL divisor(ULL K){
	ULL i = 2;
	for(i = 2; i<K; i++){
		if(K%i==0){
			return i;
		}
	}
	return 0;
}

void print_a(){
	for(int i = 0; i<N; i++)
		cout<<a[i]<<flush;
	cout<<endl<<flush;
}

int main(){
	int test = 0;
	int i = 0, x = 0, b = 0;
//	int N = 0, J = 0;
	ULL v = 0, final[11];
	bool flag = true;
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		scanf("%d %d\n",&N,&J);
		printf("Case #%d:\n",x_test);
		MEM(final,0);
		MEM(a,0);
		a[0] = 1;
		for(i = 1; i<N-1;i++) a[i] = 0;
		a[N-1] = 1;
		for(x = 0; x<J;){
//			print_a();
//			cout<<"x = "<<x<<endl<<flush;
			flag = true;
			for(b=2; b<=10 && flag == true; b++){
				v = value_with_base_b(b);
//				cout<<"v = "<<v<<endl<<flush;
				if(is_prime(v)==false){
//					cout<<v<<" is not prime"<<endl<<flush;
					final[b] = divisor(v);
				}
				else{
//					cout<<v<<" is prime"<<endl<<flush;
					flag = false;
				}
			}
			if(flag == false){
				next_a();
				continue;
			}
			else{
				for(i = 0; i<N;i++)printf("%d",a[i]);
//				printf(":");
				for(i = 2; i<=10; i++)printf(" %llu",final[i]);
				printf("\n");
				x++;
				next_a();
			}
		}
	}
	return(0);
}
