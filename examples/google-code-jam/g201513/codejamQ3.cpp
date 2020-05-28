#include<stdio.h>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

const int maxn = 2200;

long long ntest,R,k,N;
long long g[maxn],s[maxn];
long long go[maxn],add[maxn];
map<pair<long long,long long>,pair<long long,long long> > T;

pair<long long,long long> calc(long long st,long long k)
{
	if(T.find(make_pair(st,k))!=T.end()) return T[make_pair(st,k)];
	long long kk = (k&-k);
	pair<long long,long long> res1, res2;
	if(kk!=k)
	{
		res1 = calc(st,k-kk);
		res2 = calc(res1.first,kk);
		res2.second += res1.second;
		return T[make_pair(st,k)] = res2;
	}
	else if(k!=1)
	{
		res1 = calc(st,k/2);
		res2 = calc(res1.first,k/2);
		res2.second += res1.second;
		return T[make_pair(st,k)] = res2;
	}
	else
	{
		return make_pair(go[st],add[st]);
	}
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%I64d",&ntest);
	for(long long test=1;test<=ntest;test++)
	{
		T.clear();
		scanf("%I64d%I64d%I64d",&R,&k,&N);
		s[0] = 0;
		for(long long i=1;i<=N;i++)
		{
			scanf("%I64d",&g[i]);
			s[i] = s[i-1] + g[i];
		}
		for(long long i=1;i<=N;i++) s[N+i] = s[N+i-1] + g[i];
		printf("Case #%I64d: ",test);
		if(s[N] <= k)
		{
			printf("%I64d\n",1ll*s[N]*R);
			continue;
		}
		for(long long i=0;i<N;i++)
		{
			go[i] = upper_bound(s,s+N+N+1,s[i]+k) - s - 1;
			add[i] = s[go[i]] - s[i];
			go[i] %= N;
		}
		printf("%I64d\n",calc(0,R).second);
	}
	return 0;
}
