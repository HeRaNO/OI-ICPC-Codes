#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, tmp;
int dice[7] = {0, 1, 2, 3, 4, 5, 6};
string flag;
int ans = 1;

int main()
{
	//freopen("dice.in","r",stdin);freopen("dice.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin.clear();
		cin >> flag;
		if (flag == "North")
		{
			tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;
		}
		else if (flag == "South")
		{
			tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
		}
		else if (flag == "East")
		{
			tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
		}
		else if (flag == "West")
		{
			tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
		}
		else if (flag == "Left")
		{
			tmp = dice[2];
			dice[2] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[3];
			dice[3] = tmp;
		}
		else
		{
			tmp = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[4];
			dice[4] = tmp;
		}
		ans += dice[1];
	}
	printf("%d\n", ans);
	return 0;
}
