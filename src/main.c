/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for my runner
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

structs structalls(int sizel)
{
	spritex s = {sfTexture_createFromFile("src/graph/b1.png", NULL),
	sfSprite_create(), {0, 0}, {-1, 0}};
	spritex s1 = {sfTexture_createFromFile("src/graph/b2.png", NULL),
	sfSprite_create(), {0, 0}, {-2, 0}};
	spritex s2 = {sfTexture_createFromFile("src/graph/b3.png", NULL),
	sfSprite_create(), {0, 0}, {-5, 0}};
	spritex s3 = {sfTexture_createFromFile("src/graph/b4.png", NULL),
	sfSprite_create(), {0, 0}, {-17, 0}};
	spritex fish = {sfTexture_createFromFile("src/graph/fish.png", NULL),
	sfSprite_create(), {200, 340}, {0, 0}};
	spritex score = {sfTexture_createFromFile("src/graph/barre.png", NULL),
	sfSprite_create(), {345, 20}, {0, 0}};
	spritex sp = {sfTexture_createFromFile("src/graph/score.png", NULL),
	sfSprite_create(), {350, 25}, {50, 0}};
	structs alls = {s, s1, s2, s3, fish, score, sp,
	(100 * sizel - 327), (100 * sizel - 327)};

	return (alls);
}

void main2(int sizel, char **av, Liste *boxx, listef *fin)
{
	sfVideoMode mode = {1200, 800, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode,
	"My fish Runner", sfClose, NULL);
	othersx other = {{-127, 0, 127, 100}, 0};
	structs alls = structalls(sizel);

	mainmenu(window, &other);
	init(window, &alls);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_display(window);
		event_(window, &other, &alls);
		spritesheet(&other, &alls);
		display(window, &alls, boxx, fin);
		moveall(&alls, boxx, fin, window);
	}
	sfRenderWindow_destroy(window);
}

void redirectionseption(placement *place, Liste *boxx, char *map, listef *fin)
{
	if (map[place->i] == 'C')
		mapp(place, boxx);
	else if (map[place->i] == '-')
		placefinish(place, fin);
	else if (map[place->i] == '\n')
		place->line++;
	place->i++;
}

void redirection(int ac, char **av)
{
	char *map = readfile(ac, av);
	placement place = {0, 0, 0, 0};
	Liste *boxx = initialisation(place.i, place.line);
	listef *fin = initialisationf(place.i, place.line);
	sfMusic *music = sfMusic_createFromFile("src/audio/music.wav");

	place.sizel = sizeline(map);
	sfMusic_setLoop(music, sfTrue);
	sfMusic_setVolume(music, 30);
	sfMusic_play(music);
	while (map[place.i] != '#')
		redirectionseption(&place, boxx, map, fin);
	free(map);
	main2(place.sizel, av, boxx, fin);
	sfMusic_destroy(music);
}

int main(int ac, char **av)
{
	if (ac != 2) {
		manual(ac);
		return (84);
	}
	else if (my_strcmp(av[1], "-h") == 0) {
		manual(ac);
		return (0);
	}
	else if (open(av[1], O_RDONLY) >= 0) {
		redirection(ac, av);
		return (0);
	} else {
		manual(ac);
		return (84);
	}
}
