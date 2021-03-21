cc = gcc
cflags = -std=c17 -pedantic -Wall -g

game.exe: game.o score.o question.o
	$(cc) $(cflags) -o game.exe game.o score.o question.o

game.o: game.c score/score.h
	$(cc) $(cflags) -c game.c

score.o: score/score.c score/score.h
	$(cc) $(cflags) -c score/score.c

question.o: question/question.h question/question.c
	$(cc) $(cflags)  -c question/question.c
