/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:10:08 by mameyer           #+#    #+#             */
/*   Updated: 2016/11/15 15:55:12 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2 && n)
	{
		i = 0;
		while (*s1 && *s2 && i < n)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
			i++;
		}
	}
	return (1);
}