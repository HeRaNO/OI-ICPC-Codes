#include <bits/stdc++.h>
using namespace std;

char a[1000];

int main()
{
	while (scanf("%s",a)!=EOF)
	{
		int n=strlen(a);
		int i=0;
		while (i<n)
		{
			int p=i;
			while (a[p]!='/'&&p<n) p++;
			if (p-i==1)
			{
				if (a[i]=='.') putchar('E');
				else putchar('T');
			}
			else if (p-i==2)
			{
				if (a[i]=='.'&&a[i+1]=='-') putchar('A');
				else if (a[i]=='.'&&a[i+1]=='.') putchar('I');
				else if (a[i]=='-'&&a[i+1]=='-') putchar('M');
				else if (a[i]=='-'&&a[i+1]=='.') putchar('N');
			}
			else if (p-i==3)
			{
				if (a[i]=='-'&&a[i+1]=='.'&&a[i+2]=='.') putchar('D');
				else if (a[i]=='-'&&a[i+1]=='-'&&a[i+2]=='.') putchar('G');
				else if (a[i]=='-'&&a[i+1]=='.'&&a[i+2]=='-') putchar('K');
				else if (a[i]=='-'&&a[i+1]=='-'&&a[i+2]=='-') putchar('O');
				else if (a[i]=='.'&&a[i+1]=='-'&&a[i+2]=='.') putchar('R');
				else if (a[i]=='.'&&a[i+1]=='.'&&a[i+2]=='.') putchar('S');
				else if (a[i]=='.'&&a[i+1]=='.'&&a[i+2]=='-') putchar('U');
				else if (a[i]=='.'&&a[i+1]=='-'&&a[i+2]=='-') putchar('W');
			}
			else
			{
				if (a[i]=='-'&&a[i+1]=='.'&&a[i+2]=='.'&&a[i+3]=='.') putchar('B');
				else if (a[i]=='-'&&a[i+1]=='.'&&a[i+2]=='-'&&a[i+3]=='.') putchar('C');
				else if (a[i]=='.'&&a[i+1]=='.'&&a[i+2]=='-'&&a[i+3]=='.') putchar('F');
				else if (a[i]=='.'&&a[i+1]=='.'&&a[i+2]=='.'&&a[i+3]=='.') putchar('H');
				else if (a[i]=='.'&&a[i+1]=='-'&&a[i+2]=='-'&&a[i+3]=='-') putchar('J');
				else if (a[i]=='.'&&a[i+1]=='-'&&a[i+2]=='.'&&a[i+3]=='.') putchar('L');
				else if (a[i]=='.'&&a[i+1]=='-'&&a[i+2]=='-'&&a[i+3]=='.') putchar('P');
				else if (a[i]=='-'&&a[i+1]=='-'&&a[i+2]=='.'&&a[i+3]=='-') putchar('Q');
				else if (a[i]=='.'&&a[i+1]=='.'&&a[i+2]=='.'&&a[i+3]=='-') putchar('V');
				else if (a[i]=='-'&&a[i+1]=='.'&&a[i+2]=='.'&&a[i+3]=='-') putchar('X');
				else if (a[i]=='-'&&a[i+1]=='.'&&a[i+2]=='-'&&a[i+3]=='-') putchar('Y');
				else if (a[i]=='-'&&a[i+1]=='-'&&a[i+2]=='.'&&a[i+3]=='.') putchar('Z');
			}
			if (a[p+1]=='/'){++p;putchar(' ');}
			i=++p;
		}
		putchar('\n');
	}
	return 0;
}
