#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

int cnt[26],a[26],n,len,l,r;
char s[MAXN];

int main()
{
	scanf("%s",s);n=strlen(s);int t=0;
	for (int i=0;i<26;i++) scanf("%d",&cnt[i]);
	for (int i=0;i<26;i++) len+=cnt[i];
	if (!len) return puts("Yes"),0;
	l=0;r=len-1;
	for (int i=0;i<len;i++) ++a[s[i]-'a'];
	while (r<n)
	{
		bool f=true;
		for (int i=0;i<26&&f;i++)
			if (cnt[i]!=a[i]) f=false;
		if (f) return puts("Yes"),0;
		++r;
		if (r==n) break;
		++a[s[r]-'a'];
		--a[s[l]-'a'];
		++l;
	}
	puts("No");
	return 0;
}