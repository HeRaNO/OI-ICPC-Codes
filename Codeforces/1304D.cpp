#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,p[MAXN];
char s[MAXN];
vector <int> pos;

inline void getMin()
{
	for (int i=1;i<=n;i++) p[i]=0;
	int pt=n;
	for (int i=2;i<=n;i++)
		if (s[i]=='<'&&s[i+1]!='<')
		{
			for (int j=i;s[j]=='<';j--)
				p[j]=pt--;
		}
	for (int i=1;i<=n;i++) if (!p[i]) p[i]=pt--;
	for (int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
	return ;
}

void getMax()
{
	for (int i=1;i<=n;i++) p[i]=0;
	pos.clear();pos.push_back(1);
	for (int i=2;i<=n;++i) if (s[i]=='<') pos.push_back(i);
	pos.push_back(n+1);
	int pt=n-pos.size()+2;
	for (int i=1;i<(int)pos.size();++i)
	{
		int pt=pos[i];
		for (int j=pos[i-1];j<pos[i];++j) p[j]=--pt;
	}
	for (int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
	return ;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);scanf("%s",s+2);
		getMin();getMax();
	}
	return 0;
}
