cmake_minimum_required(VERSION 3.9)
project (projeto_basico)


find_package(Boost COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(hello hello_world.cpp)
endif()

target_link_libraries(hello
	Boost::filesystem
	Boost::system
)

find_package(OpenMP)
if(OPENMP_FOUND)
	add_executable(teste teste_omp.cpp)
	target_link_libraries(teste OpenMP::OpenMP_CXX)
endif()
