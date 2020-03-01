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
const int N=100050;
int a[N],b[N];
int l[N],r[N];
int n,k,L,R;

int main()
{
	cin>>n>>L>>R>>k;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	l[1]=L,r[1]=R;
	for(int i=2;i<=n;++i)
	{
		if(a[i]==a[i-1])l[i]=l[i-1],r[i]=r[i-1];
		else if(a[i]>a[i-1])l[i]=l[i-1]+1,r[i]=min(r[i-1]+k,R);
		else if(a[i]<a[i-1])l[i]=max(l[i-1]-k,L),r[i]=r[i-1]-1;
	}
	for(int i=1;i<=n;++i)if(l[i]>r[i]||l[i]>R||r[i]<L)return puts("-1"),0;
	b[n]=l[n];
	for(int i=n-1;i;--i)
	{
		if(a[i]==a[i+1])b[i]=b[i+1];
		else if(a[i]>a[i+1])b[i]=max(l[i],b[i+1]+1);
		else b[i]=max(b[i+1]-k,l[i]);
	}
	for(int i=1;i<=n;++i)printf("%d ",b[i]);
	return 0;
}
