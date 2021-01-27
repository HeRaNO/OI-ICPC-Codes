#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int T;
bool f[MAXN];

int main(int argc, char const *argv[])
{
	for (int i=0;i<=500;i++)
		for (int j=0;j<=500;j++)
			if (2020*i+2021*j<=1000000)
				f[2020*i+2021*j]=true;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		puts(f[n]?"YES":"NO");
	}
	return 0;
}