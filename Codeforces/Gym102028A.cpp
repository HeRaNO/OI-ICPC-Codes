#include <bits/stdc++.h>
using namespace std;

int a[4];

int main()
{
	int T;cin>>T;
	while(T--)
	{
		int ans=0;
		for (int i=0;i<4;++i)
		{
			cin>>a[i];
			if (a[i]) ans++;
		}
		switch (ans)
		{
			case 4:
			{
				puts("Contemporary Xu Xiake");
				break;
			}
			case 0:
			{
				puts("Typically Otaku");
				break;
			}
			case 1:
			{
				puts("Eye-opener");
				break;
			}
			case 2:
			{
				puts("Young Traveller");
				break;
			}
			case 3:
			{
				puts("Excellent Traveller");
				break;
			}
		}
	}
	return 0;
}