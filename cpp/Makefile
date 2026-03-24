CXX ?= clang++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
BUILD_DIR := build
COMMON_SOURCES := src/inventory.cpp tests/inventory_tests.cpp

EMPTY_SOURCES := $(COMMON_SOURCES) src/inventory_service.cpp

EMPTY_OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/empty/%.o,$(EMPTY_SOURCES))

EMPTY_BINARY := $(BUILD_DIR)/empty/inventory_tests

.PHONY: all empty test test-empty clean

all: empty

empty: $(EMPTY_BINARY)

test: test-empty

test-empty: $(EMPTY_BINARY)
	./$(EMPTY_BINARY)

$(EMPTY_BINARY): $(EMPTY_OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(EMPTY_OBJECTS) -o $@

$(BUILD_DIR)/empty/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
