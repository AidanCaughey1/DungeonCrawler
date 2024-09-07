CC=g++ --std=c++11 -g
exe_file=run

$(exe_file): main.cpp bats.o event.o game.o gold.o pit.o room.o wumpus.o
	$(CC) main.cpp bats.o event.o game.o gold.o pit.o room.o wumpus.o -o $(exe_file)

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

event.o: event.h event.cpp
	$(CC) -c event.cpp

game.o: game.h game.cpp
	$(CC) -c game.cpp

gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp

pit.o: pit.h pit.cpp
	$(CC) -c pit.cpp

room.o: room.h room.cpp
	$(CC) -c room.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp

clean: 
	rm -f *.o $(exe_file)