/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_zone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:13:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/10/21 14:43:06 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int		check_limit(size_t size)
{
	struct rlimit	limit;

	if (getrlimit(RLIMIT_MEMLOCK, &limit) == -1)
		return (-1);
	if (limit.rlim_cur < size)
		return (-1);
	return (0);
}

static void		*create_map(size_t size)
{
	void	*ptr;

	if (check_limit(size + sizeof(t_alloc)) == -1)
		return (NULL);
	ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE
		| MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}

void			*create_new_zone(t_zone **zone, size_t size)
{
	t_zone	*new_zone;
	t_zone	*cpy;
	size_t	zone_len;

	zone_len = zone_size(size);
	new_zone = create_map(zone_len);
	if (!new_zone)
		return (NULL);
	new_zone->zone_len = zone_len;
	new_zone->first_alloc = NULL;
	new_zone->next = NULL;
	cpy = *zone;
	if (!(*zone))
		*zone = new_zone;
	else
	{
		while (cpy->next)
		{
			cpy = cpy->next;
		}
		cpy->next = new_zone;
	}
	return (new_zone);
}
