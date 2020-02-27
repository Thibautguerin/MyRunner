/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** 
*/

#ifndef MY_H
#define MY_H

#include "box_and_finish.h"
#include "sprite_and_other.h"

void gameo_or_win_destroy(sfSound *sound, sfSoundBuffer *sd, spritex *sprite);
structs structalls(int sizel);
void main2(int sizel, char **av, Liste *boxx, listef *fin);
void redirectionseption(placement *place, Liste *boxx, char *map, listef *fin);
void redirection(int ac, char **av);
int main(int ac, char **av);
void manual(int ac);
void displaybox(Liste *boxx, listef *fin, sfRenderWindow *window);
int colision1(finish *tmp1, spritex *fish);
int colision(Element *tmp, spritex *fish);
int event(sfRenderWindow *window, othersx *other, spritex *pause);
void keyevent(spritex *fish);
void event_(sfRenderWindow *window, othersx *other, structs *alls);
void deletebox(Liste *boxx, listef *fin);
void destroy(structs *alls, Liste *boxx, listef *fin);
void gameover(sfRenderWindow *window, Liste *boxx, listef *fin, structs *alls);
void win(sfRenderWindow *window, Liste *boxx, listef *fin, structs *alls);
void movebox(Liste *boxx, listef *fin, structs *alls, sfRenderWindow *window);
int readfil(int ac, char **av);
char *readfile(int ac, char **av);
int sizeline(char *map);
void my_put_in_listf(listef *fin, int i, int line);
void my_put_in_list(Liste *boxx, int i, int line);
void placefinish(placement *place, listef *fin);
void mapp(placement *place, Liste *boxx);
listef *initialisationf(int i, int line);
Liste *initialisation(int i, int line);
int display(sfRenderWindow *window, structs *alls, Liste *boxx, listef *fin);
void spritesheet(othersx *other, structs *alls);
void moveall2(structs *alls);
void moveall(structs *alls, Liste *boxx, listef *fin,  sfRenderWindow *window);
void init(sfRenderWindow *window, structs *alls);
void mainmenu(sfRenderWindow *window, othersx *other);

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *,int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int , int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int );
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);

#endif
