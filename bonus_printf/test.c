#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *test = "test";
    int m;
    int o;

/*    m = ft_printf("%-10c\n", 'Y');
    o = printf("%-10c\n", 'Y');
    printf("\n%d %d\n", m, o); 
    
    printf("\n");
    m = ft_printf("%d\n", 1234567);
    o = printf("%d\n", 1234567);
    printf("\n%d %d\n", m, o); 
    
    printf("\n");
    m = ft_printf("%i\n", 1234567);
    o = printf("%i\n", 1234567);
    printf("\n%d %d\n", m, o); 

    printf("\n");
    m = ft_printf("%10s\n", test);
    o = printf("%10s\n", test);
    printf("\n%d %d\n", m, o);  */

    m = ft_printf(" %X \n", -1);
    o = printf(" %X \n", -1);
    printf("\n%d %d\n", m, o);
}