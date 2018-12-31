#include <queue>
#include <cstdio>
#define MAXN 500010
using namespace std;

int n, A, B, x, a, b;
priority_queue <int> q;

int main()
{
	//freopen("dry.in","r",stdin);freopen("dry.out","w",stdout);
	scanf("%d %d %d", &n, &A, &B);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		q.push(x);
	}
	while (q.top() > a * A)
	{
		b = q.top();
		q.pop();
		b -= B;
		q.push(b);
		a++;
	}
	printf("%d\n", a);
	return 0;
}
