#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
#define GETPOS(c,x) (lower_bound(ALL(c),x)-c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x),0,sizeof((x)))
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<pii> Vpii;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(ull &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MAXN=1e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

struct mxinfo
{
	int m,s,t;
	mxinfo(){}
	mxinfo(int _,int __,int ___):m(_),s(__),t(___){}
	mxinfo operator + (const mxinfo &a)const{
		mxinfo res;
		if (m>a.m)
		{
			res.m=m;res.t=t;
			res.s=max(s,a.m);
		}
		else if (m<a.m)
		{
			res.m=a.m;res.t=a.t;
			res.s=max(a.s,m);
		}
		else
		{
			res.m=a.m;res.t=t+a.t;
			res.s=max(s,a.s);
		}
		return res;
	}
};

struct mninfo
{
	int m,s,t;
	mninfo(){}
	mninfo(int _,int __,int ___):m(_),s(__),t(___){}
	mninfo operator + (const mninfo &a)const{
		mninfo res;
		if (m<a.m)
		{
			res.m=m;res.t=t;
			res.s=min(s,a.m);
		}
		else if (m>a.m)
		{
			res.m=a.m;res.t=a.t;
			res.s=min(a.s,m);
		}
		else
		{
			res.m=a.m;res.t=t+a.t;
			res.s=min(s,a.s);
		}
		return res;
	}
};

struct SegTBeats
{
	struct SegmentTreeBeats
	{
		int p,r,m;long long x,lazy;
		mxinfo mx;mninfo mn;
	};

	SegmentTreeBeats tree[1<<20];
	int a[MAXN];

	inline void PushUp(int u)
	{
		tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
		tree[u].mn=tree[u<<1].mn+tree[u<<1|1].mn;
		tree[u].mx=tree[u<<1].mx+tree[u<<1|1].mx;
		return ;
	}

	inline void addmax(int u,int v)
	{
		tree[u].x+=1LL*tree[u].mn.t*(v-tree[u].mn.m);
		tree[u].mn.m=v;tree[u].mx.m=max(tree[u].mx.m,v);
		if (tree[u].mx.m==tree[u].mn.m)
		{
			tree[u].x=1LL*(tree[u].r-tree[u].p)*v;
			tree[u].mn=mninfo(tree[u].mn.m,~(1<<31),tree[u].r-tree[u].p);
			tree[u].mx=mxinfo(tree[u].mx.m,  1<<31 ,tree[u].r-tree[u].p);
		}
		else tree[u].mx.s=max(tree[u].mx.s,v);
		return ;
	}

	inline void addmin(int u,int v)
	{
		tree[u].x-=1LL*tree[u].mx.t*(tree[u].mx.m-v);
		tree[u].mx.m=v;tree[u].mn.m=min(tree[u].mn.m,v);
		if (tree[u].mx.m==tree[u].mn.m)
		{
			tree[u].x=1LL*(tree[u].r-tree[u].p)*v;
			tree[u].mn=mninfo(tree[u].mn.m,~(1<<31),tree[u].r-tree[u].p);
			tree[u].mx=mxinfo(tree[u].mx.m,  1<<31 ,tree[u].r-tree[u].p);
		}
		else tree[u].mn.s=min(tree[u].mn.s,v);
		return ;
	}

	inline void Lazy(int u,long long v)
	{
		tree[u].lazy+=v;tree[u].x+=(tree[u].r-tree[u].p)*v;
		tree[u].mx.m+=v;if (tree[u].mx.s!=  1<<31 ) tree[u].mx.s+=v;
		tree[u].mn.m+=v;if (tree[u].mn.s!=~(1<<31)) tree[u].mn.s+=v;
		return ;
	}

	inline void PushDown(int u)
	{
		if (tree[u].lazy)
		{
			Lazy(u<<1,tree[u].lazy);
			Lazy(u<<1|1,tree[u].lazy);
			tree[u].lazy=0LL;
		}
		if (tree[u<<1].mx.s<tree[u].mx.m&&tree[u].mx.m<tree[u<<1].mx.m) addmin(u<<1,tree[u].mx.m);
		if (tree[u<<1].mn.m<tree[u].mn.m&&tree[u].mn.m<tree[u<<1].mn.s) addmax(u<<1,tree[u].mn.m);
		if (tree[u<<1|1].mx.s<tree[u].mx.m&&tree[u].mx.m<tree[u<<1|1].mx.m) addmin(u<<1|1,tree[u].mx.m);
		if (tree[u<<1|1].mn.m<tree[u].mn.m&&tree[u].mn.m<tree[u<<1|1].mn.s) addmax(u<<1|1,tree[u].mn.m);
		return ;
	}

	void BuildTree(int u)
	{
		if (tree[u].p+1==tree[u].r)
		{
			tree[u].x=0;
			tree[u].mn=mninfo(0,~(1<<31),1);
			tree[u].mx=mxinfo(0,  1<<31 ,1);
			return ;
		}
		tree[u].m=tree[u].p+tree[u].r>>1;
		tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
		tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
		PushUp(u);
		return ;
	}

	inline void add(int u,int l,int r,int v)
	{
		if (tree[u].p==l&&tree[u].r==r)
		{
			Lazy(u,v);
			return ;
		}
		PushDown(u);
		if (r<=tree[u].m) add(u<<1,l,r,v);
		else if (tree[u].m<=l) add(u<<1|1,l,r,v);
		else
		{
			add(u<<1,l,tree[u].m,v);
			add(u<<1|1,tree[u].m,r,v);
		}
		PushUp(u);
		return ;
	}

	inline void changemin(int u,int l,int r,int v)
	{
		if (v>=tree[u].mx.m) return ;
		if (tree[u].p==l&&tree[u].r==r&&v>tree[u].mx.s){addmin(u,v);return ;}
		if (tree[u].p+1==tree[u].r) return ;
		PushDown(u);
		if (r<=tree[u].m) changemin(u<<1,l,r,v);
		else if (tree[u].m<=l) changemin(u<<1|1,l,r,v);
		else
		{
			changemin(u<<1,l,tree[u].m,v);
			changemin(u<<1|1,tree[u].m,r,v);
		}
		PushUp(u);
		return ;
	}

	inline void changemax(int u,int l,int r,int v)
	{
		if (v<=tree[u].mn.m) return ;
		if (tree[u].p==l&&tree[u].r==r&&v<tree[u].mn.s){addmax(u,v);return ;}
		if (tree[u].p+1==tree[u].r) return ;
		PushDown(u);
		if (r<=tree[u].m) changemax(u<<1,l,r,v);
		else if (tree[u].m<=l) changemax(u<<1|1,l,r,v);
		else
		{
			changemax(u<<1,l,tree[u].m,v);
			changemax(u<<1|1,tree[u].m,r,v);
		}
		PushUp(u);
		return ;
	}

	inline long long query(int u,int l,int r)
	{
		if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
		PushDown(u);
		if (r<=tree[u].m) return query(u<<1,l,r);
		else if (tree[u].m<=l) return query(u<<1|1,l,r);
		else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
	}

	inline int qmin(int u,int l,int r)
	{
		if (tree[u].p==l&&tree[u].r==r) return tree[u].mn.m;
		PushDown(u);
		if (r<=tree[u].m) return qmin(u<<1,l,r);
		else if (tree[u].m<=l) return qmin(u<<1|1,l,r);
		else return min(qmin(u<<1,l,tree[u].m),qmin(u<<1|1,tree[u].m,r));
	}

	inline int qmax(int u,int l,int r)
	{
		if (tree[u].p==l&&tree[u].r==r) return tree[u].mx.m;
		PushDown(u);
		if (r<=tree[u].m) return qmax(u<<1,l,r);
		else if (tree[u].m<=l) return qmax(u<<1|1,l,r);
		else return max(qmax(u<<1,l,tree[u].m),qmax(u<<1|1,tree[u].m,r));
	}

};

SegTBeats x,y;

int n,m;
set<int> s1,s2;
int xx[MAXN],yy[MAXN],dir[MAXN];
bool visx[MAXN],visy[MAXN];

void solve()
{
	s1.insert(0);s2.insert(0);
	R(n,m);
	x.tree[1].p=1;x.tree[1].r=m*2+1;x.BuildTree(1);
	y.tree[1].p=1;y.tree[1].r=m*2+1;y.BuildTree(1);
	vector<int> X,Y;
	X.pb(0);Y.pb(0);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char s[2];
		R(xx[i],yy[i],s);
		if(s[0]=='L')dir[i]=0;
		else dir[i]=1;
		X.pb(xx[i]);
		Y.pb(yy[i]);
	}
	UNI(X);UNI(Y);
	for(int i=1;i<=m;i++)
	{
		xx[i]=GETPOS(X,xx[i]);
		yy[i]=GETPOS(Y,yy[i]);
	}
	for(int i=1;i<=m;i++)
	{
		if(dir[i])
		{
			if(visx[xx[i]])
			{
				W(0);
				continue;
			}
			int u=x.qmax(1,xx[i],xx[i]+1);
			W(Y[yy[i]]-Y[u]);
			//W(u,xx[i],yy[i],"U");
			y.changemax(1,max(u,1),yy[i]+1,xx[i]);
			visx[xx[i]]=1;
		}
		else
		{
			if(visy[yy[i]])
			{
				W(0);
				continue;
			}
			int u=y.qmax(1,yy[i],yy[i]+1);
			W(X[xx[i]]-X[u]);
			//W(u,xx[i],yy[i],"L");
			x.changemax(1,max(u,1),xx[i]+1,yy[i]);
			visy[yy[i]]=1;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t=1;
	//R(t);
	while(t--)solve();
	return 0;
}