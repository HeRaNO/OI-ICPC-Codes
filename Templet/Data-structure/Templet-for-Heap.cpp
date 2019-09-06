#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

inline void swap(int &x, int &y)
{
	int z = x;
	x = y;
	y = z;
	return ;
}

struct Small_Root_Heap
{
	int h[MAXN], _top;
	void push(int x)
	{
		h[++_top] = x;
		int t = _top;
		while (t > 1 && h[t]<h[t >> 1]) swap(h[t], h[t >> 1]), t >>= 1;
		return ;
	}
	void pop()
	{
		int t = 2;
		h[1] = h[_top];
		h[_top--] = 0;
		while (t <= _top)
		{
			if (h[t] > h[t + 1] && t < _top) t++;
			if (h[t]<h[t >> 1]) swap(h[t], h[t >> 1]), t <<= 1;
			else break;
		}
		return ;
	}
	int top()
	{
		return h[1];
	}
	bool empty()
	{
		return !_top;
	}
	void clear()
	{
		memset(h, 0, sizeof h);
		_top = 0;
		return ;
	}
};

struct Big_Root_Heap
{
	int h[MAXN], _top;
	void push(int x)
	{
		h[++_top] = x;
		int t = _top;
		while (t > 1 && h[t] > h[t >> 1]) swap(h[t], h[t >> 1]), t >>= 1;
		return ;
	}
	void pop()
	{
		int t = 2;
		h[1] = h[_top];
		h[_top--] = 0;
		while (t <= _top)
		{
			if (h[t] < h[t + 1] && t < _top) t++;
			if (h[t] > h[t >> 1]) swap(h[t], h[t >> 1]), t <<= 1;
			else break;
		}
		return ;
	}
	int top()
	{
		return h[1];
	}
	bool empty()
	{
		return !_top;
	}
	void clear()
	{
		memset(h, 0, sizeof h);
		_top = 0;
		return ;
	}
};


Small_Root_Heap q;
Big_Root_Heap r;

int n;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int main()
{
	clock_t st, ed;
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	st = clock();
	n = read();
	for (int i = 1; i <= n; i++) r.push(read());
	while (!r.empty())
	{
		printf("%d\n", r.top());
		r.pop();
	}
	ed = clock();
	printf("%lf\n", (double)(ed - st) / CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
