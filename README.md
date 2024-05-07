# Markov Chain Monte Carlo research
This MCMC simulation uses cache parallelization via MPI (C++).

The video of the presentation can be found at https://youtu.be/BffpjVDpsBQ 

The project should be buildable with make.

The directory is organized as follows:
- Directory "common":
        Contains the utilities file that are used by all the implementations.
- Directory "build":
        Contains the object files.
- Directory "impl_serial":
        Serial implementation of the Monte Carlo algorithm.
- Directory "impl_mpi":
        Optimized parralelized implementation of the algorithm usign mpi.
- Directory "impl_mpi_reduce":
        Optimized parralelized implementation of the algorithm usign mpi and making use of the function "reduce" instead of the usual "gather".
- This README.md file.
