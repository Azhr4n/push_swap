/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:30:29 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/09 10:30:29 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "push_swap.h"

void	preset_pile(t_pile *pile_a, t_pile *pile_b)
{
	pile_a->list = NULL;
	pile_a->last = NULL;
	pile_b->list = NULL;
	pile_b->last = NULL;
	pile_a->nb_elem = 0;
	pile_b->nb_elem = 0;
}

void	free_2d(char **array)
{
	char	**ptr;

	ptr = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(ptr);
}

int		put_in_list(t_pile *pile, char *str)
{
	char	**array;
	char	**tmp;
	int		ret;

	array = ft_strsplit(str, ' ');
	tmp = array;
	while (*tmp)
	{
		if (!is_number(*tmp))
		{
			free_2d(array);
			return (0);
		}
		ret = ft_atoi(*tmp);
		push_front(&pile->list, create_elem(ret));
		if (!pile->nb_elem)
			pile->last = pile->list;
		pile->nb_elem++;
		tmp++;
	}
	free_2d(array);
	return (1);
}

int		process_arg(t_pile *pile, char **av)
{
	t_list	*offset;
	t_list	*ptr;

	while (*av)
	{
		if (!put_in_list(pile, *av))
			return (0);
		av++;
	}
	offset = pile->list;
	while (offset->next)
	{
		ptr = offset->next;
		while (ptr)
		{
			if (offset->value == ptr->value)
				return (0);
			ptr = ptr->next;
		}
		offset = offset->next;
	}
	return (1);
}
