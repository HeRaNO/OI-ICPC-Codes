#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

int a[1<<MAXN][1<<MAXN];

int main(int argc, char const *argv[])
{
	int n,now=0;
	scanf("%d",&n);
	if (n==1) return puts("NO"),0;
	puts("YES");
	for (int i=0;i<1<<n;i+=2)
	{
		int row=i;
		for (int j=0;j<1<<n;j++,row^=1)
			a[row][j]=++now;
	}
	for (int i=(1<<n)-2;i>=0;i-=2)
	{
		int row=i;
		for (int j=(1<<n)-1;~j;j--,row^=1)
			a[row][j]=++now;
	}
	for (int i=0;i<1<<n;i++)
		for (int j=0;j<1<<n;j++)
			printf("%d%c",a[i][j]," \n"[j==(1<<n)-1]);
	return 0;
}
