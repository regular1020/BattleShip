CC = g++
TARGET = BattleShip
SOURCES = 	./main.cpp \
			./BattleShipApp.cpp \
			./Pane.cpp \
			./BattleShipMap.cpp \
			./StatPane.cpp \
			./InputPane.cpp \
			./client/Aircraft.cpp \
			./client/Battleship.cpp \
			./client/Crusier.cpp \
			./client/Destroyer.cpp \
			./client/GameManager.cpp \
			./client/Player.cpp \
			./client/Map.cpp \
			./client/Ship.cpp
LDFLAGS = -lncurses

all:
	$(CC) -std=c++11 -o $(TARGET) $(SOURCES) $(LDFLAGS)

run:
	$(CC) -std=c++11 -o $(TARGET) $(SOURCES) $(LDFLAGS) && ./$(TARGET)

clean:
	rm -rf *.o $(TARGET)