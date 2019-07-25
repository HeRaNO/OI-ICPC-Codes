#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,m,x,y,a[MAXN],ori[MAXN],s[MAXN];
vector <int> aa;
int nn,mm;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1)
	{
		puts("YES");
		printf("%d %d\n",1,a[1]);
		return 0;
	}
	for (int i=1;i<n;i++) s[i]=a[i+1]-a[i];
	for (int i=1;i<n;i++)
		if (s[i]) aa.push_back(abs(s[i]));
		else return puts("NO"),0;
	sort(aa.begin(),aa.end());
	ori[++m]=aa[0];
	for (int i=1;i<aa.size();i++)
		if (aa[i]!=aa[i-1]) ori[++m]=aa[i];
	if (m>2) return puts("NO"),0;
	if (m==1)
	{
		puts("YES");
		if (ori[1]==1) puts("1 1000000000");
		else printf("1000000000 %d\n",ori[1]);
		return 0;
	}
	if (ori[1]!=1&&m>1) return puts("NO"),0;
	nn=1e9;mm=ori[1]==1?ori[2]:ori[1];
	x=(a[1]-1)/mm+1;y=a[1]-(x-1)*mm;
	for (int i=1;i<n;i++)
	{
		if (abs(s[i])==1)
		{
			if (s[i]==-1) --y;
			else ++y;
		}
		else
		{
			if (s[i]<0) --x;
			else ++x;
		}
		if (x<1||x>nn||y<1||y>mm) return puts("NO"),0;
	}
	puts("YES");
	printf("%d %d\n",nn,mm);
	return 0;
}
