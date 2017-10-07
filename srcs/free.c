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

	
	while (zone)
	{
		
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
	if (free_in_list(&g_env.tiny_alloc, ptr_rch) == 1
		|| free_in_list(&g_env.small_alloc, ptr_rch) == 1
		|| free_in_list(&g_env.large_alloc, ptr_rch) == 1)
		return ;
}
