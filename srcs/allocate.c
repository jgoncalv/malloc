/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:30:34 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/23 18:30:36 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*allocate(size_t size, t_alloc *list)
{
	t_alloc	*new;

	new = (list->ptr + list->len);
	new->ptr = (void *)((size_t)new + sizeof(t_alloc));
	new->main_ptr = list->main_ptr;
	new->len = size;
	new->next = list->next;
	new->zone_len = list->zone_len;
	list->next = new;
	return (new->ptr);
}

void	*allocate_at_start(size_t size, t_alloc **list)
{
	t_alloc	*new;

	new = (*list)->main_ptr;
	new->ptr = (void *)((size_t)new + sizeof(t_alloc));
	new->main_ptr = (*list)->main_ptr;
	new->len = size;
	new->next = (*list)->next;
	new->zone_len = (*list)->zone_len;
	(*list) = new;
	return (new->ptr);
}
