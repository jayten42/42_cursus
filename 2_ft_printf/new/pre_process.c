/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:06:08 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/26 17:50:12 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pre_process_char(va_list ap, t_tag *tag)
{
	wint_t	w;
	char	*res;
	char	c;

	if (tag->len_mod == DISABLED)
	{
		c = (char)va_arg(ap, int);
		return (print_char(tag, c));
	}
	else if (tag->len_mod == 'l')
	{
		w = (wchar_t)va_arg(ap, wint_t);
		res = ft_atouni(w);
		return (print_string(tag, res));
	}
	return (ERROR);
}

int pre_process_str(va_list ap, t_tag *tag)
{
	wchar_t	*ws;
	char	*res;

	if (tag->len_mod == DISABLED)
	{
		res = (char *)va_arg(ap, char *);
		return (print_string(tag, res));
	}
	else if (tag->len_mod == 'l')
	{
		ws = va_arg(ap, wchar_t *);
		//while (ws[i] != L'\0')
		res = ft_atouni(ws[0]);
		return (print_string(tag, res));
	}
	return (ERROR);
}

int pre_process_int(va_list ap, t_tag *tag)
{
	char		*res;

	if (tag->len_mod == DISABLED)
		res = ft_itoa((int)va_arg(ap, int));
	else if (tag->len_mod == 'h' + 'h')
		res = ft_itoa((char)va_arg(ap, int));
	else if (tag->len_mod == 'h')
		res = ft_itoa((short)va_arg(ap, int));
	else if (tag->len_mod == 'l' + 'l')
		res = ft_itoa((long)va_arg(ap, long));
	else if (tag->len_mod == 'l')
		res = ft_itoa((long long)va_arg(ap, long long));
	else
		return (ERROR);
	return (print_int(tag, res));
}

int pre_process_unsigned_int(va_list ap, t_tag *tag)
{
	char		*res;

	if (tag->len_mod == DISABLED)
		res = ft_uitoa((int)va_arg(ap, int));
	else if (tag->len_mod == 'h' + 'h')
		res = ft_uitoa((char)va_arg(ap, int));
	else if (tag->len_mod == 'h')
		res = ft_uitoa((short)va_arg(ap, int));
	else if (tag->len_mod == 'l' + 'l')
		res = ft_uitoa((long)va_arg(ap, long));
	else if (tag->len_mod == 'l')
		res = ft_uitoa((long long)va_arg(ap, long long));
	else
		return (ERROR);
	return (print_unsigned_int(tag, res));
}
int pre_process_hex(va_list ap, t_tag *tag, char *base)
{
	char	*res;

	if (tag->len_mod == DISABLED)
		res = ft_itoa_base(va_arg(ap, int), base);
	else if (tag->len_mod == 'h' + 'h')
		res = ft_itoa_base((char)va_arg(ap, int), base);
	else if (tag->len_mod == 'h')
		res = ft_itoa_base((short)va_arg(ap, int), base);
	else if (tag->len_mod == 'l' + 'l')
		res = ft_itoa_base((long)va_arg(ap, long), base);
	else if (tag->len_mod == 'l')
		res = ft_itoa_base((long long)va_arg(ap, long long), base);
	else
		return (ERROR);
	return (print_hexa(tag, res));
}
