#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void    ft_putchar(int c)
{
    write (1, &c, 1);
}

void    ft_putstr (char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        write (1, &str[i], 1);
        i++;
    }
}

void    ft_putdigit(int num)
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
		ft_putdigit(n2 / 10);
		ft_putdigit(n2 % 10);
	}
	else
		ft_putchar(n2 + '0');
}

void    ft_putptr(int n)
{
    int num;

    num = n;
    ft_putdigit (num);
}

int    ft_check(const char flag, va_list args)
{
    if (flag == 'p')
        ft_putptr (va_arg(args, unsigned long long));
    else if (flag == 's')
        ft_putstr (va_arg(args, char *));
    else if (flag == 'd')
        ft_putdigit (va_arg(args, int));
    else if (flag == '%')
        write (1, "%", 1);
    else
        return (1);
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     len;
    int     i;
    int     f;

    va_start (args, format);
    len = 0;
    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            f = ft_check (format[i + 1], args);
            i++;
        }
        else
            write (1, &format[i], 1);
        //if (f == 1)
            //error message
        i++;
    }
    va_end (args);
    return (len);
}

int main ()
{
    char *s = "string";
    ft_printf ("abc%d\n", 1);
    ft_printf ("%p\n", s);
    ft_printf ("%s\n", s);
}