#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int M=1000000007;

struct PAM
{
	int nxt[26],fail,l,cnt;
};

PAM tree[MAXN];
int n,tot=1,last;
char s[MAXN];
long long k,ans=1;
vector<pair<int,int>> a;

inline void pre()
{
	tree[0].fail=1;tree[1].l=-1;
	return ;
}

void add(int x,int t)
{
	int now=last;
	while (s[t-tree[now].l-1]!=s[t]) now=tree[now].fail;
	if (!tree[now].nxt[x])
	{
		int nptr=++tot,k=tree[now].fail;
		tree[nptr].l=tree[now].l+2;
		while (s[t-tree[k].l-1]!=s[t]) k=tree[k].fail;
		tree[nptr].fail=tree[k].nxt[x];
		tree[now].nxt[x]=nptr;
	}
	last=tree[now].nxt[x];
	++tree[last].cnt;
	return ;
}

int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=1LL*a*a%M) if (b&1) r=1LL*r*a%M;
	return r;
}

int main()
{
	pre();
	scanf("%d %lld",&n,&k);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) add(s[i]-'a',i);
	for (int i=tot;i;i--) tree[tree[i].fail].cnt+=tree[i].cnt;
	for (int i=1;i<=tot;i++) a.push_back({tree[i].l,tree[i].cnt});
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for (auto [l,c]:a)
		if (l&1)
		{
			if (c<=k)
			{
				ans=1LL*ans*fpow(l,c)%M;
				k-=c;
			}
			else
			{
				ans=1LL*ans*fpow(l,k)%M;
				k=0;break;
			}
		}
	if (!k) printf("%lld\n",ans);
	else puts("-1");
	return 0;
}