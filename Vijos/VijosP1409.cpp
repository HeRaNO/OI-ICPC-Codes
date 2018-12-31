#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 30005;
int main()
{
	int maxWeight, count;
	int weight[maxn];
	scanf("%d%d", &maxWeight, &count);
	for (int i = 0; i < count; i++) scanf("%d", &weight[i]);
	sort(weight, weight + count, greater<int>());
	int head = 0, tail = count - 1;
	int ans = 0;
	while (head < tail)
	{
		if (weight[head] + weight[tail] <= maxWeight) tail--;
		head++;
		ans++;
	}
	if (head == tail) ans++;
	printf("%d", ans);
	return 0;
}
