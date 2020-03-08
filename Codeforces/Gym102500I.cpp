#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define flush fflush(stdout)
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=1000050;
int a[N],b[N],n;
int L,R;
bool ck1()
{
	for(int i=1;i<=n;++i)if(a[i]!=b[i])return 0;
	return 1;
}
bool ck2()
{
	for(int i=1,j=n;i<=n;++i,--j)if(a[i]!=b[j])return 0;
	return 1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	if(ck1())return puts("1 1"),0;
	if(ck2())return printf("%d %d\n",1,n),0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=b[i])
		{
			L=i;
			break;
		}
	}
	for(int i=n;i;--i)
	{
		if(a[i]!=b[i])
		{
			R=i;
			break;
		}
	}
	reverse(b+L,b+R+1);
	if(!ck1())return puts("impossible"),0;
	printf("%d %d\n",L,R);
	return 0;
}

