/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:31:45 by sasano            #+#    #+#             */
/*   Updated: 2023/10/09 23:13:09 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	ft_putchar(char);
int	ft_putstr(char *);
int	ft_putptr(unsigned long long, const char);
int	ft_putnbr(int);
int	ft_putnbr_unsigned(unsigned int);
int	ft_putnbr_hex(unsigned int, const char);

#endif