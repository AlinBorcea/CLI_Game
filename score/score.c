#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "score.h"

#define CLEAR() system("clear")

#define SCORE_FILE_NAME "leaderboard.lb"

void read_score(FILE *file, score *score) {
    fscanf(file, "%d%s%d%s", &score->id, score->name, &score->score, score->date);
}

void print_score(FILE *outfile, score *score) {
    printf("%d %s %d ", score->id, score->name, score->score);
    for (int i = 0; i < strlen(score->date); i++) {
        if (score->date[i] == '_')
            fprintf(outfile, " ");
        else
            fprintf(outfile, "%c", score->date[i]);
    }
    fprintf(outfile, "\n");
}

bool score_display() {
    FILE *scorefile;
    score score;
    char buffer[32];
    CLEAR();

    scorefile = fopen(SCORE_FILE_NAME, "r");
    if (scorefile == NULL) {
        fprintf(stderr, "Error opening leaderboard!\n");
        return true;
    }
    
    printf("Enter a name to search for or '.' to print the entire leaderboard...\n");
    scanf("%s", buffer);

    if (strcmp(buffer, ".") != 0) {
        while (!feof(scorefile)) {
            read_score(scorefile, &score);
            if (strcmp(score.name, buffer) == 0) {
                print_score(stdout, &score);
            }
        }

    } else {
        while (!feof(scorefile)) {
            read_score(scorefile, &score);
            print_score(stdout, &score);
        }
    }
    
    fclose(scorefile);
    printf("\nEnter a character to continue...");
    scanf("%s", buffer);
    CLEAR();
    return false;
}

bool score_append(score *score) {
    FILE *fp = fopen(SCORE_FILE_NAME, "a");
    if (fp == NULL) {
        fprintf(stderr, "Leaderboard could not be opened!");
        return true;
    }

    print_score(fp, score);
    fclose(fp);
    return false;
}
