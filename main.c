#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

int main()
{
//	char *str = strdup("badabada");
//	char	*str;
//write(1, "\0", 1);
//	char *str1;
//	char *str2 = strdup("qwerty");
	int k = ft_printf("%3.s\n", NULL);
	int i = printf("%3.s\n", NULL);
//	int k =
//	printf("or |%s\n", NULL);
//	printf("my |%10.*s\n", 0, NULL);
	printf("================\nor %d\nmy %d\n", i, k);
//	int m = 5;
//	ft_printf("%-20p\n", &m);
//	printf("%-20p\n", &m);
//	int s_hello;
//	ft_printf("%.*p\n", -1, s_hello);
//	printf("qwerty%10.3sqw", str);
//	char *str;
//	printf("%s", str);

//	write(1, "123456", 2);
	return 0;
}
