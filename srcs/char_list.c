/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:26:03 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/09 10:26:04 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

t_char_list	*create_cl(char *value)
{
	t_char_list	*new;

	if ((new = (t_char_list *)malloc(sizeof(t_char_list))) == NULL)
		exit(-1);
	new->next = NULL;
	new->value = value;
	return (new);
}

void		push_back_cl(t_char_list **list, t_char_list *new)
{
	t_char_list	*tmp;

	if (*list == NULL)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
