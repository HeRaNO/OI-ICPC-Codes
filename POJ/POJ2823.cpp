#include <cstdio>
#include <cstring>
#define MAXN 1000010
#define DOWN 0
#define UP 1
using namespace std;

struct Monotonous_Queue
{
	int q[MAXN], head, tail;
	Monotonous_Queue(): head(1), tail(0) {}
	bool empty()
	{
		return head > tail;
	}
	int front()
	{
		return q[head];
	}
	void push(int x, int w);
	void pop()
	{
		head++;
		return ;
	}
	int getlower(int l, int r, int x);
	int getupper(int l, int r, int x);
};

Monotonous_Queue Q[2];
int n, k;
int a[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

int Monotonous_Queue::getlower(int l, int r, int x)
{
	int mid;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (a[q[mid]] < x) l = mid + 1;
		else if (a[q[mid]] >= x) r = mid - 1;
	}
	return r;
}

int Monotonous_Queue::getupper(int l, int r, int x)
{
	int res = r + 1, mid;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (x > a[q[mid]]) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	return res - 1;
}

void Monotonous_Queue::push(int x, int w)
{
	if (!w)
	{
		//if (!empty()) tail=getupper(head,tail,a[x]);
		while (!empty() && a[q[tail]] <= a[x]) tail--;
		q[++tail] = x;
	}
	else
	{
		//if (!empty()) tail=getlower(head,tail,a[x]);
		while (!empty() && a[q[tail]] >= a[x]) tail--;
		q[++tail] = x;
	}
	return ;
}

inline void Sliding_Window(int W)
{
	for (int i = 1; i <= mymin(k, n); i++) Q[W].push(i, W);
	printf("%d", a[Q[W].front()]);
	for (int i = mymin(k, n) + 1; i <= n; i++)
	{
		while (!Q[W].empty() && Q[W].front() <= i - k) Q[W].pop();
		Q[W].push(i, W);
		printf(" %d", a[Q[W].front()]);
	}
	puts("");
	return ;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	Sliding_Window(UP);
	Sliding_Window(DOWN);
	return 0;
}
