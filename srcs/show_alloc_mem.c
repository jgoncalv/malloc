/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:55:24 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/10/21 16:28:39 by jgoncalv         ###   ########.fr       */
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
		while (i > -1)
		{
			cpy = ft_pow(16, i);
			ft_putchar(((hex / cpy) % 16) +
			((hex / cpy) % 16 > 9 ? 'a' - 10 : '0'));
			i--;
		}
	}
}

static void		show_alloc_mem_while(t_alloc *list)
{
	size_t ptr;

	while (list)
	{
		ptr = (size_t)list + sizeof(t_alloc);
		en_hex(ptr);
		ft_putstr(" - ");
		en_hex(ptr + list->len - 1);
		ft_putstr(" : ");
		ft_putnbr(list->len);
		ft_putstr(" octets\n");
		list = list->next;
	}
}

static void		show_zone(t_zone *zone, char *name)
{
	while (zone)
	{
		ft_putstr(name);
		ft_putstr(" : ");
		en_hex((size_t)zone);
		ft_putstr("\n");
		show_alloc_mem_while(zone->first_alloc);
		zone = zone->next;
	}
}

void			show_alloc_mem(void)
{
	show_zone(g_env.tiny_zone, "TINY");
	show_zone(g_env.small_zone, "SMALL");
	show_zone(g_env.large_zone, "LARGE");
}
