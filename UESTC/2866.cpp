#include <set>
#include <cstdio>
#include <cassert>
#define MAXN 300010
using namespace std;

int n,T,l,r,x,opt,top,a[MAXN],sta[MAXN][3];
set <int> s;
set <int> :: iterator it;

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='A'){x=0;return ;}
		if (ch=='B'){x=1;return ;}
		if (ch=='C'){x=2;return ;}
		if (ch=='-') f=true;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	//freopen("bounce.in","r",stdin);freopen("bounce.out","w",stdout);
	read(n);read(T);s.insert(1);s.insert(n+1);
	a[1]=2'100'000'000;a[n+1]=-2'100'000'000;
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(l);read(r);read(x);++r;
			a[l]+=x;a[r]-=x;
			it=s.find(l);
			if (a[l]==0&&it!=s.end()) s.erase(it);
			if (a[l]!=0&&it==s.end()) s.insert(l);
			it=s.find(r);
			if (a[r]==0&&it!=s.end()) s.erase(it);
			if (a[r]!=0&&it==s.end()) s.insert(r);
			sta[++top][0]=l;sta[top][1]=r;sta[top][2]=x;
		}
		else if (opt==1)
		{
			read(x);it=s.find(x);
			if (it!=s.end())
			{
				l=*it;++it;
				assert(it!=s.end());
				r=*it;
			}
			else
			{
				s.insert(x);it=s.find(x);
				assert(it!=s.begin());
				--it;
				l=*it;
				++it;
				++it;
				assert(it!=s.end());
				r=*it;
				--it;s.erase(it);
			}
			assert(l<=x&&x<r);
			printf("%d %d\n",l,r-1);
		}
		else
		{
			l=sta[top][0];r=sta[top][1];x=sta[top--][2];
			a[l]-=x;a[r]+=x;
			it=s.find(l);
			if (a[l]==0&&it!=s.end()) s.erase(it);
			if (a[l]!=0&&it==s.end()) s.insert(l);
			it=s.find(r);
			if (a[r]==0&&it!=s.end()) s.erase(it);
			if (a[r]!=0&&it==s.end()) s.insert(r);
		}
	}
	return 0;
}