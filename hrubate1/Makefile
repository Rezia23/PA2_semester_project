TARGET = hrubate1
CXX = g++
CXX_FLAGS = -Wall -pedantic -Wextra -std=c++14 -MMD -MP
BUILD_DIR = build
SRC_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
MKDIR = mkdir -p


.PHONY: all
all: compile doc


.PHONY: compile
compile: $(TARGET)

.PHONY:run
run: $(TARGET)
	./$(TARGET)

$(TARGET): ${OBJ_FILES}
		$(CXX) $(CXX_FLAGS) $^ -o $@

-include $(OBJ_FILES:.o=.d)

$(BUILD_DIR)/%.o: src/%.cpp
		$(MKDIR) $(BUILD_DIR)
		$(CXX) $(CXX_FLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(TARGET) $(BUILD_DIR)/ doc/ 2>/dev/null

doc: Doxyfile src/*.h
	doxygen Doxyfile



