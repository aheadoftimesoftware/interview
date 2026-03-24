# C++ Interview Version

This folder mirrors the TypeScript interview in C++.

It includes the candidate implementation skeleton and the tests for the exercise.

The exercise uses only the C++ standard library.

## Files

- `include/model.hpp` defines the interview data model.
- `include/inventory.hpp` and `src/inventory.cpp` provide the fixed interview fixtures.
- `include/inventory_service.hpp` defines the service API.
- `src/inventory_service.cpp` is the empty interview skeleton.
- `tests/inventory_tests.cpp` contains the expected behavior.
- `Makefile` provides simple build and test targets.

## Required tools

You need:

- a C++17 compiler
- GNU Make
- a shell that can run the Makefile targets

Recommended setup by platform:

- Linux (Debian/Ubuntu): `clang` and `make`
- macOS: Homebrew `llvm` and `make`
- Windows: `clang++`, `make`, and Git Bash

Install scripts are included in `scripts/`.

## Build and test

From this directory:

```sh
make
make test
make clean
```

`make` builds the interview version, and `make test` runs that same version.

Available targets:

```sh
make empty
make test-empty
```

- `make test` or `make test-empty` runs the empty candidate version in `src/inventory_service.cpp`.

If your compiler is not available as `clang++`, override it when calling make:

```sh
make CXX=g++
make test CXX=g++
```

## Windows note

Run the Makefile from Git Bash or another POSIX-compatible shell. After installing tools with `winget`, reopen your terminal so `clang++` and `make` are on `PATH`.

## Original interview tasks

The exercise asks you to implement these four methods:

- `searchForBookWithTitle`
- `searchForAvailableBookWithTitle`
- `getLentBooksForCustomer`
- `getAllOverdueBooks`

The test names and expected outcomes match the TypeScript interview.
