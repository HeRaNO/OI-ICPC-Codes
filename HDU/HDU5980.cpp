#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int ans;
unsigned int x;
template <class _E> inline void read(_E &e){
	e=0;bool ck=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ck=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){e=e*10+ch-'0';ch=getchar();}
	if(ck)e=-e;
}
long long num=97;

int main()
{
	while(scanf("%d",&n)==1)
	{
		ans=0;
		for(int i=1;i<=n;++i)
		{
			read(x);
			while (x)
			{
				if((x&255)==97) ++ans;
				x>>=8;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}