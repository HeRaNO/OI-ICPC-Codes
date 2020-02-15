#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,m,p[MAXN],q[MAXN];
string s[MAXN];
bool c[MAXN],pl[MAXN];
string ans,ansp,ansq,ansr;

inline bool isP(string s)
{
	for (int i=0;i<m;i++)
		if (s[i]!=s[m-i-1]) return false;
	return true;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		if (isP(s[i])) pl[i]=c[i]=true;
	}
	for (int i=1;i<=n;i++)
	{
		if (c[i]) continue;
		for (int j=i+1;j<=n;j++)
			if (!c[j])
			{
				bool f=true;
				for (int k=0;k<m;k++)
					if (s[i][k]!=s[j][m-k-1])
						f=false;
				if (f)
				{
					p[++p[0]]=i;
					q[++q[0]]=j;
					c[i]=c[j]=true;
				}
			}
	}
	for (int i=1;i<=p[0];i++)
	{
		ansp+=s[p[i]];
		ansq=s[q[i]]+ansq;
	}
	for (int i=1;i<=n;i++)
		if (pl[i])
		{
			ansr+=s[i];
			break;
		}
	ans=ansp+ansr+ansq;
	cout<<ans.size()<<'\n';
	cout<<ans<<'\n';
	return 0;
}