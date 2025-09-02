#include "ft_printf.h"

int    ft_puthexlower(int num)
{
    int len;

    len = 0;
    if (num > 15)
    {
        len += ft_puthexlower (num / 16);
        len += ft_puthexlower (num % 16);
    }
    else
    {
        if (num < 10)
            ft_putchar (num + '0');
        else
            ft_putchar (num + 'a' - 10);
        len++;
    }
    return (len);
}
