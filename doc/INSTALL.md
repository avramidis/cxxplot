# Installing cxxplot

These instructions will get you a copy of cxxplot up and running on your machine with Ubuntu.

### Prerequisites

To get the code you will need git. To install git on Ubuntu use the following commands in a terminal

```bash
sudo apt update
sudo apt install git
```

To clone the repository from github use the following command in a terminal

```bash
git clone git@github.com:avramidis/cxxplot.git
```

To generate the makefiles for compiling cxxplot you will need cmake with release version equal of higher than 3.15.3. Go to https://cmake.org/download/
and download the latest binary distribution for Linux x86_64. For example, the latest file at the time when this doc was written was
cmake-3.16.2-Linux-x86_64.sh. To install cmake use the following command in a terminal

```bash
sudo cmake-3.16.2-Linux-x86_64.sh
```

To build and run cxxplot you will need a C++ compiler, the Python3 interpreter, numpy and matplotlib.

Use the following commands in a terminal to install the GNU compiler

```bash
sudo apt update
sudo apt install build-essential g++-9
```

Download the latest OpenMPI version and install to it with the GNU compiler use the following commands

```bash
./configure --enable-mpi-fortran --prefix=/opt/openmpi-4.0.2 CC=/usr/bin/gcc CXX=/usr/bin/g++ FC=/usr/bin/gfortran F77=/usr/bin/gfortran
make -j4
sudo make install
```

To install the Python3 interpreter, numpy and matplotlib use the following command in a terminal

```bash
sudo apt install python3 python3-dev python3-pip python3-tk python3-numpy
sudo pip3 install matplotlib
```

### Build

Build with g++ navigate to the directory with 

```bash
mkdir build-gcc
cd build-gcc
cmake -DCMAKE_BUILD_TYPE=Release -DENABLE_OPENACC=OFF -DCMAKE_C_COMPILER=mpicc -DCMAKE_CXX_COMPILER=mpic++ -DCMAKE_Fortran_COMPILER=mpif90 -DHDF5_ROOT=/opt/hdf5/openmpi-4.0.2/gcc/1.10.5 ..
make -j4
```

## Support

If you encounter any problems, found a bug or need help, please open an [issue on github](https://github.com/avramidis/cxxplot/issues)  
with your system details, *exact* commands used, and logs posted as a [gist](https://gist.github.com/).