/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** event for my_runner
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

int colision1(finish *tmp1, spritex *fish)
{
	if ((sfSprite_getPosition(tmp1->sprite).x
	>= sfSprite_getPosition(fish->sprite).x + 127)
	|| (sfSprite_getPosition(tmp1->sprite).x + 100
	<= sfSprite_getPosition(fish->sprite).x)
	|| (sfSprite_getPosition(tmp1->sprite).y
	>= sfSprite_getPosition(fish->sprite).y + 100)
	|| (sfSprite_getPosition(tmp1->sprite).y + 100
	<= sfSprite_getPosition(fish->sprite).y))
		return (0);
	else
		return (1);
}

int colision(Element *tmp, spritex *fish)
{
	if ((sfSprite_getPosition(tmp->sprite).x + 20
	>= sfSprite_getPosition(fish->sprite).x + 127)
	|| (sfSprite_getPosition(tmp->sprite).x + 80
	<= sfSprite_getPosition(fish->sprite).x)
	|| (sfSprite_getPosition(tmp->sprite).y
	>= sfSprite_getPosition(fish->sprite).y + 100)
	|| (sfSprite_getPosition(tmp->sprite).y + 100
	<= sfSprite_getPosition(fish->sprite).y))
		return (0);
	else
		return (1);
}

int event(sfRenderWindow *window, othersx *other, spritex *pause)
{
	sfRenderWindow_drawSprite(window, pause->sprite, NULL);
	sfRenderWindow_display(window);
	while (sfRenderWindow_pollEvent(window, &other->event)) {
		if (other->event.type == sfEvtKeyReleased
		&& other->event.key.code == sfKeyP)
			return (1);
		else
			return (0);
	}
}

void keyevent(spritex *fish)
{
	sfVector2f move = {0, -20};
	sfVector2f move1 = {0, 20};

	if (sfKeyboard_isKeyPressed(sfKeyUp)
	&& sfSprite_getPosition(fish->sprite).y > 0)
		sfSprite_move(fish->sprite, move);
	else if (sfKeyboard_isKeyPressed(sfKeyDown)
	&& sfSprite_getPosition(fish->sprite).y < 700)
		sfSprite_move(fish->sprite, move1);
}

void event_(sfRenderWindow *window, othersx *other, structs *alls)
{
	spritex pause = {sfTexture_createFromFile("src/graph/break.png",
	NULL), sfSprite_create(),{0, 0}, {0, 0}};
	int i = 0;

	sfSprite_setTexture(pause.sprite, pause.texture, sfTrue);
	while (sfRenderWindow_pollEvent(window, &other->event)) {
		if (other->event.type == sfEvtKeyReleased
		&& other->event.key.code == sfKeyP){
			while (i == 0) {
				i = event(window, other, &pause);
			}
		}
	}
	sfTexture_destroy(pause.texture);
	sfSprite_destroy(pause.sprite);
	keyevent(&alls->fish);
}
