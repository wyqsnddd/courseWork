# include <iostream>

# include "sampleGraph.cpp"
# include "sampleHeap.cpp"

void DFS_one(sampleGraph &G, int node, int *f, bool *m, int *counter);
void DFS_two(sampleGraph &G, int i, bool *m, int* groupID, int parent, long &groupSize);

int main(int argc, char ** argv )
{

  std::string inputFile("../benchmarkData/test_3.txt"); 
  int numberOfSCC;
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
    	argumentSS>>numberOfSCC;

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

  }else{
  
    std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt > \n\t-N <Number of SCC to be printed out >."<<std::endl; 
    std::cin.get();
    exit(0);
  } // end of argument parsing 

  // sampleGraph workingCopy(numberOfNodes);
  // sampleGraph workingCopyReverse(numberOfNodes);
  // workingCopy.readEdgeFile(inputFile, false);
  // workingCopyReverse.readEdgeFile(inputFile, true);

  sampleGraph workingCopy(inputFile, false);

  //  sampleGraph workingCopyReverse(inputFile, true);
  // workingCopy.printGraph();


  sampleGraph workingCopyReverse(workingCopy.getNumberOfNodes());
  workingCopyReverse.setHashTable(workingCopy.readHashTable());
  workingCopyReverse.readEdges(inputFile, true);

  std::cout<<"----------------"<<std::endl;
  // workingCopyReverse.printGraph();
  std::cout<<"----------------"<<std::endl;

  int  finishingTime [workingCopy.getNumberOfNodes()]; // variable size, cannot use  = { 0 } initializer
  //  int  test [numberOfNodes]; // variable size, cannot use  = { 0 } initializer
  int  finishingTimeCounter = 0; 
  bool markedID [workingCopy.getNumberOfNodes()];
  int  groupID [workingCopy.getNumberOfNodes()] ;

  // since variable size vector so we have to initialize manually 
  for(int i = 0; i < workingCopy.getNumberOfNodes(); i++){
    markedID[i] = false;
    groupID[i] = -1;
    finishingTime[i] = -1;
    //    test[i] = 0;
  }
  
  // 1st DFS loop 
  for(int i = workingCopyReverse.getNumberOfNodes() - 1; i>=0; i--){
    if(!markedID[i]){
      //      std::cout<<"markedID["<<i<<"]: "<<markedID[i]<<std::endl;
      DFS_one(workingCopyReverse, i, finishingTime, markedID, &finishingTimeCounter);
      //    std::cout<<"outer DFS checking: "<<i<<std::endl;
    }
  }
  std::cout<<"finished 1st DFS: ";

  // std::cout<<"sorted by finishing time: \n";
  // for(int i = 0; i < workingCopy.getNumberOfNodes(); i++)
  //   std::cout<<" "<< finishingTime[i]<<" ";
  // std::cout<<"\n";

  // std::cout<<"\n";
  for(int i = 0; i < workingCopy.getNumberOfNodes(); i++){
    markedID[i] = false;
  }
  
  //  2nd DFS loop
  sampleMinHeap <long> bigFive(numberOfSCC); 
  long max = 100; 
  for(int i = workingCopy.getNumberOfNodes() - 1; i>=0; i--){
    int j = finishingTime[i];
    //    std::cout<<"checking: "<<j<<" --------------------------------"<<std::endl;
    long size = 0;

    if(!markedID[j]){
      DFS_two(workingCopy, j, markedID, groupID, j, size);
    }


    int heapSize = bigFive.size();
    if(heapSize<numberOfSCC)
      bigFive.insert(size);
    else{
      max = bigFive.readMin();
      if(size>max){
      bigFive.extractMin();
      bigFive.insert(size);
      }
    }


    //    std::cout<<"groupsize bag : "<<std::endl;
    //    bigFive.printBag();
    //    std::cout<<"bigFive size  : "<<bigFive.getSize()<<std::endl;
    // bigFive.add(size);
    //    std::cout<<"add group size : "<<size<<std::endl;
    // std::cout<<"bag size : "<<bigFive.getSize()<<std::endl;

    // if(size>=101){
    //   std::cout<<"temp: "<<size<<std::endl;
    //   //      max = size;
    // }
      
    //    if(size!=0){
      // if(bigFive.getSize()<3){
      // 	// add directly 
      // 	bigFive.add(size);
      // 	std::cout<<"add group size : "<<size<<std::endl;
      // 	std::cout<<"bag size : "<<bigFive.getSize()<<std::endl;
	
      //   bigFive.printBag();
      // }else  if(size > bigFive.getData()){
	// bigFive.printBag();
	// bigFive.add(size);
	// std::cout<<"new group size : "<<size<<std::endl;
	// std::cout<<"bag size : "<<bigFive.getSize()<<std::endl;
	// bigFive.printBag();


	//		bigFive.deleteFirst();
	//      std::cout<<"new size : "<<size<<std::endl;

	//   }
    //    }
      
  }  
  std::cout<<"finished 2nd DFS."<<std::endl;;

  // std::cout<<"Group ID: \n";
  // for(int i = 0; i < workingCopy.getNumberOfNodes(); i++)
  //   std::cout<<" "<< groupID[i]<<" ";
  // std::cout<<std::endl;
  
  //  std::cout<<"\n";  std::cout<<"ID size: "<<bigFive.getSize()<<std::endl;
  //  std::cout<<"\n"; std::cout<<"Biggest IDs: "<<std::endl;


  bigFive.printOut();


   //  std::cout<<"\n";
  
  // std::cout<<"ID: "<<bigFive.getData()<<std::endl;
  // for(int i = 0 ; i<4; i++){
  //   bigFive.moveCurrent();
  //   std::cout<<"ID: "<<bigFive.getData()<<std::endl;

  // }
  exit(0);

}
void DFS_one(sampleGraph &G, int i, int *f, bool *m, int * counter){
  // very important to use &G, otherwise make a local copy each time in the recursion. 
 
  // 1. mark node i: 
  //  std::cout<<"node: " <<i<<" marked: "<<m[i]<<"-------"<<std::endl;

  m[i] = true;
  //  std::cout<<"node: "<<i<<" has "<<G.getNodeEdge(i)->getSize() <<" edges."<<std::endl;
  // 2. loop each of its edges: 
  // 
  for(G.getNodeEdge(i)->iterator = G.getNodeEdge(i)->getFirst();
      G.getNodeEdge(i)->iterator !=NULL;
      G.getNodeEdge(i)->iterator = G.getNodeEdge(i)->iterator->next){

  // for(int j = 0; j<G.getNodeEdge(i)->getSize() ; j++){
    int head = G.getNodeEdge(i)->iterator->data;
    //    G.getNodeEdge(i)->moveIterator();
    //    std::cout<<"node: "<<i<<", edge: "<<head<<std::endl;
    if(!m[head])
      DFS_one(G, head, f, m, counter);
  }  
  //  G.getNodeEdge(i)->resetIterator();
   // 3. finishing time increment and set. 
  f[*counter] = i; // dot not log the finishing time, only log the order

  //  std::cout<<"node: " <<i<<" counter: "<<*counter<<"******"<<std::endl;
  // f[i] = *counter; 
  // test[*counter] = i;
  //  f[i] = *counter; 
  (*counter)++;
};


void DFS_two(sampleGraph &G, int i, bool *m, int* groupID, int parent, long &groupSize){
  // very important to use &G, otherwise make a local copy each time in the recursion. 
 
  // 1. mark node i: 
  //  std::cout<<"node: " <<i<<" marked: "<<m[i]<<"-------"<<std::endl;
      
  m[i] = true;
  groupID[i] = parent;
  groupSize++;
  // 2. loop each of its edges: 
  for(G.getNodeEdge(i)->iterator = G.getNodeEdge(i)->getFirst();
      G.getNodeEdge(i)->iterator !=NULL;
      G.getNodeEdge(i)->iterator = G.getNodeEdge(i)->iterator->next){

  // for(int j = 0; j< G.getNodeEdge(i)->getSize(); j++){
    //    int head = G.getNodeEdge(i)->getData();
    int head = G.getNodeEdge(i)->iterator->data;

    //    G.getNodeEdge(i)->moveIterator();

    //    std::cout<<"node: "<<i<<", edge: "<<head<<std::endl;
    if(!m[head])
      DFS_two(G, head, m, groupID, parent, groupSize);
  }  
  //  G.getNodeEdge(i)->resetIterator();

};
