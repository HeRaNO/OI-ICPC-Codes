#include <cstdio>
using namespace std;

int k;

int main()
{
	scanf("%d",&k);
	for (int x=k+1,p=(k<<1);x<=p;x++)
	{
		if ((x*k)%(x-k)) continue;
		printf("1/%d=1/%d+1/%d\n",k,x,(x*k)/(x-k));
	}
	return 0;
}