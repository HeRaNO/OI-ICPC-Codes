#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,t,a[MAXN];
set<int> s;

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&t);
	for (int i=1;i<=n;i++) s.insert(a[i]/t);
	printf("%d\n",s.size());
	return 0;
}
