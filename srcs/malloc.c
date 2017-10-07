/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:33:57 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/23 15:33:59 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*allocate(t_zone *zone_list, size_t size, size_t size_alloc)
{
	t_alloc	*new_alloc;
	t_alloc	*cpy_alloc;
	t_zone	*zone;
	size_t	len;

	zone = zone_list;
	while (zone)
	{
		if (!zone->first_alloc ||
			((size_t)zone->first_alloc - ((size_t)zone + sizeof(t_zone))) >= size_alloc)
		{
			new_alloc = (void*)((size_t)zone + sizeof(t_zone));
			new_alloc->len = size;
			new_alloc->next = zone->first_alloc;
			zone->first_alloc = new_alloc;
			return ((void*)((size_t)new_alloc + sizeof(t_alloc)));
		}
		else
		{
			cpy_alloc = zone->first_alloc;
			while (cpy_alloc)
			{
				if (cpy_alloc->next == NULL)
				{
					len = ((size_t)zone + zone->zone_len)  - ((size_t)cpy_alloc + sizeof(t_alloc) + cpy_alloc->len);
					if (len >= size_alloc)
					{
						new_alloc = (void*)((size_t)cpy_alloc + sizeof(t_alloc) + cpy_alloc->len);
						new_alloc->len = size;
						new_alloc->next = NULL;
						cpy_alloc->next = new_alloc;

						return ((void*)((size_t)new_alloc + sizeof(t_alloc)));
					}
				}
				else
				{
					len = (size_t)cpy_alloc->next - ((size_t)cpy_alloc + sizeof(t_alloc) + cpy_alloc->len);
					if (len >= size_alloc)
					{
						new_alloc = (void*)((size_t)cpy_alloc + sizeof(t_alloc) + cpy_alloc->len);
						new_alloc->len = size;
						new_alloc->next = cpy_alloc->next;
						cpy_alloc->next = new_alloc;

						return ((void*)((size_t)new_alloc + sizeof(t_alloc)));
					}
				}
				cpy_alloc = cpy_alloc->next;
			}
		}
		zone = zone->next;
	}
	return (NULL);
}


void		*malloc(size_t size)
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
