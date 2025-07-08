/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:37:07 by csener            #+#    #+#             */
/*   Updated: 2025/07/07 14:22:02 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	format_ind(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(args, int)));
	if (c == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_format(va_list args, const char *format)
{
	int	i;
	int	written;
	int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			written = format_ind(args, format[i + 1]);
			if (written == -1)
				return (-1);
			len += written;
			i += 2;
			continue ;
		}
		if (ft_putchar(format[i]) == -1)
			return (-1);
		len++;
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	len = ft_format(args, format);
	va_end(args);
	return (len);
}
