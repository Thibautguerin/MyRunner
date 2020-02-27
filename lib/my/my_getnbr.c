/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** 
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] != 0) {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10 + str[i] - 48;
		}
		i = i + 1;
	}
	return (nb);
}
