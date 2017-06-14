________________________
          BUGS
________________________

(resolu)			- En cas de ls -Ra, l'algo essaie de cat un nouveau path a
					chaque fois et essaie d'ouvrir des dossiers comme
					"././././././././././"
					=> Ajouter une condition pour le set_newpath, pour qu'il ne
					cree pas de nouveau path si le nom du dossier est egal a "."
					ou a ".."

(resolu)			- Si un fichier a pour proprietaire root, les permissions du
					proprietaire sont donc "rwx". L'algo voit que le
					proprietaire a les droits de lecture et essaie donc de lire
					l'element.
					=> Ajouter une condition : Si le proprietaire du fichier est
					different de l'utilisateur actuel ET que le groupe du
					proprietaire est different du groupe de l'utilisateur ET que
					les droits de OTH en lecture ne sont pas actifs, alors
					message d'erreur : Permission denied.

					- Si on fait ft_ls empty_directory, le programme affiche le
					nom du dossier suivi d'une ligne vide
					=> Le programme ne devrait rien afficher

					- Impossible de compter les dependances d'un dossier si on
					n'a pas les droits de lecture dessus.
					=> st_nlink

________________________
          A FAIRE
________________________
-	Fonctions de tri apres la recuperation des arguments et des contenus


-	Affichage avec l'option -l


-	Modifier tous les appels de la fonction d'erreur et les remplacer par perror
		///// DONE /////

-	Ajouter une condition pour gerer les permissions
			=> Recuperer le nom de l'user puis le nom de son groupee
			=> Si on n'a pas les permissions :
			Affichage d'erreur (ls: nom_de_l_elem: Permission denied\n)
			=> L'algo doit continuer
		///// DONE /////

-	Fonction qui free toutes les listes allouees

-	Toujours 2 espaces entre l'information la plus longue et les autres autour
