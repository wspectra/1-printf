#include "ft_printf.h"
#include <string.h>

int main()
{
//	char *str = strdup("12345");
//	char	*str;
//	int k = ft_printf("qwerty%10.3sqw\n", str);
//write(1, "\0", 1);

	int i = printf("or |%5p\n", 4316124215);
	int k = ft_printf("my |%5p\n", 4316124215);
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
