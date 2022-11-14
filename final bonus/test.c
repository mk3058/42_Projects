#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *test = "test";
    int m;
    int o;

   /* ft_printf("%.20s", "test");
    ft_printf("%.3s", "test");
    ft_printf("%.0s", "test");
    ft_printf("%s", "test"); */

    ft_printf("%.20d", -1234);
    ft_printf("%.3d", -1234);
    ft_printf("%.0d", -1234);
    ft_printf("%d", -1234);
}