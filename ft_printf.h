#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>

int     ft_printf(const char *format, ...);
int     ft_putchar(int c);
int     ft_putdigit(int num);
int     ft_puthexlower(int num);
int     ft_puthexupper(int num);
int     ft_putint(int num);
int     ft_putptr(int n);
int     ft_putstr (char *str);
int     ft_putunsign(int n);

#endif