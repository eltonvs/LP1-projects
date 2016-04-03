CXX = g++
DEL = /bin/rm

CFLAGS = -Wall -std=c++11
DFLAGS = -g -O0

BIN_DIR = bin
TARGET = message
SRC1 = dirver_message
SRC2 = message
DEBUG = debug
SRC_DIR = src
INCLUDE_DIR = include

all: $(BIN_DIR)/$(TARGET)

debug: $(BIN_DIR)/$(DEBUG)

$(BIN_DIR)/$(TARGET): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o
	@echo "Creating compiled file"
	$(CXX) $(CFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o -o $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(DEBUG): $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o
	@echo "Creating compiled [ready to debug] file"
	$(CXX) $(CFLAGS) $(DFLAGS) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o -o $(BIN_DIR)/$(DEBUG)

$(BIN_DIR)/$(SRC1).o: $(SRC_DIR)/$(SRC1).cpp
	@echo "Creating object file 1"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC1).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC1).o

$(BIN_DIR)/$(SRC2).o: $(SRC_DIR)/$(SRC2).cpp
	@echo "Creating object file 2"
	$(CXX) $(CFLAGS) -c $(SRC_DIR)/$(SRC2).cpp -I $(INCLUDE_DIR) -o $(BIN_DIR)/$(SRC2).o

clean:
	$(DEL) $(BIN_DIR)/$(TARGET) $(BIN_DIR)/$(SRC1).o $(BIN_DIR)/$(SRC2).o
	$(DEL) $(BIN_DIR)/$(DEBUG)