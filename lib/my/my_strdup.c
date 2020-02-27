/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** duplicate str
*/

#include <stdlib.h>
#include "my_strlen.c"
#include "my_strcpy.c"

char *my_strdup(char *str)
{
	int len = my_strlen(str) + 1;
	char *dup = malloc(len);

	if (dup == NULL)
		return (NULL);
	dup = my_strcpy(dup, str);
	dup[len - 1] = '\0';
	return (dup);
}
