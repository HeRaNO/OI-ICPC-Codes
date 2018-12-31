#include <iostream>
#include <cstdio>
using namespace std;

struct save
{
	int a;
	int b;
};

struct data
{
	int x;
	int y;
	int dataa;
};

int n;
bool map[2010][2010] = {true};
bool arrive[2010][2010];
char ch;
int i, j, head, tail;
save ship1, ship2;
data dat[10100000];

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> ch;
			map[i][j] = ch - '0';
		}
	cin >> ship1.a >> ship1.b >> ship2.a >> ship2.b;
	head = 0;
	tail = 1;
	dat[head].x = ship1.a;
	dat[head].y = ship1.b;
	while (true)
	{
		if (dat[head].x == ship2.a && dat[head].y == ship2.b)
			break;
		if (head == tail) break;
		if (dat[head].x - 1 > 0 && dat[head].y > 0)
			if (!map[dat[head].x - 1][dat[head].y] && !arrive[dat[head].x - 1][dat[head].y])
			{
				dat[tail].dataa = dat[head].dataa + 1;
				dat[tail].x = dat[head].x - 1;
				dat[tail].y = dat[head].y;
				arrive[dat[head].x - 1][dat[head].y] = true;
				tail++;
			}
		if (dat[head].x > 0 && dat[head].y - 1 > 0)
			if (!map[dat[head].x][dat[head].y - 1] && !arrive[dat[head].x][dat[head].y - 1])
			{
				dat[tail].dataa = dat[head].dataa + 1;
				dat[tail].x = dat[head].x;
				dat[tail].y = dat[head].y - 1;
				arrive[dat[head].x][dat[head].y - 1] = true;
				tail++;
			}
		if (dat[head].x + 1 > 0 && dat[head].y > 0)
			if (!map[dat[head].x + 1][dat[head].y] && !arrive[dat[head].x + 1][dat[head].y])
			{
				dat[tail].dataa = dat[head].dataa + 1;
				dat[tail].x = dat[head].x + 1;
				dat[tail].y = dat[head].y;
				arrive[dat[head].x + 1][dat[head].y] = true;
				tail++;
			}
		if (dat[head].x > 0 && dat[head].y + 1 > 0)
			if (!map[dat[head].x][dat[head].y + 1] && !arrive[dat[head].x][dat[head].y + 1])
			{
				dat[tail].dataa = dat[head].dataa + 1;
				dat[tail].x = dat[head].x;
				dat[tail].y = dat[head].y + 1;
				arrive[dat[head].x][dat[head].y + 1] = true;
				tail++;
			}
		head++;
	}
	cout << dat[head].dataa << endl;
	return 0;
}
