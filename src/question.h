#ifndef QUESTION_H
#define QUESTION_H

#define QUESTION_FILE_NAME "questions.que"
#define QUESTION_COUNT 5

typedef struct question que; 

/// Initializes the module
/// Return value: 1 if there were errors else 0.
int que_init();

/// Closes the module
/// Call when the module is not needed anymore.
void que_close();

/// Reads the next question.
/// Return value: true if the file pointer is NULL.
int que_read(que *q);

/// Prints the question and its possible answears.
/// It does not print the correct answear.
int que_print(que *que);

int quiz_start();

#endif