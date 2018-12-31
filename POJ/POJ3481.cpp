#include <map>
#include <cstdio>
using namespace std;

int opt, k, p;
map <int, int> q;
map <int, int>::iterator q_iter;

int main()
{
	while (~scanf("%d", &opt) && opt)
	{
		if (opt == 1)
		{
			scanf("%d %d", &k, &p);
			q.insert(pair<int, int>(p, k));
		}
		else if (opt == 3)
		{
			if (q.empty()) printf("0\n");
			else
			{
				printf("%d\n", q.begin()->second);
				q.erase(q.begin());
			}
		}
		else
		{
			if (q.empty()) printf("0\n");
			else
			{
				int cnt = 0;
				for (q_iter = q.end(); !cnt; q_iter--) cnt++;
				printf("%d\n", q_iter->second);
				q.erase(q_iter);
			}
		}
	}
	return 0;
}
