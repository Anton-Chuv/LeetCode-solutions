#include <stdio.h>
#include <stdlib.h>
int maximum69Number (int num) {
    char str[64];
    sprintf(str, "%d", num);
    int i = 0;
    while (str[i] == '9') i++;
    if (str[i] == '6') str[i] = '9';
    num = strtol(str, NULL, 10);
    return num;
}
