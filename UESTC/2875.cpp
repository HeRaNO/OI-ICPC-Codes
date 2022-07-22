#include <cstdio>
#include <algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char guess_word[6], target_word[6];
		scanf("%s", guess_word);
		scanf("%s", target_word);
		for (int i = 0; i < 5; i++)
		{
			if (guess_word[i] == target_word[i])
				putchar('g');
			else
			{
				if (std::count(guess_word, guess_word + 5, guess_word[i]) <= std::count(target_word, target_word + 5, guess_word[i]))
					putchar('y');
				else
					putchar('x');
			}
		}
		putchar('\n');
	}
	return 0;
}