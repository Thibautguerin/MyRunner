/*
** EPITECH PROJECT, 2018
** put_in_list.c
** File description:
** put new element in linked lists for my runner
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

void my_put_in_listf(listef *fin, int i, int line)
{
	finish *nouveau1 = malloc(sizeof(*nouveau1));
	sfVector2f position = {(100 * i), (100 * line)};
	sfVector2f speed = {-17, 0};

	nouveau1->texture = sfTexture_createFromFile("src/graph/f.png", NULL);
	nouveau1->sprite = sfSprite_create();
	nouveau1->position = position;
	nouveau1->speed = speed;
	sfSprite_setTexture(nouveau1->sprite, nouveau1->texture, sfTrue);
	sfSprite_setPosition(nouveau1->sprite, nouveau1->position);
	nouveau1->next = fin->first;
	fin->first = nouveau1;
}

void my_put_in_list(Liste *boxx, int i, int line)
{
	Element *nouveau = malloc(sizeof(*nouveau));
	sfVector2f position = {(100 * i), (100 * line)};
	sfVector2f speed = {-17, 0};

	nouveau->texture = sfTexture_createFromFile("src/graph/box.png", NULL);
	nouveau->sprite = sfSprite_create();
	nouveau->position = position;
	nouveau->speed = speed;
	sfSprite_setTexture(nouveau->sprite, nouveau->texture, sfTrue);
	sfSprite_setPosition(nouveau->sprite, nouveau->position);
	nouveau->next = boxx->first;
	boxx->first = nouveau;
}
