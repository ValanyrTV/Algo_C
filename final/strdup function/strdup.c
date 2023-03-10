#include <stdio.h>
#include <stdlib.h>

char *gd_strdup(const char *src) {
    int memory;
    memory = 0;

    while(src[memory]) {
        memory++;
    }

    char *ret = (char *)malloc(sizeof(char) * memory);
    if (ret == NULL) {
        return NULL;
    }
    memory = 0;
    while(src[memory]) {
        ret[memory] = src[memory];
        memory++;
    }
    printf("%i\n", memory);
    return ret;
}

int main(void) {
    char *str = "Hello world";
    char *dup;

    dup = gd_strdup(str);
    printf("%s\n", dup);
    free(dup);
}
