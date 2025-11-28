/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:49:30 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/28 00:49:54 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putstr(char *s);
int		ft_putnbr_base(long n, char *base);
int		ft_putchar(char c);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_print_pointer(void *ptr);
int		ft_printf(const char *s, ...);

#endif