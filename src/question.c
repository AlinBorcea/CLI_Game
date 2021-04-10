#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "question.h"
#include "score.h"

typedef struct question {
    char sentence[128];
    char answears[4][16];
    char solutions[4];
} que;

static FILE *infile = NULL;
static que que_array[QUESTION_COUNT];
static int is_init = 0;

int read_questions() {
    int x = 0;
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

int que_init() {
    int x;

    que_close();
    infile = fopen(QUESTION_FILE_NAME, "r");
    if (infile == NULL) {
        fprintf(stderr, "Error opening questions\n");
        return 1;
    }

    if (!is_init) {
        if ((x = read_questions()))
            return x;
        is_init = 1;
    }

    return 0;
}

void que_close() {
    if (infile != NULL)
        fclose(infile);
}

int que_read(que *q) {
    if (infile == NULL || q == NULL) {
        return 0;
    }
    
    fscanf(infile, "%s", q->sentence);
    fscanf(infile, "%s", q->answears[0]);
    fscanf(infile, "%s", q->answears[1]);
    fscanf(infile, "%s", q->answears[2]);
    fscanf(infile, "%s", q->answears[3]);
    fscanf(infile, "%s", q->solutions);

    return 1;
}

int que_print(que *que) {
    if (que == NULL) return 1;

    print_strxy(stdout, que->sentence, '_', ' ');
    for (int i = 0; i < 4; i++) {
        print_strxy(stdout, que->answears[i], '_', ' ');
    }

    return 0;
}

void quiz_ask(que *que) {    
    que_print(que);
}

void create_date(struct tm *timeinfo, char *buffer) {
    sprintf(buffer, "%d:%d_%d_%d_%d", timeinfo->tm_hour, timeinfo->tm_min,
    timeinfo->tm_mday, timeinfo->tm_mon, (timeinfo->tm_year + 1900)); 
    // tm_year is the number of years since 1900 on Posix systems.
}

int quiz_start() {
    int que_was_answeared[QUESTION_COUNT] = { 0 };
    score *sc;
    char buffer[32];
    char name[32];
    int x;

    for (int i = 0; i < QUESTION_COUNT; i++) {
        do {
            x = rand() % QUESTION_COUNT;
        } while (que_was_answeared[x]);

        que_was_answeared[x] = 1;
        quiz_ask(&que_array[x]);
    }

    CLEAR();
    printf("Game over\n");
    printf("User name...");
    scanf("%s", name);

    time_t now = time(NULL);
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);
    create_date(timeinfo, buffer);
    sc = score_new(0, name, 10, buffer);

    score_append(sc);
    score_delete(&sc);

    return 0;
}
