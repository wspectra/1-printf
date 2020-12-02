#include "ft_printf.h"
#include <string.h>

int main()
{
//	char *str = strdup("12345");
//	char	*str;
//	int k = ft_printf("qwerty%10.3sqw\n", str);
	int i = printf("or |%x\n", 0);
	int k = ft_printf("my |%x\n", 0);
	printf("================\nor %d\nmy %d\n", i, k);
//	int m = 5;
//	ft_printf("%-20p\n", &m);
//	printf("%-20p\n", &m);
//	int s_hello;
//	ft_printf("%.*p\n", -1, s_hello);
//	printf("qwerty%10.3sqw", str);
	char *str;
//	printf("%s", str);
	return 0;
}
