/*
** EPITECH PROJECT, 2018
** readfile.c
** File description:
** file for read the map
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Music.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include "my.h"
#include "box_and_finish.h"
#include "sprite_and_other.h"

int readfil(int ac, char **av)
{
	int j;
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(av[1], "r");
	j = getline(&line, &len, fp);
	j = j * 9 - 1;
	return (j);
}

char *readfile(int ac, char **av)
{
	int map;
	char *str;
	int i;
	int j = readfil(ac, av);

	str = malloc(sizeof(char) * j);
	map = open(av[1], O_RDONLY);
	while (i = read(map, str, j)) {
		str[i] = '\0';
	}
	return (str);
}

int sizeline(char *map)
{
	int i = 0;

	while (map[i] != '\n')
		i++;
	return (i + 1);
}
