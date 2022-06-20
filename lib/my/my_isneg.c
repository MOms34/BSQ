/*
** EPITECH PROJECT, 2021
** task04
** File description:
** isneg
*/

void my_putchar(char c);
int  my_isneg(int nb) {

        if (nb > 0) {
            my_putchar('P');
        }
        else if (nb < 0){
            my_putchar('N');
        }  
        return(0);
}
