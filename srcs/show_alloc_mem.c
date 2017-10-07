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

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}



void	ft_putstr(char const *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(intmax_t n)
{
	if (n >= 10 || n <= -10)
	{
		ft_putnbr(n / 10);
		if (n < 0)
			ft_putchar((n % 10) * -1 + '0');
		else
			ft_putchar(n % 10 + '0');
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			ft_putchar((n % 10) * -1 + '0');
		}
		else
			ft_putchar(n % 10 + '0');
	}
}



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
	ft_putstr(name);
	ft_putstr(" : ");
	en_hex((size_t)zone);
	ft_putstr("\n");
	while (zone)
	{
		show_alloc_mem_while(zone->first_alloc);
		zone = zone->next;
	}
}

void			show_alloc_mem()
{
	show_zone(g_env.tiny_zone, "TINY");
	show_zone(g_env.small_zone, "SMALL");
	show_zone(g_env.large_zone, "LARGE");
}
