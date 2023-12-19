/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:04:00 by pdi-pint          #+#    #+#             */
/*   Updated: 2023/11/07 15:04:02 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n <= -2147483648)
	{
		return (ft_putstr ("-2147483648"));
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		i++;
	}
	if (n < 10)
	{
		i += ft_putchar(n + 48);
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putchar((n % 10) + 48);
	}
	return (i);
}

int	ft_numhex_low(unsigned int num)
{
	char	*num_hex_low;
	int		i;

	num_hex_low = "0123456789abcdef";
	i = 0;
	if (num >= 16)
	{
		i += ft_numhex_low(num / 16);
		i += ft_numhex_low(num % 16);
	}
	else
		i += ft_putchar(num_hex_low[num]);
	return (i);
}

int	ft_numhex_up(unsigned int num)
{
	char	*num_hex_up;
	int		i;

	num_hex_up = "0123456789ABCDEF";
	i = 0;
	if (num >= 16)
	{
		i += ft_numhex_up(num / 16);
		i += ft_numhex_up(num % 16);
	}
	else
		i += ft_putchar(num_hex_up[num]);
	return (i);
}

int	ft_pointer_numhex(uintptr_t ptr, int index)
{
	int		i;
	char	*num_hex_low;

	num_hex_low = "0123456789abcdef";
	i = 0;
	if (!ptr && !index)
		return (ft_putstr("(nil)"));
	if (index == 0)
		i += ft_putstr("0x");
	if (ptr >= 16)
	{
		i += ft_pointer_numhex(ptr / 16, 1);
		i += ft_pointer_numhex(ptr % 16, 1);
	}
	else
		i += ft_putchar(num_hex_low[ptr]);
	return (i);
}
