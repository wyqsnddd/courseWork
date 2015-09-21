cmake_minimum_required(VERSION 2.4.6 FATAL_ERROR)

if( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
 # add_definitions("-g -fPIC  -Wall -std=gnu++0x  ")
 add_definitions("-std=gnu++0x -o4 ")
endif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)


#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


# add_executable( sampleHeap src/sampleHeap.cpp
#  )

# add_executable( sampleGraph src/sampleGraph.cpp
#  )


 add_executable( dijkstraDebug 
                         src/sampleHeap.cpp
                         src/sampleGraph.cpp
			 src/dijkstraDebug.cpp
 )


 add_executable( dijkstra 
                         src/sampleHeap.cpp
                         src/sampleGraph.cpp
			 src/dijkstra.cpp
 )

