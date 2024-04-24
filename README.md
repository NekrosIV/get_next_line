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

### main.c
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
  ```c
  #include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + 1));
	return (0);
}
char	*ft_strdup(char *s)
{
	int		i;
	char	*r;

	i = 0;
	if (!s)
		return (0);
	r = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!r)
		return (0);
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
void	ft_new_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
}

char	*ft_join_and_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	r = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!r)
		return (0);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	free(s1);
	return (r);
}

char	*result(char *s, int byte_read)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (free(s), NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	free(s);
	if (!line || (byte_read == 0 && ft_strlen(line) < 1))
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			byte_read;
	char		*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	storage = 0;
	if (ft_strchr(buffer, '\n') != 0)
	{
		storage = ft_strdup(ft_strchr(buffer, '\n') + 1);
		ft_new_buffer(buffer);
	}
	byte_read = 1;
	while (!ft_strchr(buffer, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (0);
		buffer[byte_read] = '\0';
		storage = ft_join_and_free(storage, buffer);
	}
	return (result(storage, byte_read));
}
```
