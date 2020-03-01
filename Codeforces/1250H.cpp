#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=300050;
int c[10];
void solve()
{
	for(int i=1;i<10;++i)if(c[i]==0){printf("%d\n",i);return;}
	int num=0,bit=inf;
	for(int i=1;i<10;++i)
	{
		if(bit>c[i]+1)
		{
			bit=c[i]+1;
			num=i;
		}
	}
	if(num!=0&&bit>c[0]+1)num=0;
	if(num!=0)
	{
		for(int i=1;i<=c[num]+1;++i)
			printf("%d",num);
		puts("");
		return;
	}
	else
	{
		printf("1");
		for(int i=1;i<=c[0]+1;++i)
			printf("0");
		puts("");
		return;
	}
}

int main()
{
	int Test;cin>>Test;
	while(Test--)
	{
		for(int i=0;i<10;++i)scanf("%d",&c[i]);
		solve();
	}
	return 0;
}
