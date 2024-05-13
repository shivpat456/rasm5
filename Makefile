CC=g++
AS=as
LD=g++

EXEC=build/RASM5.out

SRC_DIR=src

OBJ_DIR=build
OBJS=$(OBJ_DIR)/bubbleSortA.o $(OBJ_DIR)/bubbleSortC.o $(OBJ_DIR)/RASM5.o ../obj/putstring.o ../obj/String_length.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(LD) -g -o $(EXEC) $(OBJS)

$(OBJ_DIR)/bubbleSortA.o: $(SRC_DIR)/bubbleSortA.s
	$(AS) -g -o $(OBJ_DIR)/bubbleSortA.o $(SRC_DIR)/bubbleSortA.s

$(OBJ_DIR)/bubbleSortC.o: $(SRC_DIR)/bubbleSortC.cpp
	$(CC) -c -g -o $(OBJ_DIR)/bubbleSortC.o $(SRC_DIR)/bubbleSortC.cpp

$(OBJ_DIR)/RASM5.o: $(SRC_DIR)/RASM5.cpp
	$(CC) -c -g -o $(OBJ_DIR)/RASM5.o $(SRC_DIR)/RASM5.cpp

clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)

.PHONY: all clean
