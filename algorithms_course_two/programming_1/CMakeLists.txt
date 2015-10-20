cmake_minimum_required(VERSION 2.4.6 FATAL_ERROR)
project(sensor_fusion_project)

#if( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
  #add_definitions("-g -fPIC  -Wall  -O4 -std=gnu++0x  ")
  #add_definitions("-std=gnu++0x  ")
#endif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)


#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
message("The source dir: " ${PROJECT_SOURCE_DIR})

add_library(sampleHeap SHARED src/completionTime.cpp)
#add_library(sampleHeap src/sampleHeap.cpp)

add_executable(completionTime  
 src/completionTime.cpp)
target_link_libraries(completionTime sampleHeap ) 


add_executable( testJobNode
 src/testJobNode.cpp)

#add_executable(completionTime  
#               src/temp.cpp src/completionTime.cpp)
 
