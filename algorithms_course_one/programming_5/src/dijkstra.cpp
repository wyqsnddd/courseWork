# include <iostream>
# include <fstream>
# include <sstream>
# include "sampleGraph.cpp"
# include "sampleHeap.cpp"
# include <limits.h>
std::ostream& operator <<(std::ostream& os, const newNode & obj) 
{
  // write obj to stream
  os<<" key: "<<obj.getKey()<<", node: "<<obj.getNode();
  return os;
}

int main(int argc, char ** argv )
{

  std::string inputFile("../benchmarkData/dijkstraData.txt"); 
  // std::string inputFile(""); 
  int numberOfNodes(0);
  int sourceNode(0);
  if(argc == 7){    
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
      if(param == "-S"){
    	//  positionMotionRaw
    	argumentSS>>sourceNode;
	sourceNode--;
      }else if(param == "-N"){
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

    }else{ // end of if
  
      std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt>  -\t -N <number of nodes in the graph  >"<<std::endl; 
      std::cin.get();
      exit(0);
    } // end of argument parsing 



    bool byNode = false;
    sampleGraph G( numberOfNodes, byNode);
    G.readEdgeFile(inputFile);
    //    G.printGraph();

    // // where to start

    // // This is an n-by-1 array, which contains the processed node  
    bool  * nodeProcessed; 
    nodeProcessed = new bool [numberOfNodes];
    // // This is an n-by-1 array, which contains the shortest path
    int  * shortestDistances;
    shortestDistances = new int [numberOfNodes];

    // // initialize: heap and the associated arrays
    sampleMinHeap <newNode>  minKeyHeap(numberOfNodes);
    // Use this to save the keys 
    for(int i = 0; i<numberOfNodes; i++){
      nodeProcessed[i] = false;
      shortestDistances[i] = -1;
    }

    // for(int i = 0; i<numberOfNodes; i++){
    //   std::cout<<"node  ("<<i<<") distance: "<<shortestDistances[i]<<std::endl;
    // }
    // for(int i = 0; i<numberOfNodes; i++){
    //   std::cout<<"node  ("<<i<<") processed?: "<<nodeProcessed[i]<<std::endl;
    // }

    

    // initialize the heap
    for(int i = 0; i < numberOfNodes; i++){
      minKeyHeap.insert(newNode(std::numeric_limits<int>::max(), i), i); 
    }

    //initialize with big values for all the heap nodes
    nodeProcessed[sourceNode] = true;
    shortestDistances[sourceNode] = 0;
    
    int sourcePosition =  minKeyHeap.readHeapPosition(sourceNode);
    minKeyHeap.deleteByHeapPosition(sourcePosition);

    // scan the edges of minNode:   
    //    for(G.adj[sourceNode].iterator = G.adj[sourceNode].getFirst(); G.adj[sourceNode].iterator!=NULL; G.adj[sourceNode].iterator = G.adj[sourceNode]->next){
    for(G.getNodeEdge(sourceNode)->iterator = G.getNodeEdge(sourceNode)->getFirst(); 
	G.getNodeEdge(sourceNode)->iterator!=NULL; 
	G.getNodeEdge(sourceNode)->iterator = G.getNodeEdge(sourceNode)->iterator->next){
      
      int headNode = G.getNodeEdge(sourceNode)->iterator->node;
	//	adj[sourceNode].iterator->head;
      //      std::cout<<"Ini: "<<std::endl;
      if(!nodeProcessed[headNode]){  // if this head is not already processed yet
	//	std::cout<<"found edge to:  "<<headNode;
	//	int oldKey = minKeyHeap.readKeyByNode(headNode);
	int heapPosition =  minKeyHeap.readHeapPosition(headNode);
	minKeyHeap.deleteByHeapPosition(heapPosition);
		   
	// No need to delete at initialization 
	// compute key: 
	//	int testKey = G.adj[sourceNode].iterator->length;
	int testKey = G.getNodeEdge(sourceNode)->iterator->length;

		   
	//	std::cout<<", length: "<<testKey<<std::endl;

	// insert this node into the heap again: 
	minKeyHeap.insert(newNode(testKey, headNode), headNode); 
	//	std::cout<<"Insert node ["<<headNode<<"] with new key: "<<testKey<<std::endl;

      }
    }// end of initialization edge scan 


    while(minKeyHeap.size()>0){ // extract all the nodes
      //      std::cout<<"\033[1;31m New cycle,  the heap size is: \033[0m "<<minKeyHeap.size()<<"\033[1;31m New cycle,  the endIndex is: \033[0m "<<minKeyHeap.getEnd()<<std::endl;

      // (1) Select  the minimum: double: key: node: number
	
      newNode newMinNode = minKeyHeap.extractMin();
      //      std::cout<<"Take out: "<<std::endl;
      // std::cout<<" "<<newMinNode;
      //      minKeyHeap.printEndAndSize();

      int minKey = newMinNode.getKey();
      int minNode = newMinNode.getNode();
      // nodeProcessed[minNode] = true;
      // shortestDistances[minNode] = minKey;

      //      std::cout<<", length: "<<minKey<<std::endl;
       // (2) update the dijkstra records
      nodeProcessed[minNode] = true;
      shortestDistances[minNode] = minKey;
    // for(int i = 0; i<numberOfNodes; i++){
    //   std::cout<<"node  ("<<i<<") distance: "<<shortestDistances[i]<<std::endl;
    // }
    // for(int i = 0; i<numberOfNodes; i++){
    //   std::cout<<"node  ("<<i<<") processed?: "<<nodeProcessed[i]<<std::endl;
    // }
       
      // (2) scan its edge 
       // scan the edges of minNode in the graph    
       //       for(G.adj[minNode].iterator = G.adj[minNode].getFirst(); G.adj[minNode].iterator!=NULL; G.adj[minNode].iterator = G.adj[minNode]->next){
       for(G.getNodeEdge(minNode)->iterator = G.getNodeEdge(minNode)->getFirst(); 
	   G.getNodeEdge(minNode)->iterator!=NULL; 
	   G.getNodeEdge(minNode)->iterator = G.getNodeEdge(minNode)->iterator->next){
	 // a check if this node is processed?   
	 int newheadNode = G.getNodeEdge(minNode)->iterator->node;
	 //	   G.adj[minNode].iterator->head;

	 // std::cout<<"Checking other node: ["<<newheadNode<<"] "<<std::endl;
	   
	 if(!nodeProcessed[newheadNode]){ 
	   // (1) delete this node from the heap 
	   // std::cout<<"Update: "<<std::endl;
	   // std::cout<<" "<<newheadNode;
	   int oldKey = minKeyHeap.readKeyByNode(newheadNode);
	   //	   minKeyHeap.printEndAndSize();

	   // (2) compute the new  key: 
	   int newKey(0);
	   //	   int testKey = shortestDistances[minKey] + adj[minNode].iterator->length;
	   int testKey = shortestDistances[minNode] + 
	     G.getNodeEdge(minNode)->iterator->length;

	   if(oldKey<=testKey ){
	     newKey = oldKey;

	   }else{
	     newKey = testKey;
	     int heapPosition =  minKeyHeap.readHeapPosition(newheadNode);
	     //	     std::cout<<" look into heap position"<<heapPosition<<std::endl;
	     minKeyHeap.deleteByHeapPosition(heapPosition);
	     //	     std::cout<<"Delete node ["<<newheadNode<<"]"<<std::endl;
	     // (3) insert the new key into the heap 
	     minKeyHeap.insert( newNode(newKey, newheadNode), newheadNode); 
	     //	     std::cout<<"Insert node ["<<newheadNode<<"] with new key: "<<newKey<<std::endl;
	   }
	       // insert this node into the heap again: 
	       
      
	   // (4) update the new records
	   // nodeHeapPosition[newheadNode] = nodePosition;
	   // nodeHeapKey[newheadNode] = testKey;
	 } // end of if
       }// end of edge scan 
    }// after extract all nodes 

    
    // std::cout<<std::endl<<
    //   "From the source node [ "<<sourceNode<<" ], we have:"<<std::endl;

    // for(int i = 0; i<numberOfNodes; i++){
    //   if(nodeProcessed[i])
    // 	std::cout<<"node ("<<i<<"): "<<shortestDistances[i]<<std::endl;
    // }

    
    std::string testString  = "7,37,59,82,99,115,133,165,188,197";
    std::istringstream inputS(testString);
    std::string interstingNode;
    std::cout<<std::endl<<
      "The answer is: "<<std::endl;
    
    // while(std::getline(inputS,interstingNode,',')){
    //   int j = std::atoi(interstingNode.c_str());
    //   j--;

    //   std::cout<<","<<shortestDistances[j];
    // }

    std::cout<<std::endl<<
      "The answer is: "<<std::endl;
    while(std::getline(inputS,interstingNode,',')){
      int j = std::atoi(interstingNode.c_str());
      j--;
      std::cout<<"node ("<<j<<"): "<<shortestDistances[j]<<std::endl;    
    }
    
    // free memory
    delete [] nodeProcessed;
    delete [] shortestDistances;
    std::cout<<std::endl<<
      " Finished cleanning. "<<std::endl;

    return 1;
  } // end of main

