#include <bits/stdc++.h>
using namespace std;

int n,p,q,r,a,b,c,ans;
multiset <int, greater<int> > s;
multiset <int, greater<int> > :: iterator it,pit;

inline bool del(int x)
{
	it=s.find(x);
	if (it!=s.end()){s.erase(it);return true;}
	s.insert(x);it=s.find(x);
	pit=it;++pit;
	if (pit!=s.end()) s.erase(pit);
	s.erase(it);
	return pit!=s.end();
}

int main()
{
	scanf("%d",&n);
	scanf("%d %d %d",&p,&q,&r);
	a=min(min(p,q),r);c=max(max(p,q),r);b=p+q+r-a-c;
	for (int i=1,x;i<=n;i++) scanf("%d",&x),s.insert(x);
	if (*s.begin()>a+b+c) return puts("-1"),0;
	for (;s.size();)
	{
		int now=*s.begin();
		if (now<=a)
		{
			ans+=(int)s.size()/3;
			if (s.size()%3) ++ans;
			break;
		}
		++ans;
		if (now<=b) del(a),del(b),del(c);
		else if (now<=c)
		{
			del(c);
			if (del(a)) del(b);
			else del(a+b);
		}
		else if (now<=a+b) del(a+b),del(c);
		else if (now<=a+c) del(a+c),del(b);
		else if (now<=b+c) del(b+c),del(a);
		else del(a+b+c);
	}
	printf("%d\n",ans);
	return 0;
}