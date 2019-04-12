#include <bits/stdc++.h>
using namespace std;

int a,b,x,y,z;

int main()
{
	scanf("%d %d %d %d %d",&a,&b,&x,&y,&z);
	printf("%d\n",max(2*x+y-a,0)+max(y+3*z-b,0));
	return 0;
}
