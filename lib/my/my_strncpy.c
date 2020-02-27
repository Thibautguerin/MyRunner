/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copy
*/

#include "my_putchar.c"

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (n > i && src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	if (n <= i) {
		my_putchar('\n');
		dest[i] = '\0';
	}
	dest[i] = '\0';
	return (dest);
}
