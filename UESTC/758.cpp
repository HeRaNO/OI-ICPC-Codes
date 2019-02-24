#include <cstdio>
#define MAXN 100010

int T,x,y,n;
char a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		bool f=false;
		scanf("%d %d %d",&x,&y,&n);
		scanf("%s",a);
		for (int i=0;i<n&&!f;i++)
		{
			if (!x&&!y)
			{
				printf("%d\n",i);f=true;
			}
			if (a[i]=='U'&&y>0) --y;
			if (a[i]=='D'&&y<0) ++y;
			if (a[i]=='R'&&x>0) --x;
			if (a[i]=='L'&&x<0) ++x;
		}
		if (!f) puts("-1");
	}
	return 0;
}