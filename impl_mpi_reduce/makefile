CXX = mpic++
CXX_FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -O3
LIBRARIES = -lm

COMMON = ../common
MPI_REDUCE_TARGET = MC_mpi_reduce

COMMON_OBJS = $(COMMON)/monte_carlo.cpp \
              $(COMMON)/args.cpp \
							$(COMMON)/stats.cpp \
							$(COMMON)/microtime.c

all: impl_mpi_reduce_exe

impl_mpi_reduce_exe: $(COMMON_OBJS) main.cpp
	$(CXX) $(CXX_FLAGS) -o $(MPI_REDUCE_TARGET) \
		main.cpp $(COMMON_OBJS) -I./$(COMMON) $(LIBRARIES)

$(BUILD_DIR)/%.o: $(COMMON)/%.cpp
	$(CXX) $(C_FLAGS) -c -o $@ $<

clean:
	rm -f $(MPI_REDUCE_TARGET)

.PHONY: clean
