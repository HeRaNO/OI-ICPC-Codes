#include <bits/stdc++.h>
using namespace std;

int l,r;

inline bool check(int x)
{
	int cnt[10];
	for (int i=0;i<10;i++) cnt[i]=0;
	while (x)
	{
		cnt[x%10]++;x/=10;
	}	
	for (int i=0;i<=9;i++) if (cnt[i]>=2) return false;
	return true;
}

int main()
{
	scanf("%d %d",&l,&r);
	for (int i=l;i<=r;i++)
	{
		if (check(i)) return printf("%d\n",i),0;
	}
	printf("-1\n");
	return 0;
}