#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,a[MAXN],x;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) x^=a[i];
	puts(x?"No":"Yes");
	return 0;
}