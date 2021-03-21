#ifndef QUESTION_H
#define QUESTION_H

typedef struct {
    char sentence[256];
    char answears[4][16];
    char solutions[4];
} que;

typedef struct {
    FILE *infile;
    que question;
} queinfo;

/// Initializes the passed queinfo variable.
/// Return value: true if the questions file could not be opened, false otherwise.
bool que_init(queinfo *info);

/// Closes the file if it is opened.
/// If the file pointer is NULL, nothing happens.
void que_close(queinfo *info);

/// Reads the next question.
/// Return value: true if the file pointer is NULL.
bool que_read(queinfo *info);

/// Prints the question and its possible answears.
/// It does not print the correct answear.
void que_print(que *que);

#endif