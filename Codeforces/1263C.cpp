#include <bits/stdc++.h>
using namespace std;

int T,n;
vector <int> ans;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans.clear();
		for (int i=1,j;i<=n;i=j+1)
		{
			j=n/(n/i);
			ans.push_back(j);
		}
		printf("%d\n",ans.size()+1);
		printf("0");
		for (auto i:ans) printf(" %d",i);
		puts("");
	}
	return 0;
}