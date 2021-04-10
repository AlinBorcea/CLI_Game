CC = gcc
CFLAGS = -std=c17 -pedantic -Wall -g
OBJS = game.o score.o question.o

game: $(OBJS) game.c
	$(CC) $(CFLAGS) $(OBJS) -o game 

game.o: game.c question/question.h score/score.h
	$(CC) $(CFLAGS) -c game.c

question.o: question/question.c question/question.h score/score.h
	$(CC) $(CFLAGS) -c question/question.c

score.o: score/score.c score/score.h
	$(CC) $(CFLAGS) -c score/score.c