#include "ft_printf.h"
#include <string.h>

int main()
{
//	char *str = strdup("12345");
//	char	*str;
//write(1, "\0", 1);
//	char *str1;
//	char *str2 = strdup("qwerty");
	int k = ft_printf("my |%2.7x\n", 3267);
	int i = printf("or |%2.7x\n", 3267);
//	int k =
//	printf("or |%s\n", NULL);
//	ft_printf("my |%s\n", NULL);
	printf("================\nor %d\nmy %d\n", i, k);
//	int m = 5;
//	ft_printf("%-20p\n", &m);
//	printf("%-20p\n", &m);
//	int s_hello;
//	ft_printf("%.*p\n", -1, s_hello);
//	printf("qwerty%10.3sqw", str);
//	char *str;
//	printf("%s", str);
	return 0;
}
