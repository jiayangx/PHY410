# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
LIBS=-I$(CPT_PATH) -L$(CPT_PATH) -lcpt


all: triatomic problem1 problem2 problem3 #matrixmult

problem1: problem1.cpp
	$(CC) $^ $(LIBS) -o problem1

problem2: problem2.cpp
	$(CC) $^  $(LIBS) -o problem2

problem3: problem3.cpp
	$(CC) $^  $(LIBS) -o problem3

triatomic: triatomic.cpp
	$(CC) $^  $(LIBS) -o triatomic

#matrixmult: matrixmult.cpp
#	$(CC) $^  $(LIBS) -o matrixmult


clean:
	rm -rf *o triatomic problem1 problem2 problem3  #matrixmult
