#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N=25;
int n,m,K;
int a[N][N];
vector <int> v[N];
bool check3()
{
	for(int i=1;i<=n;++i)
	{
		int cnt=0;
		for(int j=1;j<=m;++j)
			if(a[i][j]!=j)cnt++;
		if(cnt>2||(i==K&&cnt>0))return false;
	}
	return true;
}
bool check2()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			if(a[i][j]!=j)return false;
	}
	return true;
}

bool check()
{
	for(int i=1;i<=m;++i)
	{
		for(int j=i;j<=m;++j)
		{
			for(int k=1;k<=n;++k)swap(a[k][i],a[k][j]);
			if(check2()||check3())return true;
			for(int k=1;k<=n;++k)swap(a[k][i],a[k][j]);
		}
	}
	return false;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	}
	if(check())return puts("YES"),0;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		if(a[i][j]!=j)v[i].push_back(j);
	}
	for(int i=1;i<=n;++i)
		if(v[i].size()>4)return puts("NO"),0;
	for(K=1;K<=n;++K)
	for(int i=0;i<v[K].size();++i)
	{
		for(int j=i;j<v[K].size();++j)
		{
			swap(a[K][v[K][i]],a[K][v[K][j]]);
			if(check())return puts("YES"),0;
			swap(a[K][v[K][i]],a[K][v[K][j]]);
		}
	}
	puts("NO");
	return 0;
}
