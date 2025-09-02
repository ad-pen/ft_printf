int ft_putunsign(int n)
{
    unsigned int num;

    num = n;
    if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putchar((num % 10) + '0');
	}
	else
		ft_putchar(num + '0');
}