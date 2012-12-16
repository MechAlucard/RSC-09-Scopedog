# Makefile
OBJS = MainScreen.o main.o Login.o control.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LIBS = -lwt -lwthttp -lboost_signals
test: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test $(LIBS)
MainScreen.o: MainScreen.h MainScreen.cpp
	$(CC) $(CFLAGS) MainScreen.cpp $(LIBS)
Login.o: Login.h Login.cpp
	$(CC) $(CFLAGS) Login.cpp $(LIBS)
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBS)
control.o: Picontrol/control.cpp
	$(CC) $(CFLAGS) Picontrol/control.cpp $(LIBS)
clean:
	\rm *.o test
all: main.o Login.o MainScreen.o control.o
