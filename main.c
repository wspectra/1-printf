#include "ft_printf.h"
#include <string.h>

int main()
{
	char *str = strdup("12345");
//	int i = printf("or |%-30.15p\n", str);
//	int k = ft_printf("my |%-30.15p\n", str);
	int i = printf("or |%-30.0u\n", 12345);
	int k = ft_printf("my |%-30.0u\n", 12345);
	printf("================\nor %d\nmy %d\n", i, k);
	return 0;
}
