/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_zone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:13:28 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/30 18:13:29 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int check_limit(size_t size)
{
  struct rlimit limit;

  if (getrlimit(RLIMIT_MEMLOCK, &limit) == -1)
    return (-1);
  if (limit.rlim_cur < size)
    return (-1);
  return (0);
}

void *create_new_zone(size_t size)
{
  void *ptr;

  if (check_limit(size + sizeof(t_alloc)) == -1)
    return (NULL);
  ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (ptr == MAP_FAILED)
    return (NULL);
  return (ptr);
}
