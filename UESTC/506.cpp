#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,T,p,q;char s[3];bool pos;

inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d %s",&a,&b,&c,&d,s);
		if (s[0]=='+'){p=a*d+b*c;q=b*d;}
		else if (s[0]=='-'){p=a*d-b*c;q=b*d;}
		else if (s[0]=='*'){p=a*c;q=b*d;}
		else{p=a*d;q=b*c;}
		if (p*q>0) pos=true;
		else pos=false;
		p=abs(p);q=abs(q);
		int t=gcd(p,q);p/=t;q/=t;
		if (!pos) p=-p;
		if (q==1) printf("%d/%d%s%d/%d=%d\n",a,b,s,c,d,p);
		else printf("%d/%d%s%d/%d=%d/%d\n",a,b,s,c,d,p,q);
	}
	return 0;
}
