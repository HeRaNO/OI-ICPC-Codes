#include <bits/stdc++.h>
using namespace std;

inline int dfs(int a,int b)
{
	if (a<=b) return b-a;
	if (a&1) return dfs(a+1,b)+1;
	else return dfs(a>>1,b)+1;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",dfs(a,b));
	return 0;
}