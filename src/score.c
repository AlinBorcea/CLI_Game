#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "score.h"

typedef struct score { 
    int id;
    char name[32];
    int score;
    char date[32];
} score;

void read_score(FILE *file, score *score) {
    fscanf(file, "%d%s%d%s", &score->id, score->name, &score->score, score->date);
}

void print_score(FILE *outfile, score *score, int is_spaceunder) {
    fprintf(outfile, "%d %s %d ", score->id, score->name, score->score);
    for (int i = 0; i < strlen(score->date); i++) {
        if (is_spaceunder && score->date[i] == '_')
            fprintf(outfile, " ");
        else
            fprintf(outfile, "%c", score->date[i]);
    }
    fprintf(outfile, "\n");
}

int score_display() {
    FILE *scorefile;
    score score;
    char buffer[32];
    int all;
    CLEAR();

    scorefile = fopen(SCORE_FILE_NAME, "r");
    if (scorefile == NULL) {
        fprintf(stderr, "Error opening leaderboard!\n");
        return 1;
    }
    
    printf("Enter a name to search for or '.' to print the entire leaderboard...\n");
    scanf("%s", buffer);
    all = strcmp(buffer, ".") == 0;

    read_score(scorefile, &score);
    while (!feof(scorefile)) {
        if (all || (!all && strcmp(score.name, buffer) == 0)) {
            print_score(stdout, &score, 1);
        }
        read_score(scorefile, &score);
    }
    
    fclose(scorefile);
    printf("\nEnter a character to continue...");
    scanf("%s", buffer);
    CLEAR();
    return 0;
}

int score_append(score *score) {
    FILE *fp = fopen(SCORE_FILE_NAME, "a");
    if (fp == NULL) {
        fprintf(stderr, "Leaderboard could not be opened!");
        return 1;
    }

    print_score(fp, score, 0);
    fclose(fp);
    return 0;
}

score *score_new(int id, char *name, int score_int, char *date) {
    score *sc = (score*) malloc(sizeof(score));
    sc->id = id;
    sc->score = score_int;
    strcpy(sc->name, name);
    strcpy(sc->date, date);
    return sc;
}

void score_delete(score **sc) {
    free(*sc);
    *sc = NULL;
}
