#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

long long a,b;

int main()
{
	scanf("%lld %lld",&a,&b);
	if (a>b) return puts("-1"),0;
	if (!a&&!b) return puts("0"),0;
	if (a==b) return printf("1\n%lld\n",a),0;
	if ((b-a)&1) return puts("-1"),0;
	long long t=b-a;t>>=1;
	if (t&a) printf("3\n%lld %lld %lld\n",a,t,t);
	else printf("2\n%lld %lld\n",t|a,t);
	return 0;
}