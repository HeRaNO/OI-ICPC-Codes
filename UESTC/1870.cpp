#include <cstdio>
using namespace std;

inline int rev(int p){int x=0;while (p){x=x*10+p%10;p/=10;}return x;}

int main()
{
	int l,r,ans=0;
	scanf("%d %d",&l,&r);
	for (int i=l;i<=r;i++) if (rev(i)==i) ++ans;
	printf("%d\n",ans);
	return 0;
}