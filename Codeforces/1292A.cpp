#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,T,r,c,cnt,a[2][MAXN];

int main()
{
	scanf("%d %d",&n,&T);
	while (T--)
	{
		scanf("%d %d",&r,&c);--r;
		if (!a[r][c])
		{
			a[r][c]=1;
			cnt+=a[r^1][c-1]+a[r^1][c]+a[r^1][c+1];
		}
		else
		{
			cnt-=a[r^1][c-1]+a[r^1][c]+a[r^1][c+1];
			a[r][c]=0;
		}
		puts(cnt?"No":"Yes");
	}
	return 0;
}