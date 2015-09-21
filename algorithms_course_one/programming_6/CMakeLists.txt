cmake_minimum_required(VERSION 2.4.6 FATAL_ERROR)

if( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
 # add_definitions("-g -fPIC  -Wall -std=gnu++0x  ")
 add_definitions("-std=gnu++0x -o4 ")
endif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)


#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_executable( two_sum_hash src/two_sum_hash.cpp
 )
add_executable( two_sum_hash_map src/two_sum_hash_map.cpp
 )
# target_link_libraries(${program} threadPool)  
add_executable( test_multi_map src/test_multi_map.cpp
 )
#

add_executable( median_maintannance src/median_maintannance.cpp
                                src/sampleHeap.cpp
)
# add_executable( sampleHeap     src/sampleHeap.cpp
# )


#
