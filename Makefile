INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

all: $(BIN_DIR)/main

$(BIN_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/semiIssue.o $(BUILD_DIR)/Issue.o $(BUILD_DIR)/Board.o $(BUILD_DIR)/Strings.o
	g++ -o $@ $^

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	g++ -c -o $@ $<

$(BUILD_DIR)/semiIssue.o: $(SRC_DIR)/semiIssue.cpp $(INCLUDE_DIR)/semiIssue.h
	g++ -c -o $@ $<

$(BUILD_DIR)/Issue.o: $(SRC_DIR)/Issue.cpp $(INCLUDE_DIR)/Issue.h
	g++ -c -o $@ $<

$(BUILD_DIR)/Board.o: $(SRC_DIR)/Board.cpp $(INCLUDE_DIR)/Board.h
	g++ -c -o $@ $<

$(BUILD_DIR)/Strings.o: $(SRC_DIR)/Strings.cpp $(INCLUDE_DIR)/Strings.h
	g++ -c -o $@ $<
