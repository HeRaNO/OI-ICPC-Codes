#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int X1,Y1,X2,Y2;
int ans;

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
	ans=ans+(m%2)*(n-(X2-X1+1));
//	cout<<ans<<endl;
	ans=ans+((Y1-1)%2)*(X2-X1+1);
//	cout<<ans<<endl;
	ans=ans+((m-Y2)%2)*(X2-X1+1);
//	cout<<ans<<endl;
	printf("%d\n",(ans+1)/2);
	return 0;
}