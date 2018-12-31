#include <cstdio>
#define MAXN 110
using namespace std;

int height[MAXN];
int n, c;

int work_1_1()
{
	return n;
}
int work_1_2()
{
	int ans = 0;
	for (int i = 1; i <= n - 3; i++)
		if (height[i] == height[i + 1] && height[i + 1] == height[i + 2] && height[i + 2] == height[i + 3])
			ans++;
	return ans;
}
int work_1()
{
	return work_1_1() + work_1_2();
}
//1
int work_2()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] == height[i + 1])
			ans++;
	return ans;
}
//2
int work_3_1()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] == height[i + 1] && height[i + 1] + 1 == height[i + 2])
			ans++;
	return ans;
}
int work_3_2()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] - 1 == height[i + 1])
			ans++;
	return ans;
}
int work_3()
{
	return work_3_1() + work_3_2();
}
//4
int work_4_1()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] == height[i + 1] + 1 && height[i + 1] == height[i + 2])
			ans++;
	return ans;
}
int work_4_2()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] + 1 == height[i + 1])
			ans++;
	return ans;
}
int work_4()
{
	return work_4_1() + work_4_2();
}
//5
int work_5_1()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] == height[i + 1] && height[i + 1] == height[i + 2])
			ans++;
	return ans;
}
int work_5_2()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] == height[i + 1] - 1)
			ans++;
	return ans;
}
int work_5_3()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] - 1 == height[i + 1] && height[i + 1] + 1 == height[i + 2])
			ans++;
	return ans;
}
int work_5_4()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] - 1 == height[i + 1])
			ans++;
	return ans;
}
int work_5()
{
	return work_5_1() + work_5_2() + work_5_3() + work_5_4();
}
//6
int work_6_1()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] == height[i + 1] && height[i + 1] == height[i + 2])
			ans++;
	return ans;
}
int work_6_2()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] == height[i + 1])
			ans++;
	return ans;
}
int work_6_3()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] + 1 == height[i + 1] && height[i + 1] == height[i + 2])
			ans++;
	return ans;
}
int work_6_4()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] - 2 == height[i + 1])
			ans++;
	return ans;
}
int work_6()
{
	return work_6_1() + work_6_2() + work_6_3() + work_6_4();
}
//7
int work_7_1()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] == height[i + 1] && height[i + 1] == height[i + 2])
			ans++;
	return ans;
}
int work_7_2()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] + 2 == height[i + 1])
			ans++;
	return ans;
}
int work_7_3()
{
	int ans = 0;
	for (int i = 1; i <= n - 2; i++)
		if (height[i] == height[i + 1] && height[i + 1] - 1 == height[i + 2])
			ans++;
	return ans;
}
int work_7_4()
{
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (height[i] == height[i + 1])
			ans++;
	return ans;
}
int work_7()
{
	return work_7_1() + work_7_2() + work_7_3() + work_7_4();
}
int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++)
		scanf("%d", &height[i]);
	if (c == 1) printf("%d\n", work_1());
	else if (c == 2) printf("%d\n", work_2());
	else if (c == 3) printf("%d\n", work_3());
	else if (c == 4) printf("%d\n", work_4());
	else if (c == 5) printf("%d\n", work_5());
	else if (c == 6) printf("%d\n", work_6());
	else printf("%d\n", work_7());
	return 0;
}
