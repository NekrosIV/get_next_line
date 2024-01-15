# get_next_line

## Description
Le projet Get Next Line de l'école 42 consiste en l'implémentation d'une fonction permettant de lire une ligne depuis un descripteur de fichier, que ce soit un fichier texte ou l'entrée standard. La fonction `get_next_line` doit être capable de lire successivement toutes les lignes du fichier.

## Partie Obligatoire

### Sujet
- [x] **[Sujet](fr.subject.pdf):** Voici le sujet de `get_next_line`.

### Fonction Principale
- [x] **[get_next_line.c](get_next_line.c ):** La fonction principale qui lit une ligne depuis un descripteur de fichier.

### Fichiers Associés
- [x] **[get_next_line.h](get_next_line.h ):** Fichier d'en-tête contenant les prototype des fonctions pour la partie Principale.
- [x] **[get_next_line_utils.c](get_next_line_utils.c ):** Fichier contenant des fonctions utilitaires nécessaires à la réalisation de `get_next_line`.

## Partie Bonus

### Fonction Principale
- [x] **[get_next_line_bonus.c](get_next_line_bonus.c ):** Version de la fonction principale permettant de gérer plusieurs descripteurs de fichier et avec une seule variable statique.

### Fichiers Associés
- [x] **[get_next_line_bonus.h](get_next_line_bonus.h ):** Fichier d'en-tête contenant les prototype des fonctions pour la partie bonus.
- [x] **[get_next_line_utils_bonus.c](get_next_line_utils_bonus.c ):** Fichier contenant des fonctions utilitaires nécessaires à la réalisation de `get_next_line_bonus`.

## Utilisation
```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("README.md", O_RDONLY);
    char *line;

    // avec cette boucle la fonctione va lire tout le fichier
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
### Compilation
Le programme doit être compilé avec l'option `-D BUFFER_SIZE=n`, où `n` est la taille du buffer lors des appels à `read()`.

Exemple de compilation :
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
## Note

- Voici la note que j'ai obtenue :
    ![Note](img.png)
