#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void gd_putstr(char *str);

int gd_atoi(char *str);

#define VRAI 1
#define FAUX 0
typedef int BOOLEAN;



typedef struct my_struct{
    int minutes;
    int hours;
}   type_struc;

typedef struct my_lst {
    int nbr;
    struct my_lst *next;
    struct my_lst *prev;
}   type_lst;

#endif
