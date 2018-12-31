#include <vector>
#include <cstdio>
using namespace std;

vector <int> num, best;
int n, tmp, len, len1, t;

int main()
{
	//freopen("palindromes.in","r",stdin);freopen("palindromes.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= 100000; i++) best.push_back(9);
	len = best.size() << 1 - 1;
	for (int i = 9; ~i; i--)
	{
		num.clear();
		tmp = n - i;
		if (tmp < 0) continue;
		if (tmp % 2 != 0) continue;
		tmp >>= 1;
		num.push_back(i);
		while (tmp >= 9)
		{
			num.push_back(9);
			tmp -= 9;
		}
		if (tmp) num.push_back(tmp);
		if (i == 9)
		{
			t = i;
			best = num;
			num.clear();
			len = best.size() << 1 - 1;
		}
		else
		{
			len1 = num.size() << 1 - 1;
			if (!i) len1--;
			if (len1 < len)
			{
				t = i;
				len = len1;
				best = num;
			}
		}
	}
	if (t)
	{
		for (int i = best.size() - 1; ~i; i--) printf("%d", best[i]);
		for (int i = 1; i < best.size(); i++) printf("%d", best[i]);
	}
	else
	{
		for (int i = best.size() - 1; i; i--) printf("%d", best[i]);
		for (int i = 1; i < best.size(); i++) printf("%d", best[i]);
	}
	puts("");
	return 0;
}
