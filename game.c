#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "score/score.h"
#include "question/question.h"

#define CLEAR() system("clear")

#define MAIN_MENU_LEN 4
#define OPTION_LEN 32

#define OPTION_EXIT "exit"
#define OPTION_HELP "help"
#define OPTION_SCORE "score"
#define OPTION_START "start"

void print_menu(char menu[][OPTION_LEN], int menu_len) {
    for (int i = 0; i < menu_len; i++) {
        printf("%s\n", menu[i]);
    }
    printf("\n");
}

int run() {
    bool err = false;
    char option[16] = OPTION_HELP;
    char main_menu[MAIN_MENU_LEN][OPTION_LEN] = {
        "exit -> exit",
        "help -> view Main Menu",
        "score -> View leaderboard",
        "start -> Start game",
    };

    while (strcmp(option, OPTION_EXIT) != 0) {
        printf("==== Millionaire Game ====\n\n");

        if (strcmp(option, OPTION_HELP) == 0) {
            print_menu(main_menu, MAIN_MENU_LEN);
        
        } else if (strcmp(option, OPTION_SCORE) == 0) {
            err = score_display();
        
        } else if (strcmp(option, OPTION_START) == 0) {
            err = quiz_start();
            
        } else {
            printf("Option '%s' does not exist\n", option);
            printf("Enter 'help' to view menu\n");
        }

        if (err) return EXIT_FAILURE;

        printf("Choose an option.. ");
        scanf("%s", option);
        CLEAR();
    }

    return EXIT_SUCCESS;
}

int main() {
    CLEAR();
    srandom(time(NULL));
    return run();
}