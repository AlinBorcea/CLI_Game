#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "score.h"

typedef struct score {
    int id;
    char name[32];
    int score;
    char date[32];
} score_t;

void read_score(FILE *file, score_t *score) {
    fscanf(file, "%d%s%d%s", &score->id, score->name, &score->score, score->date);
}

void print_score(score_t *score) {
    printf("%d %s %d ", score->id, score->name, score->score);
    for (int i = 0; i < strlen(score->date); i++) {
        if (score->date[i] == '_')
            printf(" ");
        else
            printf("%c", score->date[i]);
    }
    printf("\n\n");
}

int score_display() {
    FILE *scorefile;
    score_t score;
    char buffer[32];
    system("cls");

    scorefile = fopen(SCORE_FILE_NAME, "r");
    if (scorefile == NULL) {
        fprintf(stderr, "Error opening leaderboard!\n");
        return 1;
    }

    fscanf(scorefile, "%s", score.name);
    fscanf(scorefile, "%s", score.name);
    fscanf(scorefile, "%s", score.name);
    fscanf(scorefile, "%s", score.name);
    
    printf("Enter a name to search for or '.' to print the entire leaderboard...\n");
    scanf("%s", buffer);

    if (strcmp(buffer, ".") != 0) {
        while (!feof(scorefile)) {
            read_score(scorefile, &score);
            if (strcmp(score.name, buffer) == 0) {
                print_score(&score);
            }
        }

    } else {
        while (!feof(scorefile)) {
            read_score(scorefile, &score);
            print_score(&score);
        }
    }
    
    fclose(scorefile);
    printf("\nEnter any key to continue...");
    scanf("%s", buffer);
    system("cls");
    return EXIT_SUCCESS;
}
