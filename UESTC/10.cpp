#include <cstdio>
#include <cstring>
#define MAXN 1000010

int n,T,tp,ans,c,p[MAXN];
char a[MAXN];

bool ok(char a,char b)
{
	if (a=='('&&b==')') return true;
	if (a=='['&&b==']') return true;
	if (a=='{'&&b=='}') return true;
	return false;
}

inline void max(int &a,int b){if (a<b) a=b;return ;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		++c;int l=0,now=0;
		scanf("%s",a);n=strlen(a);tp=0;ans=0;
		for (int i=0;i<n;i++)
		{
			if (a[i]=='('||a[i]=='['||a[i]=='{')
				p[++tp]=i;
			else
			{
				if (!tp)
				{
					now+=l;max(ans,now);l=0;now=0;continue;
				}
				if (ok(a[p[tp]],a[i]))
				{
					++l;++l;--tp;
					if (!tp)
					{
						now+=l;max(ans,now);l=0;
					}
				}
				else
				{
					tp=0;max(ans,l);l=0;now=0;
				}
			}
		}
		if (!ans) printf("Case #%d: I think H is wrong!\n",c);
		else printf("Case #%d: %d\n",c,ans);
	}
	return 0;
}