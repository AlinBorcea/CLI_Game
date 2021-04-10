#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "score.h"
#include "question.h"

int run() {
    int err = 0;
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

        if (err) return err;

        printf("Choose an option.. ");
        scanf("%s", option);
        CLEAR();
    }

    return 0;
}

int main() {
    CLEAR();
    srand(time(NULL));

    #ifndef __unix__
    printf("Program was tested on a unix like system!\n");
    return 1;
    #endif

    return run();
}
