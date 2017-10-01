/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:14:41 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/30 18:14:42 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t	get_zone(size_t size)
{
	if (size <= TINY)
		return (TINY + sizeof(t_alloc)) * 100;
	else if (size <= SMALL)
		return (SMALL + sizeof(t_alloc)) * 100;
	return (size + sizeof(t_alloc));
}

size_t			zone_size(size_t req_size)
{
	size_t	size;
	size_t	pagesize;

	pagesize = getpagesize();
	size = get_zone(req_size + sizeof(t_alloc));
	if (size % pagesize)
		size += pagesize - size % pagesize;
	return (size);
}
