#ifndef SCORE_H
#define SCORE_H

typedef struct {
    int id;
    char name[32];
    int score;
    char date[32];
} score;

/// Displays the leaderboard or the scores obtained by one person depending on user input.
/// Return value: false if no errors were encountered or true if errors were encountered.
bool score_display();

/// Appends the new score to the leaderboard.
/// Return value: true if the leaderboard could not be opened.
bool score_append(score *score);

#endif