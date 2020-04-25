#include <bits/stdc++.h>
using namespace std;

int n,ans;

inline int SG(int x)
{
	if (x%8==0) --x;
	else if (x%8==7) ++x;
	return x;
}

int main()
{
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),ans^=SG(x);
	puts(ans?"First":"Second");
	return 0;
}