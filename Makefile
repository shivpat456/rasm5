CC=g++
AS=as
LD=g++

EXEC=build/RASM5.out

SRC_DIR=src


OBJ_DIR=build
OBJS=$(OBJ_DIR)/bubbleSortA.o $(OBJ_DIR)/bubbleSortC.o $(OBJ_DIR)/RASM5.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(LD) -o build/RASM5.out build/bubbleSortA.o build/bubbleSortC.o build/RASM5.o

$(OBJ_DIR)/bubbleSortA.o: $(SRC_DIR)/bubbleSortA.s
	$(AS) -g -o build/bubbleSortA.o src/bubbleSortA.s

$(OBJ_DIR)/bubbleSortC.o: $(SRC_DIR)/bubbleSortC.cpp
	$(CC) -c -o build/bubbleSortC.o src/bubbleSortC.cpp

$(OBJ_DIR)/RASM5.o: $(SRC_DIR)/RASM5.cpp
	$(CC) -c -o build/RASM5.o src/RASM5.cpp


clean:
	rm -f build/*.o build/RASM5.out

.PHONY: all clean
