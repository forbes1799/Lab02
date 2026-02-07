#!/bin/bash -l
# Specify the current working directory as the location for executables/files
# This is the default setting.
#SBATCH -D ./

# Export the current environment to the compute node
# This is the default setting.
#SBATCH --export=ALL

# Specific course queue, exclusive use (for timings), max 1 min wallclock time
#SBATCH -p course
#SBATCH -t 1

# just 1 thread to run on
export OMP_NUM_THREADS=1

# GNU no-opt

# Run...

