# include <vector>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <stdlib.h>
# include <stdio.h>


class hashGraph{

private:

  int n_;
  int ni_;
  int m_;
  std::map<int, int> nodeHash_;
  std::vector<std::map<int, int> >  nodeEdgeHash_;

  int getNodeIndex() const{
    return ni_;
  }
  void incrementNodeIndex(){
    ni_++;
  }
  void decrementNode(){
    n_--;
  }
  void incrementEdge(){
    m_++;
  }
  void decrementEdge(){
    std::cout<<"decrement edge"<<std::endl;
    m_--;
  }
  
  void mergeNodeEdges(int tail, int head){

    std::map<int,int>::iterator tailNodeLook = nodeHash_.find(tail);
    std::map<int,int>::iterator headNodeLook = nodeHash_.find(head);


    std::cout<<"tail: "<<tailNodeLook->first<<" head "<<headNodeLook->first<<std::endl;    
    std::cout<<"tail has: ";
    for(std::map<int, int>::iterator ii = nodeEdgeHash_[tailNodeLook->second].begin();
    	ii!=nodeEdgeHash_[tailNodeLook->second].end();
    	ii++
    	){
      std::cout<<" "<<ii->first;
    }    

    std::cout<<std::endl;

    std::cout<<"head has: ";
    for(std::map<int, int>::iterator ii = nodeEdgeHash_[headNodeLook->second].begin();
    	ii!=nodeEdgeHash_[headNodeLook->second].end();
    	ii++
    	){
      std::cout<<" "<<ii->first;
    }    
    std::cout<<std::endl;


    std::cout<<"Merge edges: ";
    // loop over the edges of the head node 
    for(std::map<int, int>::iterator ii = nodeEdgeHash_[headNodeLook->second].begin();
	ii!=nodeEdgeHash_[headNodeLook->second].end();
	ii++
	){
      // insert the edge into the tail node 
      std::pair<std::map<int, int>::iterator, bool> insertCheck  
	= nodeEdgeHash_[tailNodeLook->second].insert(
						     std::pair<int,int>(
									ii->first,
									nodeEdgeHash_[tailNodeLook->second].size()
									)
						     );
      std::cout<<" "<<ii->first;

      if(!insertCheck.second){//Already exists!
	std::cout<<" "<<insertCheck.first->first;
	decrementEdge();	
      }
      // 	std::pair<std::map<int, int>::iterator, bool> insertCheckOther  
      // 	  = nodeEdgeHash_ [ii->first].insert(
      // 		   std::pair<int,int>(
      // 				      tailNodeLook->first,				
      // 				      nodeEdgeHash_[ii->first].size() + 1
      // 				      )
      // 		   );

      // if(insertCheckOther.second){
      // 	// inserted edge
      // 	incrementEdge();
      // }
      // 	insertCheckOther.second


      // if(!insertCheck.second){//Already exists!
      // 	//	std::cout<<" "<<insertCheck.first->first;
      // 	//	decrementEdge();	
      // }

      // remove edges from other nodes to head
      // if(
      // 	 nodeEdgeHash_[nodeHash_[ii->first]].erase(tail)
      // 	 ){
      // 	// found self loop
      // 	// std::cout<<"Other node: "<<ii->first;
      // 	// std::cout<<" "<<tail<<std::endl;;
      // 	decrementEdge();	
      // }
      int eraseTest = nodeEdgeHash_[nodeHash_[ii->first]].erase(head);
      if(
	 eraseTest
	 ){
	std::pair<std::map<int, int>::iterator, bool> insertCheck  
	  = nodeEdgeHash_[nodeHash_[ii->first]].insert(
						       std::pair<int,int>(
									  tail,
									  nodeEdgeHash_[
											nodeHash_[ii->first]
											].size())
						       );
	if(!insertCheck.second){
	  // faile to insert 
	  decrementEdge();
	}
	// found self loop
	std::cout<<"replace at node: "<<ii->first<<" head "<<head;
	std::cout<<" with "<<tail<<std::endl;;
	// decrementEdge();	
      }else{
	std::cout<<"unable to erase tail: "<<ii->first<<" head: "<<head<<std::endl;
	std::cout<<"The node ["<<ii->first<<"] has: ";

	for(std::map<int, int>::iterator jj = nodeEdgeHash_[
							    nodeHash_[ii->first]
							    ].begin();
	    jj!=nodeEdgeHash_[
			      nodeHash_[ii->first]
			      ].end();
	    jj++
	    ){
	  	  std::cout<<" "<<jj->first;
	


	} 
	std::cout<<std::endl;
	
      }// end of erase other node 

      //    std::cout<<std::endl;
    }// end of head edges
  

    // let me do the remove self loop automatically
    removeSelfLoop(tail, head);
    removeSelfLoop(tail, tail);


  }
  bool removeSelfLoop(int tail, int head){
    std::map<int,int>::iterator tailNodeLook = nodeHash_.find(tail);
    
    int check = nodeEdgeHash_[tailNodeLook->second].erase(head);
    if(check){
      // found self loop
      std::cout<<"Selfloop: ";
      std::cout<<" "<<head<<std::endl;;
      decrementEdge();	
    }
    return true;

  }

  void insertNode(int node){
    std::map<int,int>::iterator nodeLook = nodeHash_.find(node);
      
    if(nodeLook==nodeHash_.end()){
      // not yet in: 
      std::pair<std::map<int, int>::iterator, bool> insertCheck  
	= nodeHash_.insert(
			   std::pair<int,int>(
					      node,
					      getNodeIndex()
					      )

			   );
      //      nodeHash_[node] = getNodeIndex();
      
      incrementNodeIndex();

      if(!insertCheck.second){
	std::cout<<"fail to insert: "<<node<<std::endl;
      }
    }
    // open the edge account 
  }

  void insertEdge(int tail, int head ){
    // std::stringstream edgeSample;
    // edgeSample<<tail<<","<<head;

    
    std::map<int,int>::iterator nodeLook = nodeHash_.find(tail);
    std::map<int,int>::iterator edgeLook = nodeEdgeHash_[nodeLook->second].find(head);
    //    std::cout<<" "<<head;
    if(edgeLook==nodeEdgeHash_[nodeLook->second].end()){
      // not yet in: 
      nodeEdgeHash_[nodeLook->second][head] = getNumberOfEdges();
      incrementEdge();
    }
  }
  
  void readFile(std::string inputFile){
    std::ifstream integerReader;
    std::string line;
    integerReader.open(inputFile, std::ios::in);
    
    while(std::getline(integerReader, line)){
      
      //      std::string line;
      std::istringstream iss(line);
      // iss.seekg(0, iss.end);
      // int length = iss.tellg();
      // iss.seekg (0, iss.beg);
      // std::cout<<"(length: "<< length<<")";

      int tail(0);
      iss>>tail;
      
      // First insert the tail
      insertNode(tail);
      std::cout<<"["<<tail<<"]: ";
      int head;
      //      while(iss.tellg()>0){
      while(iss>>head){

	// if(iss.tellg()<0)
	//   break;
	std::cout<<"("<<head<<")";
	// std::cout<<"(tellg: "<< iss.tellg()<<")";

	// insert the new node
	insertNode(head);
	// insert the edge
	insertEdge(tail, head);

      }// end of line parsing
      std::cout<<std::endl;
      
    }// end of file parsing
  } // end of reader
  
public:
  hashGraph(int n, std::string inputFile){
    n_ = n;
    ni_ = 0;
    m_ = 0;
    
    nodeEdgeHash_.resize(getNumberOfNodes());
    
    readFile(inputFile);
  }
  ~hashGraph(){

  }
  int getNumberOfNodes() const{
    return n_;
  }
  int getNumberOfEdges() const{
    return m_;
  }
  void getEdgeNodes(const int edge, int & tail, int & head) {
    // edge 1 - total number of edges
    //    std::cout<<"edge number: "<<edge<<std::endl;
    int test = 0;

    std::map<int,int>::iterator ii = nodeHash_.begin();
    while(test<edge){
      //      std::cout<<"node "<<ii->first<<" has "<<nodeEdgeHash_[ii->second].size()<<" edges."<<std::endl;
      test += nodeEdgeHash_[ii->second].size();
      ii++;
    }
    //    std::cout<<"test is: "<<test<<std::endl;


    ii--;      
    // get the edge number of node: ii->first
    test = edge - (test - nodeEdgeHash_[ii->second].size());
    // base + difference
    //    std::cout<<"test is: "<<test<<std::endl;

    std::map<int,int>::iterator jj = nodeEdgeHash_[ii->second].begin();
    
    // to start from zero
    test--;
    
    for(int k = 0; k<test;k++)
      jj++;
    
    head = jj->first; 
    tail = ii->first;
    // std::cout<<"test is: "<<test<<std::endl;
    
    // std::cout<<"The nodes to be removed are: "<<tail<<" "<<head<<std::endl;
  }

  bool mergeNodes(int tail, int head){

    std::cout<<"Merge: ["<<tail<<"] and ["<<head<<"]"<<std::endl;

    std::map<int,int>::iterator tailLook = nodeHash_.find(tail);
    std::map<int,int>::iterator headLook = nodeHash_.find(head);

    // Check if both of them are there ?
    bool tailStatus = (tailLook!=nodeHash_.end());
    bool headStatus = (headLook!=nodeHash_.end());

    if(
       tailStatus&&headStatus
       ){
      // It is crucial to merge the edges first
      mergeNodeEdges(tail, head);
      
      // always remove head;
      if(nodeHash_.erase(head) == 0){
	std::cout<<"Can not remove node: ["<<head<<"]"<<std::endl;
	return false;
      }
      decrementNode();

      // let me merge the nodes too

      return true;
    }else{
      std::cout<<"Tail or head is not in the node list: ";
      std::cout<<"Merge: ["<<tail<<"] and ["<<head<<"]"<<std::endl;

      std::cout<<"tail "<< tailStatus<<", ";
      std::cout<<"head "<< headStatus
	       <<std::endl;
      return false;
    }

  }
  
  void printGraph(){
    std::cout<<"This hash graph is: "<<std::endl;

    for(std::map<int, int>::iterator ii = nodeHash_.begin();
	ii!=nodeHash_.end();
	ii++){
      // loop over the nodes: 
      std::cout<<"Node :";
      std::cout<<"["<<ii->first<<"]: ";

      for(std::map<int, int>::iterator jj = nodeEdgeHash_[ii->second].begin();
	  jj!=nodeEdgeHash_[ii->second].end();
	  jj++
	  ){
	std::cout<<" ["<<jj->first<<"]";
      }// end of edge loop
      std::cout<<std::endl;

    }// end of node loop
    std::cout<<std::endl;
    




  } // end of print function 
};

