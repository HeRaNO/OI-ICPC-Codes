#include <bits/stdc++.h>
using namespace std;

int x,y;

int main()
{
	scanf("%d %d",&x,&y);swap(x,y);
	if (x==1)
	{
		if (!y) return puts("Yes"),0;
		else return puts("No"),0;
	}
	if (!x||!y) return puts("No"),0;
	if (y<x-1) return puts("No"),0;
	y-=(x-1);
	if (y&1) return puts("No"),0;
	puts("Yes");
	return 0;
}
