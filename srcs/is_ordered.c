/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:28:41 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/09 10:28:42 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

int		ordered(t_pile *pile)
{
	t_list	*ptr;

	ptr = pile->list;
	while (ptr->next)
	{
		if (ptr->value <= ((t_list *)ptr->next)->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		is_ordered(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->nb_elem > 0 || pile_b->list != NULL)
		return (0);
	return (ordered(pile_a));
}
