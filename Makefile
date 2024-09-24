CXX=g++
CFLAGS= -g -Wall -std=c++11
LDFLAGS= -lSDL2 -lSDL2main

BUILD_DIR = build
SRC_DIR = src

LIB_INC = -Llib/SDL2/lib/x86 -Ilib/SDL2/include

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/Engine.o
	$(CXX) $(CFLAGS) $(LIB_INC) $(BUILD_DIR)/main.o $(BUILD_DIR)/Engine.o $(BUILD_DIR)/PHandler.o $(BUILD_DIR)/Particle.o -o $(BUILD_DIR)/main $(LDFLAGS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(BUILD_DIR)/Engine.o
	$(CXX) $(CFLAGS) $(LIB_INC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o $(LDFLAGS)

$(BUILD_DIR)/Engine.o: $(SRC_DIR)/Engine.cpp $(SRC_DIR)/Engine.h $(BUILD_DIR)/PHandler.o
	$(CXX) $(CFLAGS) $(LIB_INC) -c $(SRC_DIR)/Engine.cpp -o $(BUILD_DIR)/Engine.o $(LDFLAGS)

$(BUILD_DIR)/PHandler.o: $(SRC_DIR)/PHandler.cpp $(SRC_DIR)/PHandler.h $(BUILD_DIR)/Particle.o
	$(CXX) $(CFLAGS) $(LIB_INC) -c $(SRC_DIR)/PHandler.cpp -o $(BUILD_DIR)/PHandler.o $(LDFLAGS)

$(BUILD_DIR)/Particle.o: $(SRC_DIR)/Particle.cpp $(SRC_DIR)/Particle.h $(SRC_DIR)/Vector2D.hpp
	$(CXX) $(CFLAGS) $(LIB_INC) -c $(SRC_DIR)/Particle.cpp -o $(BUILD_DIR)/Particle.o $(LDFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/main

run:
	./$(BUILD_DIR)/main