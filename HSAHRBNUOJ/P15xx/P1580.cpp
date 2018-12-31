#include <iostream>
#include <queue>
using namespace std;

long long n;
bool flag;
queue <long long> q;

int main()
{
	cin >> n;
	q.push(1);
	do
	{
		if (q.front() % n == 0)
			flag = true;
		else
		{
			q.push(q.front() * 10);
			q.push(q.back() + 1);
		}
		q.pop();
	}
	while (!flag);
	if (flag) cout << q.front() / n << endl;
	else cout << "No  Solution" << endl;
	return 0;
}
