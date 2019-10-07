#include <bits/stdc++.h>
using namespace std;
int H[105],W[105];

void Init()
{
	freopen("kotlin.in","r",stdin);
	freopen("kotlin.out","w",stdout);
}
int h,w,n;

int main()
{
	Init();
	scanf("%d%d%d",&h,&w,&n);
	for(int hi=1;hi<=(h+1)/2;++hi)
	{
		for(int wi=1;wi<=(w+1)/2;++wi)
		{
			if(hi*wi==n)
			{
				for(int i=0;i<hi-1;++i)H[1+i*2]=1;
				for(int i=0;i<wi-1;++i)W[1+i*2]=1;
				for(int i=0;i<h;++i)
				{
					for(int j=0;j<w;++j)
					{
						if(H[i]||W[j])printf("#");
						else printf(".");
					}
					puts("");
				}
				return 0;
			}
		}
	}
	printf("Impossible");
	return 0;
}
