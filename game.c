#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "score/score.h"
#include "question/question.h"

#define MAIN_MENU_LEN 4
#define OPTION_LEN 32

void print_menu(char menu[][OPTION_LEN], int menu_len) {
    for (int i = 0; i < menu_len; i++) {
        printf("%s\n", menu[i]);
    }
    printf("\n");
}

int run() {
    int error_code = EXIT_SUCCESS;
    char option[16] = "help";
    char main_menu[MAIN_MENU_LEN][OPTION_LEN] = {
        "exit -> exit",
        "help -> view Main Menu",
        "score -> View leaderboard",
        "start -> Start game",
    };

    while (strcmp(option, "exit") != 0) {

        if (strcmp(option, "help") == 0) {
            print_menu(main_menu, MAIN_MENU_LEN);
        
        } else if (strcmp(option, "score") == 0) {
            error_code = score_display();
        
        } else if (strcmp(option, "start") == 0) {
            printf("Start\n");
            
        } else {
            printf("Option '%s' does not exist\n", option);
            printf("Enter 'help' to view menu\n");
        }

        if (error_code != EXIT_SUCCESS) return error_code;

        printf("Choose an option.. ");
        scanf("%s", option);
        system("cls");
    }

    return EXIT_SUCCESS;
}

void test_question() {
    queinfo_t info;
    que_init(&info);

    while (que_read(&info) == 0) {
        que_print(&info.question);
    }

    que_close(&info);
}

int main() {
    system("cls");
    printf("==== Millionaire Game ====\n\n");
    test_question();
    return run();
}