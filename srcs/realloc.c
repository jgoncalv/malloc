/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 19:05:42 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/10/01 19:05:43 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_alloc *search_in_env(void *ptr, t_alloc *list)
{
	while (list)
	{
		if (list->ptr == ptr)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	t_alloc	*alloc;

	if (ptr == NULL)
		return (NULL);
	if ((alloc = search_in_env(ptr, g_env.tiny_alloc))
		|| (alloc = search_in_env(ptr, g_env.small_alloc))
		|| (alloc = search_in_env(ptr, g_env.large_alloc)))
	{
		if (alloc->len >= size)
		{
			alloc->len = size;
			return (ptr);
		}
		else if (alloc->next && (((size_t)alloc->next - (size_t)alloc->ptr) >= size))
		{
			alloc->len = size;
			return (ptr);
		}
		else if (alloc->next == NULL)
		{
			if (alloc->zone_len - (size_t)alloc->ptr >= size)
			{
				alloc->len = size;
			}
			return (ptr);
		}
		else
		{
			if ((new_ptr = malloc(size)) == NULL)
				return (NULL);
			ft_memcpy(new_ptr, ptr, size);
			free(ptr);
		}
	}
	else
	{
		if ((new_ptr = malloc(size)) == NULL)
			return (NULL);
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}
