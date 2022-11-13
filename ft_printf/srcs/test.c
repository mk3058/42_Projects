#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *test = "test";

    ft_printf("%-10.5s", "testtesttesttesttest");

    /*printf("%#c\n", 'k');
    printf("%#s\n", "testtesttest");
    printf("%#p\n", test);
    printf("%#d\n", 123);
    printf("%#i\n", 123);
    printf("%#u\n", (unsigned int)123);
    printf("%#x\n", 423523831);
    printf("%#X\n", 423523831);
    printf("%#%\n");*/
}