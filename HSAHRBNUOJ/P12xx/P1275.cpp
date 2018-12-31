#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

string ans;
int r;

inline int compare(string str1, string str2)
{
	if (str1.size() > str2.size()) //长度长的整数大于长度小的整数
		return 1;
	else if (str1.size() < str2.size())
		return -1;
	else
		return str1.compare(str2); //若长度相等，从头到尾按位比较，compare函数：相等返回0，大于返回1，小于返回－1
}

string ADD_INT(string str1, string str2)
{
	string MINUS_INT(string str1, string str2);
	int sign = 1; //sign 为符号位
	string str;
	if (str1[0] == '-')
	{
		if (str2[0] == '-')
		{
			sign = -1;
			str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));
		}
		else
			str = MINUS_INT(str2, str1.erase(0, 1));
	}
	else
	{
		if (str2[0] == '-')
			str = MINUS_INT(str1, str2.erase(0, 1));
		else
		{
			//把两个整数对齐，短整数前面加0补齐
			string::size_type l1, l2;
			int i;
			l1 = str1.size();
			l2 = str2.size();
			if (l1 < l2)
			{
				for (i = 1; i <= l2 - l1; i++)
					str1 = "0" + str1;
			}
			else
			{
				for (i = 1; i <= l1 - l2; i++)
					str2 = "0" + str2;
			}
			int int1 = 0, int2 = 0; //int2 记录进位
			for (i = str1.size() - 1; i >= 0; i--)
			{
				int1 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) % 10;  //48 为 '0' 的ASCII 码
				int2 = (int(str1[i]) - 48 + int(str2[i]) - 48 + int2) / 10;
				str = char(int1 + 48) + str;
			}
			if (int2 != 0) str = char(int2 + 48) + str;
		}
	}
	//运算后处理符号位
	if ((sign == -1) && (str[0] != '0'))
		str = "-" + str;
	return str;
}

//高精度减法
string MINUS_INT(string str1, string str2)
{
	string MULTIPLY_INT(string str1, string str2);
	int sign = 1; //sign 为符号位
	string str;
	if (str2[0] == '-')
		str = ADD_INT(str1, str2.erase(0, 1));
	else
	{
		int res = compare(str1, str2);
		if (res == 0) return "0";
		if (res < 0)
		{
			sign = -1;
			string temp = str1;
			str1 = str2;
			str2 = temp;
		}
		string::size_type tempint;
		tempint = str1.size() - str2.size();
		for (int i = str2.size() - 1; i >= 0; i--)
		{
			if (str1[i + tempint] < str2[i])
			{
				str1[i + tempint - 1] = char(int(str1[i + tempint - 1]) - 1);
				str = char(str1[i + tempint] - str2[i] + 58) + str;
			}
			else
				str = char(str1[i + tempint] - str2[i] + 48) + str;
		}
		for (int i = tempint - 1; i >= 0; i--)
			str = str1[i] + str;
	}
	//去除结果中多余的前导0
	str.erase(0, str.find_first_not_of('0'));
	if (str.empty()) str = "0";
	if ((sign == -1) && (str[0] != '0'))
		str = "-" + str;
	return str;
}

//高精度乘法
string MULTIPLY_INT(string str1, string str2)
{
	int sign = 1; //sign 为符号位
	string str;
	if (str1[0] == '-')
	{
		sign *= -1;
		str1 = str1.erase(0, 1);
	}
	if (str2[0] == '-')
	{
		sign *= -1;
		str2 = str2.erase(0, 1);
	}
	int i, j;
	string::size_type l1, l2;
	l1 = str1.size();
	l2 = str2.size();
	for (i = l2 - 1; i >= 0; i --)   //实现手工乘法
	{
		string tempstr;
		int int1 = 0, int2 = 0, int3 = int(str2[i]) - 48;
		if (int3 != 0)
		{
			for (j = 1; j <= (int)(l2 - 1 - i); j++)
				tempstr = "0" + tempstr;
			for (j = l1 - 1; j >= 0; j--)
			{
				int1 = (int3 * (int(str1[j]) - 48) + int2) % 10;
				int2 = (int3 * (int(str1[j]) - 48) + int2) / 10;
				tempstr = char(int1 + 48) + tempstr;
			}
			if (int2 != 0) tempstr = char(int2 + 48) + tempstr;
		}
		str = ADD_INT(str, tempstr);
	}
	//去除结果中的前导0
	str.erase(0, str.find_first_not_of('0'));
	if (str.empty()) str = "0";
	if ((sign == -1) && (str[0] != '0'))
		str = "-" + str;
	return str;
}

string fib(int n)
{
	string s1, s2;
	int a[1200], b[1200];
	char sum[12000] = {"\0"};
	int he, i;
	int s = 0, m = 0;
	s1 = "1";
	s2 = "1";
	for (m = 2; m < n; m++)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		a[0] = s1.length();
		for (i = 1; i <= a[0]; i++)
			a[i] = s1[a[0] - i] - '0';
		b[0] = s2.length();
		for (i = 1; i <= b[0]; i++)
			b[i] = s2[b[0] - i] - '0';
		he = (a[0] > b[0] ? a[0] : b[0]);
		for (i = 1; i <= he; i++)
		{
			a[i] += b[i];
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		he++;
		while ((a[he] == 0) && (he > 1))
			he--;
		for (i = he, s = 0; i >= 1; i--, s++)
			sum[s] = a[i] + '0';
		s1 = s2;
		s2 = sum;
	}
	return s2;
}

int main()
{
	scanf("%d", &r);
	if (r == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	ans = MULTIPLY_INT(fib(r), "2");
	ans = ADD_INT(ans, fib(r - 1));
	ans = MINUS_INT(ans, "1");
	cout << ans << endl;
	return 0;
}
