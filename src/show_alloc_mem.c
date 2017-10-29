/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:55:24 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/10/21 18:11:55 by jgoncalv         ###   ########.fr       */
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

static size_t	show_alloc_mem_while(t_alloc *list)
{
	size_t ptr;
	size_t total;

	total = 0;
	while (list)
	{
		total += list->len;
		ptr = (size_t)list + sizeof(t_alloc);
		en_hex(ptr);
		ft_putstr(" - ");
		en_hex(ptr + list->len - 1);
		ft_putstr(" : ");
		ft_putnbr(list->len);
		ft_putstr(" octets\n");
		list = list->next;
	}
	return (total);
}

static size_t	show_zone(t_zone *zone, char *name)
{
	size_t total;

	total = 0;
	while (zone)
	{
		ft_putstr(name);
		ft_putstr(" : ");
		en_hex((size_t)zone);
		ft_putstr("\n");
		total += show_alloc_mem_while(zone->first_alloc);
		zone = zone->next;
	}
	return (total);
}

void			show_alloc_mem(void)
{
	size_t total_alloc;

	total_alloc = 0;
	total_alloc += show_zone(g_env.tiny_zone, "TINY");
	total_alloc += show_zone(g_env.small_zone, "SMALL");
	total_alloc += show_zone(g_env.large_zone, "LARGE");
	ft_putstr("Total = ");
	ft_putnbr(total_alloc);
	ft_putstr(" octets\n");
}
