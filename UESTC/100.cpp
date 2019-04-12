#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,T,x;
vector <int> a;

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(T);
	for (int i=1;i<=n;i++){read(x);a.push_back(x);}
	sort(a.begin(),a.end());
	while (T--)
	{
		read(x);
		printf("%d\n",n-(lower_bound(a.begin(),a.end(),x)-a.begin()));
	}
	return 0;
}
