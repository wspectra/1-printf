#include "ft_printf.h"
#include <string.h>

int main()
{
	char *str = strdup("badabada");
//	char	*str;
//write(1, "\0", 1);
//	char *str1;
//	char *str2 = strdup("qwerty");
	int k = ft_printf("my |%p\n", 140732675873192);
	int i = printf("or |%p\n", 140732675873192);
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
