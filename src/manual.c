/*
** EPITECH PROJECT, 2018
** manual.c
** File description:
** manual for the game
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

void manual(int ac)
{
	my_putstr("====================================\n");
	my_putstr("USAGE:\n\nThe goal of this game is to lead the fish ");
	my_putstr("until the arrival! For this it will avoid ");
	my_putstr("the obstacles put on his way! ");
	my_putstr("Be carefull, you only have 1 life!\n\n");
	my_putstr("Enter this command for launch the game: ");
	my_putstr("./my_hunter *map path*\n\nCONTROL:\n-arrow up and");
	my_putstr(" down: move\n-P: pause\n\nGood luck, have fun!\n\n");
	my_putstr("CREATE A MAP:\nC: Box\n#: Ground\n-: finish\n\n");
	my_putstr("The map must be 8 block high!\nLike that:\n\n");
	my_putstr("     -\n     -\n     -\n     -\n  C  -\n CC  -\n CC  -\n");
	my_putstr(" CCC -\n######\n");
	my_putstr("====================================\n");
}
