/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:49:50 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/10/21 15:51:24 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	ft_strlen(const char *str)
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
