/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:31:23 by sasano            #+#    #+#             */
/*   Updated: 2023/10/10 00:50:08 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putptr(va_arg(args, unsigned long long), 'x');
	}
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += check_format(args, format[i]);
			if (!(format[i] == '%'))
				va_arg(args, void *);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/* 
int	main(void)
{
	// ft_printf("Hello, %s\n", "world!");
	// ft_printf("Hello, %c\n", 'c');
	// ft_printf("Hello, %p\n", "world!");
	// ft_printf("Hello, %d\n", 42);
	// ft_printf("Hello, %i\n", 42);
	// ft_printf("Hello, %u\n", 4200000000);
	// ft_printf("Hello, %u\n", 42);
	// ft_printf("Hello, %x\n", 42);
	// ft_printf("Hello, %X\n", 42);
	// ft_printf("Hello, %%\n");
	// ft_printf(" %c %c %c ", '0', 0, '1');
	// ft_printf(" %c %c %c ", ' ', ' ', ' ');
	// ft_printf(" %c %c %c ", '1', '2', '3');
	// ft_printf(" %c %c %c ", '2', '1', 0);
	// ft_printf(" %c %c %c ", 0, '1', '2');
	// ft_printf(" NULL %s NULL ", NULL);
	ft_printf("%%%c",'A');
	return (0);
} */