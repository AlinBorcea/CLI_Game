#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "question.h"

int que_init(queinfo_t *info) {
    info->infile = fopen(QUESTION_FILE_NAME, "r");
    if (info->infile == NULL) {
        fprintf(stderr, "Error opening questions\n");
        return 2;
    }
    return EXIT_SUCCESS;
}

void que_close(queinfo_t *info) {
    fclose(info->infile);
}

int que_read(queinfo_t *info) {
    if (feof(info->infile)) {
        return 3;
    }
    
    fscanf(info->infile, "%s", info->question.sentence);
    fscanf(info->infile, "%s", info->question.answears[0]);
    fscanf(info->infile, "%s", info->question.answears[1]);
    fscanf(info->infile, "%s", info->question.answears[2]);
    fscanf(info->infile, "%s", info->question.answears[3]);
    fscanf(info->infile, "%s", info->question.solutions);

    return EXIT_SUCCESS;
}

void que_print(que_t *que) {
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
