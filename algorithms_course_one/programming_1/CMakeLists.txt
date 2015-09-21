cmake_minimum_required(VERSION 2.4.6 FATAL_ERROR)
project(sensor_fusion_project)

if( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
  # add_definitions("-g -fPIC  -Wall  -O4 -std=gnu++0x  ")
  add_definitions("-std=gnu++0x  ")
endif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)


#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# FIND_PACKAGE(Eigen)
# include_directories(/usr/include/eigen3/)

set (programs   
  countInversion
  )

foreach (program ${programs})
  add_executable(${program} src/${program}.cpp)
  # target_link_libraries(${program} threadPool)  
endforeach(program)


