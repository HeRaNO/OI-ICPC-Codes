#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;

int T,o,x,t[MAXN*30][4],top,root;

inline void add(int x)
{
	int now=0;
	for (int i=29;~i;i--)
	{
		int p=x>>i&1;
		if (!~t[now][p])
		{
			t[top][0]=t[top][1]=-1;
			t[now][p]=top++;
		}
		++t[now][2+p];
		now=t[now][p];
	}
	return ;
}

inline void del(int x)
{
	int now=0;
	for (int i=29;~i;i--)
	{
		int p=x>>i&1,pre=now;
		now=t[now][p];
		if (t[pre][2+p]==1) t[pre][p]=-1;
		--t[pre][2+p];
	}
	return ;
}

inline pair<int,int> query(int x)
{
	int mx=0,mn=0,now=0;
	for (int i=29;~i;i--)
	{
		int p=x>>i&1;
		if (!~t[now][p]) mn|=(1<<i),now=t[now][p^1];
		else now=t[now][p];
	}
	now=0;
	for (int i=29;~i;i--)
	{
		int p=x>>i&1;
		if (~t[now][p^1]) mx|=(1<<i),now=t[now][p^1];
		else now=t[now][p];
	}
	return make_pair(mn,mx);
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	top=1;t[0][0]=-1;t[0][1]=-1;
	read(T);
	while (T--)
	{
		read(o);read(x);
		if (o==1) add(x);
		else if (o==2) del(x);
		else printf("%d %d\n",query(x).first,query(x).second);
	}
	return 0;
}