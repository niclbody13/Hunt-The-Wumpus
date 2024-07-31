CC = g++ -std=c++11 -g -Wall
exe_file = wumpus
$(exe_file): driver.o room.o event.o wumpus.o bats.o pit.o gold.o game.o player.o rope.o
	$(CC) driver.o room.o event.o wumpus.o bats.o pit.o gold.o game.o player.o rope.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
room.o: room.cpp
	$(CC) -c room.cpp
event.o: event.cpp
	$(CC) -c event.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
game.o: game.cpp
	$(CC) -c game.cpp
player.o: player.cpp
	$(CC) -c player.cpp
rope.o: rope.cpp
	$(CC) -c rope.cpp
clean:
	rm -f *.out *.o $(exe_file) *.temp

valgrind:
	valgrind --leak-check=full $(exe_file)

.PHONY: clean
