all: main.o explosion.o game.o window.o data.o action.o
	gcc -gstabs+ -o minesweeper main.o explosion.o game.o window.o data.o action.o -lncurses
	rm *.o

main.o: src/main.c
	gcc -c src/main.c

explosion.o: src/explosion.c
	gcc -c src/explosion.c

game.o: src/game.c
	gcc -c src/game.c

window.o: src/window.c
	gcc -c src/window.c

data.o: src/data.c
	gcc -c src/data.c

action.o: src/action.c
	gcc -c src/action.c

clean:
	rm minesweeper
