#include <cstdio>
#include <cstring>
#define MAXN 200005

int n,top,cnt,rb;
char a[MAXN],sta[MAXN];

int main()
{
	scanf("%d",&n);
	if (n&1) return puts("No"),0;
	scanf("%s",a);
	for (int i=0;i<n;i++)
		if (a[i]=='(') ++cnt;
	if (cnt!=(n>>1)) return puts("No"),0;
	for (int i=0;i<n;i++)
	{
		if (a[i]=='(') sta[++top]='(';
		else
		{
			if (top) --top;
			else ++rb;
		}
	}
	puts(top<=1?"Yes":"No");
	return 0;
}