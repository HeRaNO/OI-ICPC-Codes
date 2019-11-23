#include <bits/stdc++.h>
#define mp make_pair
#define MAXN 300005
using namespace std;

int n,a[MAXN];
multiset <pair<int,int> > s;
int cnt,pos=1,l=1,r=1,mx;

int main()
{
	scanf("%d",&n);cnt=(n<<1)+n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
		a[i+(n<<1)]=a[i];
	}
	s.insert(mp(a[1],1));
	mx=(*s.rbegin()).first;
	while (l<=r&&r<=cnt&&l<=n)
	{
		if (r==cnt+1)
		{
			while (l<=n)
			{
				printf("-1 ");
				l++;
			}
			break;
		}
		while (a[r]*2>=mx&&r<=cnt)
		{
			if (a[r]>mx)
			{
				mx=a[r];
				pos=r;
			}
			r++;
			s.insert(mp(a[r],r));
		}
		if (r==cnt+1)
		{
			while (l<=n)
			{
				printf("-1 ");
				l++;
			}
			break;
		}
		while (l<=pos&&l<=n)
		{
			printf("%d ",r-l);
			auto it=s.find(mp(a[l],l));
			s.erase(it);
			l++;
		}
		mx=(*s.rbegin()).first;
		pos=(*s.rbegin()).second;
	}
	puts("");
	return 0;
}