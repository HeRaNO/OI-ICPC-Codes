#include <bits/stdc++.h>
using namespace std;

int T,n,cnt;float a,x,mx,mn;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);x=0;mx=0;mn=20;cnt=0;
		for (int i=1;i<=n;i++) scanf("%f",&a),x+=a,mx=max(mx,a),mn=min(mn,a);
		printf("%.2f\n",(x-mx-mn)/(float)(n-2));
	}
	return 0;
}