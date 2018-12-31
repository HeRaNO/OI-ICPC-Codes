#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int mi2[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}, full = 1023;
int m, n, ans;
__attribute__((__optimize__("-O2"))) struct matrix
{
	int arr[10], dep;
	__attribute__((__optimize__("-O2"))) bool operator<(const matrix &b)const
	{
		for (int i = 0; i < m; i++)
			if (arr[i] < b.arr[i]) return true;
			else if (arr[i] > b.arr[i]) return false;
		return false;
	}
	__attribute__((__optimize__("-O2"))) matrix()
	{
		memset(arr, 0, sizeof arr);
		dep = 0;
	}
} st, en;
set<matrix> S1, S2;
set<matrix>::iterator it;
queue<matrix> Q1, Q2;
__attribute__((__optimize__("-O2"))) void swap(int &x, int a, int b)
{
	int t1 = x & mi2[a], t2 = x & mi2[b];
	(x &= full - mi2[a]) &= full - mi2[b];
	if (t1) x |= mi2[b];
	if (t2) x |= mi2[a];
}
__attribute__((__optimize__("-O2"))) matrix cc(matrix x, int a, int b)
{
	for (int i = 0; i < m; i++)
		swap(x.arr[i], a, b);
	x.dep++;
	return x;
}
__attribute__((__optimize__("-O2"))) matrix rc(matrix x, int a)
{
	int arr[10];
	for (int i = 0; i < m; i++)
		arr[i] = x.arr[i] & mi2[a];
	for (int i = 0; i < m; i++)
		(x.arr[i] &= full - mi2[a]) |= arr[m - i - 1];
	x.dep++;
	return x;
}
__attribute__((__optimize__("-O2"))) matrix cr(matrix x, int a, int b)
{
	swap(x.arr[a], x.arr[b]);
	x.dep++;
	return x;
}
__attribute__((__optimize__("-O2"))) matrix rr(matrix x, int a)
{
	bool arr[10];
	for (int i = 0; i < n; i++)
		arr[i] = x.arr[a] & mi2[i];
	x.arr[a] = 0;
	for (int i = 0; i < n; i++)
		if (arr[i])
			x.arr[a] |= mi2[n - i - 1];
	x.dep++;
	return x;
}
__attribute__((__optimize__("-O2"))) int input(matrix &x)
{
	char t[11];
	int ret = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%s", t);
		x.arr[i] = 0;
		for (int j = 0; j < n; j++)
			(x.arr[i] <<= 1) |= t[j] - '0', ret += t[j] - '0';
	}
	return ret;
}
__attribute__((__optimize__("-O2"))) bool ins(const matrix &x, set<matrix> &toins, set<matrix> &toans, queue<matrix> &toque)
{
	it = toans.find(x);
	if (it != toans.end())
	{
		ans = it->dep + x.dep;
		return true;
	}
	it = toins.find(x);
	if (it == toins.end())
		toins.insert(x), toque.push(x);
	return false;
}
__attribute__((__optimize__("-O2"))) bool judge(set<matrix> &toins, set<matrix> &toans, queue<matrix> &toque)
{
	int dep = toque.front().dep;
	matrix w;
	while (toque.front().dep == dep)
	{
		w = toque.front();
		toque.pop();
		for (int i = 0; i < m; i++)
		{
			if (ins(rr(w, i), toins, toans, toque)) return true;
			for (int j = i + 1; j < m; j++)
				if (ins(cr(w, i, j), toins, toans, toque)) return true;
		}
		for (int i = 0; i < n; i++)
		{
			if (ins(rc(w, i), toins, toans, toque)) return true;
			for (int j = i + 1; j < n; j++)
				if (ins(cc(w, i, j), toins, toans, toque)) return true;
		}
	}
	return false;
}
__attribute__((__optimize__("-O2"))) void bfs()
{
	while (!Q1.empty()) Q1.pop();
	while (!Q2.empty()) Q2.pop();
	S1.clear();
	S2.clear();
	Q1.push(st);
	Q2.push(en);
	S1.insert(st);
	S2.insert(en);
	while (!Q1.empty() && !Q2.empty())
	{
		if (judge(S1, S2, Q1)) return;
		if (judge(S2, S1, Q2)) return;
	}
}
__attribute__((__optimize__("-O2"))) int main()
{
	while (~scanf("%d %d", &m, &n))
	{
		ans = -1;
		if (input(st) != input(en))
		{
			puts("No solution!");
			continue;
		}
		bfs();
		if (~ans)
			printf("%d\n", ans);
		else
			puts("No sulution!");
	}
	return 0;
}
