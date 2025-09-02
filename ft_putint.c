#include "ft_printf.h"

int ft_putint(int num)
{
    long int	n2;

	n2 = num;
	if (n2 < 0)
	{
		n2 = (n2 * -1);
		write(1, "-", 1);
	}
	if (n2 > 9)
	{
		ft_putnbr(n2 / 10);
		ft_putchar((n2 % 10) + '0');
	}
	else
		ft_putchar(n2 + '0');
}
