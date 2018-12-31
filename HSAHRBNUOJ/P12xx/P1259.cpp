#include <iostream>
#include <cstdio>
using namespace std;

int dat[201];
bool arrive[201];
int ans[201];
int i, j, n, a, b;
int toFloor[201];
int head, tail, up, down;
bool flag;

int main()
{
	cin >> n >> a >> b;
	for (i = 1; i <= n; i++)
		scanf("%d", &toFloor[i]);
	if (a == b)
	{
		printf("0\n");
		return 0;
	}
	head = 0;
	tail = 1;
	dat[head] = a;
	while (true)
	{
		if (dat[head] == b)
			break;
		if (head == tail)
		{
			flag = true;
			break;
		}
		up = dat[head] + toFloor[dat[head]];
		down = dat[head] - toFloor[dat[head]];
		if (up <= n && !arrive[up])
		{
			dat[tail] = up;
			tail++;
			ans[tail - 1] = ans[head] + 1;
			arrive[up] = true;
		}
		if (down >= 1 && !arrive[down])
		{
			dat[tail] = down;
			tail++;
			ans[tail - 1] = ans[head] + 1;
			arrive[down] = true;
		}
		head++;
	}
	if (flag) cout << -1 << endl;
	else cout << ans[head] << endl;
	return 0;
}
