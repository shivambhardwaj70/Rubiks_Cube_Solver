cmake_minimum_required(VERSION 4.2)
project(Rubiks_Cube_Solver)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenCV REQUIRED)

add_executable(Rubiks_Cube_Solver
        main.cpp
        Model/GenericRubiksCube.cpp
        Model/GenericRubiksCube.h
        Model/RubiksCube3DArray.cpp
        Model/RubiksCube1DArray.cpp
        Model/RubiksCubeBitboard.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/NibbleArray.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/math.cpp
        PatternDatabases/math.h
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/CornerDBMaker.h
        bits/stdc++.h
        Scanner/CubeScanner.cpp
        Scanner/CubeScanner.h
)

target_include_directories(Rubiks_Cube_Solver PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(Rubiks_Cube_Solver PRIVATE ${OpenCV_LIBS})