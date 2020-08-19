#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<cstring>
#include<stack>
using namespace std;
const int N=2000005;

int n,m,q,ans[N];

int t[N];
inline int lowbit(int x){return x&(-x);}
void add(int i,int p) {for (;i<=m;i+=lowbit(i)) t[i]+=p;}
int sum(int i){int ans=0;for (;i;i-=lowbit(i)) ans+=t[i];return ans;}

struct aa
{
	int a,b,id;
	bool operator <(const aa &c) const 
	{
		return b<c.b;
	}
}Q[N],bian[N];

int fa[N],ch[N][2],rev[N],val[N],mi[N],id[N],ql[N],qr[N];
stack<int> s;
bool isroot(int x)
{
	return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}
void up(int x)
{
	mi[x]=val[x],id[x]=x;
	if (ch[x][0]&&mi[ch[x][0]]<mi[x]) mi[x]=mi[ch[x][0]],id[x]=id[ch[x][0]];
	if (ch[x][1]&&mi[ch[x][1]]<mi[x]) mi[x]=mi[ch[x][1]],id[x]=id[ch[x][1]];
}
void down(int x)
{
	if (rev[x])
	{
		rev[x]^=1,rev[ch[x][0]]^=1,rev[ch[x][1]]^=1;
		swap(ch[x][0],ch[x][1]);
	}
}
void rot(int x)
{
	int y=fa[x],z=fa[y],l,r;
	if (ch[y][0]==x) l=0;else l=1;r=l^1;
	if (!isroot(y))
		if (ch[z][0]==y) ch[z][0]=x;else ch[z][1]=x;
	fa[x]=z,fa[y]=x,fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r],ch[x][r]=y;
	up(y);
}
void splay(int x)
{
	int y=x,z;
	while (!isroot(y)) s.push(y),y=fa[y];s.push(y);
	while (!s.empty()) down(s.top()),s.pop();
	
	while (!isroot(x))
	{
		y=fa[x],z=fa[y];
		if (!isroot(y))
		if (ch[y][0]==x^ch[z][0]==y) rot(x);else rot(y);
		rot(x);
	}
	up(x);
}
void access(int x)
{
	int t=0;
	while (x)
	{
		splay(x);down(x);
		ch[x][1]=t;up(x);
		t=x,x=fa[x];
	}
}
int find(int x)
{
	access(x),splay(x);
	while (ch[x][0]) x=ch[x][0];
	return x;
}
void to_rt(int x)
{
	access(x),splay(x),rev[x]^=1;
}
void link(int x,int y)
{
	to_rt(x),fa[x]=y;
}
void cut(int x,int y)
{
	to_rt(x),access(y),splay(y);ch[y][0]=fa[x]=0;up(y);
}
int find_mi(int u,int v)
{
	to_rt(u),access(v),splay(v);
	return id[v];
}
void addedge(int ii)
{
	int u=bian[ii].a,v=bian[ii].b,fu,fv;
	if (u==v) return ;
	fu=find(u),fv=find(v);
	add(ii,1);
	if (fu!=fv) 
	{
		link(u,n+ii);
		link(v,n+ii);
		return ;
	}
	int pos=find_mi(u,v)-n;
	add(pos,-1);
	cut(pos+n,bian[pos].a);
	cut(pos+n,bian[pos].b);
	link(ii+n,u);
	link(ii+n,v);
}
void clear()
{
	for (int i=0;i<=m+5;i++) t[i]=0;
	for (int i=0;i<=n+m+5;i++) fa[i]=ch[i][0]=ch[i][1]=rev[i]=id[i]=mi[i]=0;
}
const int SIZ =150000000+3;
char buf1[SIZ];
char *p1=buf1,*p2=buf1;
inline char readchar()
{
    if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);
    return p1==p2?EOF:*p1++;
}
inline void read(int &ret)
{
    int c;ret=0;
    while((c=readchar())> '9'|c< '0');ret=c-'0';
    while((c=readchar())>='0'&&c<='9')ret=ret*10+c-'0';
    return ;
}
int main()
{
	int T,x,y;
	read(T);
	while (T--)
	{	
		read(n);read(m);read(q);
		for (int i=0;i<=n+5;i++) mi[i]=val[i]=1e9,id[i]=i;
		for (int i=1;i<=m;i++)
		{
			read(bian[i].a);read(bian[i].b);
			mi[i+n]=val[n+i]=i,id[i+n]=i+n;
		}
		for (int i=1,l,r;i<=q;i++)
		{
			read(l);read(r);
			ql[i]=l%m+1;qr[i]=r%m+1;
			if (ql[i]>qr[i]) swap(ql[i],qr[i]);
			Q[i]={ql[i],qr[i],i};
			ql[i+q]=(l^1)%m+1;qr[i+q]=(r^1)%m+1;
			if (ql[i+q]>qr[i+q]) swap(ql[i+q],qr[i+q]);
			Q[i+q]={ql[i+q],qr[i+q],i+q};
		}
		q<<=1;
		sort(Q+1,Q+q+1);
		int j=1;
		for (int i=1;i<=m;i++)
		{
			addedge(i);
			for (;Q[j].b==i;j++)
				ans[Q[j].id]=n-(sum(m)-sum(Q[j].a-1));
		}
		int las=0;
		q>>=1;
		for (int i=1;i<=q;i++)
		{
			int l,r,cnt;
			if (!las)
			{
				l=ql[i];r=qr[i];cnt=ans[i];
			}
			else
			{
				l=ql[i+q];r=qr[i+q];cnt=ans[i+q];
			}
			if (r-l+1<n-cnt+1)
			{
				puts("No");las=0;
			}
			else
			{
				puts("Yes");las=1;
			}
		}
		clear();
	}
	return 0;
}
