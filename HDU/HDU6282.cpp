#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int n,m,aa,ba,ab,bb,ac,bc;
char a[MAXN],b[MAXN];

int main()
{
	while (~scanf("%s",&a))
	{
		scanf("%s",&b);aa=ba=ab=bb=ac=bc=0;
		n=strlen(a);m=strlen(b);
		for (int i=0;i<n;i++) if (a[i]=='c') ++ac;a[n]='c';
		for (int i=0;i<m;i++) if (b[i]=='c') ++bc;b[m]='c';
		if (ac!=bc){puts("No");continue;}
		int i=0,j=0;bool f=true;
		while (i<=n&&j<=m&&f)
		{
			for (;i<=n&&a[i]!='c';i++)
				if (a[i]=='a') ++aa;
				else ++ab;
			for (;j<=m&&b[j]!='c';j++)
				if (b[j]=='a') ++ba;
				else ++bb;
			++i;++j;
			if ((aa&1)^(ba&1)) f=false;
			if ((ab&1)^(bb&1)) f=false;
			aa=0;ab=0;ba=0;bb=0;
		}
		puts(f?"Yes":"No");
	}
	return 0;
}