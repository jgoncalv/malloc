/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:33:57 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/11/02 22:32:44 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t	get_len(t_zone *zone, t_alloc *cpy)
{
	if (cpy->next == NULL)
		return (((size_t)zone + zone->zone_len) -
		((size_t)cpy + sizeof(t_alloc) + cpy->len));
	else
		return ((size_t)cpy->next -
		((size_t)cpy + sizeof(t_alloc) + cpy->len));
}

static void		*allocate_next(t_alloc *cpy,
	t_zone *zone, size_t size, size_t size_alloc)
{
	t_alloc	*new_alloc;

	while (cpy)
	{
		if (get_len(zone, cpy) >= size_alloc)
		{
			new_alloc = (void*)((size_t)cpy + sizeof(t_alloc) + cpy->len);
			new_alloc->len = size;
			new_alloc->next = cpy->next;
			cpy->next = new_alloc;
			return ((void*)((size_t)new_alloc + sizeof(t_alloc)));
		}
		cpy = cpy->next;
	}
	return (NULL);
}

static void		*allocate(t_zone *zone_list, size_t size, size_t size_alloc)
{
	t_alloc	*new_alloc;
	t_zone	*zone;
	void	*ptr;

	zone = zone_list;
	while (zone)
	{
		if (!zone->first_alloc ||
			((size_t)zone->first_alloc -
			((size_t)zone + sizeof(t_zone))) >= size_alloc)
		{
			new_alloc = (void*)((size_t)zone + sizeof(t_zone));
			new_alloc->len = size;
			new_alloc->next = zone->first_alloc;
			zone->first_alloc = new_alloc;
			return ((void*)((size_t)new_alloc + sizeof(t_alloc)));
		}
		if ((ptr = allocate_next(zone->first_alloc, zone, size, size_alloc))
		!= NULL)
			return (ptr);
		zone = zone->next;
	}
	return (NULL);
}

void			*ft_malloc(size_t size)
{
	t_zone	**zone_list_ptr;
	t_zone	*zone;
	void	*ptr;

	if (size <= 0)
		return (NULL);
	zone_list_ptr = zone_list(size);
	ptr = allocate(*zone_list_ptr, size, size + sizeof(t_alloc));
	if (!ptr)
	{
		if (!(zone = create_new_zone(zone_list_ptr, size)))
			return (NULL);
		ptr = allocate(zone, size, size + sizeof(t_alloc));
	}
	return (ptr);
}
