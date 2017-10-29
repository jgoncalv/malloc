/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:26:22 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/30 17:26:23 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone	**zone_list(size_t size)
{
	if (size <= TINY)
		return (&g_env.tiny_zone);
	else if (size <= SMALL)
		return (&g_env.small_zone);
	else
		return (&g_env.large_zone);
}
