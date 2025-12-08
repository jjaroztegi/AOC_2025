CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -g
BUILD_DIR = build

ifeq ($(OS),Windows_NT)
	LDFLAGS = -lstdc++exp
	EXE_EXT = .exe
	RM = cmd /c if exist
	RMDIR = cmd /c if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	MKDIR = cmd /c if not exist
else
	LDFLAGS =
	EXE_EXT =
	RM = rm -f
	RMDIR = rm -rf
	MKDIR = mkdir -p
endif

TARGETS = $(BUILD_DIR)/part1$(EXE_EXT) $(BUILD_DIR)/part2$(EXE_EXT)

.PHONY: all clean run1 run2

all: $(BUILD_DIR) $(TARGETS)

$(BUILD_DIR):
ifeq ($(OS),Windows_NT)
	$(MKDIR) "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
else
	$(MKDIR) $(BUILD_DIR)
endif

$(BUILD_DIR)/part1$(EXE_EXT): part1.cpp common.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

$(BUILD_DIR)/part2$(EXE_EXT): part2.cpp common.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

run1: $(BUILD_DIR)/part1$(EXE_EXT)
	$(BUILD_DIR)/part1$(EXE_EXT)

run2: $(BUILD_DIR)/part2$(EXE_EXT)
	$(BUILD_DIR)/part2$(EXE_EXT)

clean:
	$(RMDIR)
