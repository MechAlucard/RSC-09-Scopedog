# Makefile
OBJS = MainScreen.o main.o Login.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LIBS = -lwt -lwthttp -lboost_signals
test: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test $(LIBS)
MainScreen.o: MainScreen.h MainScreen.c
	$(CC) $(CFLAGS) MainScreen.c $(LIBS)
Login.o: Login.h Login.c
	$(CC) $(CFLAGS) Login.c $(LIBS)
main.o: main.c
	$(CC) $(CFLAGS) main.c $(LIBS)
clean:
	\rm *.o test
all: main.o Login.o MainScreen.o 
