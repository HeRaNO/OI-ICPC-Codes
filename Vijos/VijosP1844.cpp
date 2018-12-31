#include<iostream>
#include<cstdio>
using namespace std;
long n, count = 0;
int target[100001];
int main()
{
	//freopen("block.in","r",stdin);
	//freopen("block.out","w",stdout);
	int i;
	cin >> n;
	for (i = 1; i <= n; i++)
		scanf("%d", &target[i]);
	for (i = 1; i <= n; i++)
		if (target[i] > target[i - 1])
			count += target[i] - target[i - 1];
	cout << count;
	return 0;
}