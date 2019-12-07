#include <bits/stdc++.h>
using namespace std;
int n;
const int N=300050;
char s[N*2];
inline int idx(char c){return c-'A'+1;}
struct segment{
	char c;
	int cnt;
}a[N*2];
int tot;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int now=0;
	for(int i=1;i<=n+1;++i)
	{
		if(s[i]!=s[i-1])
		{
			++tot;
			a[tot].c=s[i];
			a[tot-1].cnt=now;
			now=0;
		}
		now++;
	}
	tot--;
	if(tot%2==0)return puts("0"),0;
	int ii=tot/2,jj=tot/2+2;
	if(a[tot/2+1].cnt<2)return puts("0"),0;
	while(ii>0)
	{
		if(a[ii].cnt+a[jj].cnt<3)return puts("0"),0;
		if(a[ii].c!=a[jj].c)return puts("0"),0;
		ii--;
		jj++;
	}
	printf("%d\n",a[tot/2+1].cnt+1);
	return 0;
}