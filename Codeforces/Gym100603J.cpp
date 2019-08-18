#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;
using namespace __gnu_pbds;

const long long b1=233LL;
const long long b2=131LL;
const long long M1=1e9+7LL;
const long long M2=998244353;

cc_hash_table <long long,int> mp;
char s[MAXN][MAXN];
int n,m,l,x,y,p,q;
int mx[MAXN];
long long hs1[MAXN];

int main()
{
	scanf("%d %d %d",&n,&l,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		long long h1=0,h2=0;
		for (int j=0;j<l;j++)
		{
			h1=(h1*b1+s[i][j]-'a')%M1;
			//h2=(h2*b2+s[i][j]-'a')%M2;
		}
		hs1[i]=h1;//hs2[i]=h2;
		mp[h1]++;
	}
	for (int i=1;i<=n;i++) mx[i]=mp[hs1[i]];
	while (m--)
	{
		scanf("%d %d %d %d",&x,&y,&p,&q);
		mp[hs1[x]]--;
		if (x!=p) mp[hs1[p]]--;
		swap(s[x][y-1],s[p][q-1]);
		long long h1=0,h2=0;
		for (int j=0;j<l;j++)
		{
			h1=(h1*b1+s[x][j]-'a')%M1;
			//h2=(h2*b2+s[x][j]-'a')%M2;
		}
		hs1[x]=h1;//hs2[x]=h2;
		mp[h1]++;
		if (x!=p)
		{
			h1=0;//h2=0;
			for (int j=0;j<l;j++)
			{
				h1=(h1*b1+s[p][j]-'a')%M1;
				//h2=(h2*b2+s[p][j]-'a')%M2;
			}
			hs1[p]=h1;//hs2[p]=h2;
			mp[h1]++;
		}
		for (int i=1;i<=n;i++) mx[i]=max(mx[i],mp[hs1[i]]);
	}
	for (int i=1;i<=n;i++) printf("%d\n",mx[i]);
	return 0;
}