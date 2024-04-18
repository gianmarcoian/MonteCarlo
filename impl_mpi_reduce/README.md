This folder contains the optimized implementation of the Monte Carlo algorithm.
This optimized version uses mpi to parallelize the computation on multiple threads in order to improve performance.
It differ from the previus implementation in that it makes use of the MPI function "reduce" instead of the MPI function "gather" in order to put together the the results of the process.

To run the program:
```shell
$ make
$ ./mpirun -np <number of nodes> ./MC_mpi_reduce <number of simulations>
```
