# Maze Solver

Compile:
```bash
g++ -O2 maze_solver.cpp -o maze_solver
```

Run (default: `test_mazes/tiny_2coins.txt`):
```bash
./maze_solver
```

Run other test mazes:
```bash
./maze_solver test_mazes/tiny_2coins.txt
./maze_solver test_mazes/medium_5coins.txt
./maze_solver test_mazes/weighted_4coins.txt
./maze_solver test_mazes/stress_8coins.txt
```

Expected output (tiny test):
```text
=== UNIFORM COST (BFS + DFS) ===
Coins: 2
Best order: S -> c(3,0) -> c(0,7) -> G
Total steps: 17
Path:
S******c
*......*
*...#..*
c......*
.......G

=== WEIGHTED (Dijkstra + A*) ===
Coins: 2
Best order: S -> c(3,0) -> c(0,7) -> G
Total cost: 17
A* cells expanded across all pair queries: 103
Dijkstra cells expanded across all pair queries: 162

SUMMARY | BFS pairs computed: 6 | DFS orderings tried: 4 | Dijkstra:162 | A*:103
```
