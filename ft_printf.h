/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:16:17 by csener            #+#    #+#             */
/*   Updated: 2025/07/07 16:58:57 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_puthex(unsigned long pa, int type);
int		ft_putptr(void *ptr);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putint(int n);
int		ft_putuint(unsigned int n);
int		ft_printf(const char *format, ...);

#endif