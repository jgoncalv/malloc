/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:30:34 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/23 18:30:36 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void *allocate(size_t size, t_alloc *list)
{
  t_alloc *next;
  t_alloc *new;
  void *ptr;

  next = list->next;
  new = (list->ptr + list->len);
  ptr = new;
  new->main_ptr = list->main_ptr;
  new->ptr = ptr + sizeof(t_alloc);
  new->len = size;
  new->next = next;
  list->next = new;
  return new->ptr;
}
