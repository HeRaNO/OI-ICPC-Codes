#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h,m,s;
	scanf("%d:%d:%d",&h,&m,&s);
	int a=h*3600+m*60+s;
	scanf("%d:%d:%d",&h,&m,&s);
	int b=h*3600+m*60+s;
	printf("%d\n",abs(b-a));
	return 0;
}