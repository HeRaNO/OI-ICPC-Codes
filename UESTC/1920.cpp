#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

set <pair<int, string> > a;
map <string, int> b;
int n, x, o;
string name;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> name >> x;
			if (b[name]) continue;
			a.insert(mp(x, name));
			b[name] = x;
		}
		else if (o == 2)
		{
			cin >> name;
			if (!b[name]) continue;
			a.erase(mp(b[name], name));
			b[name] = 0;
		}
		else if (o == 3)
		{
			cin >> name >> x;
			if (!b[name]) continue;
			a.erase(mp(b[name], name));
			a.insert(mp(x, name));
			b[name] = x;
		}
		else
		{
			cin >> x;
			if (a.empty()) continue;
			if (x == 1) cout << a.begin()->second << '\n';
			else cout << a.rbegin()->second << '\n';
		}
	}
	return 0;
}