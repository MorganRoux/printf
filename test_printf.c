#include "libft.h"
#include <stdio.h>

int main(void)
{
	int i = 1123456789;
	unsigned int u = 876876;
	int j = 20;
	int k = 15;
	int l = -16;
	char c = '!';
	char *s = "Morgan!";
	ft_printf("yo%%yoo-%-20d-yo\n", i);
	ft_printf("yo%%yoo-%-020d-yo\n", i);
	ft_printf("yo%%yoo-%20d-yo\n", i);
	ft_printf("yo%%yoo-%0020d-yo\n", i);
	ft_printf("%-20.15u-\n", u);
	ft_printf("%-20.15d-\n", i);
	ft_printf("%-*.*d-\n", j, k, i);
	ft_printf("%20X-\n", l);
	ft_printf("%-20.15d\n", l);
	ft_printf("%20.10c\n", c);
	ft_printf("%.8s-\n", "MorganRoux");
	printf("%p\n",&i);
	ft_printf("%p\n", &i);

	return (0);
}
