#include <map>
#include <cstdio>
#define MAXN 200010
using namespace std;

int n, ans, JO, JI;
int J[MAXN], O[MAXN], I[MAXN];
char s[MAXN];
map <pair<int, int>, int> m;
map <pair<int, int>, int> :: iterator it;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	m.insert(make_pair(make_pair(0, 0), 0));
	for (int i = 1; i <= n; i++)
	{
		J[i] = J[i - 1] + (s[i] == 'J');
		O[i] = O[i - 1] + (s[i] == 'O');
		I[i] = I[i - 1] + (s[i] == 'I');
		JO = J[i] - O[i];
		JI = J[i] - I[i];
		it = m.find(make_pair(JO, JI));
		if (it != m.end()) ans = mymax(ans, i - it->second);
		m.insert(make_pair(make_pair(JO, JI), i));
	}
	printf("%d\n", ans);
	return 0;
}