#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int N;
	fin>>N;
	for(int i = 1;i<=N;++i)
	{
		int a;
		fin>>a;
		int b;
		fin>>b;
		int c = 1<<a;
		fout<<"Case #";
		fout<<i;
		fout<<": ";
		if((b+1)%c == 0)
		{
			fout<<"ON"<<endl;;
		}
		else
		{
			fout<<"OFF"<<endl;
		}
	}
	return 0;
}