//By Billchenchina @ HLJSSYZX
/*  #include "testlib.h"
    #include <iostream>
    #include <vector>
    #include <set>*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
	//setName("Test the answer");
	//registerTestlibCmd(argc, argv);
	ifstream fin(argv[1]), fx(argv[2]), fout(argv[3]);
	bool correct = 1;
	int N;
	//N=inf.readInt();
	fin >> N;
	vector<int>pos(N + 1, 0);
	set<int>answer_set;
	for (int i = 1; i <= N; i++)
	{
		int a;
		//a=ouf.readInt();
		fout >> a;
		pos[a] = i;
		answer_set.insert(i);
	}
	set<int>output_set;
	for (int i = 1; i <= N; i++)
	{
		while (true)
		{
			int a;
			//a=inf.readInt();
			fin >> a;
			output_set.insert(a);
			if (a != 0)
			{
				if (pos[i] > pos[a])
					correct = 0;
			}
			else break;
		}
	}
	if (answer_set == output_set)correct = false;
	if (correct)
	{
		//quitf(_ok, "The answer is correct.");
		return 0;
	}
	else
		return 1;
}