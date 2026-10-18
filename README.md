# Educational CLI Calculator in C

A minimalist, high-performance command-line calculator written in C. This project serves as an educational resource demonstrating low-level array manipulation, dynamic memory allocation, and command-line argument processing (`argc`/`argv`).

## 🎓 Educational Focus

This repository showcases key C programming concepts:
* **CLI Argument Parsing:** Utilizing `argc` and `argv` to ingest multi-argument input streams dynamically.
* **Array Index Alignment:** Safe alignment between text-parsed arguments (`argv`) and numerical heap buffers (`int *nums`), avoiding classic off-by-one errors.
* **Dynamic Memory Allocation:** Proper runtime heap allocation using `malloc()` and explicit memory clearing via `free()` to prevent leaks.
* **Input Validation & Safety:** Robust `assert()` usage for development-time parameter checking and runtime zero-division defense mechanisms.

## 🛠 Features

* **Multi-Value Reduction:** Process an arbitrary chain of numbers (e.g., sequentially dividing \(N\) values).
* **Stateful CLI Menu:** An interactive loop running via standard input until an explicit exit interrupt (`Ctrl+C` or EOF) is triggered.
* **Supported Operations:**
  * `1` — Addition
  * `2` — Subtraction
  * `3` — Multiplication
  * `4` — Division (Safeguarded against integer division-by-zero crashes)

## 🚀 Getting Started

### Prerequisites
Ensure you have a modern C compiler installed (`GCC 11+` or `Clang 13+` recommended).

### Compilation
Compile the source code directly using `gcc`:

```bash
gcc main.c -o calculator-c
```

### Usage
Run the binary and pass the sequence of numeric values as space-separated arguments:

```bash
./calculator-c 100 5 2
```

### Interactive Execution Example

```text
$ ./calculator-c 100 5 2

Calculator made on C:
        1.Addition
        2.Subtraction
        3.Multiplication
        4.Division
Enter: 4

Result: 10

Calculator made on C:
        1.Addition
        2.Subtraction
        3.Multiplication
        4.Division
Enter: ^C
```

## 🔍 Core Logic Explanation

The binary maps the execution arguments linearly to match the indexing constraints of custom accumulator loops:

1. **Safety Assert:** `assert(argc > 2)` enforces at least two operand inputs before initialization.
2. **Buffer Alignment:** Arrays are allocated to size `argc`. The 0th index retains the fallback value `0` (converted string literal of the binary pathway), allowing mathematical accumulator loops to safely iterate over inputs starting strictly from index `2`.
3. **Loop Accumulation:** Operations leverage shorthand modification operators (`+=`, `-=`, `*=`, `/=`) directly over target index arrays to process inputs linearly without auxiliary register inflation.

