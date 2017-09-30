/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_new_zone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:49:49 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/30 19:49:50 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_alloc *assign_in_new_zone(void *ptr, size_t size, t_alloc **list)
{
  t_alloc *new;
  t_alloc *cpy;

  cpy = *list;
  new = ptr;
  new->main_ptr = ptr;
  new->ptr = ptr + sizeof(t_alloc);
  new->len = size;
  new->next = NULL;

  if (*list == NULL)
  {

    printf("LIST %p\n", *list);
    printf(" ENV %p\n", g_env.tiny_alloc);
    printf("  New %p\n", new);
    *list = new;
    printf("LIST %p\n", *list);
    printf(" ENV %p\n", g_env.tiny_alloc);
    printf("  New %p\n", new);
  }
  else
  {

    while (cpy)
    {
      if (cpy->next == NULL)
      {
        cpy->next = new;
        break;
      }
      cpy = cpy->next;
    }
  }
  return (new->ptr);
}
