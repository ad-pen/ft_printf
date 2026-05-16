#include "ft_printf.h"

int    ft_check(char flag, va_list args)
{
    if (flag == 'c')
        ft_putchar (va_arg(args, int));
    else if (flag == 's')
        ft_putstr (va_arg(args, char *));
    else if (flag == 'p')
        ft_putptr (va_arg(args, unsigned long long));
    else if (flag == 'd')
        ft_putdigit (va_arg(args, int));
    else if (flag == 'i')
        ft_putint (va_arg(args, int));
    else if (flag == 'u')
        ft_putunsign (va_arg(args, int));
    else if (flag == 'x')
        ft_puthexlower (va_arg (args, int));
    else if (flag == 'X')
        ft_puthexupper (va_arg(args, int));
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
            write (1, format[i], 1);
        if (f == 1)
            //error message
        i++;
    }
    va_end (args);
    return (len);
}
