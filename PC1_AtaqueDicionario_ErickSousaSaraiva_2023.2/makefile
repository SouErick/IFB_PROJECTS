# Makefile
CC = gcc
CFLAGS = -Wall
LIBS = -lssl -lcrypto

SRC = criptografico.c leitura.c main.c quebra.c saida.c

OBJ = $(SRC:.c=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(LIBS)

clean:
	rm -f $(OBJ) $(TARGET)