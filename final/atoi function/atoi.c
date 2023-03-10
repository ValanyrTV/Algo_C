#include <stdio.h>
#include <unistd.h>

void gd_putnbr(int nb) {
    printf("%i\n", nb);
    /*write(1,&nb, 1);*/
}

void gd_putchar(char c) {
    write(1, &c, 1);
}

int gd_atoi(char *str) {
    /* 43 -> +
       45 -> -
       49 à 57 -> 1 à 9
    */
    int res;
    res = 0;
    int neg;
    neg = 0;
    int i;
    i = 0;
    int pow;
    pow = 10;
    int rep;
    rep = 0;
    int j;
    j = 0;

    while(str[j] != '\0') {
        j++;
    }
    while (rep != j-2) {
        pow = pow * 10;
        rep++;
    }

    while(str[i]) {
        if (str[i] < 43 || str[i] > 57) {
            break;
        } else if (str[i] == 43) {
            break;
        } else if (str[i] == 45) {
            neg = -1;
        } else if (str[i] >= 49 && str[i] <= 57) {
            res = res + ((str[i] - 48) * pow);
            pow = pow / 10;
        }
        i++;
    }
    if (neg == -1) {
        res = res * neg;
    }
    return res;
}

int main(void) {
    int nb = gd_atoi("78344");
    gd_putnbr(nb);
    gd_putchar('\n');
}
