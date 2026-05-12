CC = gcc
TARGET = main
OBJS = main.o funciones.o procedimientos.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c funciones.h
	$(CC) -c main.c

funciones.o: funciones.c funciones.h
	$(CC) -c funciones.c

procedimientos.o: procedimientos.c procedimientos.h
	$(CC) -c procedimientos.c

clean:
	rm -f *.o $(TARGET)