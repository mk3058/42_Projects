#include "ft_printf.h"
#include <limits.h>
void test_adr(char *res);

int main()
{
    char *test = "test";
    int m;
    int o;

/* precision 사용 가능한 자료형들 pricision별 정렬
    ft_printf("%.20d", -1234);
    ft_printf("%.3d", -1234);
    ft_printf("%.0d", -1234);
    ft_printf("%d", -1234);
    printf("%.20d\n", -1234);
    printf("%.3d\n", -1234);
    printf("%.0d\n", -1234);
    printf("%d\n", -1234);
    printf("========================\n");

    ft_printf("%.20d", 1234);
    ft_printf("%.3d", 1234);
    ft_printf("%.0d", 1234);
    ft_printf("%d", 1234);
    printf("%.20d\n", 1234);
    printf("%.3d\n", 1234);
    printf("%.0d\n", 1234);
    printf("%d\n", 1234);
    printf("========================\n"); 

    ft_printf("%.20i", -1234);
    ft_printf("%.3i", -1234);
    ft_printf("%.0i", -1234);
    ft_printf("%i", -1234);
    printf("%.20i\n", -1234);
    printf("%.3i\n", -1234);
    printf("%.0i\n", -1234);
    printf("%i\n", -1234);
    printf("========================\n");

    ft_printf("%.20i", 1234);
    ft_printf("%.3i", 1234);
    ft_printf("%.0i", 1234);
    ft_printf("%i", 1234);
    printf("%.20i\n", 1234);
    printf("%.3i\n", 1234);
    printf("%.0i\n", 1234);
    printf("%i\n", 1234);
    printf("========================\n"); 

    ft_printf("%.20u", -1234);
    ft_printf("%.3u", -1234);
    ft_printf("%.0u", -1234);
    ft_printf("%u", -1234);
    printf("%.20u\n", -1234);
    printf("%.3u\n", -1234);
    printf("%.0u\n", -1234);
    printf("%u\n", -1234);
    printf("========================\n");

    ft_printf("%.20u", 1234);
    ft_printf("%.3u", 1234);
    ft_printf("%.0u", 1234);
    ft_printf("%u", 1234);
    printf("%.20u\n", 1234);
    printf("%.3u\n", 1234);
    printf("%.0u\n", 1234);
    printf("%u\n", 1234);
    printf("========================\n");

    ft_printf("%.20x", 47319432);
    ft_printf("%.3x", 47319432);
    ft_printf("%.0x", 47319432);
    ft_printf("%x", 47319432);
    printf("%.20x\n", 47319432);
    printf("%.3x\n", 47319432);
    printf("%.0x\n", 47319432);
    printf("%x\n", 47319432);
    printf("========================\n");

    ft_printf("%.20X", 47319432);
    ft_printf("%.3X", 47319432);
    ft_printf("%.0X", 47319432);
    ft_printf("%X", 47319432);
    printf("%.20X\n", 47319432);
    printf("%.3X\n", 47319432);
    printf("%.0X\n", 47319432);
    printf("%X\n", 47319432);
    printf("========================\n");

    ft_printf("%.20s", test);
    ft_printf("%.3s", test);
    ft_printf("%.0s", test);
    ft_printf("%s", test);
    printf("%.20s\n", test);
    printf("%.3s\n", test);
    printf("%.0s\n", test);
    printf("%s\n", test);
    printf("========================\n");
    */
/*
    ft_printf("%c", 't');
    ft_printf("%c", 't');
    ft_printf("%c", 't');
    ft_printf("%c", 't');
    printf("%c\n", 't');
    printf("%c\n", 't');
    printf("%c\n", 't');
    printf("%c\n", 't');
    printf("========================\n");

    ft_printf("%p", test);
    ft_printf("%p", test);
    ft_printf("%p", test);
    ft_printf("%p", test);
    printf("%p\n", test);
    printf("%p\n", test);
    printf("%p\n", test);
    printf("%p\n", test);
    printf("========================\n");

    ft_printf("%%", test);
    ft_printf("%%", test);
    ft_printf("%%", test);
    ft_printf("%%", test);
    printf("%%\n", test);
    printf("%%\n", test);
    printf("%%\n", test);
    printf("%%\n", test);
    printf("========================\n"); */ //precision 적용되지 않는 지정자도 잘 변환되는지 확인

    /*ft_printf("%10d||", -123);
    printf("\n");
    printf("%10d||", -123);
    printf("\n\n");

    ft_printf("%10d||", 123);
    printf("\n");
    printf("%10d||", 123);
    printf("\n\n");

    ft_printf("%-10d||", -123);
    printf("\n");
    printf("%-10d||", -123);
    printf("\n\n");

    ft_printf("%-10d||", 123);
    printf("\n");
    printf("%-10d||", 123);
    printf("\n\n");

    ft_printf("% 10d||", -123);
    printf("\n");
    printf("% 10d||", -123);
    printf("\n\n");
    
    ft_printf("% 10d||", 123);
    printf("\n");
    printf("% 10d||", 123);
    printf("\n\n");

    ft_printf("%- 10d||", -123);
    printf("\n");
    printf("%- 10d||", -123);
    printf("\n\n");
    
    ft_printf("%- 10d||", 123);
    printf("\n");
    printf("%- 10d||", 123);
    printf("\n\n"); */
/*
    ft_printf("%10.3d||", -123);
    printf("\n");
    printf("%10.3d||", -123);
    printf("\n\n");

    ft_printf("%10.3d||", 123);
    printf("\n");
    printf("%10.3d||", 123);
    printf("\n\n");

    ft_printf("%-10.3d||", -123);
    printf("\n");
    printf("%-10.3d||", -123);
    printf("\n\n");

    ft_printf("%-10.3d||", 123);
    printf("\n");
    printf("%-10.3d||", 123);
    printf("\n\n");

    ft_printf("% 10.3d||", -123);
    printf("\n");
    printf("% 10.3d||", -123);
    printf("\n\n");
    
    ft_printf("% 10.3d||", 123);
    printf("\n");
    printf("% 10.3d||", 123);
    printf("\n\n");

    ft_printf("%- 10.3d||", -123);
    printf("\n");
    printf("%- 10.3d||", -123);
    printf("\n\n");
    
    ft_printf("%- 10.3d||", 123);
    printf("\n");
    printf("%- 10.3d||", 123);
    printf("\n\n"); */

    m = ft_printf("%-5.0i", 0);
    printf("\n");
    o = printf("%-5.0i", 0);
    printf("\n%d %d\n", m, o);
}
