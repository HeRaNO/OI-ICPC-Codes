#include <bits/stdc++.h>
using namespace std;

int T,cnt[1<<18|1];
long long x;
char o[3];

inline int get(long long x)
{
	int r=0,t=1;
	for (;x;x/=10)
	{
		if ((x%10)&1) r|=t;
		t<<=1;
	}
	return r;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s %lld",o,&x);
		int p=get(x);
		if (o[0]=='+') ++cnt[p];
		else if (o[0]=='-') --cnt[p];
		else printf("%d\n",cnt[p]);
	}
	return 0;
}