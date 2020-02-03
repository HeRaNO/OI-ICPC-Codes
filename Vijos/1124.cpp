#include <map>
#include <queue>
#include <cstring>
#include <iostream>
#define MAXN 10
using namespace std;

struct trans
{
	string from, to;
};

trans p[MAXN];
string a, b;
int n = 1;
bool out = false;
queue <string> q;
map <string, int> ans;

inline void BFS()
{
	q.push(a);
	ans[a] = 0;
	while (!q.empty())
	{
		string u = q.front();
		q.pop();
		if (ans[u] > 10) return ;
		if (u == b)
		{
			cout << ans[u] << endl;
			out = true;
			return ;
		}
		for (int i = 1; i <= n; i++)
		{
			string now;
			int pos = u.find(p[i].from);
			while (pos != string::npos)
			{
				now = u;
				now.replace(pos, p[i].from.size(), p[i].to, 0, p[i].to.size());
				if (!ans.count(now))
				{
					ans[now] = ans[u] + 1;
					q.push(now);
				}
				pos = u.find(p[i].from, pos + 1);
			}
		}
	}
}

int main()
{
	cin >> a >> b;
	while (cin >> p[n].from >> p[n].to) n++;
	n--;
	BFS();
	if (!out) cout << "NO ANSWER!" << endl;
	return 0;
}
