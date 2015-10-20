# include <iostream>
# include <fstream>
# include <sstream>
# include <limits.h>

# include <map>
# include "sampleHeap.h"
# include "sampleGraph.cpp"


int main(int argc, char ** argv )
{

  // ------------------------------------------------------ Read the text file 
  std::string inputFile("../data/edges.txt"); 

  if(argc == 3){    
    std::stringstream argumentSS(argv[1]);
    std::string param;
    std::string paramContainer;

    for (int i = 1; i< argc; i++){
      argumentSS.clear();
      argumentSS.str(argv[i]);
      argumentSS>>param;
      paramContainer = paramContainer + " " + param;
    }
    argumentSS.clear();
    argumentSS.str(paramContainer);

    while(argumentSS>>param){
      if(param == "-data"){
	//  positionMotionRaw
	argumentSS>>inputFile;
      }else if(param == "-help"){
	std::cout << "Usage is: \n \t -data <path to the file to be sorted sample.txt > \n "; 
	std::cin.get();
	exit(0);
      }else{
	std::cout << std::endl
		  <<argv[0]
		  << " Error in parameter parsing, please type any key to continue... "
		  <<std::endl; 
	
	std::cin.get();
	exit(0);
      }
    } // end of while;

  }else{ // end of if
  
    std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt>  -\t -N <number of nodes in the graph  >"<<std::endl; 
    std::cin.get();
    exit(0);
  } // end of argument parsing 

  // ------------------------------------------------------ Read the graph 
  // int numberOfNodes(0);
  // int numberOfEdges(0);
  
  // std::ifstream grashReader;
  // std::string line;
  // grashReader.open(inputFile.c_str(), std::ios::in);
  
  // std::getline(graphReader, line);
  // std::istringstream iss(line);
  
  // iss>>numberOfNodes;
  // std::cout<<"The number of nodes are: "<<numberOfNodes<<std::endl;
  // iss>>numberOfEdges;
  // std::cout<<"The number of edges are: "<<numberOfEdges<<std::endl;
 
  // ------------------------------------------------------ 

  // Initialization 
  bool byNode = false;
  sampleGraph G( numberOfNodes, byNode);


  
  // Find the tree 
  


}
