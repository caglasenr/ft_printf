/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ffonks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:20:05 by csener            #+#    #+#             */
/*   Updated: 2025/07/08 11:33:58 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putint(int n)
{
	long	nbr;
	int		len;
	int		tmp;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nbr = -nbr;
		len++;
	}
	if (nbr > 9)
	{
		tmp = ft_putint(nbr / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar((nbr % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_putuint(unsigned int n)
{
	long	nbr;
	int		len;
	int		tmp;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr > 9)
	{
		tmp = ft_putuint(nbr / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar((nbr % 10) + '0') == -1)
		return (-1);
	len++;
	return (len);
}
