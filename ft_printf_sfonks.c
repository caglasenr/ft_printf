/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sfonks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:20:17 by csener            #+#    #+#             */
/*   Updated: 2025/07/08 11:39:27 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;
	int	tmp;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	tmp = write(1, "0x", 2);
	if (tmp == -1)
		return (-1);
	count += tmp;
	tmp = ft_puthex((unsigned long)ptr, 0);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}

int	ft_puthex(unsigned long pa, int type)
{
	int			count;
	const char	*hex_chars;
	int			tmp;

	count = 0;
	if (type == 1)
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	if (pa > 15)
	{
		tmp = ft_puthex(pa / 16, type);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (ft_putchar(hex_chars[pa % 16]) == -1)
		return (-1);
	return (count + 1);
}
