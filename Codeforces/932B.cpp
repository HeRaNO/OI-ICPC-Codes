#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=1000050;
int l,r,k;
int ans[N][10];
int a[N];

int work(int x)
{
	while(x>=10)
	{
		int tmp=1;
		int num=x;
		while(num)
		{
			if(num%10)tmp*=(num%10);
			num/=10;
		}
		x=tmp;
	}
	return x;
}

void Init()
{
	for(int i=1;i<=1000000;++i)
	{
		int num=work(i);
		for(int j=1;j<=9;++j)ans[i][j]=ans[i-1][j];
		ans[i][num]=ans[i-1][num]+1;
	}
}

int main()
{
	Init();
	int Test;cin>>Test;
	while(Test--)
	{
		cin>>l>>r>>k;
		printf("%d\n",ans[r][k]-ans[l-1][k]);
	}
	return 0;
}
