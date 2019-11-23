#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[100050];
int b[100050];

inline bool can(int A,int B,int C)
{
	if(A+B>C&&B+C>A&&A+C>B)return true;
	else return false;
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		while(m--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(r-l+1<3)
			{
				puts("no");
				continue;
			}
			else if(r-l+1>=50)
			{
				puts("yes");
				continue;
			}
			else
			{
				for(int i=l;i<=r;++i)
				{
					b[i]=a[i];
				}
				sort(b+l,b+r+1);
				bool flag=false;
				for(int i=l;i<=r-2;++i)
				{
					if(can(b[i],b[i+1],b[i+2]))
					{
						flag=true;
						break;
					}
				}
				if(flag)puts("yes");
				else puts("no");
			}
		}
	}
	return 0;
}