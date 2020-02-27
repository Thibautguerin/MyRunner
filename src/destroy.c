/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** destroy sprite and free malloc for my runner
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

void deletebox(Liste *boxx, listef *fin)
{
	Element *tmp = boxx->first;
	finish *tmp1 = fin->first;

	while (tmp != NULL) {
		sfTexture_destroy(tmp->texture);
		sfSprite_destroy(tmp->sprite);
		free(tmp);
		tmp = tmp->next;
	}
	while (tmp1 != NULL) {
		sfTexture_destroy(tmp1->texture);
		sfSprite_destroy(tmp1->sprite);
		free(tmp1);
		tmp1 = tmp1->next;
	}
}

void destroy(structs *alls, Liste *boxx, listef *fin)
{
	sfTexture_destroy(alls->s0.texture);
	sfTexture_destroy(alls->s1.texture);
	sfTexture_destroy(alls->s2.texture);
	sfTexture_destroy(alls->s3.texture);
	sfTexture_destroy(alls->fish.texture);
	sfTexture_destroy(alls->score.texture);
	sfTexture_destroy(alls->sp.texture);
	sfSprite_destroy(alls->sp.sprite);
	sfSprite_destroy(alls->score.sprite);
	sfSprite_destroy(alls->s0.sprite);
	sfSprite_destroy(alls->s1.sprite);
	sfSprite_destroy(alls->s2.sprite);
	sfSprite_destroy(alls->s3.sprite);
	sfSprite_destroy(alls->fish.sprite);
	deletebox(boxx, fin);
}

void gameo_or_win_destroy(sfSound *sound, sfSoundBuffer *sd, spritex *sprite)
{
	sfSound_destroy(sound);
	sfSoundBuffer_destroy(sd);
	sfTexture_destroy(sprite->texture);
	sfSprite_destroy(sprite->sprite);
}
