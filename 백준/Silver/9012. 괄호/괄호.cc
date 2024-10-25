#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T;
	char parenthesis_string[51], buffer[2];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%s", parenthesis_string);
		char* cp = parenthesis_string;
		int parenthesis = 0, flag = 0;
		while (*cp)
		{
			if (*cp == '(')
				parenthesis++;
			else
			{
				if (parenthesis > 0)
					parenthesis--;
				else
				{
					flag = 1;
					break;
				}
			}
			cp++;
		}
		if (flag)
			printf("NO\n");
		else
		{
			if (parenthesis == 0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	
	return 0;
}