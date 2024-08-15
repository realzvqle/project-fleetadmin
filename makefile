


windows:
	cl src/*.c lib/windows/libraylibdll.a lib/windows/libraylib.a /Fe:game.exe
	rm *.obj
	game.exe




linux:
	gcc src/*.c lib/linux/libraylib.a -lGL -lm -lpthread -ldl -lrt -lX11 -std=c99 -o game
	./game