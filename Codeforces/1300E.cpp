#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,a[MAXN],top;
pair <long long,int> sta[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		long long s=a[i];int l=1;
		while (top&&s*sta[top].second<=l*sta[top].first)
		{
			s+=sta[top].first;l+=sta[top].second;
			--top;
		}
		sta[++top]={s,l};
	} 
	for (int i=1;i<=top;i++)
	{
		double avg=(double)sta[i].first/sta[i].second;
		for (int j=1;j<=sta[i].second;j++)
			printf("%.10lf\n",avg);
	}
	return 0;
}