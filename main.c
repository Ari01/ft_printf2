#include "ft_printf.h"

int main()
{
	int a = 5;
	ft_printf("il etait une fois %p\n", &a);
	printf("il etait une fois %p\n", &a);
	return 0;
}
