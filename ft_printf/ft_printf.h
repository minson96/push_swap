/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:14:35 by minson            #+#    #+#             */
/*   Updated: 2023/04/29 17:13:10 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *sentence, ...);
int		check_form(const char c, va_list *list);
int		print_char(int c);
int		print_str(char *str);
int		print_nbr(int nbr, char *base);
int		print_unsigned_int(unsigned int nbr, char *base);
int		print_hex(unsigned int nbr, char *base);
int		print_ptr(unsigned long long ptr);

#endif