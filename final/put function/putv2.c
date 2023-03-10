#include <stdio.h>
#include <unistd.h>

// Code 2

int gd_putstr(char *str) {
    int i;
    i = 0;
    while(str[i] != '\0') {
        i++;
    }
    write(1, str, i);
    return i;
}

int main(void) {
    int nb_put = gd_putstr("Code");
    printf("\n%i\n", nb_put);
}
