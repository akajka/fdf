/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:04:59 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/05 15:05:01 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	ft_space(char c)
{
	if (c == '\t' || c == '\n' ||
		c == '\r' || c == '\v' ||
		c == ' ' || c == '\f')
		return (0);
	return (1);
}

static	int	test_base(const char c)
{
	int		nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		sign;
	int		nb;
	int		current;

	nb = 0;
	sign = 1;
	str += 2;
	while (!ft_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	current = test_base(*str);
	while (current >= 0 && current < str_base)
	{
		nb = nb * str_base + current;
		str++;
		current = test_base(*str);
	}
	return (sign * nb);
}
