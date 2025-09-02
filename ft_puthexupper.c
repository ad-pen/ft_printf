#include "ft_printf.h"

int    ft_puthexupper(int num)
{
    int len;

    len = 0;
    if (num > 15)
    {
        len += ft_puthexupper (num / 16);
        len += ft_puthexupper (num % 16);
    }
    else
    {
        if (num < 10)
            ft_putchar (num + '0');
        else
            ft_putchar (num + 'A' - 10);
        len++;
    }
    return (len);
}
