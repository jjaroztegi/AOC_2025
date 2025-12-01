# Advent of Code 2025

C++23 solutions for [Advent of Code 2025](https://adventofcode.com/2025).

## Structure

```
DayXX/
  common.h    # Shared code
  part1.cpp   # Part 1 solution
  part2.cpp   # Part 2 solution
  test.txt    # Puzzle test input
  Makefile    # Build system
```

## Usage

```bash
cd DayXX
make        # Build both parts
make run1   # Run part 1
make run2   # Run part 2
make clean
```

## Requirements

- C++23 compiler (g++ with `-std=c++23`)
- GNU Make
- Windows (MSYS2 UCRT64): `-lstdc++exp` flag
