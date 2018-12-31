#include <vector>
#include <cstring>
#include <iostream>
#define MAXN 1010
using namespace std;

struct file_system
{
	string name;
	vector <int> son;
	int son_cnt;
};

file_system tree[50000];
int n, ans, cnt, top;
string path, folder[MAXN];

void dfs(int node, int dep)
{
	bool have = false;
	if (dep == cnt) return ;
	for (int i = 0; i < tree[node].son.size(); i++)
	{
		if (tree[tree[node].son[i]].name == folder[dep])
		{
			have = true;
			dfs(tree[node].son[i], dep + 1);
		}
	}
	if (!have)
	{
		tree[node].son.push_back(++top);
		tree[top].name = folder[dep];
		ans++;
		dfs(top, dep + 1);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> path;
		int j = 0;
		cnt = 1;
		while (j < path.length())
		{
			j++;
			folder[cnt].clear();
			while (j < path.length() && path[j] != '/')
				folder[cnt].push_back(path[j++]);
			cnt++;
		}
		dfs(0, 1);
		printf("%d\n", ans);
	}
	return 0;
}
