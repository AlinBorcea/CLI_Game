#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "question.h"
#include "../score/score.h"

#define QUESTION_FILE_NAME "questions.que"

#define QUESTION_COUNT 5

#define CLEAR() system("clear")

static FILE *infile = NULL;
static que que_array[QUESTION_COUNT];
static bool is_init = false;

bool que_init() {
    que_close();
    infile = fopen(QUESTION_FILE_NAME, "r");
    if (infile == NULL) {
        fprintf(stderr, "Error opening questions\n");
        return true;
    }
    return false;
}

void que_close() {
    if (infile != NULL)
        fclose(infile);
}

bool que_read(que *q) {
    if (infile == NULL) {
        return false;
    }
    
    fscanf(infile, "%s", q->sentence);
    fscanf(infile, "%s", q->answears[0]);
    fscanf(infile, "%s", q->answears[1]);
    fscanf(infile, "%s", q->answears[2]);
    fscanf(infile, "%s", q->answears[3]);
    fscanf(infile, "%s", q->solutions);

    return true;
}

void que_print(que *que) {
    if (que == NULL) return;

    for (int i = 0; i < strlen(que->sentence); i++) {
        if (que->sentence[i] == '_')
            printf(" ");
        else
            printf("%c", que->sentence[i]);
    
    } printf("\n");


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < strlen(que->answears[i]); j++) {
            if (que->answears[i][j] == '_')
                printf(" ");
            else
                printf("%c", que->answears[i][j]);
        }
        printf("\n");
    }

}

void quiz_ask(que *que) {    
    que_print(que);
}

void create_date(struct tm *timeinfo, char *buffer) {
    sprintf(buffer, "%d:%d_%d_%d_%d", timeinfo->tm_hour, timeinfo->tm_min,
    timeinfo->tm_mday, timeinfo->tm_mon, (timeinfo->tm_year + 1900)); 
    // tm_year is the number of years since 1900 on Posix systems.
}

bool read_questions() {
    bool x = false;
    int count = 0;

    if ((x = que_init())) {
        return x;
    }

    while (count < QUESTION_COUNT && que_read(que_array + count)) {
        count++;
    }

    que_close();
    return x;
}

bool quiz_start() {
    bool que_was_answeared[QUESTION_COUNT] = {false};
    score user_score;
    int x;

    if (!is_init) {
        if ((x = read_questions()))
            return x;
        is_init = true;
    }

    for (int i = 0; i < QUESTION_COUNT; i++) {
        do {
            x = rand() % QUESTION_COUNT;
        } while (que_was_answeared[x]);

        que_was_answeared[x] = true;
        quiz_ask(&que_array[x]);
    }

    CLEAR();
    printf("Game over\n");
    printf("User name...");
    scanf("%s", user_score.name);

    time_t now = time(NULL);
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);
    
    create_date(timeinfo, user_score.date);
    score_append(&user_score);

    return false;
}
