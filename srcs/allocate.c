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

#include <sys/mman.h>

/*
**  Allocate with mmap and return the pointer
*/

void *allocate(size_t size)
{
  void *ptr;

  ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (ptr == MAP_FAILED)
  {
    return NULL
  }
  return ptr
}
