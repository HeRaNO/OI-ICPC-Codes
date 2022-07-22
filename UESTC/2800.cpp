#include <bits/stdc++.h>
using namespace std;

void Solve()
{
	int n,A=0;
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++)
		scanf("%d",&x),A+=(x==1);
	if (A==n) return puts(n&1?"Win":"Lose"),void();
	puts(A&1?"Lose":"Win");
	return ;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}