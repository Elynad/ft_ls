/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:33:50 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/22 17:48:48 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_lst		cpy_lst(t_lst content)
{
	t_lst		tmp;

	tmp.name = ft_strdup(content.name);
	tmp.path = ft_strdup(content.path);
	tmp.next = content.next;
	return (tmp);
}
