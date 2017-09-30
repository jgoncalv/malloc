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
  t_alloc *list;
  t_alloc *curr_alloc;
  void *ptr;

  if (size <= 0)
    return NULL;
  list = zone_list(size);

  // si il y a de la place alors on a le pointeur de la structure avant celui que l'on veut placer donc on alloue
  // si il n'y en a pas alors on creer une nouvelle map et on alloue
  curr_alloc = check_zone_space(list, size);
  if (curr_alloc != NULL)
    return (allocate(size, curr_alloc));
  else
  {
    if ((ptr = create_new_zone(zone_size(size))) == NULL)
      return NULL;
    return (assign_in_new_zone(ptr, size, &list));
  }
}
