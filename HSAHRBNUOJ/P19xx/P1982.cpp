#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100001;
int xiaoshu[maxn];
int i, j = 1, k;
int tongji[maxn + 100];
int zf = 0;
int a, b;
void print()
{
	if (zf == 76)
	{
		printf("\n");
		zf = 0;
	}
	zf++;
}
int main()
{
	cin >> a >> b;
	if (a % b == 0)
	{
		cout << a / b << ".0";
		return 0;
	}
	printf("%d.", a / b);
	print();
	int tmp = a / b;
	if (tmp == 0)
		print();
	else
	{
		while (tmp != 0)
		{
			print();
			tmp /= 10;
		}
	}//统计整数部分位数；
	a %= b;
	tongji[a] = 1;
	xiaoshu[j++] = a;
	for (i = 2;; i++)
	{
		a = (a * 10) % b;
		xiaoshu[j++] = a;
		if (tongji[a]) break;
		tongji[a] = i;
	}
	j--;
	for (i = 1; i < tongji[xiaoshu[j]]; i++)
	{
		print();
		printf("%d", (xiaoshu[i] * 10) / b);
	}//输出重复值之前的部分
	if ((xiaoshu[tongji[xiaoshu[j]]] * 10) / b == 0 && tongji[xiaoshu[j]] == j - 1) return 0; //重复值为0
	print();
	printf("(");
	for (i = tongji[xiaoshu[j]]; i < j; i++)
	{
		print();
		printf("%d", (xiaoshu[i] * 10) / b);
	}
	print();
	printf(")");
	return 0;
}
