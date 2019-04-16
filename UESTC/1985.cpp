#include <map>
#include <cstdio>
using namespace std;

long long a,b,c,d,ans;
map <long long,int> s;

int main()
{
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	for (long long i=1;i<=1000;i++)
		for (long long j=1;j<=1000;j++)
			s[a*i*i+b*j*j]+=1;
	for (long long i=1;i<=1000;i++)
		for (long long j=1;j<=1000;j++)
			ans+=s[-c*i*i-d*j*j];
	printf("%lld\n",ans<<4);
	return 0;
}