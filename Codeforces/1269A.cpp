#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if (n&1) printf("%d 9\n",n+9);
	else printf("%d 4\n",n+4);
	return 0;
}