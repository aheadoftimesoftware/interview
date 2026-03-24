CXX ?= clang++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
BUILD_DIR := build
COMMON_SOURCES := src/inventory.cpp tests/inventory_tests.cpp

EMPTY_SOURCES := $(COMMON_SOURCES) src/inventory_service.cpp
POOR_SOURCES := $(COMMON_SOURCES) solutions/poor/inventory_service.cpp
SOLID_SOURCES := $(COMMON_SOURCES) solutions/solid/inventory_service.cpp
MODEL_SOURCES := $(COMMON_SOURCES) solutions/model/inventory_service.cpp

EMPTY_OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/empty/%.o,$(EMPTY_SOURCES))
POOR_OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/poor/%.o,$(POOR_SOURCES))
SOLID_OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/solid/%.o,$(SOLID_SOURCES))
MODEL_OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/model/%.o,$(MODEL_SOURCES))

EMPTY_BINARY := $(BUILD_DIR)/empty/inventory_tests
POOR_BINARY := $(BUILD_DIR)/poor/inventory_tests
SOLID_BINARY := $(BUILD_DIR)/solid/inventory_tests
MODEL_BINARY := $(BUILD_DIR)/model/inventory_tests

.PHONY: all empty poor solid model solutions test test-empty test-poor test-solid test-model clean

all: empty

empty: $(EMPTY_BINARY)

solutions: poor solid model

poor: $(POOR_BINARY)

solid: $(SOLID_BINARY)

model: $(MODEL_BINARY)

test: test-empty

test-empty: $(EMPTY_BINARY)
	./$(EMPTY_BINARY)

test-poor: $(POOR_BINARY)
	./$(POOR_BINARY)

test-solid: $(SOLID_BINARY)
	./$(SOLID_BINARY)

test-model: $(MODEL_BINARY)
	./$(MODEL_BINARY)

$(EMPTY_BINARY): $(EMPTY_OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(EMPTY_OBJECTS) -o $@

$(POOR_BINARY): $(POOR_OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(POOR_OBJECTS) -o $@

$(SOLID_BINARY): $(SOLID_OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(SOLID_OBJECTS) -o $@

$(MODEL_BINARY): $(MODEL_OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(MODEL_OBJECTS) -o $@

$(BUILD_DIR)/empty/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/poor/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/solid/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/model/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
