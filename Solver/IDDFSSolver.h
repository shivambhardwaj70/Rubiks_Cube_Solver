#include "../bits/stdc++.h"

#include "DFSSolver.h"
#include "../Model/GenericRubiksCube.h"
#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<typename T,typename H>
class IDDFSSolver {
private:
    int max_search_depth;
    vector<GenericRubiksCube::MOVE> moves;

public:
    T rubiksCube;
    IDDFSSolver(T _rubiksCube,int _max_search_depth=7) {
        rubiksCube = _rubiksCube;
        max_search_depth = max_search_depth;
    }

    //    Used DFSSolver with increasing max_search_depth
    vector<GenericRubiksCube::MOVE> solve() {
        for (int i=1;i<=max_search_depth;i++) {
            DFSSolver<T,H> dfssolver(rubiksCube,i);
            moves=dfssolver.solve();
            if (dfssolver.rubiksCube.isSolved()) {
                rubiksCube=dfssolver.rubiksCube;
                break;
            }
        }
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
