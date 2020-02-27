/*
** EPITECH PROJECT, 2018
** sprite_and_other.h
** File description:
** structs for my runner
*/

#ifndef SPRITE_AND_OTHER_H
#define SPRITE_AND_OTHER_H

typedef struct sprite_x
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f position;
	sfVector2f speed;
}spritex;

typedef struct others_x
{
	sfIntRect rect;
	int score;
	sfEvent event;
	sfVector2f getposition;
}othersx;

typedef struct struct_s
{
	spritex s0;
	spritex s1;
	spritex s2;
	spritex s3;
	spritex fish;
	spritex score;
	spritex sp;
	int i;
	int sl;
}structs;

typedef struct score_x
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f position;
	struct score_x *next;
}Score;

typedef struct list_s
{
	Score *first;
}listes;

#endif
