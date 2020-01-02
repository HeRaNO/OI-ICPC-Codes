#include <bits/stdc++.h>
using namespace std;

int n,p,pp,cnt[4];

inline bool judge(int x)
{
	if (!(x%7)) return true;
	while (x)
	{
		if (x%10==7) return true;
		x/=10;
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++,p=(p+1)%4)
	{
		if (judge(i))
		{
			++cnt[p];
			continue;
		}
		++pp;
	}
	for (int i=0;i<4;i++) printf("%d\n",cnt[i]);
	return 0;
}