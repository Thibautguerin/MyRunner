/*
** EPITECH PROJECT, 2018
** box_and_finish.h
** File description:
** linked list of boxes and finish line for my runner
*/

#ifndef BOX_AND_FINISH_H
#define BOX_AND_FINISH_H

typedef struct box_placement
{
	int i;
	int line;
	int j;
	int sizel;
}placement;

typedef struct box_x
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f position;
	sfVector2f speed;
	struct box_x *next;
}Element;

typedef struct list_x
{
	Element *first;
}Liste;

typedef struct finish_x
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f position;
	sfVector2f speed;
	struct finish_x *next;
}finish;

typedef struct listf_x
{
	finish *first;
}listef;

#endif
