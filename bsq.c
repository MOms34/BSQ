/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** File Header
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <sys/types.h>

int first (char *filepath, OKLM *antman)
{
    int fd = open(filepath, O_RDONLY);
    int count = 0;
    int count_line = 0;
    char c = '\0';
    int first_line = 0;

    while (read (fd, &c, 1)) {
        if (c == '\n')
            count_line++;
        if (count_line == 0)
            first_line++;
        count++;
    }
    antman->nb_line = count_line + 1;
    antman->nb_words = count;
    antman->first_line = first_line;
    return count;
}
char *creat_tab (char *filepath, OKLM *antman)
{
    int index = 0;
    int compt = antman->nb_words;
    int fd = open(filepath, O_RDONLY);
    char *tab = malloc(sizeof(char) * compt + 1);
    char c = '\0';

    while (index != compt) {
        while (read (fd, &c, 1)) {
            tab[index] = c;
            index++;

        }
        if (index == compt)
            tab[index] = '\0';
    }

    antman->tab = tab;
    return tab;
}
int strlen_word (OKLM *antman)
{
    char *buffer = antman->tab;
    int index = 0;
    int compt2 = 0;
    int compt3 = 0;
    int temp = 0;

    while (buffer[index] != '\0' && compt2 <= 2) {
        if (buffer[index] == '\n')
            compt2++;
        if (compt2 == 1)
            compt3++;
        index++;
        }

    antman->max_caract = compt3;
    return compt2;
}
char** tab_finish (OKLM *antman)
{
    int index = 0;
    int b = antman->nb_line;
    char **tab2 = malloc(sizeof(char*) * b);
    int a = antman->max_caract;
    char *buffer = antman->tab;
    int c = 0;
    int d = 0;
    int e = 0;

    while (index < b) {
        tab2[index] = malloc(sizeof(char) * (a));
        index += 1;
    }
    while (buffer[c] != '\0') {
        if (c == antman-> first_line || e == (a - 1)){
            tab2[d][e] = '\0';
            e = 0;
            c++;
            d++;
        }
        if(buffer[c] == '\0')
            break;
        tab2[d][e] = buffer[c];
        c++;
        e++;
    }

    antman->tab2 = tab2;
    return (tab2);
}
int check_square(char **map, int row, int col, int square_size)
{
    int i = 0;
    int j = 0;

    for (i = row; i < square_size + row; i++) {
        if (map[i] == NULL ) {
            return (0);
        }
        for(j = col; j < square_size + col ; j++){
            if (map[i][j] == 'o' || map[i][j] == '\0'){

                return (0);
            }
        }
    }
    return (1);
}
void find_finish (char** map, OKLM *antman)
{
    int i = 1 ;
    int j = 0;
    int square_max = 0;
    int nb_word = antman->max_caract - 2;
    int compteur  = 0;
    int x = 0;
    int test = 0;

    while (i <= (antman->nb_line - 1) ) {
        for(j = 0; j < nb_word; j++) {
            if (i > (antman->nb_line) - compteur)
                break;
            if (map[i][j] == '.'){
                while (check_square(map, i, j, compteur) == 1)
                    compteur++;
                if (compteur > square_max ) {
                        square_max = compteur;
                        antman->square_max = square_max;
                        antman->i_max = i;
                        antman->j_max = j;
                }
            }
        }
        i++;
    }
}
void remplir (char ** map, OKLM *antman)
{
    int i = antman->i_max;
    int j = antman->j_max;
    int square = antman->square_max;

    for(int b = 1; b < square; b++) {
        for(int x = 1; x < square; x++){
            map[i][j] = 'x';
            j++;
            }
            j -= square - 1;
            i++;
    }
       for (int a = 1; a != antman->nb_line; a++) {
            if (a == (antman->nb_line - 1))
                my_putstr(map[a]);
            if (a != (antman->nb_line - 1)){
                my_putstr(map[a]);
                my_putchar('\n');
            }
       }
}
int main (int ac, char **argv)
{
    struct OKLM antman;
    char *filepath = argv[1];
    int fd = open(filepath, O_RDONLY);

    if (ac != 2)
        return 84;
    if (fd < 0)
        return 84;
    first(filepath, &antman);
    creat_tab(filepath, &antman);
    strlen_word(&antman);
    char **map = tab_finish(&antman);
    find_finish(map, &antman);
    remplir(map, &antman);

    return 0;
}