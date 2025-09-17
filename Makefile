# Makefile — TP2 (C++)

CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic
INCLUDES := -Isrc
SRC_DIR  := src
BUILD_DIR:= build
TARGET   := $(BUILD_DIR)/tp2

# Sources présents (main.cpp prioritaire si disponible)
SOURCES  := $(wildcard $(SRC_DIR)/*.cpp)
HEADERS  := $(wildcard $(SRC_DIR)/*.h)

$(TARGET): $(SOURCES) $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: all run clean format

all: $(TARGET)

run: all
	$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

format:
	@command -v clang-format >/dev/null 2>&1 && clang-format -i $(SOURCES) $(HEADERS) || echo 'clang-format non installé'
