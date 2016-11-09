/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:31:29 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/09 10:31:29 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pile		pile_a;
	t_pile		pile_b;

	if (ac > 1)
	{
		preset_pile(&pile_a, &pile_b);
		if (process_arg(&pile_a, av + 1))
		{
			if (reading_command(&pile_a, &pile_b))
				ft_putstr("Ok\n");
			else
				ft_putstr("KO\n");
		}
		else
			ft_putstr("Error.\n");
	}
	return (0);
}
