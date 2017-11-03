/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:35:11 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/11/03 13:31:47 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
		ptr[i++] = c;
	return (s);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	s;

	s = nmemb * size;
	if (!(p = ft_malloc(s)))
		return (p);
	ft_memset(p, 0, s);
	return (p);
}
