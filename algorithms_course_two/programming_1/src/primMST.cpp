# include <limits.h>
// # include "sampleHeap.h"
# include "graphHeap.h"
# include "vertexNode.h"
# include "sampleGraph.cpp"


int main(int argc, char ** argv )
{

  // ------------------------------------------------------ Read the text file 
  std::string inputFile("../data/edges.txt"); 
  int sourceNode(0);
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
      if(param == "-s"){
    	//  positionMotionRaw
    	argumentSS>>sourceNode;

      }else if(param == "-data"){
	//  positionMotionRaw
	argumentSS>>inputFile;
      }else if(param == "-help"){
	std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt>  \t -s <number of source node>"<<std::endl; 
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
  
    std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt>  \t -s <number of source node>"<<std::endl; 
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
  // later it will be freed by the graph
  // std::map<int, int> *  hashTableIntPointer = new std::map<int, int>;
  // int lineCounter = 0;  
    
  // while(std::getline(graphReader, line)){
  //   // read in the integer 
  //   std::istringstream iss(line);
  //   int intSample(0);
  //   iss>>intSample; 
  //   std::map<int, int>::iterator testIterator = hashTableIntPointer->find(intSample);

  //   if(testIterator==hashTableIntPointer->end()){
  //     hashTableIntPointer->insert(std::pair<int, int>(intSample, lineCounter));
  //     lineCounter++;
  //   }

  //   iss>>intSample; 
  //   testIterator = hashTableIntPointer->find(intSample);

  //   if(testIterator==hashTableIntPointer->end()){
  //     hashTableIntPointer->insert(std::pair<int, int>(intSample, lineCounter));
  //     // std::cout<<"key: "<<intSample<<" node: "<< lineCounter<<std::endl;
  //     lineCounter++;
  //   }
  // }// end of while 
  
  // if(numberOfNodes!=hashTableIntPointer->size()){
  //   std::cout<<"The number of nodes does not equal to what we counted."<<std::endl;
  //   std::cout<<"The hash table size is: "<<hashTableIntPointer->size()<<std::endl;
  //   std::cout<<"The number of node is: "<<numberOfNodes<<std::endl;
  //   std::cout<<std::endl;

  //   exit(0);
  // }

  // Initialization 
  sampleGraph G(numberOfNodes);
  // G.setHashTable(hashTableIntPointer);  

  // reset the reader 
  // The last call to std::getline upon reaching end-of-stream fails, setting failbit. Since failbit is set, the call to seekg has no effect. You need to clear the stream's status flags before calling seekg
  // graphReader.clear();
  // graphReader.seekg (0, graphReader.beg);

  // std::getline(graphReader, line);
  // if(G.hashSet()){
    while(std::getline(graphReader, line)){
      std::cout<<"----------------"<<std::endl;
  
      std::istringstream iss(line);
      int head(0);
      int tail(0);
      int cost(0);
      iss>>tail;
      iss>>head;
      iss>>cost;
      // std::cout<<"We are reading, tail: "<<tail<<", head: "<<head<<std::endl;
      // int tailHash = G.readOriginalNode(tail);
      // int headHash = G.readOriginalNode(head);
	  
      // std::cout<<"We are setting, tail: "<<tailHash<<", head: "<<headHash<<std::endl;
      // G.addEdge(tailHash, headHash, cost);	
      G.addEdge(tail -1 , head -1, cost);	
      G.addEdge(head -1 , tail -1, cost);	

    }
  // }else{
  //   std::cout<<"hash table is not set."<<std::endl;
  //   exit(0);
  // }
  graphReader.close();

  if(G.getNumberOfEdges()!=2*numberOfEdges){
    std::cout<<"Number of edges mismatch!"<<std::endl;
    std::cout<<"Graph has: "<<G.getNumberOfEdges()<<" edges."<<std::endl;
    std::cout<<"We    got: "<<numberOfEdges<<" edges."<<std::endl;
    exit(0);
  }

  G.printGraph();
  //---------------------------------------------------
  // Initialize the invariants
  int mstCost(0);
  
  // vertex nodes in the tree 
  std::map<int, int>  mstVertices;
  // key, node
  mstVertices.insert(std::pair<int, int>(sourceNode, sourceNode));  
  
  // vertex nodes in the heap
  // sampleMinHeap <vertexNode>  freeVertexHeap(numberOfNodes-1);
  graphMinHeap <vertexNode>  freeVertexHeap(numberOfNodes-1);
  // std::map<int, int>  freeVertexHeapMap;
  // initialize the heap 
  if((sourceNode<0)
     ||sourceNode>(numberOfNodes-1)
     ){
    std::cout<<"source node is in a bad range"<<std::endl;
    exit(0);
  }
  
  sampleBag <int>  * sourceNodeEdgePointer = G.getNodeEdge(sourceNode);
  if(sourceNodeEdgePointer==NULL){
    std::cout<<" is null"<<std::endl;
  }
  for(sourceNodeEdgePointer->iterator = sourceNodeEdgePointer->getFirst();
      sourceNodeEdgePointer->iterator!=NULL; 
      sourceNodeEdgePointer->iterator = sourceNodeEdgePointer->iterator->next){
     // Insert the other node into the heap 
     // The key will be the edge cost
    // std::cout<<"node "<<sourceNodeEdgePointer->iterator->node<<", length: "<<sourceNodeEdgePointer->iterator->length<<std::endl;
    vertexNode newVertex(sourceNodeEdgePointer->iterator->node,   // node number
			 sourceNodeEdgePointer->iterator->length);// cost 

     int newHeapDataIndex = freeVertexHeap.insert(newVertex);
     // std::cout<<"Insert (heap) node "<<newVertex.readNodeNumber()<<" with cost: "<<newVertex.readKey()<<" at "<<newHeapDataIndex<<" of the heap."<<std::endl;


     // Key, value
     // freeVertexHeapMap.insert(
     // 			      std::pair<int, int>(
     // 			      sourceNodeEdgePointer->iterator->node,
     // 			      newHeapDataIndex)
     // 			      );
     
     // std::cout<<"The node: "<<sourceNodeEdgePointer->iterator->node
     // 	      <<", sits at: "<<newHeapDataIndex<<" of the heap."<<std::endl;
   }

   // freeVertexHeap.printOut();
   
  // construct the heap using "vertex nodes in the tree" 

  //  ---------------------------------------------------
  //  the main loop 
  while(mstVertices.size()!=numberOfNodes){
  // while(mstVertices.size()!=5){
    std::cout<<"-------------------------New while iteration--- "<<std::endl;
    // freeVertexHeap.testPrintHeap();
    // freeVertexHeap.testPrintHeapMap();
    if(freeVertexHeap.size()!=freeVertexHeap.nodeHeapMap_.size()){
      std::cout<<"lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll"<<std::endl;
    }
     // //(0) extract the cheapest edge  
     vertexNode newVertex = freeVertexHeap.extractMin();
     // std::cout<<"extracted vertex: "<<newVertex.readNodeNumber()<<", with key: "<<newVertex.readKey()<<std::endl;
     // //(1) add the edge to the tree 
     mstCost += newVertex.readKey();
      
     // //(2) add the node to tree (key, node)
     // // 2.1 add the node 
     int nodeNumber = newVertex.readNodeNumber();
     mstVertices.insert(std::pair<int, int>(nodeNumber,
					    nodeNumber
					    )
			);  
    
     // // loop through the edges of node: "nodeNumber"
     sampleBag <int>  * nodeEdgePointer = G.getNodeEdge(nodeNumber);
     // std::cout<<"Go through edges of node: "<<nodeNumber<<std::endl;
    
     for(nodeEdgePointer->iterator = nodeEdgePointer->getFirst();
	 nodeEdgePointer->iterator!=NULL; 
	 nodeEdgePointer->iterator = nodeEdgePointer->iterator->next){
      
       //     // If the otherside is on the mst tree already? 
       int otherVertexNumber = nodeEdgePointer->iterator->node;
       // std::cout<<"New edge with the other node: "<<otherVertexNumber<<std::endl;

       std::map<int,int>::iterator it;
       it = mstVertices.find(otherVertexNumber);      
       if(it==mstVertices.end()){
	 // std::cout<<"the other side of the edge is NOT on the tree."<<std::endl;
	 // If the other side of the edge is NOT on the tree 
	 // 	// (1) compute the key for the other node
	 int newKey = nodeEdgePointer->iterator->length;

	 // std::map<int,int>::iterator itHeap;
	 // itHeap = freeVertexHeapMap.find(otherVertexNumber);      
	 
	 // if(itHeap!=freeVertexHeapMap.end()){
	 if(freeVertexHeap.inHeap(otherVertexNumber)){
	   // std::cout<<"node: "<<otherVertexNumber<<" is already on the heap. ";
	   int oldIndex = freeVertexHeap.nodeHeapIndex(otherVertexNumber);
	   // std::cout<<"node: "<<otherVertexNumber<<" is already on "<<itHeap->second<<" of the heap. ";

	   // If the other node is in the heap, delete the other node from the heap 
	   int oldValue(0);

	   
	   vertexNode heapInformation = freeVertexHeap.readElement(oldIndex);
	   oldValue = heapInformation.readKey();// heap index 
	   // std::cout<<"The old index is: "<<oldIndex<<" the old key is:"<<oldValue<<" the new key is: "<<newKey<<std::endl;
	   
	   freeVertexHeap.deleteElement(oldIndex);
	   // freeVertexHeapMap.erase(itHeap);
	   
	   newKey = oldValue>newKey?newKey:oldValue;	   
	   // std::cout<<"The new key is: "<<newKey<<std::endl;
	 }else{
	   // std::cout<<"node: "<<otherVertexNumber<<" is NOT on the heap. "<<std::endl;
	 }

	 // (3)Insert the other node on the heap
	 vertexNode updatedNode(otherVertexNumber, newKey); 
	 // std::cout<<"new node: "<< otherVertexNumber<<"constructed with key: "<<newKey<<std::endl;
	 int dataIndex = freeVertexHeap.insert(updatedNode);
	 // std::cout<<"Insert (heap) node: "<<otherVertexNumber<<" with cost: "<<newKey<<" at "<<dataIndex<<" of the heap."<<std::endl;
	   
	 // freeVertexHeapMap.insert(
	 // 			  std::pair<int, int>(
	 // 					      otherVertexNumber,
	 // 					      dataIndex)
	 // 			  );


       }else{
	 // std::cout<<"This node is already on the MST."<<std::endl;
       }// end of if 
      
     }// end of looping edges (the for loop)
     // std::cout<<"mstVertices.size() is "<<mstVertices.size()<<std::endl;
   }// end of while loop

     std::cout<<"The total cost is: "<<mstCost<<std::endl;
  return 0;

}
