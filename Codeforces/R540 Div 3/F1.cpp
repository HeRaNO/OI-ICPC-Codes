#include <bits/stdc++.h>
using namespace std;

struct link
{
	int to,nxt;
};

link e[600010];
int head[300010],cnt;
int n,a[300010],R,B,u,v,ans;

void add(int a,int b)
{
	e[cnt]=(link){b,head[a]};head[a]=cnt++;
	e[cnt]=(link){a,head[b]};head[b]=cnt++;
}

pair<int,int> TreeDP(int x,int f)
{
	int sr=0,sb=0;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			pair <int,int> s=TreeDP(e[i].to,x);
			sr+=s.first;sb+=s.second;
		}
	if (a[x]==1) sr++;
	else if (a[x]==2) sb++;
	if (sr==R&&!sb) ++ans;
	if (sb==B&&!sr) ++ans;
	return make_pair(sr,sb);
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==1) ++R;
		else if (a[i]==2) ++B;
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	TreeDP(1,0);printf("%d\n",ans);
	return 0;
}