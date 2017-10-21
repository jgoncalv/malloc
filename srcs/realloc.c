/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 19:05:42 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/10/21 17:28:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_alloc	*search_in_env(void *ptr, t_zone *zone)
{
	t_alloc	*alloc;

	while (zone)
	{
		alloc = zone->first_alloc;
		while (alloc)
		{
			if (alloc == ptr)
				return (alloc);
			alloc = alloc->next;
		}
		zone = zone->next;
	}
	return (NULL);
}

static t_alloc	*get_alloc(void *ptr)
{
	t_alloc *alloc;

	if ((alloc = search_in_env(ptr, g_env.tiny_zone))
	|| (alloc = search_in_env(ptr, g_env.small_zone))
	|| (alloc = search_in_env(ptr, g_env.large_zone)))
		return (alloc);
	return (NULL);
}

static void		copy_ptr(void *dest, void *src, size_t size)
{
	size_t	len;
	size_t	i;
	t_alloc	*alloc_src;

	i = 0;
	alloc_src = (t_alloc*)(src - sizeof(t_alloc));
	len = alloc_src->len;
	while (i < len && i < size)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
}

void			*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	t_alloc	*alloc;

	new_ptr = NULL;
	if (size == 0
		|| !(alloc = get_alloc((void*)((size_t)ptr - sizeof(t_alloc)))))
		return (NULL);
	if (alloc->len >= size)
	{
		alloc->len = size;
		return (ptr);
	}
	else
	{
		new_ptr = malloc(size);
		copy_ptr(new_ptr, ptr, size);
		free(ptr);
		return (new_ptr);
	}
}
