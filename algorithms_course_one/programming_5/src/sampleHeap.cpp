# include <iostream>
# include <limits>

// Finding an item in a heap is an O(n) operation, but if you already know where it is in the heap, removing it is O(log n).

template<class a_type> class sampleMinHeap{

private:

  int endIndex_;
  int rootIndex_;
  int capacity_;
  int size_; 
  a_type * array_;
  int * nodeHeapPosition_;

  int parentIndex(int child){
    // if(child%2 == 0){
    //   return child/2;
    // 	}else{
    //   return child/2;
    // }
    return child/2;// This is floor operation anyway. 
  }

  void swap(int a, int b){
    if(a!=b){
      int nodeA = array_[a].getNode();
      int nodeB = array_[b].getNode();

      a_type temp = array_[b];
      array_[b] = array_[a];
      array_[a] = temp;
      
      int tempHeapPosition = nodeHeapPosition_[nodeB];
      nodeHeapPosition_[nodeB] = nodeHeapPosition_[nodeA];
      nodeHeapPosition_[nodeA] = tempHeapPosition;
    }
  }
  bool properHeapNode(int index, int& status){
    //    std::cout<<"size() is: "<<size()<<" and index is: "<<index<<std::endl;
    if(index<size()){
      status = 0;
      int childLeft = 2*index;
      int childRight = 2*index + 1;
	
      if(childLeft<size())
	status += 4;
      if(childRight<size())
	status += 2;
      //      std::cout<<"index: "<<index<< "left is: "<<childLeft<<"right is: "<<childRight<<". status is: "<<status<<std::endl;

      switch (status){
      case 0:  // no child 
	return true;
      case 2:  // rightchild 
	//	std::cout<<"array_[index]"<<array_[index]<<", array_[childRight]: "<<array_[childRight]<<std::endl;
	return (array_[index]<=array_[childRight]);
      case 4: // left child 
	//	std::cout<<"array_[index]"<<array_[index]<<", array_[childLeft]: "<<array_[childLeft]<<std::endl;
	return (array_[index]<=array_[childLeft]);
      case 6: // left and right 
	//	std::cout<<"array_[index]"<<array_[index]<<", array_[childLeft]: "<<array_[childLeft]<<", array_[childRight]: "<<array_[childRight]<<std::endl;
	return (array_[index]<=array_[childRight]) && (array_[index]<=array_[childLeft]);
      default: 
	std::cout<<"error! with index: "<<index<<", status is: "<<status<<std::endl;
	return false;
      }
    }else{
      return false;
    }
      
  }
  int miner(int a, int b){
    if(
       (a < size())&&(b < size())
       ){
      if(array_[a]>=array_[b])
	return b;
      else 
	return a;
    }
  }

  void deleteEnd(){
    if(!isEmpty()){
      //      array_[rootIndex_] = array_[endIndex_];

      //      std::cout<<"Deleting index: ["<<endIndex_<<"], node: "<<array_[endIndex_].getNode()<<std::endl;      

      // Should not do endindex--;

      endIndex_--;

      size_--;
    }
  }
  void deleteSimpleEnd(){
    if(!isEmpty()){
      //      array_[rootIndex_] = array_[endIndex_];

      //      std::cout<<"Deleting index: ["<<endIndex_<<"], node: "<<array_[endIndex_].getNode()<<std::endl;      

      // Should not do endindex--;

      //      endIndex_--;

      size_--;
    }
  }


  void deleteRootAndReplace(){
    if(!isEmpty()){
      swap(rootIndex_, endIndex_);
      // int nodeR = array_[rootIndex_].getNode();
      // int nodeE = array_[endIndex_].getNode();
      // nodeHeapPosition_[nodeR] = nodeHeapPosition_[nodeE];
      // array_[rootIndex_] = array_[endIndex_];

      // It is ok to leave it there
      //      array_[rootIndex_].getNode();

      if(!isOne())
	endIndex_--;	
      size_--;
    }
  }
  void goodParent(int dataIndex ){
    int parent = 0;
    parent = parentIndex(dataIndex);
    // bubble up
    while(array_[dataIndex] < array_[parent] ){
      swap(dataIndex, parent);
      dataIndex = parent;
      parent = parentIndex(dataIndex);
    }

  } // end of good parent

public:
  
  sampleMinHeap(int size){

    size_ = 0;
    capacity_ = size;
    array_ = new a_type [size];
    nodeHeapPosition_ = new int [size];
    //    a_type max = std::numeric_limits<a_type>::max();
    // for(int i = 0; i<size; i++){
    //   //      array_[i] = max;
    //   array_[i] = std::numeric_limits<a_type>::max();
    // }
    
    rootIndex_ = 0;
    endIndex_ = 0;
      
  }
  ~sampleMinHeap(){
    delete [] array_;
    delete [] nodeHeapPosition_;
  }


  int size() const {
    return size_;
  }
  int getEnd() const {
    return endIndex_;
  }
  int getRoot() const {
    return rootIndex_;
  }

  bool  isFull() const{
    return size_ == capacity_;
  }
  bool  isEmpty() const{
    return size_ == 0;
  }
  bool  isOne() const{
    return size_ == 1;
  }
  int readHeapPosition(int nodeNumber) const {
    return nodeHeapPosition_[nodeNumber];
  }
  int readKeyByNode(int nodeNumber) const {
    return array_[nodeHeapPosition_[nodeNumber]].getKey();
  }
  void insert(a_type data, int nodeNumber){
    if(isEmpty()){
      // std::cout<<"endIndex is: "<<endIndex_<<std::endl;
      // std::cout<<"size is: "<<size_<<std::endl;
      array_[endIndex_] = data;     
      nodeHeapPosition_[nodeNumber] = endIndex_;
      size_++;
      //      endIndex_++;
      return;
    }
    if(!isFull()){
      // insert 
      size_++;
      endIndex_++;
      array_[endIndex_] = data;     
      nodeHeapPosition_[nodeNumber] = endIndex_;

      int dataIndex = getEnd();
      goodParent(dataIndex);
      // int parent = 0;
      // parent = parentIndex(dataIndex);
      // // bubble up
      // while(array_[dataIndex] < array_[parent] ){
      // 	swap(dataIndex, parent);
      // 	dataIndex = parent;
      // 	parent = parentIndex(dataIndex);
      // }
      //      std::cout<<"insert: "<<data<<" at: "<<dataIndex<<std::endl;
    }else{
      std::cout<<"The heap is full. "<<std::endl;
    }
  }
  void printOut(){
    std::cout<<"The heap is: ";
    
    while(size()!=0){
      std::cout<<"\t"<<extractMin()<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"from min to max. "<<std::endl;
  }
  void printEndAndSize(){

    std::cout<<"\033[1;31m The heap size is: \033[0m"<<size()<<" \033[1;31m and the heap endIndex is at: \033[0m"<<
      getEnd()<<std::endl;
    
  }
  void printIndex(){
    std::cout<<"The heap index node is: "<<std::endl;
    
    for(int i = 0; i<size(); i++){
      std::cout<<"node: "<<i<<"->index: "<<nodeHeapPosition_[i]<<std::endl;
      std::cout<<"Compare: node: "<<array_[nodeHeapPosition_[i]].getNode()
      	       <<", key: "<< array_[nodeHeapPosition_[i]].getKey()<<std::endl;

    }
    std::cout<<std::endl;

  }

  a_type readMin(){
    return array_[rootIndex_];

  }
  // void deleteByNode(){

  // }

  void deleteByHeapPosition(int index){
    //    std::cout<<"Delete: heap index: ["<<index<<"], node: "<<array_[index].getNode()<<std::endl;
    // Jia she wo zhidao 
    if(index<size()){
      if(index!=getEnd()){

      // (1)  swap with the end: 
	swap(index, getEnd());
      // (2) delete the end
	deleteEnd();      
      // (3) put the node in a good position: 

	// if it is smaller than the parent: 
	goodParent(index);
	// check it is ok with the children:  
	int status = 0;
	while(!properHeapNode(index, status)){
	  int smallerChild = 0;
	  switch(status){
	  case 0:
	    // no child left it is ok
	    return;
	    break;
	  case 2: //right 
	    smallerChild = index*2 + 1;
	    break;
	  case 4: //left 
	    smallerChild = index*2;
	    break;
	  case 6: //left 
	    smallerChild = miner(index*2, index*2 + 1);
	    break;
	  default:
	    std::cout<<"\033[1;31m  Error: \033[0m"<<std::endl;
	  }
	  swap(index, smallerChild);
	  index = smallerChild;

	}// end of while proper node 

	
      }else{// delete the end;
	if(isOne())
	  deleteSimpleEnd();
	else
	  deleteEnd();
      }// 
    }else{
      
      std::cout<<"\033[1;31m  Error: index: \033[0m "<<index<<", heap size:"<<size()<<std::endl;
    }
  }// end of deletion function 


  a_type extractMin(){
    // std::cout<<"last  is: "<<getEnd()<<std::endl;
    // std::cout<<"root  is: "<<getRoot()<<std::endl;
    
    a_type min = array_[rootIndex_];
    //    std::cout<<"min is: "<<min<<std::endl;

    // delete root and move end to root. 
    deleteRootAndReplace();
    //    std::cout<<"delete root"<<std::endl;
    if(size()>0){
      // // bubble down.
      int currentIndex = getRoot();
      //      std::cout<<"root: "<<array_[rootIndex_]<<std::endl;

      //      std::cout<<"currentIndex: "<<currentIndex<<std::endl;
      int status = 0;
      while(!properHeapNode(currentIndex, status)){
	int smallerChild = 0;
	switch(status){
	case 0:
	  std::cout<<"\033[1;31m  Error:proper node and no child left \033[0m"<<std::endl;
	  break;
	case 2: //right 
	  smallerChild = currentIndex*2 + 1;
	  break;
	case 4: //left 
	  smallerChild = currentIndex*2;
	  break;
	case 6: //left 
	  smallerChild = miner(currentIndex*2, currentIndex*2 + 1);
	  break;
	default:
	  std::cout<<"\033[1;31m  Error: \033[0m"<<std::endl;
	}

	
	//	int smallerChild = miner(currentIndex*2, currentIndex*2 + 1);
	//	std::cout<<"smallerChild calculated: "<<smallerChild<<", currentIndex: "<<currentIndex<<std::endl;
	swap(currentIndex, smallerChild);
	currentIndex = smallerChild;
	//	std::cout<<"smallerChild calculated: "<<smallerChild<<", currentIndex: "<<currentIndex<<std::endl;

      }// end of while
    }  

    //    std::cout<<std::endl;
    // std::cout<<std::endl;

    //    std::cout<<"finish one extract min"<<std::endl;

    return min;
  } // end of extractMin

};
class newNode{
private:
  int key_;
  int node_;
public:
  newNode(int key, int node ){
    key_ = key;
    node_ = node;
  }
  newNode( ){
    key_ = -1;
    node_ = -1;
  }
  ~newNode(){
  }
  int getNode() const { 
    return node_;
  }
  int getKey() const {
    return key_;
  }
  newNode& operator =(const newNode& b) {
    if(this == &b)
      return *this;
    key_ = b.getKey();
    node_ = b.getNode();
    return *this;
  }

  bool operator <=(const newNode& b) const{
    return key_ <= b.getKey();
  }
  bool operator < (const newNode& b) const{
    return key_ < b.getKey();
  }
  bool operator >=(const newNode& b) const{
    return key_ >= b.getKey();
  }
  bool operator > (const newNode& b) const{
    return key_ > b.getKey();
  }
    
}; // end of new node 

// std::ostream& operator <<(std::ostream& os, const newNode & obj) 
// {
//   // write obj to stream
//   os<<" key: "<<obj.getKey()<<", node: "<<obj.getNode();
//   return os;
// }

// int main(){

//   sampleMinHeap <newNode>  b(20);
//   int bPosition = 0;

//   b.insert(newNode(0,0),0);
//   // b.printIndex();
//   bPosition = b.readHeapPosition(0);
//   std::cout<<"node: "<<0<<", index: "<<bPosition<<std::endl;
//   b.deleteByHeapPosition(bPosition);
//   b.insert(newNode(0,0),0);

//   b.insert(newNode(2,1),1);
//   // b.printIndex();
//   bPosition = b.readHeapPosition(1);
//   std::cout<<"node: "<<1<<", index: "<<bPosition<<std::endl;
//   b.deleteByHeapPosition(bPosition);
//   b.insert(newNode(2,1),1);


//   b.insert(newNode(4,2),2);
//   // b.printIndex();
//   bPosition = b.readHeapPosition(2);
//   std::cout<<"node: "<<2<<", index: "<<bPosition<<std::endl;
//   b.deleteByHeapPosition(bPosition);



//   b.insert(newNode(1,3),3);
//   // b.printIndex();
//   // bPosition = b.readHeapPosition(3);
//   // std::cout<<"node: "<<3<<", index: "<<bPosition<<std::endl;
//   // b.deleteByHeapPosition(bPosition);

//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(21,4), 4);
//   //  b.printOut();
//   //  b.printIndex();
//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(12,5), 5);
//   //  b.printOut();
//   //  b.printIndex();
//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(122,6), 6);
//   //  b.printOut();
//   //  b.printIndex();
//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(133,7), 7);
//   //  b.printOut();
//   //  b.printIndex();
//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(12,8), 8);
//   //  b.printOut();
//   //  b.printIndex();
//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(13,9), 9);
//   //  b.printOut();
//   //  b.printIndex();
//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(0,10),10);
//   //  b.printOut();
//   //  b.printIndex();
//   // std::cout<<"\t \t Insertion:"<<std::endl;

//   b.insert(newNode(90,11),11);
//   //  b.printOut();
//   //  b.printIndex();

//   // std::cout<<"\t \t Insertion:"<<std::endl;
//   b.insert(newNode(90000,12),12);
//   //  b.printOut();
//   //  b.printIndex();


//   bPosition = b.readHeapPosition(11);
//   std::cout<<"node: "<<11<<", index: "<<bPosition<<std::endl;
//   b.deleteByHeapPosition(bPosition);

//   bPosition = b.readHeapPosition(12);
//   std::cout<<"node: "<<11<<", index: "<<bPosition<<std::endl;
//   b.deleteByHeapPosition(bPosition);
//   bPosition = b.readHeapPosition(12);
  
//   bPosition = b.readHeapPosition(10);
//   std::cout<<"node: "<<10<<", index: "<<bPosition<<std::endl;
//   b.deleteByHeapPosition(bPosition);
  
//   b.printOut();
//   //  b.printIndex();
//   return 0;
// }
