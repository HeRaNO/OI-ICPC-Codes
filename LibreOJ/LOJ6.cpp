#include "interaction.h"
using namespace std;

vector <int> ans;

inline int Binary(int index)
{
	int l = 0, r = 1000000, mid, res;
	while (l <= r)
	{
		mid = l + r >> 1;
		res = guess(index, mid);
		if (res > 0) r = mid - 1;
		else if (!res) return mid;
		else l = mid + 1;
	}
	return l;
}

int main()
{
	int n = get_num();
	for (int i = 0; i < n; i++) ans.push_back(Binary(i));
	submit(ans);
	return 0;
}