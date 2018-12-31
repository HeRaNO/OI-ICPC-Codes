//Code By HeRaNO
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string a;
	cin >> a;
	char g[7];
	for (int j = 0; j < a.size(); j++) g[j] = a[j];
	sort(g, g + a.size());
	do
	{
		for (int k = 0; k < a.size(); ++k) cout << g[k];
		cout << endl;
	}
	while (next_permutation(g, g + a.size()));
	return 0;
}
