/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:31:57 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/09 10:31:58 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "push_swap.h"

void	ordering(t_pile *pile_a, t_pile *pile_b)
{
	int		done;

	while (!is_ordered(pile_a, pile_b))
	{
		done = 0;
		test_swap(pile_a, pile_b, &done);
		test_r_rot(pile_a, pile_b, &done);
		test_rot(pile_a, pile_b, &done);
		magic_trick(pile_a, &done);
		if (!done)
		{
			if (pile_b->list != NULL && pile_b->nb_elem > 0 && ordered(pile_a))
			{
				ft_putstr("pa\n");
				push(pile_a, pile_b);
				done = 1;
			}
			else
			{
				ft_putstr("pb\n");
				push(pile_b, pile_a);
			}
		}
	}
}

int		main(int ac, char **av)
{
	t_pile		pile_a;
	t_pile		pile_b;

	if (ac > 1)
	{
		preset_pile(&pile_a, &pile_b);
		if (process_arg(&pile_a, av + 1))
			ordering(&pile_a, &pile_b);
		else
			ft_putstr("Error.\n");
	}
	return (0);
}
