#include <stdlib.h>
#include <stdio.h>


int str_double_len(char const *str1, char const *str2) {
    int len1 = 0;
    int len2 = 0;
    int len = 0;

    while (str1[len1]) {
        len1++;
    }
    while (str2[len2]) {
        len2++;
    }

    len = len1 + len2;

    return len;
}

char *join_two_string(char const *s1, char const *s2) {
    int len_str;
    int i;
    int j;
    char *ret;

    len_str = str_double_len(s1, s2);
    printf("%i\n", len_str);
    ret = (char *)malloc(sizeof(char) * len_str);
    if (ret == NULL) {
        return NULL;
    }

    i = 0;
    while(s1[i]) {
        ret[i] = s1[i];
        i++;
    }

    j = 0;
    while(s2[j]) {
        ret[i] = s2[j];
        i++;
        j++;
    }

    return ret;
}

int main(void) {
    char *str1 = "Hello";
    char *str2 = " world";
    char *join;

    join = join_two_string(str1, str2);
    printf("%s\n", join);
    free(join);
}
