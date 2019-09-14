#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,d,a[MAXN],b[MAXN],c[MAXN],f[MAXN];
long long x;

long long getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

void initAB() {
	for(int i = 0; i < n; i = i + 1){
		a[i] = i + 1;
	}
	for(int i = 0; i < n; i = i + 1){
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for(int i = 0; i < n; i = i + 1){
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for(int i = 0; i < n; i = i + 1){
		swap(b[i], b[getNextX() % (i + 1)]);
	}
	return ;
}

int main()
{
	scanf("%d %d %lld",&n,&d,&x);
	initAB();
	for (int i=0;i<n;i++) if (b[i]) c[++c[0]]=i;
	for (int i=0;i<n;i++) f[a[i]]=i;
	for (int i=0;i<n;i++)
	{
		int ans=0;
		for (int j=n;j>=n-50&&j>0;j--)
			if (i>=f[j]&&b[i-f[j]])
			{
				ans=j;break;
			}
		if (!ans)
		{
			for (int j=1;j<=c[0]&&c[j]<=i;j++)
				ans=max(ans,a[i-c[j]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}