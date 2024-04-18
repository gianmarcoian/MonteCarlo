CXX = mpic++
CXX_FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -O3
LIBRARIES = -lm

COMMON = ../common
SERIAL_TARGET = MC_serial

COMMON_OBJS = $(COMMON)/monte_carlo.cpp \
              $(COMMON)/args.cpp \
							$(COMMON)/stats.cpp \
							$(COMMON)/microtime.c

all: impl_serial_exe

impl_serial_exe: $(COMMON_OBJS) main.cpp
	$(CXX) $(CXX_FLAGS) -o $(SERIAL_TARGET) \
		main.cpp $(COMMON_OBJS) -I./$(COMMON) $(LIBRARIES)

$(BUILD_DIR)/%.o: $(COMMON)/%.cpp
	$(CXX) $(C_FLAGS) -c -o $@ $<

clean:
	rm -f $(SERIAL_TARGET)

.PHONY: clean
