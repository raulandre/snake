CC=clang++
CFLAGS=-Wall -O3 -std=c++17 #-DGRID
LFLAGS=-lm -lraylib -ldl -pthread
INCLUDE=-Iinclude/
OUT=snake

all: src/*.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LFLAGS) -o $(OUT)

clean:
	rm $(OUT)
