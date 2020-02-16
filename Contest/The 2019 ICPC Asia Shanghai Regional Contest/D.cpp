#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define Flush fflush(stdout)
#define mp(a,b) make_pair((a),(b))
#define ld long double
using namespace std;
const int N=1050;
int n;
int a[N];
bool b[N][N];

void solve1()
{
	n--;
	for(int i=1;i<=n/2;++i)
	{
		printf("%d %d\n",i,i+1);
		for(int j=1;j<n/2;++j)
		{
			printf("%d %d\n",i+j,((i+j)-(j<<1)-1+n)%n+1);
			printf("%d %d\n",((i+j)-(j<<1)-1+n)%n+1,i+j+1);
		}
		printf("%d %d\n",n+1,i);
	}
}

void solve2()
{
	for(int i=1;i<=n/2;++i)
	{
		printf("%d %d\n",i,i+1);
		for(int j=1;j<n/2;++j)
		{
			printf("%d %d\n",i+j,((i+j)-(j<<1)-1+n)%n+1);
			printf("%d %d\n",((i+j)-(j<<1)-1+n)%n+1,i+j+1);
		}
	}
}

int main()
{
	int T;cin>>T;
	int kase=0;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)a[i]=i;a[0]=n;
		printf("Case #%d: %d\n",++kase,n/2);
		if(n&1)solve1();
		else solve2();
	}
	return 0;
}