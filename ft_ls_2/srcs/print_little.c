/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_little.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:17:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/05 18:01:01 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_type(char *str, struct stat sb)
{
	if (S_ISDIR (sb.st_mode))
		ft_putchar('d');
	else
		ft_putchar('-');
}
