# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <stdlib.h>
# include <algorithm>

# include <map>

# include "sampleBag.cpp"

class sampleGraph{
private: 
  int nN_;
  int nE_;
  // sampleBag <int> ** adj;
  //  sampleBag <int>  **adj;
  sampleBag <long>  **adj;
  std::map<int, int> *hashTableInt;
  bool hashSet_;

  void readNodes(std::string inputFile ){
    std::ifstream integerReader;
    std::string line;
    integerReader.open(inputFile.c_str(), std::ios::in);
    int lineCounter = 0;  
    //  int diff = 1;
    while(std::getline(integerReader, line)){
      // read in the integer 
      std::istringstream iss(line);
      int intSample(0);
      iss>>intSample; 
      // if(reverseOrder){
      // 	iss>>intSample; 
      // }
      // add it to the hash table 
      // mapSample[key] = data;
      // mapSample[intSample] = lineCounter;
      std::map<int, int>::iterator testIterator = hashTableInt->find(intSample);

      if(testIterator==hashTableInt->end()){
	hashTableInt->insert(std::pair<int, int>(intSample, lineCounter));
	// std::cout<<"key: "<<intSample<<" node: "<< lineCounter<<std::endl;
	lineCounter++;
      }

      iss>>intSample; 
      testIterator = hashTableInt->find(intSample);

      if(testIterator==hashTableInt->end()){
	hashTableInt->insert(std::pair<int, int>(intSample, lineCounter));
	// std::cout<<"key: "<<intSample<<" node: "<< lineCounter<<std::endl;
	lineCounter++;
      }
      //    if((lineCounter - mapSample.size()) == diff){
      //      std::cout<<"At line: "<<lineCounter<<" , key: "<<intSample<<" is not inserted. "<<"Map size is: "<< mapSample.size()<<std::endl;
      //      diff++;
      // }

    }// end of while 
    std::cout<<"The hash table size is: "<<hashTableInt->size()<<std::endl;
    std::cout<<"line counter is: "<<lineCounter<<std::endl;
    std::cout<<std::endl;

    //  std::cout<<"If the above two are not equal, then it means there are : "<<lineCounter<<std::endl;
  } // end of reader 


public: 

  void readEdges(std::string inputFile, bool reverseOrder ){

    std::ifstream integerReader;
    std::string line;
    integerReader.open(inputFile.c_str(), std::ios::in);

    while(std::getline(integerReader, line)){
      std::istringstream iss(line);
      int head(0);
      int tail(0);

      iss>>tail;

      iss>>head;
      
      if(reverseOrder){
	int temp = tail;
	tail = head;
	head = temp;

      }

      // std::cout<< "reading tail:"<<tail<<", head:"<<head<<"."<<std::endl;
      
      // std::map<int, int>::iterator tailHashIterator = hashTableInt->find(tail);
      // int tailHash = tailHashIterator->second;

      int tailHash = readOriginalNode(tail);
      // std::cout<< "found  tail:"<<tailHash<<std::endl;

      // std::map<int, int>::iterator headHashIterator = hashTableInt->find(head);
      // int headHash= headHashIterator->second;

      int headHash=  readOriginalNode(head);
      // std::cout<< "found  head:"<<headHash<<std::endl;      
      addEdge(tailHash, headHash);	
    }

  }
  //  void readNodes(std::string inputFile, bool reverseOrder ){

  void setHashTable(std::map<int, int> * pointer){
    hashTableInt = pointer;
    hashSet_ = true;
  }
  bool hashSet() const{
    return hashSet_;
  }

  std::map<int, int>* readHashTable(){
    std::map<int, int> * pointer = hashTableInt;
    return pointer;
  }
  sampleGraph(long N){
    hashSet_ = false;
    nN_ = N;
    nE_ = 0;
    
    adj = new sampleBag<long>* [N];
    //    adj = new sampleBag<long>* [N];
    //    adj = new sampleBag<long>* [N];

    for(int i = 0; i< N ; i++){
      //      adj[i] = new sampleBag<int>();
      adj[i] = new sampleBag<long>();
    }
    std::cout<<"initialized with "<<N<<" Nodes. "<<std::endl;
  }

  // sampleGraph( sampleGraph &inputG ){

  //   *this = sampleGraph(inputG.getNumberOfNodes());
    
  //   for(int i = 0; i<nN_; i++){
  //     inputG.adj[i]->initializeCurrent();
  //     //      std::cout<<"adj[i]->getSize() is: "<<inputG.adj[i]->getSize()<<std::endl;
  //     for(int j = 0; j< inputG.adj[i]->getSize(); j++){
  // 	addEdge(i, inputG.adj[i]->getData());
  // 	inputG.adj[i]->moveIterator();
  //     }
  //   }
  //   std::cout<<"initialized"<<std::endl;
    
  // }


  sampleGraph(std::string &inputFile, bool reverseOrder){
    hashTableInt = new std::map<int, int>;
    //    readNodes(inputFile, reverseOrder);
    readNodes(inputFile);

    long numberOfNodes = hashTableInt->size(); 

    nN_ = numberOfNodes;
    nE_ = 0;
    
    adj = new sampleBag<long>* [numberOfNodes];
    //    adj = new sampleBag<long>* [N];

    for(int i = 0; i< numberOfNodes ; i++){
      //      adj[i] = new sampleBag<int>();
      adj[i] = new sampleBag<long>();
    }
    hashSet_ = true;
	
    std::cout<<" initialized with "<<getNumberOfNodes()<<" Nodes. "<<std::endl;
    
    readEdges(inputFile, reverseOrder);

    //    std::cout<<"initialized with "<<getNumberOfNodes()<<" Nodes. "<<std::endl;
    std::cout<<"initialized with "<<getNumberOfEdges()<<" Edges. "<<std::endl;
  }


  ~sampleGraph(){
  }  
  int readOriginalNode(int key ) {
    std::map<int, int>::iterator keyIterator = hashTableInt->find(key);
    return keyIterator->second;
  }

  void readEdgeFile(std::string inputFile, bool reverseOrder ){
    std::ifstream integerReader;
    std::string line;
    integerReader.open(inputFile.c_str(), std::ios::in);
    if(!reverseOrder){
      while(std::getline(integerReader, line)){
	std::cout<<"----------------"<<std::endl;
  
	std::istringstream iss(line);
	int head(0);
	int tail(0);
	iss>>tail;
	iss>>head;
	if(hashSet()){
	  int tailHash = readOriginalNode(tail);
	  int headHash= readOriginalNode(head);
	  
	  // std::map<int, int>::iterator tailHashIterator = hashTableInt->find(tail);
	  // std::map<int, int>::iterator headHashIterator = hashTableInt->find(head);
	  // int tailHash = tailHashIterator->second;
	  // int headHash= headHashIterator->second;
	  //	  std::cout<<"We are reading, tail: "<<tailHash<<", head: "<<headHash<<std::endl;
	  addEdge(tailHash, headHash);	
	}
	else{
	  addEdge(tail - 1, head - 1);	
	}
      }
    }else{
      while(std::getline(integerReader, line)){
	std::istringstream iss(line);
	int head(0);
	int tail(0);
	iss>>tail;
	iss>>head;
	// if yes add edge in the reverse order.
	if(hashSet()){
	  int tailHash = readOriginalNode(tail);
	  int headHash= readOriginalNode(head);

	  // std::map<int, int>::iterator tailHashIterator = hashTableInt->find(tail);
	  // std::map<int, int>::iterator headHashIterator = hashTableInt->find(head);
	  // int tailHash = tailHashIterator->second;
	  // int headHash= headHashIterator->second;
	  //	  std::cout<<"We are reading, tail: "<<tailHash<<", head: "<<headHash<<std::endl;
	  addEdge(tailHash, headHash);	
	}
	else{
	  addEdge(head - 1, tail - 1);	
	}
      }
    }
  }
  // sampleGraph(std::string inputFile ){

  //   std::ifstream integerReader;
  //   integerReader.open(inputFile, std::ios::in);

  //   if(
  //      !integerReader.is_open()
  //      )
  //     {
  // 	std::cout<<"Text files are not open."<<std::endl;
  // 	exit(0);
  //     }else{
  //     int pre_reading = integerReader.tellg();
  //     std::cout<<"The reader position is: "<<pre_reading<<std::endl;


  //     int linesN =  std::count(std::istreambuf_iterator<char>(integerReader), 
  // 			       std::istreambuf_iterator<char>(), '\n');

  //     //    int pos_reading = integerReader.tellg();
  //     integerReader.seekg(0);
  //     int post_reading = integerReader.tellg();
  //     std::cout<<"The reader position is: "<<post_reading<<std::endl;
  //     std::cout<<"There are "<<linesN<<" lines."<<std::endl;
  //     // 
  //     *this = sampleGraph(linesN);
      
  //     std::string line;
    
  //     while(std::getline(integerReader, line)){
  // 	std::istringstream iss(line);
  // 	int single_int(0);
  // 	int nodeNumber(0);
  // 	iss>>nodeNumber;
  // 	std::cout<<std::endl<<"the node is: "<<nodeNumber<<std::endl;
  // 	while(iss>>single_int){
  // 	  std::cout<<" "<<single_int<<" ";
  // 	  // Note that I start from 0
  // 	  addEdge( (nodeNumber - 1), (single_int - 1));
  // 	  //	  single_int = 0;
  // 	}
  //     }
  //     integerReader.close();
  //   }

  //   // std::cout<<"initialized"<<std::endl;

  // }  
  void addEdge(int u, int v){

    if(
       (adj[u] == NULL)
       ||
       (adj[v] == NULL)
       ){
      std::cout<< "required node doest not exist."<<std::endl;
      std::cout<< "tail is: "<<u<<" head is: "<<v<<std::endl;
      
      throw "required node doest not exist.";

    }
    //    std::cout<< "tail is: "<<readOriginalNode(u)<<" head is: "<<readOriginalNode(v)<<std::endl;
    adj[u]->add(v);
    //    adj[v]->add(u);
    nE_++;
  }
  
  
  int getNumberOfNodes(){
    return nN_;
  }

  int getNumberOfEdges(){
    return nE_;
    // int number = 0;
    // int i = 0;
    // while(
    // 	  (adj[i]!=NULL)
    // 	  &&
    // 	  (i<nN_)
    // 	  ){
    //   number += adj[i]->getSize();
    //   i++;
    // }
    // return number;
  }
  void printGraph(){

    std::cout<<"Graph:"<<std::endl;
    for(int i = 0; i < nN_; i++){
      std::cout<<"Node "<<i<<": ";
      adj[i]->printBag();
    }
    std::cout<<std::endl;
  }
  
  
  //  sampleBag <int>  * getNodeEdge(int n){
  sampleBag <long>  * getNodeEdge(int n){
    return adj[n];
  }  


};


