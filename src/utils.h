#ifndef UTILS_H
#define UTILS_H

#define CLEAR() system("clear")

#define MAIN_MENU_LEN 4
#define OPTION_LEN 26
#define OPTION_EXIT "exit"
#define OPTION_HELP "help"
#define OPTION_SCORE "score"
#define OPTION_START "start"

void print_menu(char menu[][OPTION_LEN], int menu_len);

/// Prints a String and replaces x with y.
/// It does not modify the string.
void print_strxy(FILE *outfile, char *str, char x, char y);

#endif