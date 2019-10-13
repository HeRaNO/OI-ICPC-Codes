#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int t1,t2;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		if(x>=m)t1++;
		else t2++;
	}
	printf("%d\n",max(0,t1-t2));
	return 0;
}