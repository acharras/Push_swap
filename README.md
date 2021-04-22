# Push_swap


ALGO 100 nombres

- Couper la stack A en 2 (médiane)
- Trouver le nombre de chunk en fonction du nombre de valeur donnée
- Check le premier nombre parmi le chunk 1 (par exemple chunk 1 = 0 - 19 trouver le premier nombre qui en fait parti) -> choisir le plus proche du haut de la stack A
- Faire RA si le nombre est en haut de la stack / RRA si il est en bas
- Une fois que le bon nombre est en haut de la stack A, faire tourner la stack B pour pouvoir insérer le nombre au bon endroit 


Répéter les étapes jusqu’a ce qu’il n’y est plus de nombre du chunk 1 dans la  stack A


Répéter les étapes pour les autres chunk

Une fois que la stack A est vide, trouver le plus grand nombre de la stack B, le mettre en haut de la stack B (utiliser rb ou rrb) et le push sur la stack A 

Faire ça jusqu’a ce que la stack B soit vide 

GG c’est fini


./push_swap -63 654 962 34 3254 421302 -9 0 1 856
./push_swap -63 35 654 98 12 65 962 34 658 3254 421302 3 032 741 3625 -9 0 1 856
./push_swap -63 35 654 98 12 65 962 34 658 3254 421302 3 032 741 3625  0 1 856 