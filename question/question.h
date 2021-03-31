#ifndef QUESTION_H
#define QUESTION_H

typedef struct {
    char sentence[128];
    char answears[4][16];
    char solutions[4];
} que;

/// Initializes the file pointer
/// Return value: true if the questions file could not be opened, false otherwise.
bool que_init();

/// Closes the file if it is opened.
/// If the file pointer is NULL, nothing happens.
void que_close();

/// Reads the next question.
/// Return value: true if the file pointer is NULL.
bool que_read(que *q);

/// Prints the question and its possible answears.
/// It does not print the correct answear.
void que_print(que *que);

bool quiz_start();

#endif