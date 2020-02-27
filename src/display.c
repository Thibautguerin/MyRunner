/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display sprite and window for my runner
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

void displaybox(Liste *boxx, listef *fin, sfRenderWindow *window)
{
	finish *tmp1 = fin->first;
	Element *tmp = boxx->first;

	while (tmp != NULL) {
		sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
		tmp = tmp->next;
	}
	while (tmp1 != NULL) {
		sfRenderWindow_drawSprite(window, tmp1->sprite, NULL);
		tmp1 = tmp1->next;
	}
}

void gameover(sfRenderWindow *window, Liste *boxx, listef *fin, structs *alls)
{
	spritex gameover = {sfTexture_createFromFile("src/graph/gameover.png",
	NULL), sfSprite_create(), {0, 0}, {0, 0}};
	sfSoundBuffer *sd = sfSoundBuffer_createFromFile("src/audio/win.wav");
	sfSound *sound = sfSound_create();

	sfSprite_setTexture(gameover.sprite, gameover.texture, sfTrue);
	sfSound_setBuffer(sound, sd);
	destroy(alls, boxx, fin);
	sfSound_play(sound);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_drawSprite(window, gameover.sprite, NULL);
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
			gameo_or_win_destroy(sound, sd, &gameover);
			sfRenderWindow_close(window);
		}
	}
}

void win(sfRenderWindow *window, Liste *boxx, listef *fin, structs *alls)
{
	spritex win = {sfTexture_createFromFile("src/graph/win.png", NULL),
	sfSprite_create(), {0, 0}, {0, 0}};
	sfSoundBuffer *sd = sfSoundBuffer_createFromFile("src/audio/dead.wav");
	sfSound *sound = sfSound_create();

	sfSprite_setTexture(win.sprite, win.texture, sfTrue);
	sfSound_setBuffer(sound, sd);
	destroy(alls, boxx, fin);
	sfSound_play(sound);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_drawSprite(window, win.sprite, NULL);
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
			gameo_or_win_destroy(sound, sd, &win);
			sfRenderWindow_close(window);
		}
	}
}

int display(sfRenderWindow *window, structs *alls, Liste *boxx, listef *fin)
{
	sfRenderWindow_drawSprite(window, alls->s0.sprite, NULL);
	sfRenderWindow_drawSprite(window, alls->s1.sprite, NULL);
	sfRenderWindow_drawSprite(window, alls->s2.sprite, NULL);
	sfRenderWindow_drawSprite(window, alls->s3.sprite, NULL);
	sfRenderWindow_drawSprite(window, alls->fish.sprite, NULL);
	displaybox(boxx, fin, window);
	sfRenderWindow_drawSprite(window, alls->score.sprite, NULL);
	sfRenderWindow_drawSprite(window, alls->sp.sprite, NULL);
}

void mainmenu(sfRenderWindow *window, othersx *other)
{
	spritex menu = {sfTexture_createFromFile("src/graph/menu.png", NULL),
	sfSprite_create(), {0, 0}, {0, 0}};
	int i = 1;

	sfSprite_setTexture(menu.sprite, menu.texture, sfTrue);
	while (i == 1) {
		sfRenderWindow_drawSprite(window, menu.sprite, NULL);
		sfRenderWindow_display(window);
		while (sfRenderWindow_pollEvent(window, &other->event)) {
			if (other->event.type == sfEvtKeyReleased
			&& other->event.key.code == sfKeyReturn){
				sfTexture_destroy(menu.texture);
				sfSprite_destroy(menu.sprite);
				i = 0;
			}
		}
	}
}
