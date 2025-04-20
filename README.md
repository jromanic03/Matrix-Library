# Matrix Library in C and C++

## AUTHORING
- Name: Joseph Romanic
- Affiliation: UMBC/CMSC 313/Dr. Kid Kidd
- Last Updated: 4-19-2025, 11:27 PM

---

## PURPOSE OF SOFTWARE

The purpose of this software is to create a basic matrix manipulation library in both C++ and C. It supports matrix addition, scalar multiplication, matrix multiplication, and matrix transposition.

The primary goal is to evaluate the expression:

`D = A + (3 * B) x C^T`

Where
```
A =	[6 4;	B =	[1 2 3; C =	[2 4 6
	8 3]		4 5 6]		1 3 5]
```

---

## FILES

Each version of the project is stored within its own directory, `matrixC` and `matrixC++`.

### C Version
- `main.c` — Main test driver for evaluating the matrix expression in C.
- `matrix.c` — Implementation of matrix functions (create, add, multiply, transpose, etc.).
- `matrix.h` — Header file for the C matrix library (struct and function declarations).
- `Makefile` — Automates building, cleaning, and running the C project.

### C++ Version
- `main.cpp` — Main test driver for evaluating the matrix expression in C++.
- `Matrix.cpp` — Implementation of the `Matrix` class and its operations.
- `Matrix.h` — Header file declaring the `Matrix` class and its member functions.
- `Makefile` — Automates building, cleaning, and running the C++ project.

---

## BUILD INSTRUCTIONS

To compile either version, ensure you are using a POSIX-compatible environment (Linux/macOS/WSL), and run these commands within the designated subdirectories.

### C Version
```bash
cd c_version/
make
```

### C++ Version
```bash
cd cpp_version/
make
```

Each Makefile also supports:

`make run` — Compile and run the program

`make clean` — Remove object files and executables

---

## TESTING METHODOLOGY
The matrix library is tested by computing the result of a known matrix expression. The expected result is printed to the console:

```mathematica
D = A + (3 * B) x C^T:
90 70
200 150
```

Additional verification can be done by substituting known matrices and manually checking outputs.

The matrix library functions were designed with dynamic memory management, and cleanup routines were manually tested using valgrind (or similar) to verify no memory leaks occur.

---

## ADDITIONAL INFORMATION

- The C version is written in standard C99 and avoids any non-standard extensions.

- The C++ version uses idiomatic object-oriented practices and operator overloading.

- All matrix dimensions are checked implicitly through careful construction and testing, but further dimension checking could be added for robustness.

- All matrix memory is dynamically allocated; care has been taken to ensure cleanup is complete.