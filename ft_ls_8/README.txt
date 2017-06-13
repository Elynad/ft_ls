L'algo fonctionne et est rapide.

BUGS :
-	En cas de ls -Ra, l'algo essaie de cat un nouveau path a chaque fois et
		essaie d'ouvrir des dossiers comme "././././././././././"
		=> Ajouter une condition pour le set_newpath, pour qu'il ne cree pas de
		nouveau path si le nom du dossier est egal a "." ou a ".."

A FAIRE :
-	Fonctions de tri apres la recuperation des arguments et des contenus
-	Affichage avec l'option -l
