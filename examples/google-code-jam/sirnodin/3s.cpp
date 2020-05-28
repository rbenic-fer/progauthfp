#include<iostream>
#include<fstream>

using namespace std;

int gcd(int a,int b)
{
	while(b != 0)
	{
		int temp = a;
		a = b;
		b = temp%b;
	}
	return a;
}

bool test(int a,int b,int t)
{
	if(a == b)
	{
		switch(t)
		{
		case 1:return false;
		case -1:return true;
		}
	}
	int x = a>b?a:b;
	int y = a>b?b:a;
	if(x>=2*y)
	{
		switch(t)
		{
		case -1:return false;
		case 1:return true;
		}
	}
	return test(x-y,y,t*(-1));
}

int main()
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");

	int ALL;
	fin>>ALL;
	for(int TIME = 1;TIME<=ALL;++TIME)
	{
		int num = 0;
		int a1,a2,b1,b2;
		fin>>a1;
		fin>>a2;
		fin>>b1;
		fin>>b2;
		for(int a = a1;a<=a2;++a)
		{
			for(int b = b1;b<=b2;++b)
				if(test(a,b,1))
				{
					++num;
				}
		}
		fout<<"Case #"<<TIME<<": "<<num<<endl;
	}
	return 0;
}