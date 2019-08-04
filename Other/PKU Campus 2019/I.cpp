#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int n,num[MAXN],a[MAXN];

int main()
{
    int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int l=0,ans=0,cnt=0,maxp=0;
        for(int i=1;i<=n;i++)
        {
            num[a[i]]++;
            while(num[a[i]]>1)
            {
                l++;
                num[a[l]]--;
                if(maxp>=a[l]&&a[l]!=a[i])maxp=a[l]-1;
            }
            while(num[maxp+1])maxp++;
            ans=max(ans,maxp);
        }
        printf("%d\n",ans);
	}
	return 0;
}