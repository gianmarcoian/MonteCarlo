CXX = mpic++
CXX_FLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -O3
LIBRARIES = -lm

COMMON = common
IMPL_SERIAL = impl_serial
IMPL_MPI = impl_mpi_gather
IMPL_MPI_REDUCE = impl_mpi_reduce
SERIAL_TARGET = MC_serial
MPI_TARGET = MC_mpi_gather
MPI_REDUCE_TARGET = MC_mpi_reduce

COMMON_OBJS = $(COMMON)/monte_carlo.cpp \
              $(COMMON)/args.cpp \
							$(COMMON)/stats.cpp \
							$(COMMON)/microtime.c

all: impl_serial_exe impl_mpi_gather_exe impl_mpi_reduce_exe

impl_serial_exe: $(COMMON_OBJS) $(IMPL_SERIAL)/main.cpp
	$(CXX) $(CXX_FLAGS) -o $(SERIAL_TARGET) \
		$(IMPL_SERIAL)/main.cpp $(COMMON_OBJS) -I./$(COMMON) $(LIBRARIES)

impl_mpi_gather_exe: $(COMMON_OBJS) $(IMPL_MPI)/main.cpp
	$(CXX) $(CXX_FLAGS) -o $(MPI_TARGET) \
		$(IMPL_MPI)/main.cpp $(COMMON_OBJS) -I./$(COMMON) $(LIBRARIES)

impl_mpi_reduce_exe: $(COMMON_OBJS) $(IMPL_MPI_REDUCE)/main.cpp
	$(CXX) $(CXX_FLAGS) -o $(MPI_REDUCE_TARGET) \
		$(IMPL_MPI_REDUCE)/main.cpp $(COMMON_OBJS) -I./$(COMMON) $(LIBRARIES)

$(BUILD_DIR)/%.o: $(COMMON)/%.cpp
	$(CXX) $(C_FLAGS) -c -o $@ $<

clean:
	rm -f $(SERIAL_TARGET) $(MPI_TARGET) $(MPI_REDUCE_TARGET)

.PHONY: clean
