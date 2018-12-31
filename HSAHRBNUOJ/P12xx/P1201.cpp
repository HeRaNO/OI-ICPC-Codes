#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 150000
using namespace std;

string a[MAXN];
int n, b[MAXN];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) cout << a[i] << " " << b[i] << '\n';
	return 0;
}