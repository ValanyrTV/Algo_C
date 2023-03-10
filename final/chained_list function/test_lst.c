#include "includes.h"

int cmpfunc (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

int main(void) {
    /*
    1/ Trier array_int avec qsort, ou avec un tri à bulle
    2/ Création de 5 "type_lst *" contenant un chiffre chacune
    3/ Chainer ses listes grâce au "next". La première liste doit être la valeur la plus petite, la dernière, la plus grande
    4/ Bonus si doublement chainer (avec un prev)
    5/ Bonus si bouclé, le dernier pointe sur le premier et inversement
    */
    int array_int[5] = {5, 4, 3, 2, 1};
    int i = 0;
    
    qsort(array_int, 5, sizeof(int), cmpfunc);

    while (i < 5) {
        //printf("%i\n", array_int[i]);
        i++;
    }

    type_lst *lst;
    type_lst *lst2;
    type_lst *lst3;
    type_lst *lst4;
    type_lst *lst5;

    lst = (type_lst *)malloc(sizeof(lst));
    lst2 = (type_lst *)malloc(sizeof(lst2));
    lst3 = (type_lst *)malloc(sizeof(lst3));
    lst4 = (type_lst *)malloc(sizeof(lst4));
    lst5 = (type_lst *)malloc(sizeof(lst5));

    lst->nbr = array_int[0];
    lst2->nbr = array_int[1];
    lst3->nbr = array_int[2];
    lst4->nbr = array_int[3];
    lst5->nbr = array_int[4];
    
    lst->next = lst2;
    lst2->next = lst3;
    lst3->next = lst4;
    lst4->next = lst5;
    lst5->next = lst;
    
    lst->prev = lst5;
    lst5->prev = lst4;
    lst4->prev = lst3;
    lst3->prev = lst2;
    lst2->prev = lst;
    
    int j = 0;
    while (j < i-1) {
        printf("le nbr = %i\n", lst->nbr);
        lst = lst->next;
        j++;
    }
    printf("le nbr = %i\n", lst->nbr);
}
