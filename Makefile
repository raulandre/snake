CC=clang++
CFLAGS=-Wall -O3 -std=c++17
LFLAGS=-lm -lraylib
OUT=snake

all: *.cpp
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $(OUT) && ./$(OUT)

clean:
	rm $(OUT)
