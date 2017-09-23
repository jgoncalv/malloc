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

# include <unistd.h>
# include <sys/mman.h>


# define TINY 49
# define SMALL 900

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *allocate(size_t size);
void show_alloc_mem();

#endif
