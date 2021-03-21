#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "question.h"

#define QUESTION_FILE_NAME "questions.que"

bool que_init(queinfo *info) {
    info->infile = fopen(QUESTION_FILE_NAME, "r");
    if (info->infile == NULL) {
        fprintf(stderr, "Error opening questions\n");
        return true;
    }
    return false;
}

void que_close(queinfo *info) {
    if (info->infile != NULL)
        fclose(info->infile);
}

bool que_read(queinfo *info) {
    if (info->infile == NULL) {
        return true;
    }
    
    fscanf(info->infile, "%s", info->question.sentence);
    fscanf(info->infile, "%s", info->question.answears[0]);
    fscanf(info->infile, "%s", info->question.answears[1]);
    fscanf(info->infile, "%s", info->question.answears[2]);
    fscanf(info->infile, "%s", info->question.answears[3]);
    fscanf(info->infile, "%s", info->question.solutions);

    return false;
}

void que_print(que *que) {
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
