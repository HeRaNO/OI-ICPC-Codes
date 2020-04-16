#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,m,A,pos[MAXN];

struct C
{
	int l,r,p;
	bool operator < (const C &rhs)const{
		return pos[l]==pos[rhs.l]?pos[l]&1?r>rhs.r:r<rhs.r:l<rhs.l;
	}
}p[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].l,&p[i].r),p[i].p=i;
		A=max(A,max(p[i].l,p[i].r));
	}
	m=(int)sqrt(A+1);
	for (int i=1;i<=A+1;i++) pos[i-1]=(i-1)/m+1;
	sort(p+1,p+n+1);
	for (int i=1;i<=n;i++) printf("%d%c",p[i].p,i==n?'\n':' ');
	return 0;
}