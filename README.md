# Rubik's Cube Solver using Korf's IDA*

A high-performance **3×3 Rubik's Cube Solver** built entirely in **C++**, implementing multiple cube representations, classical and heuristic search algorithms, compressed Pattern Databases, and an OpenCV-powered cube scanner for solving a real physical Rubik's Cube.

The project follows the ideas introduced in **Richard E. Korf's** optimal Rubik's Cube solving research while focusing on clean software architecture, reusable components, and memory-efficient data structures.

---

## Demo

> Scan a physical Rubik's Cube using a webcam → Detect sticker colors → Construct the cube virtually → Solve it using Korf's IDA* Algorithm.
<img width="968" height="560" alt="CubeFace1" src="https://github.com/user-attachments/assets/6ec0e947-9492-4bed-9a36-e6696767468c" />
<img width="1257" height="989" alt="CubeNet1" src="https://github.com/user-attachments/assets/5ab30835-de29-4345-b285-626d4cbf67cc" />



---

# Features

### Multiple Cube Representations

The solver supports three interchangeable cube representations.

- 3D Array Representation
- 1D Array Representation
- Bitboard Representation

Each representation implements the same abstract interface, allowing every solver to work without modification.

---

### Multiple Search Algorithms

Implemented from scratch

- Depth First Search (DFS)
- Breadth First Search (BFS)
- Iterative Deepening DFS (IDDFS)
- Korf's IDA* (Iterative Deepening A*)

This allows comparison between uninformed and heuristic search techniques.

---

### Corner Pattern Database

Implemented a compressed Corner Pattern Database used as the heuristic for IDA*.

Features include

- Pattern Database generation using BFS
- Permutation-based indexing
- Nibble Array compressed storage
- Binary database serialization

The Pattern Database significantly reduces the search space explored during solving.

---

### OpenCV Cube Scanner

The project includes an integrated Cube Scanner capable of

- Capturing all six cube faces
- Detecting sticker colors
- Constructing the cube automatically
- Passing the generated cube directly to the solver

---

## Cube Scanning & Reconstruction

The following screenshots demonstrate the six-face scanning
process and corresponding cube reconstruction.

<img width="968" height="560" alt="CubeFace1" src="https://github.com/user-attachments/assets/6ec0e947-9492-4bed-9a36-e6696767468c" />
<img width="1257" height="989" alt="CubeNet1" src="https://github.com/user-attachments/assets/5ab30835-de29-4345-b285-626d4cbf67cc" />

<img width="966" height="564" alt="CubeFace2" src="https://github.com/user-attachments/assets/fd92758f-f4b3-4cbf-80e3-7fd0be87649e" />
<img width="1260" height="993" alt="CubeNet2" src="https://github.com/user-attachments/assets/725b855d-5acf-4ce5-91e6-af4fa1b1a567" />

<img width="972" height="565" alt="CubeFcae3" src="https://github.com/user-attachments/assets/0cc0e454-7dfa-4194-a054-a679b657c5c9" />
<img width="1264" height="993" alt="CubeNet3" src="https://github.com/user-attachments/assets/48669fe9-9702-48fd-81a9-c4d94d275f10" />

<img width="969" height="556" alt="CubeFace4" src="https://github.com/user-attachments/assets/e1d09def-4e0b-46fb-921c-c9a98219a1e9" />
<img width="1255" height="988" alt="CubeNet4" src="https://github.com/user-attachments/assets/9f429ab4-fe0b-4a89-a857-e021e9b02511" />

<img width="976" height="564" alt="CubeFace5" src="https://github.com/user-attachments/assets/c6c15aab-e03c-4834-b7af-c2ea5e82a49f" />
<img width="1258" height="988" alt="CubeNet5" src="https://github.com/user-attachments/assets/79fd391c-254b-419d-bcc7-0ad8ebcde0af" />

<img width="954" height="571" alt="CubeFace6" src="https://github.com/user-attachments/assets/fd3503a6-e355-4aa0-8ef8-bee29be50ea0" />
<img width="1262" height="989" alt="CubeNet6" src="https://github.com/user-attachments/assets/2507e0d6-c436-4603-8265-3d543c016573" />

# Project Architecture

```text
                    +----------------------------------+
                    |      GenericRubiksCube           |
                    |      (Abstract Interface)        |
                    +----------------+-----------------+
                                     │
          ┌──────────────────────────┼──────────────────────────┐
          │                          │                          │
          ▼                          ▼                          ▼
+--------------------+     +--------------------+     +--------------------+
| RubiksCube3DArray  |     | RubiksCube1DArray  |     | RubiksCubeBitboard |
+--------------------+     +--------------------+     +--------------------+
          │                          │                          │
          └───────────────┬──────────┴───────────────┬──────────┘
                          │                          │
                          ▼                          ▼
              +-----------------------+   +------------------------+
              | Search Algorithms     |   | Pattern Database       |
              +-----------------------+   +------------------------+
              | DFS                   |   | Nibble Array           |
              | BFS                   |   | Pattern Database       |
              | IDDFS                 |   | Corner Pattern DB      |
              | Korf's IDA*           |   | Corner DB Generator    |
              +-----------+-----------+   | Permutation Indexer    |
                          |               +-----------+------------+
                          │                           │
                          └──────────────┬────────────┘
                                         │
                                         ▼
                              +-----------------------+
                              | OpenCV Cube Scanner   |
                              +-----------------------+
                              | Webcam Capture        |
                              | HSV Color Detection   |
                              | Cube Reconstruction   |
                              +-----------------------+
```

---

# Execution Pipeline

```text
                        Physical Rubik's Cube
                                │
                                ▼
                        OpenCV Cube Scanner
                                │
                                ▼
                        Color Classification
                                │
                                ▼
                        Cube Reconstruction
                                │
                                ▼
                        RubiksCubeBitboard
                                │
                                ▼
                 +---------------------------------------------+
                 |            Korf's IDA* Solver               |
                 |                                             |
                 |              Expand Node                    |
                 |                  │                          |
                 |                  ▼                          |
                 |       Query Corner Pattern Database         |
                 |                  │                          |
                 |                  ▼                          |
                 |         Compute f = g + h                   |
                 |                  │                          |
                 |                  ▼                          |
                 |        Continue Search Until Goal           |
                 +---------------------------------------------+
                                │
                                ▼
                        Optimal Solution Moves
                                │
                                ▼
                            Solved Cube
```

---

# Performance

The solver was benchmarked on randomly generated scrambles.

| Scramble Length | Average Solve Time |
|-----------------|-------------------:|
| 12 Moves | **< 3 seconds** |
| 13 Moves | **≈ 12 seconds** |

(Current implementation uses a Corner Pattern Database generated to depth 7.)
---
<img width="364" height="460" alt="Screenshot 2026-07-07 035525" src="https://github.com/user-attachments/assets/8ec58a82-df0a-44f1-82d1-448553a35b72" />
<img width="388" height="507" alt="Screenshot 2026-07-07 035539" src="https://github.com/user-attachments/assets/6c0be06d-db4a-4962-bab9-7f2e6d203a24" />

# Project Structure

```
Rubiks-Cube-Solver
│
├── Model
│   ├── GenericRubiksCube
│   ├── RubiksCube3DArray
│   ├── RubiksCube1DArray
│   └── RubiksCubeBitboard
│
├── Solver
│   ├── DFSSolver
│   ├── BFSSolver
│   ├── IDDFSSolver
│   └── IDAstarSolver
│
├── PatternDatabases
│   ├── PatternDatabase
│   ├── CornerPatternDatabase
│   ├── CornerDBMaker
│   ├── NibbleArray
│   └── PermutationIndexer
│
├── Scanner
│   └── CubeScanner
│
├── Databases
│
└── main.cpp
```

---

# Key Concepts Implemented

### Algorithms

- Graph Search
- Heuristic Search
- Iterative Deepening
- Pattern Databases
- Permutation Ranking

### Data Structures

- Bitboards
- Hash Maps
- Priority Queues
- Queues
- Nibble Arrays

### C++ Concepts

- Object-Oriented Programming
- Templates
- Runtime Polymorphism
- Inheritance
- Operator Overloading
- Custom Hash Functions

### Computer Vision

- OpenCV
- HSV Color Detection
- Median Filtering
- Webcam Integration

---

# Research Reference

This project is inspired by

**Richard E. Korf**

**Finding Optimal Solutions to Rubik's Cube Using Pattern Databases**

[https://www.cs.princeton.edu/courses/archive/fall06/cos402/papers/korf.pdf](https://www.cs.princeton.edu/courses/archive/fall06/cos402/papers/korfrubik.pdf)

---

# Future Improvements

- Larger Pattern Databases
- Edge Pattern Database
- Complete Korf Heuristic
- Move Pruning
- Automatic Color Calibration
- Parallel Pattern Database Generation

---

# Author

**Shivam Bhardwaj**
