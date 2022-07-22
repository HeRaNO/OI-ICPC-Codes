#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct __sort_table
{
	int cnt, pos;
	std::string first_name, last_name;
	__sort_table(){}
	__sort_table(std::string _f, std::string _l, int c, int p):
		first_name(_f), last_name(_l), cnt(c), pos(p){}
	void print()
	{
		std::cout << first_name << ' ' << last_name << '\n';
		return ;
	}
	bool operator < (const __sort_table &a) const {
		if (cnt == a.cnt) return pos < a.pos;
		return cnt > a.cnt;
	}
};

int main()
{
	std::map<std::string, int> mp;
	std::vector<__sort_table> v;
	std::string s, t;
	int i = 0;
	while (std::cin >> s >> t)
	{
		mp[s]++;
		v.emplace_back(s, t, 0, i++);
	}
	for (__sort_table& i : v)
		i.cnt = mp[i.first_name];
	std::sort(v.begin(), v.end());
	for (__sort_table i : v)
		i.print();
	return 0;
}