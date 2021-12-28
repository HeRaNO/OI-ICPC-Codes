//Just a sample
#include <cstdio>
using namespace std;

bool check(int limit)
{
	//
}

inline int binary(int left, int right)
{
	int middle;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (check(left)) left = middle;
		else right = middle;
	}
	return left;
}

inline int Trisection(int left, int right)
{
	int lmid, rmid;
	while (left + 1 < right)
	{
		lmid = (left + right) >> 1;
		rmid = (lmid + right) >> 1;
		if (check(lmid) < check(rmid)) right = rmid;
		else left = lmid;
	}
	return check(lmid) < check(rmid) ? lmid : rmid;
}

int main()
{
	return 0;
}
