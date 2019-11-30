#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,sta[MAXN],allsta,f[27];
char s[55];
set <int> ans;

inline int getf(int x)
{
	return x==f[x]?x:f[x]=getf(f[x]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);int l=strlen(s);
		for (int j=0;j<l;j++) sta[i]|=(1<<(s[j]-'a'));
		allsta|=sta[i];
	}
	for (int j=1;j<=26;j++) if (allsta&(1<<(j-1))) f[j]=j;
	for (int i=1;i<=n;i++)
		for (int j=0;j<26;j++)
			for (int k=0;k<26;k++)
				if ((sta[i]&(1<<j))&&(sta[i]&(1<<k)))
				{
					int fx=getf(j+1),fy=getf(k+1);
					if (fx!=fy) f[fy]=fx;
				}
	for (int i=1;i<=26;i++) if (f[i]) ans.insert(getf(i));
	printf("%d\n",ans.size());
	return 0;
}