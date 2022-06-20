/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** Task03
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int a = 0;
    int chiffrebouc1 = 0;
    int chiffrebouc2 = my_strlen(str) - 1;
    char chambre;

    while (chiffrebouc1 < chiffrebouc2) {
        chambre = str[chiffrebouc1];
        str[chiffrebouc1] = str[chiffrebouc2];
        str[chiffrebouc2] = chambre;
        chiffrebouc1++;
        chiffrebouc2--;
    }
    return (str);
}