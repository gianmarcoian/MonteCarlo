This folder contains the optimized implementation of the Monte Carlo algorithm.
This optimized version uses mpi to parallelize the computation on multiple threads via the MPI "gather" function in order to improve performance.

To run the program:
```shell
$ make
$ ./mpirun -np <number of nodes> ./MC_mpi <number of simulations>
```
