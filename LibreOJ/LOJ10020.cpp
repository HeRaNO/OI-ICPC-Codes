#include <cstdio>
#include <algorithm>
using namespace std;

int sticks[61];
bool used[61];
int n, len;

bool dfs(int dep, int l, int t)
{
	if (l == 0)
	{
		t -= len;
		if (t == 0)return true;
		for (dep = 1; used[dep]; dep++);
		used[dep] = true;
		if (dfs(dep + 1, len - sticks[dep], t)) return true;
		used[dep] = false;
		t += len;
	}
	else
	{
		for (int j = dep; j <= n; j++)
		{
			if (j > 0 && (sticks[j] == sticks[j - 1] && !used[j - 1]))
				continue;
			if (!used[j] && l >= sticks[j])
			{
				l -= sticks[j];
				used[j] = true;
				if (dfs(j, l, t)) return true;
				l += sticks[j];
				used[j] = false;
				if (sticks[j] == l)
					break;
			}
		}
	}
	return false;
}

bool cmp(const int a, const int b)
{
	return a > b;
}

int main()
{
	//freopen("data.in","r",stdin);freopen("data.out","w",stdout);
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sticks[i]);
		sum += sticks[i];
		used[i] = 0;
	}
	sort(sticks + 1, sticks + n + 1, cmp);
	bool flag = false;
	for (len = sticks[1]; len <= sum / 2; len++)
	{
		if (sum % len == 0)
		{
			if (dfs(1, len, sum))
			{
				printf("%d\n", len);
				return 0;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}