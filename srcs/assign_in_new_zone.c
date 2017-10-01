/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_new_zone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:49:49 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/30 19:49:50 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_alloc	*assign_in_new_zone(void *ptr, size_t size, t_alloc **list)
{
	t_alloc	*new;
	t_alloc	*cpy;

	cpy = *list;
	new = ptr;
	new->main_ptr = ptr;
	new->ptr = (void *)((size_t)ptr + sizeof(t_alloc));
	new->len = size;
	new->zone_len = zone_size(size);
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		while (cpy)
		{
			if (cpy->next == NULL)
			{
				cpy->next = new;
				break ;
			}
			cpy = cpy->next;
		}
	}
	return (new->ptr);
}
