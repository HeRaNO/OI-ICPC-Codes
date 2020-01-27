#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int N=1050;
char s[1050];
int k,n;
int cnt[1050];
ll c[N][N];
ll ans;

int work(int x)
{
	int ret=0;
	while(x>1)
	{
		int tmp=0;
		for(int i=0;i<=11;++i)
		{
			tmp+=((x>>i)&1);
		}
		ret++;
		x=tmp;
	}
	return ret;
}

void Init()
{
	cnt[0]=-1;
	for(int i=1;i<=1000;++i)
	{
		cnt[i]=work(i);
	}
	c[0][0]=1;
	for(int i=1;i<=1000;++i)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)
			c[i][j]=c[i-1][j]+c[i-1][j-1],c[i][j]%=mod;
	}
}

int main()
{
	Init();
	scanf("%s",s);
	n=strlen(s);
	cin>>k;
	if(k==0)return puts("1"),0;
	if(k==1)return printf("%d\n",n-1),0;
	int now=0;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='1')
		{
			for(int j=n-i-1;j>=0;--j)
			{
				if(cnt[j+now]+1==k)ans+=c[n-i-1][j],ans%=mod;
			}
			now++;
		}
	}
	if(cnt[now]+1==k)ans++,ans%=mod;
	cout<<ans<<endl;
	return 0;
}
