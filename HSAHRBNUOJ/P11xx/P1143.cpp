#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10010
using namespace std;

int n;
string a[MAXN];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) cout << a[i] << '\n';
	return 0;
}