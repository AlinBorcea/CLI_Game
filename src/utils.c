#include <stdio.h>
#include <string.h>

#include "utils.h"

void print_menu(char menu[][OPTION_LEN], int menu_len) {
    for (int i = 0; i < menu_len; i++) {
        printf("%s\n", menu[i]);
    }
    printf("\n");
}

void print_strxy(FILE *outfile, char *str, char x, char y) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == x) {
            fprintf(outfile, "%c", y); 
        } else {
            fprintf(outfile, "%c", str[i]);
        }
    }
    fprintf(outfile, "\n");
}
