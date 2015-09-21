# include <iostream>
# include <stdlib.h>
# include <time.h>
# include <math.h>
// # include "hashGraph.cpp"
// # include "multiMapHashGraph.cpp"
# include "quietMultiMapHashGraph.cpp"
# include "sampleHeap.cpp"


int main(int argc, char ** argv )
{

  std::string inputFile("../benchmarkData/kargerMincut.txt"); 
  int numberOfNodes;
  if(argc == 5){    
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
      if(param == "-N"){
    	//  positionMotionRaw
    	argumentSS>>numberOfNodes;

      }else if(param == "-data"){
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

  }
  else{
    std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt > \n"; 
    std::cin.get();
    exit(0);

  } // end of argument parsing 

  // hashGraph G(numberOfNodes, inputFile );


  
  //  for(int i = 2; i<numberOfNodes;i++){
  sampleMinHeap<int> minCut(numberOfNodes*numberOfNodes);
  multiMapHashGraph *G = NULL;
  
  //  for(int i = 0; i<numberOfNodes*numberOfNodes*log(numberOfNodes); i++ ){
  for(int i = 0; i<numberOfNodes*log(numberOfNodes); i++ ){
    // std::cout<<"--------------------------------- ******************************************************"<<std::endl;    
    std::cout<<"New round: "<<i<<std::endl;    

    // for(int i = 0; i<1; i++ ){
    if(G!=NULL)
      free(G);
    G = new multiMapHashGraph(numberOfNodes, inputFile );
    // std::cout<<"The number of nodes is: "<<G->getNumberOfNodes()<<std::endl;
    // std::cout<<"The number of edges is: "<<G->getNumberOfEdges()<<std::endl;
    // G->printGraph(); 

    //    srand (time(i));
    srand (i);
    //  rand() generates the same sequence of numbers, unless you call srand
    int randNumber = std::rand()%G->getNumberOfEdges() + 1; 
    int N = G->getNumberOfNodes();

    while(G->getNumberOfNodes()>2){
      // std::cout<<"--------------------------------- "<<std::endl;    
      // std::cout<<"The randnumber is: "<<randNumber<<std::endl;    
      
	  
      // G->printGraph(); 
      int tail(0), head(0);
      G->getEdgeNodes(randNumber, tail, head);
    
      G->mergeNodes(tail, head);

      if((N - G->getNumberOfNodes())!=1){
	std::cout<<"ERORR: Did not delete node"<<std::endl; 
      }
      // we want the same sequence of rand numbers 
      randNumber = std::rand()%G->getNumberOfEdges() + 1; 
      N = G->getNumberOfNodes();

      // std::cout<<"The number of nodes is: "<<G->getNumberOfNodes()<<std::endl;
      // std::cout<<"The number of edges is: "<<G->getNumberOfEdges()<<std::endl;
    }// end of one round


    minCut.insert(G->getNumberOfEdges()/2);
    // std::cout<< std::endl;
    // G->printGraph();
    // std::cout<<"--------------------------------- "<<std::endl;    


  }

  //  G->printGraph();
  std::cout<<"The min cut has edges: "<<minCut.extractMin()<<std::endl;
  

  minCut.printOut();

  // for(int i = 2; i<=numberOfNodes;i++){

  //   G.mergeNodes(1,i);
  //   std::cout<<"The number of nodes is: "<<G.getNumberOfNodes()<<std::endl;
  //   std::cout<<"The number of edges is: "<<G.getNumberOfEdges()<<std::endl;
  // }

  return 0;
}
