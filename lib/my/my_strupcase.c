/*
** EPITECH PROJECT, 2021
** task04
** File description:
** my_compute_power_rec
*/

#include <unistd.h>
void my_putchar(char c );
char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++ ) {
        while (str[i] >= 'a' || str[i] <= 'z') {
            str[i] += - 32;
            my_putchar(str[i]);
        }
        return (str);
    }
    return (str);
}