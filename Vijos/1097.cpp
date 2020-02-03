#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int n, ans = 0;
int main()
{
	scanf("%d", &n);
	for (int x, i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		q.push(x);
	}
	while (--n)
	{
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	printf("%d", ans);
}
