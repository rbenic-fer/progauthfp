#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class point
{
public:
	double X;
	double Y;
	void Cpoint(double x,double y)
	{
		X=x;
		Y=y;
	}
};

class line
{
public:
	point p1;
	point p2;
	void Cline(int a,int b)
	{
		p1.X = 0;
		p1.Y = a;
		p2.X = 1;
		p2.Y = b;
	}
};

bool Inter(line a,line b)
{
	if((a.p1.Y-b.p1.Y)*(a.p2.Y-b.p2.Y)<0)
		return true;
	else
		return false;
}

vector<point> Ps;

bool exist(point p)
{
	for(int i = 0;i<Ps.size();++i)
	{
		if(Ps[i].X == p.X && Ps[i].Y == p.Y)
			return true;
	}
	return false;
}

int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");

	int a,b;

	int T;
	fin>>T;
	for(int TC = 1;TC<=T;++TC)
	{
		int N;
		fin>>N;
		line *Ls = new line[N];
		for(int tc = 0;tc<N;++tc)
		{
			fin>>a>>b;
			Ls[tc].Cline(a,b);
		}
		for(int i = 0;i<N-1;++i)
			for(int j = i+1;j<N;++j)
			{
				if(Inter(Ls[i],Ls[j]))
				{
					point temp;
					temp.X = (Ls[j].p1.Y-Ls[i].p1.Y)/(Ls[i].p2.Y+Ls[j].p1.Y-Ls[i].p1.Y-Ls[j].p2.Y);
					temp.Y = (Ls[j].p2.Y-Ls[j].p1.Y)*temp.X+Ls[j].p1.Y;
					if(!exist(temp))
						Ps.push_back(temp);
				}
			}
			fout<<"Case #"<<TC<<": "<<Ps.size()<<endl;
		delete Ls;
		Ps.clear();
	}

	return 0;
}