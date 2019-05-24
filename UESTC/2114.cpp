#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int a[MAXN],n;
int sta[MAXN],top;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int A=1,B=1;bool f=true;
	while(B<=n&&f)
	{
		if (A==a[B]){++A,++B;}
		else if(top&&sta[top]==a[B]){--top;++B;}
		else if(A<=n){sta[++top]=A++;}
		else f=false;
	}
	puts(f?"Yes":"No");
	return 0;
}
