#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int my_len = 0;
    int or_len = 0;

    or_len = printf(" %s %c %p %s %d\n", "test", 'v', &my_len, "test", 123);
    my_len = ft_printf(" %s %c %p %s %d\n", "test", 'v', &my_len, "test", 123);
    //my_len = ft_printf("   %c\n", 'T');
    printf("\n\n%d %d\n", or_len, my_len);
}