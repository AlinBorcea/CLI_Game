#ifndef SCORE_H
#define SCORE_H

#define SCORE_FILE_NAME "leaderboard.lb"

typedef struct score score; 

score *score_new(int id, char *name, int score, char *date);

void score_delete(score **sc);

/// Displays the leaderboard or the scores obtained by one person depending on user input.
/// Return value: 1 if errors were encountered else 0.
int score_display();

/// Appends the new score to the leaderboard.
/// Return value: true if the leaderboard could not be opened.
int score_append(score *score);

#endif