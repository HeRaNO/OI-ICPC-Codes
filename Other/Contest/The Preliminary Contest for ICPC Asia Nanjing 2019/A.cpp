#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXQ 500010
#define MAXW 1000010
using namespace std;

struct A
{
	int x, y, opt, delta, id, pos;
};

struct point{
	int x,y;
	int cir;
	long long val;
}a[MAXQ];

A q[MAXQ], t[MAXQ];
int n, m, T, qq, x1, x2, y_1, y2, cas;
long long c[MAXW], ans[MAXQ];

int chai(long long x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}

inline bool cmp1(const point &x,const point &y)
{
	return x.cir<y.cir;
}

bool cmp(A a, A b)
{
	if (a.x == b.x && a.y == b.y) return a.opt < b.opt;
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, long long v)
{
	for (; x <= n; x += lowbit(x)) c[x] += v;
	return ;
}

inline long long query(int x)
{
	long long res = 0;
	for (; x; x -= lowbit(x)) res += c[x];
	return res;
}

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

inline void getval()
{
	sort(a+1,a+m+1,cmp1);
	long long nval=0;
	int cir=1;
	int i=1;
	while(true)
	{
		long long temp=n-cir*2+1;
		if(temp==0)
		{
			a[i].val=chai((long long)(nval+1));
			break;
		}
		for(;a[i].cir==cir;++i)
		{
			if(a[i].x==n-cir+1&&a[i].y!=cir)
				a[i].val=chai(nval+(long long)(n+2-cir-a[i].y));
			else if(a[i].x>cir&&a[i].y==cir)
				a[i].val=chai(nval+(long long)(temp+n+2-cir-a[i].x));
			else if(a[i].x==cir&&a[i].y<n-cir+1)
				a[i].val=chai(nval+(long long)(temp*2+1+a[i].y-cir));
			else if(a[i].y==n-cir+1&&a[i].x<n-cir+1)
				a[i].val=chai(nval+(long long)(temp*3+1+a[i].x-cir));
		}
		nval+=temp*4;
		cir++;
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(cas);
	while (cas--)
	{
		memset(c,0,sizeof c);memset(ans,0,sizeof ans);
		read(n); read(m); read(qq);
		T = 0; ans[0] = 0;
		for (int i = 1; i <= m; i++)
		{
			read(a[i].x);read(a[i].y);a[i].val=0;
			a[i].cir=min(a[i].x,min(a[i].y,min(n-a[i].x+1,n-a[i].y+1)));
		}
		getval();
		for (int i = 1; i <= m; i++)
		{
			q[++T] = (A){a[i].x, a[i].y, 0, (int)a[i].val, 0, 0};
			q[T].id = T;
		}
		for (int i = 1; i <= qq; i++)
		{
			read(x1); read(y_1); read(x2); read(y2);
			++ans[0];
			q[++T] = (A){x1 - 1, y_1 - 1, 1, 1, 0, (int)ans[0]};q[T].id = T;
			q[++T] = (A){x2, y_1 - 1, 1, -1, 0, (int)ans[0]};q[T].id = T;
			q[++T] = (A){x1 - 1, y2, 1, -1, 0, (int)ans[0]};q[T].id = T;
			q[++T] = (A){x2, y2, 1, 1, 0, (int)ans[0]};q[T].id = T;
		}
		sort(q + 1, q + T + 1, cmp);
		CDQ(1, T);
		for (int i = 1; i <= ans[0]; i++) printf("%lld\n", ans[i]);
	}
	return 0;
}