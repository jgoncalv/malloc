/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:55:24 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/09/23 18:55:26 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static double	ft_pow(double n, int exp)
{
    if (exp == 0)
        return (1);
    else if (exp > 0)
        return (n * ft_pow(n, exp - 1));
    else
        return (1 / n * ft_pow(1 / n, -exp - 1));
}

static void		en_hex(size_t hex)
{
	int		i;
	size_t	cpy;

	i = 0;
	cpy = hex;
	ft_putstr("0x");
	if (hex == 0)
		ft_putchar('0');
	else
	{
		while (cpy)
		{
			i++;
			cpy /= 16;
		}
		i--;
		while (i  > -1)
		{
			cpy = ft_pow(16, i);	
			ft_putchar(((hex / cpy) % 16) + ((hex / cpy) % 16 > 9 ? 'a' - 10 : '0'));
			i--;
		}
	}
}

static void		show_alloc_mem_while(t_alloc *list, char *name)
{
	ft_putstr(name);
	ft_putstr(" : ");
	en_hex((size_t)list);
	ft_putchar('\n');
	while (list)
	{
		printf("%p\n", list->ptr);
		en_hex((size_t)list->ptr);
		ft_putstr(" - ");
		en_hex((size_t)list->ptr + list->len - 1);
		ft_putstr(" : ");
		ft_putnbr(list->len);
		ft_putstr(" octets\n");
		list = list->next;
	}
}

void			show_alloc_mem()
{
	show_alloc_mem_while(g_env.tiny_alloc, "TINY");
	show_alloc_mem_while(g_env.small_alloc, "SMALL");
	show_alloc_mem_while(g_env.large_alloc, "LARGE");
}
