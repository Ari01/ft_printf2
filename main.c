#include "ft_printf.h"

int main()
{
	int a = 5;
	printf("n = %d\n", ft_printf("il etait une fois %p\n", &a));
	printf("n = %d\n", printf("il etait une fois %p\n", &a));
	return 0;
}
