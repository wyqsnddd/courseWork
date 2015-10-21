# include <limits.h>
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
  int numberOfNodes(0);
  int numberOfEdges(0);
  
  std::ifstream graphReader;
  std::string line;
  // graphReader.open(inputFile.c_str(), std::ios::in);
  graphReader.open(inputFile.c_str(), std::ifstream::binary);
  
  std::getline(graphReader, line);
  std::istringstream iss(line);
  
  iss>>numberOfNodes;
  std::cout<<"The number of nodes is: "<<numberOfNodes<<std::endl;
  iss>>numberOfEdges;
  std::cout<<"The number of edges is: "<<numberOfEdges<<std::endl;
 
  // ------------------------------------------------------ 

  std::map<int, int> *  hashTableIntPointer = new std::map<int, int>;
  int lineCounter = 0;  
    
  while(std::getline(graphReader, line)){
    // read in the integer 
    std::istringstream iss(line);
    int intSample(0);
    iss>>intSample; 
    std::map<int, int>::iterator testIterator = hashTableIntPointer->find(intSample);

    if(testIterator==hashTableIntPointer->end()){
      hashTableIntPointer->insert(std::pair<int, int>(intSample, lineCounter));
      lineCounter++;
    }

    iss>>intSample; 
    testIterator = hashTableIntPointer->find(intSample);

    if(testIterator==hashTableIntPointer->end()){
      hashTableIntPointer->insert(std::pair<int, int>(intSample, lineCounter));
      // std::cout<<"key: "<<intSample<<" node: "<< lineCounter<<std::endl;
      lineCounter++;
    }
  }// end of while 
  
  if(numberOfNodes!=hashTableIntPointer->size()){
    std::cout<<"The number of nodes does not equal to what we counted."<<std::endl;
    std::cout<<"The hash table size is: "<<hashTableIntPointer->size()<<std::endl;
    std::cout<<"The number of node is: "<<numberOfNodes<<std::endl;
    std::cout<<std::endl;

    exit(0);
  }

  // Initialization 
  sampleGraph G(numberOfNodes);
  G.setHashTable(hashTableIntPointer);  

  // reset the reader 
  // The last call to std::getline upon reaching end-of-stream fails, setting failbit. Since failbit is set, the call to seekg has no effect. You need to clear the stream's status flags before calling seekg
  graphReader.clear();
  graphReader.seekg (0, graphReader.beg);

  std::getline(graphReader, line);
  if(G.hashSet()){
    while(std::getline(graphReader, line)){
      std::cout<<"----------------"<<std::endl;
  
      std::istringstream iss(line);
      int head(0);
      int tail(0);
      iss>>tail;
      iss>>head;
      std::cout<<"We are reading, tail: "<<tail<<", head: "<<head<<std::endl;
      int tailHash = G.readOriginalNode(tail);
      int headHash = G.readOriginalNode(head);
	  
      std::cout<<"We are setting, tail: "<<tailHash<<", head: "<<headHash<<std::endl;
      G.addEdge(tailHash, headHash);	
      // G.addEdge(tail -1 , head -1);	

    }
  }else{
    std::cout<<"hash table is not set."<<std::endl;
    exit(0);
  }
  graphReader.close();

  if(G.getNumberOfEdges()!=numberOfEdges){
    std::cout<<"Number of edges mismatch!"<<std::endl;
    std::cout<<"Graph has: "<<G.getNumberOfEdges()<<" edges."<<std::endl;
    std::cout<<"We    got: "<<numberOfEdges<<" edges."<<std::endl;
    exit(0);
  }

  // Find the tree 

  G.printGraph();

  
  return 0;

}
