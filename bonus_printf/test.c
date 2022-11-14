#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *test = "test";
    int m;
    int o;

//width, precision 둘 다 사용 가능한 경우
    //width > precision
    o = printf("%1s", "test");
    printf("\n%d\n", o);
    
    o = printf("%5d", -1234);
    printf("\n%d\n", o);

    o = printf("%1i", 1234);
    printf("\n%d\n", o);

    o = printf("%1u", (unsigned int)1234);
    printf("\n%d\n", o);

    o = printf("%1x", 374619);
    printf("\n%d\n", o);

    o = printf("%1X", 374619);
    printf("\n%d\n", o);
}