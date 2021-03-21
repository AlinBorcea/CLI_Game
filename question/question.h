#ifndef QUESTION_H
#define QUESTION_H

#define QUESTION_FILE_NAME "questions.que"

typedef struct question {
    char sentence[256];
    char answears[4][16];
    char solutions[4];
} que_t;

typedef struct questioninfo {
    FILE *infile;
    que_t question;
} queinfo_t;

///
int que_init(queinfo_t *info);

void que_close(queinfo_t *info);

int que_read(queinfo_t *info);

void que_print(que_t *que);

#endif