#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, i, j, maxlength = 0, len1, len2;
int tmp;
char word[25][21];
int num[21], map[21][21] = {0};
char a;

int dfs(int dep)
{
	int temp, maxlen = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		temp = 0;
		if (map[dep][i] && num[i])
		{
			flag = true;
			num[i]--;
			temp = dfs(i);
			num[i]++;
			temp += strlen(word[dep]) - map[dep][i];
		}
		if (temp > maxlen) maxlen = temp;
	}
	if (!flag) return strlen(word[dep]);
	else return maxlen;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> word[i];
		num[i] = 2;
	}
	cin >> a;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			len1 = strlen(word[i]);
			len2 = strlen(word[j]);
			for (int k = 0; k < len1 && k < len2; k++)
			{
				if (strncmp(word[i] + len1 - k - 1, word[j], k + 1) == 0)
				{
					map[i][j] = k + 1;
					break;
				}
			}
		}
	for (i = 1; i <= n; i++)
	{
		if (word[i][0] == a)
		{
			num[i]--;
			tmp = dfs(i);
			if (tmp > maxlength) maxlength = tmp;
			num[i]++;
		}
	}
	cout << maxlength << endl;
	return 0;
}
