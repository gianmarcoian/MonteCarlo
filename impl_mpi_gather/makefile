CXX = mpic++
CXX_FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -O3
LIBRARIES = -lm

COMMON = ../common
MPI_TARGET = MC_mpi_gather

COMMON_OBJS = $(COMMON)/monte_carlo.cpp \
              $(COMMON)/args.cpp \
							$(COMMON)/stats.cpp \
							$(COMMON)/microtime.c

all: impl_mpi_gather_exe

impl_mpi_gather_exe: $(COMMON_OBJS) main.cpp
	$(CXX) $(CXX_FLAGS) -o $(MPI_TARGET) \
		main.cpp $(COMMON_OBJS) -I./$(COMMON) $(LIBRARIES)

$(BUILD_DIR)/%.o: $(COMMON)/%.cpp
	$(CXX) $(C_FLAGS) -c -o $@ $<

clean:
	rm -f $(MPI_TARGET)

.PHONY: clean
