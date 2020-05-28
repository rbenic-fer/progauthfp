#include <iostream>
#include <algorithm>

using namespace std;

long long int pow[20];

long long int palinN[10];

long long int palindromes[1000000];
long long int fair_palindr[1000000];

int fpnmbr = 0;

int pNmbr = 0;

long long int reverse(long long int x)
{
	long long int digit[10];
	long long int t = x;
	int l = 0;
	while(t>0)
	{

		digit[l] = t % 10;
		t = t / 10;
		l++;
	}
	int p1 = 1;
	long long int res = 0;
	for (int i = 0; i < l; ++i)
	{
		res+=digit[l-i-1]*p1;
		p1 *= 10;
	}
	return res;
}

long long int len(long long t )
{
	int l = 0;
	while(t>0)
	{
		t = t / 10;
		l++;
	}
	return l;
}

int pn = 0;
void genPalindromes()
{

	for (long long int i = 1; i < 10; ++i)
	{
		palindromes[pn] = i;
		pn++;
	}


	for (long long int i = 1; i <= 100000; ++i)
	{
		palindromes[pn] = i*pow[len(i)] + reverse(i);
		pn++;
		long long int l = len(i);
		for (long long int j = 0; j < 10; ++j)
		{
			palindromes[pn] = i*pow[l+1] + j*pow[l] + reverse(i);
			pn++;
		}
	}

}

bool pal(long long int x)
{
	bool p = 1;
	while(x > 9)
	{
		if(x % 10 != x / pow[len(x)-1])
		{
			p = 0;
			break;
		}

		x = x/10;
		x  = x-  (x / pow[len(x)-1])* pow[len(x)-1];
	}
	return p;
}

int main()
{	
	pow[0] = 1;
	for (int i = 1; i < 21; ++i)
	{
		pow[i] = pow[i-1]*10;
	}
	// cout<<len(10)<<endl;
	// cout<<pal(1)<<endl;
	
	long long int n;
	genPalindromes();
	// cout<<pn<<endl;
	sort(palindromes, palindromes + pn);	//isn't necessary, 
	// 										//should be done while generating

	for (int i = 0; i < pn && palindromes[i] <= 100000000; ++i)
	{
		if( pal(palindromes[i]*palindromes[i]) )
		{
			// cout<<"O "<<palindromes[i]<<endl;
			fair_palindr[fpnmbr] = palindromes[i]*palindromes[i];
			fpnmbr++;
			// cout<<fair_palindr[fpnmbr-1]<<endl;
		}
	}
	
	int t;
	cin>>t;
	for (int j = 0; j < t; ++j)
	{
		int c = 0;
		long long int a,b;
		cin>>a>>b;
		for (int i = 0; i < fpnmbr; ++i)
		{
			if(a <= fair_palindr[i] && fair_palindr[i] <= b)
				c++;
		}
		cout<<"Case #"<<j+1<<": "<<c<<endl;
	}
	return 0;
}