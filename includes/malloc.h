/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:38:26 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/23 15:38:30 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft.h"
# include <unistd.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>

# define TINY 1024
# define SMALL 2048

typedef struct		s_alloc {
	void			*main_ptr;
	void			*ptr;
	size_t			len;
	size_t			zone_len;
	struct s_alloc	*next;
}					t_alloc;

typedef struct		s_env {
	t_alloc			*tiny_alloc;
	t_alloc			*small_alloc;
	t_alloc			*large_alloc;
}					t_env;

t_env				g_env;

size_t				zone_size(size_t req_size);
t_alloc				**zone_list(size_t size);
void				*malloc(size_t size);
t_alloc				*check_zone_space(t_alloc *list, size_t size);
t_alloc				*assign_in_new_zone(void *ptr, size_t size, t_alloc **list);
void				*create_new_zone(size_t size);
void				*allocate(size_t size, t_alloc *list);
void				free(void *ptr);
int					check_space_start_to_first_alloc(t_alloc *list,
					size_t size);
void				*allocate_at_start(size_t size, t_alloc **list);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();

#endif
