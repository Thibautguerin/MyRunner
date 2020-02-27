/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** file for move sprite in my_runner
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

void movebox(Liste *boxx, listef *fin, structs *alls, sfRenderWindow *window)
{
	Element *tmp = boxx->first;
	finish *tmp1 = fin->first;
	int c = 0;
	int c1 = 0;

	while (tmp != NULL && sfRenderWindow_isOpen(window)) {
		sfSprite_move(tmp->sprite, tmp->speed);
		c = colision(tmp, &alls->fish);
		tmp = tmp->next;
		if (c == 1)
			gameover(window, boxx, fin, alls);
	}
	while (tmp1 != NULL && sfRenderWindow_isOpen(window)) {
		sfSprite_move(tmp1->sprite, tmp1->speed);
		c1 = colision1(tmp1, &alls->fish);
		tmp1 = tmp1->next;
		if (c1 == 1)
			win(window, boxx, fin, alls);
	}
}

void spritesheet(othersx *other, structs *alls)
{
	if (other->rect.left == 381) {
		other->rect.left = -127;
	}
	other->rect.left = other->rect.left + 127;
	sfSprite_setTextureRect(alls->fish.sprite, other->rect);
}

void moveall2(structs *alls)
{
	if (sfSprite_getPosition(alls->s0.sprite).x <= -1200)
		sfSprite_setPosition(alls->s0.sprite, alls->s0.position);
	if (sfSprite_getPosition(alls->s1.sprite).x <= -1200)
		sfSprite_setPosition(alls->s1.sprite, alls->s1.position);
	if (sfSprite_getPosition(alls->s2.sprite).x <= -1200)
		sfSprite_setPosition(alls->s2.sprite, alls->s2.position);
	if (sfSprite_getPosition(alls->s3.sprite).x <= -1200)
		sfSprite_setPosition(alls->s3.sprite, alls->s3.position);
}

void moveall(structs *alls, Liste *boxx, listef *fin,  sfRenderWindow *window)
{
	sfSprite_move(alls->s0.sprite, alls->s0.speed);
	sfSprite_move(alls->s1.sprite, alls->s1.speed);
	sfSprite_move(alls->s2.sprite, alls->s2.speed);
	sfSprite_move(alls->s3.sprite, alls->s3.speed);
	if ((alls->i < alls->sl / 10 && alls->i >= alls->sl / 10 - 17)
	|| (alls->i < alls->sl * 2 / 10 && alls->i >= alls->sl * 2 / 10 - 17)
	|| (alls->i < alls->sl * 3 / 10 && alls->i >= alls->sl * 3 / 10 - 17)
	|| (alls->i < alls->sl * 4 / 10 && alls->i >= alls->sl * 4 / 10 - 17)
	|| (alls->i < alls->sl * 5 / 10 && alls->i >= alls->sl * 5 / 10 - 17)
	|| (alls->i < alls->sl * 6 / 10 && alls->i >= alls->sl * 6 / 10 - 17)
	|| (alls->i < alls->sl * 7 / 10 && alls->i >= alls->sl * 7 / 10 - 17)
	|| (alls->i < alls->sl * 8 / 10 && alls->i >= alls->sl * 8 / 10 - 17)
	|| (alls->i < alls->sl * 9 / 10 && alls->i >= alls->sl * 9 / 10 - 17))
		sfSprite_move(alls->sp.sprite, alls->sp.speed);
	alls->i = alls->i - 17;
	moveall2(alls);
	movebox(boxx, fin, alls, window);
}
