//Code By HeRaNO
#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct Student
{
	string name;
	bool operator < (const Student &rhs) const
	{
		if (name.size() == rhs.name.size())
			return name < rhs.name;
		return name.size() < rhs.name.size();
	}
};

multiset<Student> s[13][32];

int main()
{
	string str;
	int n, m, d;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str >> m >> d;
		s[m][d].insert((Student)
		{
			str
		});
	}
	bool ok = false;
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 31; j++)
			if (s[i][j].size() > 1)
			{
				ok = true;
				printf("%d %d", i, j);
				for (multiset<Student>::iterator it = s[i][j].begin(); it != s[i][j].end(); ++it)
					cout << ' ' << it->name;
				cout << endl;
			}
	if (!ok) puts("None");
	return 0;
}
