#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=5e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);

int n,m,l;
int num[105];

int main()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int a;
			scanf("%d",&a);
			num[a]++;
		}
	for(int i=100;i;i--)
		num[i]+=num[i+1];
	int mx=1,sum=0;
	for(int i=100;i;i--)
	{
		sum+=num[i];
		if(sum<=l)
			mx=i;
	}
	cout<<mx-1;
	return 0;
}