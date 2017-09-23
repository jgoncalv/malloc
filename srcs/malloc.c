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
  char *ptr = NULL;

  if (size <= TINY)
  {
    ptr = "hi";
  }
  else if (size <= SMALL)
  {

  }
  else
  {

  }

  return NULL;
}
