CC = g++
CFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lSDL2

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = snake

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
