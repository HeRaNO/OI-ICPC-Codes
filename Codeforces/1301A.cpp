#include <bits/stdc++.h>
using namespace std;

int T,n;
char a[105],b[105],c[105];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		bool f=false;
		scanf("%s",a);scanf("%s",b);scanf("%s",c);
		n=strlen(a);
		for (int i=0;i<n&&!f;i++)
			if (!((c[i]==a[i])||(c[i]==b[i])))
				f=true;
		if (f) puts("NO");
		else puts("YES");
	}
	return 0;
}