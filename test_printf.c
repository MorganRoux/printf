#include "libft.h"
#include <stdio.h>

int main(void)
{
	int i = 1123456789;
	int j = 20;
	int k = 15;
	char c = '!';
	char *s = "Morgan!";
	ft_printf("yo%%yoo-%-20d-yo\n", i);
	ft_printf("yo%%yoo-%-020d-yo\n", i);
	ft_printf("yo%%yoo-%20d-yo\n", i);
	ft_printf("yo%%yoo-%0020d-yo\n", i);
	ft_printf("%-20.15d-\n", i);
	ft_printf("%-*.*d", j, k, i);




	return (0);
}
