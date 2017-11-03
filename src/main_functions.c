/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:31:41 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/11/03 13:31:01 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_env					g_env = {NULL, NULL, NULL};
pthread_mutex_t			g_mutex = PTHREAD_MUTEX_INITIALIZER;

void		*malloc(size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_mutex);
	ptr = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
	void	*new;

	pthread_mutex_lock(&g_mutex);
	new = ft_realloc(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (new);
}

void		free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	ft_free(ptr);
	pthread_mutex_unlock(&g_mutex);
}

void		show_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	ft_show_alloc_mem();
	pthread_mutex_unlock(&g_mutex);
}

void		*calloc(size_t nmemb, size_t size)
{
	void *new;

	pthread_mutex_lock(&g_mutex);
	new = ft_calloc(nmemb, size);
	pthread_mutex_unlock(&g_mutex);
	return (new);
}
