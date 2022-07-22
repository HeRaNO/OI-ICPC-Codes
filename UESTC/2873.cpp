#include <string>
#include <iostream>
using namespace std;

inline void Solve()
{
	string url;
	cin >> url;
	bool useHttps = false;
	if (url.substr(0, 5) == "https") // https://
	{
		url.erase(0, 8);
		useHttps = true;
	}
	else // http://
		url.erase(0, 7);
	int i;
	for (i = 0; i < url.length(); i++)
		if (url[i] == '/') break;
	string hostname = url.substr(0, i); // get hostname, with no /
	url.erase(0, i);
	bool usePort = false;
	for (i = 0; i < hostname.length(); i++)
	{
		if (hostname[i] == '.') hostname[i] = '-';
		if (hostname[i] == ':')
		{
			hostname[i] = '-';
			usePort = true;
		}
	}
	if (usePort) hostname += "-p";
	if (useHttps) hostname += "-s";
	hostname += ".vpn.uestc.edu.cn:8118";
	hostname += url;
	cout << "http://" << hostname << '\n';
	return ;
}

int main()
{
	int T; cin >> T;
	while (T--) Solve();
	return 0;
}