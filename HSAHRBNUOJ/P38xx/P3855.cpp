#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 110
#define NO_FA puts("No parent directory!");
#define NO_S puts("No such directory!");
#define NO_FI puts("No such file!");
#define D_EXIST puts("Directory already exists!");
#define F_EXIST puts("File already exists!");
using namespace std;

struct file_system
{
	int father;
	map <string, int> file;
	map <string, pair<int, int> > dir;
	map <int, pair<string, bool> > q;
	//dir-false file-true
};

file_system tree[MAXN];
int T, R, top, now;
string opt, name;
map <string, pair<int, int> > :: iterator it;
map <string, int> :: iterator fit;
map <int, pair<string, bool> > :: iterator qit;

inline void cd(string name)
{
	if (name == "..")
	{
		if (!~tree[now].father) NO_FA
			else now = tree[now].father;
		return ;
	}
	it = tree[now].dir.find(name);
	if (it == tree[now].dir.end()) NO_S
		else now = it->second.first;
	return ;
}

inline void touch(string name)
{
	fit = tree[now].file.find(name);
	if (fit == tree[now].file.end())
	{
		tree[now].file.insert(make_pair(name, ++R));
		tree[now].q.insert(make_pair(R, make_pair(name, true)));
	}
	else F_EXIST
		return ;
}

inline void rm(string name)
{
	fit = tree[now].file.find(name);
	if (fit != tree[now].file.end())
	{
		int x = fit->second;
		tree[now].file.erase(fit);
		qit = tree[now].q.find(x);
		tree[now].q.erase(qit);
	}
	else NO_FI
		return ;
}

inline void mkdir(string name)
{
	it = tree[now].dir.find(name);
	if (it != tree[now].dir.end()) D_EXIST
		else
		{
			top++;
			tree[now].dir.insert(make_pair(name, make_pair(top, ++R)));
			tree[now].q.insert(make_pair(R, make_pair(name, false)));
			tree[top].father = now;
		}
	return ;
}

inline void rmdir(string name)
{
	it = tree[now].dir.find(name);
	if (it == tree[now].dir.end()) NO_S
		else
		{
			int x = it->second.second;
			tree[now].dir.erase(it);
			qit = tree[now].q.find(x);
			tree[now].q.erase(qit);
		}
	return ;
}

inline void ls()
{
	for (qit = tree[now].q.begin(); qit != tree[now].q.end(); qit++)
	{
		cout << qit->second.first << " ";
		if (!qit->second.second) cout << "<D>" << endl;
		else cout << "<F>" << endl;
	}
	return ;
}

int main()
{
	//freopen("nacumegu.in","r",stdin);freopen("nacumegu.out","w",stdout);
	tree[0].father = -1;
	cin >> T;
	while (T--)
	{
		cin >> opt;
		if (opt == "ls") ls();
		else
		{
			cin >> name;
			if (opt == "cd") cd(name);
			else if (opt == "touch") touch(name);
			else if (opt == "rm") rm(name);
			else if (opt == "mkdir") mkdir(name);
			else rmdir(name);
		}
	}
	return 0;
}
