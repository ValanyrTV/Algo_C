#include <stdio.h>

int fibonacci(int max_fib) {
    int ret_fib;
    int f0;
    int f1;
    int i ;

    f0 = 0 ;
    f1 = 1 ;
    i = 1 ;
    if (max_fib == 0){
        ret_fib = 0 ;
    } else if (max_fib == 1) {
        ret_fib = 1 ;
    } else {
        while (i < max_fib) {
            ret_fib = f0 + f1 ;
            f0 = f1 ;
            f1 = ret_fib ;
            i++;
        }
    }
    return ret_fib;
}

int main(void) {
    int fib;

    fib = fibonacci(13);
    printf("%i\n", fib);
    return 1;
}
