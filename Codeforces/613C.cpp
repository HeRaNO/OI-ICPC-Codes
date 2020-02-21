#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int n,a[MAXN],sum;
char s[MAXM];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	if(n==1)
	{
		printf("%d\n",a[1]);
		for(int i=1;i<=sum;i++)printf("a");
		return 0;
	}
	int f=0,g=a[1];
	for(int i=2;i<=n;i++)g=__gcd(g,a[i]);
	for(int i=1;i<=n;i++)f+=(a[i]&1);
	if(f>=2)
	{
		puts("0");
		for(int i=1;i<=n;i++)while(a[i]--)printf("%c",i+'a'-1);
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]/=g;
	if(f==1)
	{
		printf("%d\n",g);
		for(int i=1;i<=n;i++)
		{
			if(a[i]&1)f=i,a[i]--;
		}
		int val=sum/g,l=0,r=val-1;
		s[val/2]=f+'a'-1;
		for(int i=1;i<=n;i++)
		{
			while(a[i])
			{
				a[i]-=2;
				s[l++]=s[r--]=i+'a'-1;
			}
		}
		while(g--)
		{
			reverse(s,s+val);
			printf("%s",s);
		}
	}
	else
	{
		int val=sum/g,l=0;
		printf("%d\n",g);
		for(int i=1;i<=n;i++)
		{
			while(a[i])
			{
				a[i]--;
				s[l++]=i+'a'-1;
			}
		}
		while(g--)
		{
			reverse(s,s+val);
			printf("%s",s);
		}
	}
	return 0;
}