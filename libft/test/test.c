#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("\nisalpha test\n");
	printf("%d %d\n", ft_isalpha('A'), isalpha('A'));
	printf("%d %d\n", ft_isalpha('Z'), isalpha('Z'));
	printf("%d %d\n", ft_isalpha('a'), isalpha('a'));
	printf("%d %d\n", ft_isalpha('z'), isalpha('z'));
	printf("%d %d\n", ft_isalpha('g'), isalpha('g'));
	printf("%d %d\n", ft_isalpha('&'), isalpha('&'));
	printf("%d %d\n", ft_isalpha('	'), isalpha('	'));

	printf("\nisdigit test\n");
	printf("%d %d\n", ft_isdigit('0'), isdigit('0'));
	printf("%d %d\n", ft_isdigit('9'), isdigit('9'));
	printf("%d %d\n", ft_isdigit('5'), isdigit('5'));
	printf("%d %d\n", ft_isdigit('A'), isdigit('A'));
	printf("%d %d\n", ft_isdigit('~'), isdigit('~'));

	printf("\nisalnum test\n");
	printf("%d %d\n", ft_isalpha('A'), isalpha('A'));
	printf("%d %d\n", ft_isalpha('Z'), isalpha('Z'));
	printf("%d %d\n", ft_isalpha('a'), isalpha('a'));
	printf("%d %d\n", ft_isalpha('z'), isalpha('z'));
	printf("%d %d\n", ft_isalpha('g'), isalpha('g'));
	printf("%d %d\n", ft_isalpha('&'), isalpha('&'));
	printf("%d %d\n", ft_isalpha('	'), isalpha('	'));
	printf("%d %d\n", ft_isdigit('0'), isdigit('0'));
	printf("%d %d\n", ft_isdigit('9'), isdigit('9'));
	printf("%d %d\n", ft_isdigit('5'), isdigit('5'));
	printf("%d %d\n", ft_isdigit('A'), isdigit('A'));
	printf("%d %d\n", ft_isdigit('~'), isdigit('~'));

	printf("\nisascii test\n");
	printf("%d %d\n", ft_isascii('A'), isascii('A'));
	printf("%d %d\n", ft_isascii(0), isascii(0));
	printf("%d %d\n", ft_isascii(255), isascii(255));
	printf("%d %d\n", ft_isascii(127), isascii(127));
	printf("%d %d\n", ft_isascii(126), isascii(126));

	printf("\nisprint test\n");
	printf("%d %d\n", ft_isprint('A'), isprint('A'));
	printf("%d %d\n", ft_isprint(0), isprint(0));
	printf("%d %d\n", ft_isprint(255), isprint(255));
	printf("%d %d\n", ft_isprint(127), isprint(127));
	printf("%d %d\n", ft_isprint(126), isprint(126));

	printf("\nmemchr test\n");
	printf("%s\n", ft_memchr("testAtesttest", 'A',5));
	printf("%s\n", memchr("testAtesttest", 'A', 5));

	printf("\nmemcmp test\n");
	printf("%d\n", ft_memcmp("abcde", "abcdk", 100));
	printf("%d\n", memcmp("abcde", "abcdk", 100));

	printf("\nmemcpy test\n");
	char my_dst[100];
	char or_dst[100];
	printf("%s\n", ft_memcpy(my_dst, "copyTest", 4));
	printf("%s\n", memcpy(or_dst, "copyTest", 4));

	printf("\nmemset test\n");
	printf("%s\n", ft_memset(my_dst, 'M', 100));
	printf("%s\n", memset(or_dst, 'O', 100));

	printf("\nstrchr test\n");
	printf("%s\n", ft_strchr("TestAtestBTest", 'T'));
	printf("%s\n", strchr("TestAtestBTest", 'T'));

	printf("\nstrnstr test\n");
	printf("%s\n", ft_strnstr("TestABCtestYYY", "T", 1));
	printf("%s\n", strnstr("TestABCtestYYY", "T", 1));	

	printf("\natoi test\n");
	printf("%d\n", ft_atoi("+2147483647"));
	printf("%d\n", atoi("+2147483647"));

	printf("\nbzero test\n");
	char test[10];
	char or_test[10];

	ft_bzero(test, 10);
	bzero(or_test, 10);

	for(int i = 0; i < 10; i++)
	{
		if(test[i] == 0)
			printf("\\0 ");
		else
			printf("X ");
	}
	printf("\n");
	for(int i = 0; i < 10; i++)
	{
		if(or_test[i] == 0)
			printf("\\0 ");
		else
			printf("X ");
	}

	printf("\n\nstrrchr test\n");
	printf("%s\n", ft_strrchr("strrchr test Test", 'D'));
	printf("%s\n", strrchr("strrchr test Test", 'D'));
}