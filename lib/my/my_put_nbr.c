/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** 
*/

int my_put_nbr(int nb)
{
	int i;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	} else {
		if (nb >= 10) {
			i = (nb % 10);
			nb = (nb - i) / 10;
			my_put_nbr(nb);
			my_putchar(48 + i);
		} else
			my_putchar(48 + nb % 10);
	}
}
