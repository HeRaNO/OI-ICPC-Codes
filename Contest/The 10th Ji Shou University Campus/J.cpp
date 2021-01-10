#include <bits/stdc++.h>
using namespace std;

inline bool ispri(int x)
{
	for (int i=2;i*i<=x;i++)
		if (!(x%i)) return false;
	return true;
}

vector <int> v;

int main()
{
	for (int i=10;i<=100;i++)
		if (ispri(i))
		{
			int x=i;bool f=true;int s=0;
			while (x&&f)
			{
				int p=x%10;
				if (!(p==2||p==3||p==5||p==7))
					f=false;
				s+=p;x/=10;
			}
			if (!f) continue;
			if (!ispri(s)) continue;
			v.push_back(i);
		}
	int n=v.size();
	printf("%d\n",n);
	for (int i=0;i<n;i++)
		printf("%d%c",v[i],i==n-1?'\n':' ');
	return 0;
}