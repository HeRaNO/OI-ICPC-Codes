#include <cstdio>
#define MAXN 3000010
using namespace std;

int a[MAXN], q1[MAXN], q2[MAXN];
int head1, tail1, head2, tail2;
int ans, t, n, m;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

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

inline void Monotonous_Queue()
{
	head1 = head2 = 1;
	tail1 = tail2 = 0;
	t = 1;
	for (int i = 1; i <= n; i++)
	{
		while (head1 <= tail1 && a[i] <= a[q1[tail1]]) tail1--;
		while (head2 <= tail2 && a[i] >= a[q2[tail2]]) tail2--;
		q1[++tail1] = i;
		q2[++tail2] = i;
		while (a[q2[head2]] - a[q1[head1]] > m)
		{
			if (q2[head2] <= q1[head1]) t = q2[head2] + 1, head2++;
			else t = q1[head1] + 1, head1++;
		}
		ans = mymax(ans, i - t + 1);
	}
	return ;
}

int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	Monotonous_Queue();
	printf("%d\n", ans);
	return 0;
}
