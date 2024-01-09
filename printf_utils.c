/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:56:09 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 00:05:30 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	counter(int i)
{
	int	count;

	count = 0;
	if (i < 0)
		count++;
	while (i > 9 || i < -9)
	{
		i = i / 10;
		count++;
	}
	return (count + 1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = counter(n);
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
	return (count);
}
