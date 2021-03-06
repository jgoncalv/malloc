/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:13:46 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/11/02 20:37:09 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	check_and_free(t_alloc **alloc, void *ptr)
{
	t_alloc *tmp;
	t_alloc *tmp2;

	tmp = *alloc;
	if (*alloc == ptr)
	{
		*alloc = (*alloc)->next;
		return (1);
	}
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp2 == ptr)
		{
			tmp->next = tmp2->next;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	free_in_list_next(t_zone **zone, t_zone *cpy)
{
	t_zone *tmp;
	t_zone *tmp2;

	if (*zone == cpy && (*zone)->next)
	{
		tmp = (*zone)->next;
		if (munmap(cpy, cpy->zone_len) == 0)
			*zone = tmp;
	}
	else if (cpy != *zone)
	{
		tmp = *zone;
		while (tmp->next != cpy)
			tmp = tmp->next;
		tmp2 = cpy->next;
		if (munmap(cpy, cpy->zone_len) == 0)
			tmp->next = cpy->next;
	}
}

static int	free_in_list(t_zone **zone, void *ptr)
{
	t_zone	*cpy;
	int		res;

	cpy = *zone;
	res = 0;
	while (cpy)
	{
		res = check_and_free(&cpy->first_alloc, ptr);
		if (cpy->first_alloc == NULL && res == 1)
		{
			free_in_list_next(zone, cpy);
			return (res);
		}
		cpy = cpy->next;
	}
	return (res);
}

void		ft_free(void *ptr)
{
	void	*ptr_rch;

	if (ptr == NULL)
		return ;
	ptr_rch = (void*)((size_t)ptr - sizeof(t_alloc));
	if (free_in_list(&g_env.tiny_zone, ptr_rch) == 1
		|| free_in_list(&g_env.small_zone, ptr_rch) == 1
		|| free_in_list(&g_env.large_zone, ptr_rch) == 1)
		return ;
}
