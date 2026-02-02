# C++ Algorithms and Systems Programming

This repository contains C++ implementations of core algorithms, data structures, and language features, written to understand **performance, memory behavior, and correctness from first principles**.

The emphasis is on clear problem formulation, mathematically grounded solutions, and idiomatic modern C++.

---

## Status

This repository is under active development.
New implementations and refinements are added incrementally as concepts are studied and validated.
Existing files may be refactored as understanding deepens.

## Focus areas

- **Modern C++**
  - RAII and resource management
  - Move semantics
  - Const correctness and value vs reference semantics
- **Algorithms and data structures**
  - Classical algorithms with complexity analysis
  - Core data structure implementations
- **Numerical methods and linear algebra**
  - Root finding and optimization
  - Finite-difference methods
  - Matrix factorizations and least-squares problems
- **Low-level behavior**
  - Memory layout and ownership
  - Performance-aware design

---

## Repository structure

```text
.
├── fundamentals/              # Core C++ language concepts
├── algorithms/                # Classical algorithms
│   ├── divide_and_conquer/    # Divide-and-conquer paradigm
│   │   ├── README.md
│   │   ├── binary_search.cpp
│   │   └── power.cpp
│   │
│   ├── sorting/               # Sorting algorithms
│   │   ├── README.md
│   │   ├── merge_sort.cpp
│   │   └── quick_sort.cpp
│   │
│   ├── dynamic_programming/   # DP algorithms (to be added)
│   │   └── README.md
│   │
│   ├── greedy/                # Greedy algorithms (to be added)
│   │   └── README.md
│   │
│   └── graph/                 # Graph algorithms (to be added)
│       └── README.md
├── numerical/                 # Numerical methods and linear algebra
│   ├── spin_precession_rk4.cpp
│   └── spin_precession_rk4.dat
├── analysis/                  # Data processing and visualization
│   └── plot_spin_precession.py
├── modern_cpp/                # Modern C++ design patterns and idioms
└── README.md                  # Project overview and build instructions

