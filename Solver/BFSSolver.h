#include "../bits/stdc++.h"
#include "../Model/GenericRubiksCube.h"
#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

template<typename T,typename H>
class BFSSolver {
private:
    vector<GenericRubiksCube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, GenericRubiksCube::MOVE, H> move_done;
    //    bfs() -> performs breadth-first-search and returns a solved Rubik's Cube
    //    move_done[] -> Back-Pointer map as to how we reached that state
    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;
        while (!q.empty()) {
            T node=q.front();
            q.pop();
            if (node.isSolved()) return node;
            for (int i=0;i<18;i++) {
                auto curr_move= static_cast<GenericRubiksCube::MOVE>(i);
                node.move(curr_move);
                if (!visited[node]) {
                    q.push(node);
                    visited[node] = true;
                    move_done[node] = curr_move;
                }
                node.invert(curr_move);
            }
        }
        return rubiksCube;
    }


public:
    T rubiksCube;
    BFSSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    // Performs BFS and returns the vector of moves done to solve the cube
    vector<GenericRubiksCube::MOVE> solve() {
        T solved_rubiksCube=bfs();
        assert(solved_rubiksCube.isSolved());
        T curr_rubiksCube=solved_rubiksCube;
        while (curr_rubiksCube!=rubiksCube) {
            GenericRubiksCube::MOVE curr_move = move_done[curr_rubiksCube];
            moves.push_back(curr_move);
            curr_rubiksCube.invert(curr_move);
        }
        rubiksCube=solved_rubiksCube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H
