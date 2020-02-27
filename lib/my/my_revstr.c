/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** 
*/

char *my_revstr(char *str)
{
	int i = 0;
	int k = 0;

	while (str[i] != '\0') {
		i++;
	}
	char rev[i];

	i = i - 1;
	while (i >= 0) {
		rev[k] = str[i];
		i = i - 1;
		k++;
	}
	while (i <= k) {
		str[i] = rev[i];
		i++;
	}
	return (str);
}
