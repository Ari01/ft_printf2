#include "ft_printf.h"

int main()
{
	//int a = 5;
/*	int		a = -4;
	int		b = 0;*/
	char	c = 0;
	int		d = 2147483647;
	int		e = -2147483648;
/*	int		f = 42;
	int		g = 25;
	int		h = 4200;*/
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
/*	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";*/

	printf("ret = %d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j));
	printf("ret = %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j));

	printf("ret = %d\n", printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d));
	printf("ret = %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d));

	printf("ret = %d\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d));
	printf("ret = %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d));

	printf("ret = %d\n", printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d));
	printf("ret = %d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d));

//	printf("ret = %d\n", printf("il etait une fois %--*c %d\n", 10, 'a', 42));
//	printf("ret = %d\n", ft_printf("il etait une fois %--*c %d\n", 10, 'a', 42));
	return 0;
}
