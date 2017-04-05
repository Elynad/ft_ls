/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:41:31 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/05 15:53:29 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags			flags;
	t_box			box;
	t_folders		folders;
	struct stat		info;

	if (argc >= 2)
	{
		init_flags_struct(&flags);
		parsing(&flags, argv);
	}
//	init_box_struct(&box);
	recursive_test(flags);
	return (0);
}

/*
 *	Recuperation des flags utilises											OK
 *	Recuperation des noms de fichier dans un tableau
 *	Recuperation des noms de dossiers dans une liste chainee
 *	Affichage du contenu du dossier (ordre alpha ou inverse alpha)
 *	Recommencer dans l'un des dossiers contenu dans ./ (premier ou dernier)
*/
