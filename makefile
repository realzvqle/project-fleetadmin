all:
	gcc src/*.c lib/libraylib.a -lGL -lm -lpthread -ldl -lrt -lX11 -std=c99 -o game
	./game