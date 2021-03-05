OBJS= tokenNew.o tokenizer.o UI.o

CFLAGS= -g -O3

all: UI

tokenNew.o:tokenNew.c tokenizer.h
history.o:history.c history.h
UI.o: UI.c


UI:tokenNew.o history.o UI.o
	cc -g -o UI $(CFLAGS) tokenNew.o UI.o history.o

clean:
	rm -f *.o *~ *#
	ls

run:UI
	./UI
