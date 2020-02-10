#include <bits/stdc++.h>
#define MAXN 100005
#define MAXQ 700005
using namespace std;

struct C
{
	int x,y,opt,delta,id,pos;
	bool operator < (const C &b)const{
		if (x==b.x&&y==b.y) return opt<b.opt;
		return x==b.x?y<b.y:x<b.x;
	}
};

C q[MAXQ],t[MAXQ];
int n,m,T,pre[MAXN],las[MAXN],a[MAXN],o,x,y;
long long c[MAXN],ans[MAXN];
set <int> v[MAXN];
set <int> :: iterator it;

inline int lowbit(int x){return x&-x;}
inline void modify(int x,long long v){for (;x<=n+1;x+=lowbit(x)) c[x]+=v;return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

void CDQ(int l, int r)
{
	if (l == r) return ;
	int mid = l + r >> 1, ll = l, rl = mid + 1;
	for (int i = l; i <= r; i++)
	{
		if (q[i].id <= mid && !q[i].opt) modify(q[i].y, q[i].delta);
		else if (q[i].id > mid && q[i].opt) ans[q[i].pos] += 1LL * q[i].delta * query(q[i].y);
	}
	for (int i = l; i <= r; i++)
		if (q[i].id <= mid && !q[i].opt) modify(q[i].y, -q[i].delta);
	for (int i = l; i <= r; i++)
		if (q[i].id <= mid) t[ll++] = q[i];
		else t[rl++] = q[i];
	for (int i = l; i <= r; i++) q[i] = t[i];
	CDQ(l, mid);
	CDQ(mid + 1, r);
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=las[a[i]];las[a[i]]=i;v[a[i]].insert(i);
		q[++T]=(C){i,pre[i],0,i-pre[i],0,0};q[T].id=T;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&o,&x,&y);
		if (o==1)
		{
			int p=0,nxt=0;it=v[a[x]].find(x);
			if (it!=v[a[x]].begin()) --it,p=*it,++it;
			if ((++it)!=v[a[x]].end()) nxt=*it;--it;
			v[a[x]].erase(it);q[++T]=(C){x,pre[x],0,pre[x]-x,0,0};q[T].id=T;
			if (nxt)
			{
				q[++T]=(C){nxt,pre[nxt],0,pre[nxt]-nxt,0,0};q[T].id=T;
				pre[nxt]=p;
				q[++T]=(C){nxt,pre[nxt],0,nxt-pre[nxt],0,0};q[T].id=T;
			}
			p=0;nxt=0;a[x]=y;v[a[x]].insert(x);
			it=v[a[x]].find(x);
			if (it!=v[a[x]].begin()) --it,p=*it,++it;
			if ((++it)!=v[a[x]].end()) nxt=*it;--it;
			pre[x]=p;q[++T]=(C){x,pre[x],0,x-pre[x],0,0};q[T].id=T;
			if (nxt)
			{
				q[++T]=(C){nxt,pre[nxt],0,pre[nxt]-nxt,0,0};q[T].id=T;
				pre[nxt]=x;
				q[++T]=(C){nxt,pre[nxt],0,nxt-pre[nxt],0,0};q[T].id=T;
			}
		}
		else
		{
			++ans[0];
			q[++T] = (C){x - 1, x - 1, 1, 1, 0, (int)ans[0]};q[T].id = T;
			q[++T] = (C){y, x - 1, 1, -1, 0, (int)ans[0]};q[T].id = T;
			q[++T] = (C){x - 1, n, 1, -1, 0, (int)ans[0]};q[T].id = T;
			q[++T] = (C){y, n, 1, 1, 0, (int)ans[0]};q[T].id = T;
		}
	}
	for (int i=1;i<=T;i++) ++q[i].x,++q[i].y;
	sort(q+1,q+T+1);
	CDQ(1,T);
	for (int i=1;i<=ans[0];i++) printf("%lld\n",ans[i]);
	return 0;
}