/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:41:18 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/25 12:35:43 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_printfgnrl(long int nmbr, char *base, int bsize);
int	ft_putchar(char c);
int	ft_putstr(char *ptr);
int	ft_printfptr(unsigned long int nmbr, char *base, int hex);

#endif
