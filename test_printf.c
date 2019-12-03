#include "libft.h"
#include <stdio.h>

int main(void)
{
	int i = 1123456789;
	char c = '!';
	char *s = "Morgan!";
	ft_printf("yo%%yoo-%-20d-yo\n", i);
	ft_printf("yo%%yoo-%-020d-yo\n", i);
	ft_printf("yo%%yoo-%20d-yo\n", i);
	ft_printf("yo%%yoo-%0020d-yo\n", i);
	ft_printf("yo%%yoo-%.15d-yo\n", i);
	ft_printf("yo%%yoo-%-20.15d-yo\n", i);
	printf("---\n%-20.15d", i);




	return (0);
}
