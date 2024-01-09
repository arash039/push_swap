/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:48:56 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 15:21:56 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_node **head_a)
{
	int				sign;
	long long		val;

	sign = 1;
	val = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= 48 && *str <= 57)
	{
		val = val * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' || val >= 2147483648)
	{
		free_linked_list(*head_a);
		ft_printf("Error\n");
		exit (1);
	}
	return (val * sign);
}

static char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

int	printer(const char *c, va_list args)
{
	int	len;

	len = 0;
	if (*c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (*c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (*c == 's')
		len += ft_putstr(va_arg(args, char *));
	return (len);
}

int	ft_printf(const char *c, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, c);
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			if (ft_strchr("csdi", *c))
				len += printer(c, args);
			else if (*c == '%')
				len += ft_putchar('%');
			else
				len += ft_putchar(*c);
		}
		else
			len += ft_putchar(*c);
		c++;
	}
	va_end(args);
	return (len);
}
