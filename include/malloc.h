/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:38:26 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/11/03 13:07:25 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <pthread.h>

# define TINY 1024
# define SMALL 2048

typedef struct			s_alloc {
	size_t				len;
	struct s_alloc		*next;
}						t_alloc;

typedef struct			s_zone
{
	size_t				zone_len;
	struct s_alloc		*first_alloc;
	struct s_zone		*next;
}						t_zone;

typedef struct			s_env {
	struct s_zone		*tiny_zone;
	struct s_zone		*small_zone;
	struct s_zone		*large_zone;
}						t_env;

extern t_env			g_env;
extern pthread_mutex_t	g_mutex;

void					*malloc(size_t size);
void					*ft_malloc(size_t size);
void					*create_new_zone(t_zone **zone, size_t size);
t_zone					**zone_list(size_t size);
size_t					zone_size(size_t req_size);

void					free(void *ptr);
void					ft_free(void *ptr);

void					*realloc(void *ptr, size_t size);
void					*ft_realloc(void *ptr, size_t size);

void					show_alloc_mem();
void					ft_show_alloc_mem();

void					*calloc(size_t nmemb, size_t size);
void					*ft_calloc(size_t nmemb, size_t size);

size_t					ft_strlen(const char *str);
void					ft_putnbr(intmax_t n);
void					ft_putchar(char c);
void					ft_putstr(char const *str);

#endif
