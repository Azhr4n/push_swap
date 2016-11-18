/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:27:59 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/09 10:27:59 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "push_swap.h"

static double	calc_value(const char *str, int i, double neg)
{
	double	ret;

	ret = 0;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		ret *= 10;
		if (ret < 0)
			ret -= str[i] - '0';
		else
			ret += str[i] - '0';
		if (neg && ret)
		{
			ret *= -1;
			neg = 0;
		}
		i++;
	}
	return (ret);
}

double			atof(const char *str)
{
	int		i;
	double	ret;
	double	neg;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	i = 0;
	neg = 0;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	ret = calc_value(str, i, neg);
	return (ret);
}

int				is_number(char *str)
{
	double	value;
	char	*ptr;

	ptr = str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	value = atof(ptr);
	if (value > MAXINT_VAL || value < MININT_VAL)
		return (0);
	return (1);
}
