/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:33:57 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/23 15:33:59 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *malloc(size_t size)
{
  void *list;
  t_alloc *curr_alloc;
  void *ptr;

  if (size <= 0)
    return NULL;
  list = zone_list(size);

  printf(" ICI DEBUT %p\n", list);
  curr_alloc = check_zone_space(list, size);
  if (curr_alloc != NULL)
  {
    ft_putstr("my friend");
    return (allocate(size, curr_alloc));
  }
  else
  {
    if ((ptr = create_new_zone(zone_size(size))) == NULL)
      return NULL;
    return (assign_in_new_zone(ptr, size, (void *)list));
  }


}
