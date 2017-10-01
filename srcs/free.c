/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:13:46 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/10/01 16:13:47 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	free_in_list(t_alloc **list, void *ptr)
{
	t_alloc	*cpy;
	t_alloc	*next;

	cpy = *list;
	if (cpy && cpy == ptr)
	{
		if (cpy->next == NULL || cpy->next->main_ptr != cpy->main_ptr)
			munmap(cpy->main_ptr, cpy->zone_len);
		*list = cpy->next;
		return (1);
	}
	while (cpy && cpy->next)
	{
		next = cpy->next;
		if (next == ptr)
		{
			if (cpy->main_ptr != next->main_ptr && (next->next == NULL
				|| (next->next->main_ptr != next->main_ptr)))
				munmap(next->main_ptr, next->zone_len);
			cpy->next = next->next;
			return (1);
		}
		cpy = cpy->next;
	}
	return (0);
}

void		free(void *ptr)
{
	void	*ptr_rch;

	if (ptr == NULL)
		return ;
	ptr_rch = (void *)((size_t)ptr - sizeof(t_alloc));
	if (free_in_list(&g_env.tiny_alloc, ptr)
		|| free_in_list(&g_env.small_alloc, ptr)
		|| free_in_list(&g_env.large_alloc, ptr))
		return ;
}
