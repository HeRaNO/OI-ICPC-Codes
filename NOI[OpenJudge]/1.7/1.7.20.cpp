//Code By HeRaNO
#include<stdio.h>
#include<string.h>
int main()
{
	char word[33];
	gets(word);
	int a = strlen(word), i;
	if ((word[a - 1] == 'r') && (word[a - 2] == 'e'))
		for (i = 0; i < a - 2; i++) printf("%c", word[i]);
	else if ((word[a - 1] == 'y') && (word[a - 2] == 'l'))
		for (i = 0; i < a - 2; i++) printf("%c", word[i]);
	else if ((word[a - 1] == 'g') && (word[a - 2] == 'n') && (word[a - 3] == 'i'))
		for (i = 0; i < a - 3; i++) printf("%c", word[i]);
	else puts(word);
	return 0;
}
