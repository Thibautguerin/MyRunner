/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** initialisation of linked list and others for my runner
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

void placefinish(placement *place, listef *fin)
{
	if (place->line == 0)
		place->j = place->i;
	else
		place->j = place->i - place->sizel * place->line;
	my_put_in_listf(fin, place->j, place->line);
}

void mapp(placement *place, Liste *boxx)
{
	if (place->line == 0)
		place->j = place->i;
	else
		place->j = place->i - place->sizel * place->line;
	my_put_in_list(boxx, place->j, place->line);
}

listef *initialisationf(int i, int line)
{
	listef *liste1 = malloc(sizeof(*liste1));
	finish *element1 = malloc(sizeof(*element1));
	sfVector2f position = {-100, 0};
	sfVector2f speed = {-17, 0};

	element1->texture = sfTexture_createFromFile("src/graph/f.png", NULL);
	element1->sprite = sfSprite_create();
	element1->position = position;
	element1->speed = speed;
	sfSprite_setTexture(element1->sprite, element1->texture, sfTrue);
	sfSprite_setPosition(element1->sprite, element1->position);
	element1->next = NULL;
	liste1->first = element1;
	return (liste1);
}

Liste *initialisation(int i, int line)
{
	Liste *liste = malloc(sizeof(*liste));
	Element *element = malloc(sizeof(*element));
	sfVector2f position = {-100, 0};
	sfVector2f speed = {-17, 0};

	element->texture = sfTexture_createFromFile("src/graph/box.png", NULL);
	element->sprite = sfSprite_create();
	element->position = position;
	element->speed = speed;
	sfSprite_setTexture(element->sprite, element->texture, sfTrue);
	sfSprite_setPosition(element->sprite, element->position);
	element->next = NULL;
	liste->first = element;
	return (liste);
}

void init(sfRenderWindow *window, structs *alls)
{
	sfSprite_setTexture(alls->s0.sprite, alls->s0.texture, sfTrue);
	sfSprite_setTexture(alls->s1.sprite, alls->s1.texture, sfTrue);
	sfSprite_setTexture(alls->s2.sprite, alls->s2.texture, sfTrue);
	sfSprite_setTexture(alls->s3.sprite, alls->s3.texture, sfTrue);
	sfSprite_setTexture(alls->fish.sprite, alls->fish.texture, sfTrue);
	sfSprite_setTexture(alls->score.sprite, alls->score.texture, sfTrue);
	sfSprite_setTexture(alls->sp.sprite, alls->sp.texture, sfTrue);
	sfSprite_setPosition(alls->sp.sprite, alls->sp.position);
	sfSprite_setPosition(alls->s0.sprite, alls->s0.position);
	sfSprite_setPosition(alls->s1.sprite, alls->s1.position);
	sfSprite_setPosition(alls->s2.sprite, alls->s2.position);
	sfSprite_setPosition(alls->s3.sprite, alls->s3.position);
	sfSprite_setPosition(alls->fish.sprite, alls->fish.position);
	sfSprite_setPosition(alls->score.sprite, alls->score.position);
	sfRenderWindow_setFramerateLimit(window, 20);
}
