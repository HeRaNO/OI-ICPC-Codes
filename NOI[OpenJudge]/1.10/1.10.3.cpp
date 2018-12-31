//Code By HeRaNO
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 50
using namespace std;

struct student
{
	string name;
	int score;
};

int n;
student a[MAXN];

bool cmp(student a, student b)
{
	if (a.score == b.score) return a.name < b.name;
	else return a.score > b.score;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].name >> a[i].score;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		cout << a[i].name << " " << a[i].score << endl;
	return 0;
}
