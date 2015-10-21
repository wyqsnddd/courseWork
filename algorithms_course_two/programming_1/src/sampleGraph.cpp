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
   sampleBag <int>  **adj;
  // sampleBag <a_type>  **adj;
  std::map<int, int> *hashTableInt;
  bool hashSet_;

public: 

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
    
    // adj = new sampleBag<a_type>* [N];
    adj = new sampleBag<int>* [N];
    //    adj = new sampleBag<long>* [N];
    //    adj = new sampleBag<long>* [N];

    for(int i = 0; i< N ; i++){
      adj[i] = new sampleBag<int>(false);
      //      adj[i] = new sampleBag<long>();
      // adj[i] = new sampleBag<a_type>();
    }
    std::cout<<"initialized with "<<N<<" Nodes. "<<std::endl;
  }
  ~sampleGraph(){
  }  
  int readOriginalNode(int key ) {
    std::map<int, int>::iterator keyIterator = hashTableInt->find(key);
    return keyIterator->second;
  }

  void addEdge(int u, int v, int cost){

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
    adj[u]->add(v, cost);
    //    adj[v]->add(u);
    nE_++;
  }
  
  
  int getNumberOfNodes(){
    return nN_;
  }

  int getNumberOfEdges(){
    return nE_;
  }
  void printGraph(){

    std::cout<<"Graph:"<<std::endl;
    for(int i = 0; i < nN_; i++){
      std::cout<<"Node "<<i<<": ";
      adj[i]->printBag();
    }
    std::cout<<std::endl;
  }
  
  
   sampleBag <int>  * getNodeEdge(int n){
    return adj[n];
  }  


};


