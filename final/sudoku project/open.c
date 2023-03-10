#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int empty(int **grid, char type, int num) {
    int i = 0;
    int j = 0;
    int j_save;
    num = num - 1;
    int empty_c = 0;
    int rep_c = 0;
    int rep2_c = 0;

    if (type == 'h') {
        i = num;
        while (j != 9) {
            if (grid[i][j] == 0) {
                empty_c++;
            }
            j++;
        }
    } else if (type == 'v') {
        j = num;
        while (i != 9) {
            if (grid[i][j] == 0) {
                empty_c++;
            }
            i++;
        }
    } else if (type == 'c') {
        if (num == 1) {
            j = 3;
        } else if (num == 2) {
            j = 6;
        } else if (num == 3) {
            i = 3;
        } else if (num == 4) {
            i = 3;
            j = 3;
        } else if (num == 5) {
            i = 3;
            j = 6;
        } else if (num == 6) {
            i = 6;
        } else if (num == 7) {
            i = 6;
            j = 3;
        } else if (num == 8) {
            i = 6;
            j = 6;
        }

        j_save = j;
        while (rep_c != 3) {
            while (rep2_c != 3) {
                if (grid[i][j] == 0) {
                    empty_c++;
                }
                j++;
                rep2_c ++;
            }
            if (j != 0) {
                j = j_save;
            } else {
                j = 0;
            }
            rep2_c = 0;
            i++;
            rep_c++;
        }
    } else if (type == 'a') {
        while (i != 9 && j != 9) {
            while (j < 9) {
                if (grid[i][j] == 0) {
                    empty_c++;
                }
                j++;
            }
            j = 0;
            i++;
        }
    }
    return empty_c;
}

int main(int argc, char **argv) {
    char buf[91];
    int **grid;
    int i = 0;
    int j = 0;
    int k = 0;

    
    grid = (int **)malloc(sizeof(int *)*9);
    while (i < 9) {
        grid[i] = (int *)malloc(sizeof(int)*9);
        i++;
    }

    int fd = open(argv[1], O_RDONLY);
    int nb_read = read(fd, buf, 91);

    printf("%i\n", argc);
    printf("%i\n", nb_read);
    buf[90] = '\0';

    close(fd);

    i = 0;
    while (buf[k] != '\0') {
        while (j < 9) {
            grid[i][j] = (buf[k]-48);
            j++;
            k++;
        }
        j = 0;
        k++;
        i++;
    }

    i = 0;
    j = 0;
    while (i != 9 && j != 9){
        while (j < 9) {
            printf("%i   ", grid[i][j]);
            j++;
        }
        printf("%c\n", '\n');
        j = 0;
        i++;
    }

    int z = 1;
    int zero;
    int zero_min;
    char zero_val;
    int zero_val2;
    while (z != 10) {
        zero = empty(grid, 'h', z);
        if (zero > 0) {
            if (z == 1) {
                zero_min = zero;
            } else if (zero_min > zero) {
                zero_min = zero;
                zero_val = 'h';
                zero_val2 = z;
            }
        }
        z++;
    }
    z = 1;
    while (z != 10) {
        zero = empty(grid, 'v', z);
        if (zero > 0) {
            if (zero_min > zero) {
                zero_min = zero;
                zero_val = 'v';
                zero_val2 = z;
            }
        }
        z++;
    }
    z = 1;
    while (z != 10) {
        zero = empty(grid, 'c', z);
        if (zero > 0) {
            if (zero_min > zero) {
                zero_min = zero;
                zero_val = 'c';
                zero_val2 = z;
            }
        }
        z++;
    }
    printf("%i\n", zero_min);
    printf("%c\n", zero_val);
    printf("%i\n", zero_val2);
    /*
    zero = empty(grid, 'a', 5);
    printf("%i\n", zero);
    */

    i = 0;
    while (i < 9) {
        free(grid[i]);
        i++;
    }
    free(grid);

}
