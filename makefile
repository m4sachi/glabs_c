CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = main.o array.o basic.o Pointers.o singlylinkedlist.o sort.o string.o Tree.o
TARGET = collection
all: $(TARGET)
    $(TARGET): $(OBJFILES)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
    rm -f $(OBJFILES) $(TARGET) *~