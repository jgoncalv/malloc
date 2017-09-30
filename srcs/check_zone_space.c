/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zone_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:28:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/30 18:28:32 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int check_space(t_alloc *curr, t_alloc *next, size_t size)
{
  size_t zonesize;
  size_t len;

  zonesize = zone_size(size);

  if (next == NULL || curr->main_ptr != next->main_ptr)
  {

    len = (curr->main_ptr + zonesize) - (curr->ptr + curr->len);
    if (len <= size)
      return 1;
  }
  else
  {
    if (next->ptr - curr->ptr + curr->len <= size)
      return 1;
  }
  return 0;
}


t_alloc *check_zone_space(t_alloc *list, size_t size)
{
  t_alloc *list_next;


  if (list == NULL)
  {
    return NULL;
  }
  while (list)
  {
    list_next = list->next;

    if (check_space(list, list_next, size))
      return list;

    list = list->next;
  }
  return NULL;
}
