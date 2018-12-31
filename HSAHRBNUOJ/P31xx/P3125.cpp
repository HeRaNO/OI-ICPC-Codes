#include <map>
#include <cstdio>
using namespace std;

long long n;
map <long long, bool> m;
map <long long, bool> :: iterator it;

void dfs(long long now)
{
	if (now * 9 >= n)
	{
		m.insert(make_pair(now, true));
		return ;
	}
	bool flag = true;
	for (long long i = 2; i <= 9 && flag; i++)
	{
		if (m.find(now * i) == m.end()) dfs(now * i);
		it = m.find(now * i);
		flag &= it->second;
	}
	m.insert(make_pair(now, !flag));
	return ;
}

int main()
{
	//freopen("winner.in","r",stdin);freopen("winner.out","w",stdout);
	scanf("%lld", &n);
	dfs(1);
	it = m.find(1);
	if (it->second) puts("Nic");
	else puts("Susan");
	return 0;
}
