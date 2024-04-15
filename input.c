#include <stdio.h>

int my_gets(char s[], int max_len) {
    int i = 0;
    while(i<max_len) {
        char c = getchar();
        if(c=='\n') break;
        s[i] = c;
        i++;
    }

    if(i==max_len) {
        printf("my_gets(): overflow occured\n");
        s[max_len - 1] = '\0';
        return -1;
    }

    s[i] = '\0';
    return 0;
}
