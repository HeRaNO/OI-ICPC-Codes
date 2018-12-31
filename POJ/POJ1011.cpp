#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int sticks[70];
bool used[70];
int n, len;
bool flag = false;

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
				if (dfs(j, l, t))return true;
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
	//freopen("in.txt","r",stdin);
	while (true)
	{
		memset(sticks, 0, sizeof(sticks));
		memset(used, false, sizeof(used));
		int sum = 0;
		flag = false;
		scanf("%d", &n);
		if (n == 0) break;
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
					flag = true;
					break;
				}
			}
		}
		if (!flag) printf("%d\n", sum);
	}
	return 0;
}
