#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int> >q;
int n, m, x;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)q.push(0);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x), q.push(q.top() + x), q.pop();
	while (q.size() - 1)q.pop();
	printf("%d\n", q.top());
}