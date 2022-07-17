cmake_minimum_required(VERSION 3.23.2)

set(ProjectName Linear-Algebra-Library)

set(ProjectSources
        LinearAlgebra.hpp
        LinearAlgebra/Matrix.hpp
        LinearAlgebra/SolutionSLE.hpp
        LinearAlgebra/SolutionSLE/gaussian_elimination.hpp
        LinearAlgebra/SolutionSLE/inverse_matrix_method.hpp
        LinearAlgebra/SolutionSLE/lu_decomposition.hpp
)

target_sources(${ProjectName} INTERFACE ${ProjectSources})

add_custom_target(LinAlgLib SOURCES ${ProjectSources})