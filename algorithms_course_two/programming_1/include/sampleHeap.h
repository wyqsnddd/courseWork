# ifndef SAMPLEHEAP_H
# define SAMPLEHEAP_H

# include <iostream>
# include <limits>
template<class a_type> class sampleMinHeap{

 private:
  int endIndex_;
  int rootIndex_;
  int capacity_;
  int size_; 
  
  a_type * array_;

  int parentIndex( int child){
    // if(child%2 == 0){
    //   return child/2;
    // 	}else{
    //   return child/2;
    // }
    return child/2;// This is floor operation anyway. 
  }
  int swap(int a, int b){
    a_type temp = array_[b];
    array_[b] = array_[a];
    array_[a] = temp;
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
  bool  isOne() const{
    return size_ == 1;
  }

  void deleteRootAndReplace(){
    if(!isEmpty()){
      array_[rootIndex_] = array_[endIndex_];

      if(!isOne())
	endIndex_--;

      size_--;
    }
  }

  void heapify(a_type inputArray [], int index){
    int currentIndex = index;
    int status = 0;
    while(!properHeapNode(currentIndex, status)){
      int smallerChild = 0;
      switch(status){
      case 0:
	std::cout<<"ERROR: proper node and no child left "<<std::endl;
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
	std::cout<<"ERROR: "<<std::endl;
      }// end of switch

      swap(currentIndex, smallerChild);
      currentIndex = smallerChild;
    } // end of while 

  }
 public:
  sampleMinHeap(int size, a_type inputArray []){
    size_ = size;
    capacity_ = size;
    array_ = new a_type [size];
    for(int i = 0; i<size; i++){
      array_[i] = inputArray[i];
    }
    rootIndex_ = 0;
    endIndex_ = size_ - 1;

    // build heap
    for(int i = size/2; i>-1 ; i--){
      heapify(array_, i);
    }


  }

  sampleMinHeap(int size){

    size_ = 0;
    capacity_ = size;
    array_ = new a_type [size];
    //    a_type max = std::numeric_limits<a_type>::max();
    for(int i = 0; i<size; i++){
      //      array_[i] = max;
      array_[i] = std::numeric_limits<a_type>::max();
    }
    
    rootIndex_ = 0;
    endIndex_ = 0;
      
  } // end of constructor

  
  ~sampleMinHeap(){
    delete [] array_;
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

  bool  isFull(){
    return size_ == capacity_;
  }
  bool  isEmpty(){
    return size_ == 0;
  }
  
  void insert(a_type data){
    if(isEmpty()){
      array_[endIndex_] = data;     
      size_++;
      return;
    }
    if(!isFull()){
      // insert 
      endIndex_++;
      array_[endIndex_] = data;     

      size_++;

      int parent = 0;
      int dataIndex = getEnd();
      
      parent = parentIndex(dataIndex);
      // bubble up
      while(array_[dataIndex] < array_[parent] ){
	swap(dataIndex, parent);
	dataIndex = parent;
	parent = parentIndex(dataIndex);
      }
      //      std::cout<<"insert: "<<data<<" at: "<<dataIndex<<std::endl;
    }
    
  }
  void printOut(){
    std::cout<<"The heap is: ";
    
    while(size()!=0){
      std::cout<<extractMin()<<" ";
    }

    std::cout<<"from min to max. "<<std::endl;
  }
  a_type readMin(){
    return array_[rootIndex_];

  }
  a_type extractMin(){
    // std::cout<<"last  is: "<<getEnd()<<std::endl;
    // std::cout<<"root  is: "<<getRoot()<<std::endl;
    
    a_type min = array_[rootIndex_];
    // std::cout<<"min is: "<<min<<std::endl;

    // delete root and move end to root. 
    deleteRootAndReplace();
    //       std::cout<<"delete root"<<std::endl;
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
	  std::cout<<"ERROR: proper node and no child left "<<std::endl;
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
	  std::cout<<"ERROR: "<<std::endl;
	}

	
	//	int smallerChild = miner(currentIndex*2, currentIndex*2 + 1);
	//	std::cout<<"smallerChild calculated: "<<smallerChild<<", currentIndex: "<<currentIndex<<std::endl;
	swap(currentIndex, smallerChild);
	currentIndex = smallerChild;
	//	std::cout<<"smallerChild calculated: "<<smallerChild<<", currentIndex: "<<currentIndex<<std::endl;

      }// end of while
    }  
    // std::cout<<std::endl;
    // std::cout<<std::endl;

    //    std::cout<<"finish one extract min"<<std::endl;

    return min;
  } // end of extractMin

};

template<class a_type> class sampleMaxHeap{
 private:
  int endIndex_;
  int rootIndex_;
  int capacity_;
  int size_; 
  a_type * array_;

  int parentIndex( int child){
    return child/2;// This is floor operation anyway. 
  }

  int swap(int a, int b){
    a_type temp = array_[b];
    array_[b] = array_[a];
    array_[a] = temp;
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
	return (array_[index]>=array_[childRight]);
      case 4: // left child 
	//	std::cout<<"array_[index]"<<array_[index]<<", array_[childLeft]: "<<array_[childLeft]<<std::endl;
	return (array_[index]>=array_[childLeft]);
      case 6: // left and right 
	//	std::cout<<"array_[index]"<<array_[index]<<", array_[childLeft]: "<<array_[childLeft]<<", array_[childRight]: "<<array_[childRight]<<std::endl;
	return (array_[index]>=array_[childRight]) && (array_[index]>=array_[childLeft]);
      default: 
	std::cout<<"error! with index: "<<index<<", status is: "<<status<<std::endl;
	return false;
      }
    }else{
      return false;
    }
      
  }
  int maxer(int a, int b){
    if(
       (a < size())&&(b < size())
       ){
      if(array_[a]>=array_[b])
	return a;
      else 
	return b;
    }
  }
  bool  isOne() const{
    return size_ == 1;
  }

  void deleteRootAndReplace(){
    if(!isEmpty()){
      array_[rootIndex_] = array_[endIndex_];

      if(!isOne())
	endIndex_--;
      size_--;
    }
  }
  void heapify(a_type inputArray [], int index){
    int currentIndex = index;
    int status = 0;
    while(!properHeapNode(currentIndex, status)){
      int biggerChild = 0;
      switch(status){
      case 0:
	std::cout<<"ERROR: proper node and no child left "<<std::endl;
	break;
      case 2: //right 
	biggerChild = currentIndex*2 + 1;
	break;
      case 4: //left 
	biggerChild = currentIndex*2;
	break;
      case 6: //left 
	biggerChild = maxer(currentIndex*2, currentIndex*2 + 1);
	break;
      default:
	std::cout<<"ERROR: "<<std::endl;
      }// end of switch
      swap(currentIndex, biggerChild);
      currentIndex = biggerChild;

    } // end of while 

  }

 public:
  sampleMaxHeap(int size, a_type inputArray []){
    size_ = size;
    capacity_ = size;
    array_ = new a_type [size];
    for(int i = 0; i<size; i++){
      array_[i] = inputArray[i];
    }
    rootIndex_ = 0;
    endIndex_ = size_ - 1;

    // build heap
    for(int i = size/2; i>-1 ; i--){
      heapify(array_, i);
    }


  }

  sampleMaxHeap(int size){

    size_ = 0;
    capacity_ = size;
    array_ = new a_type [size];
    //    a_type max = std::numeric_limits<a_type>::max();
    for(int i = 0; i<size; i++){
      //      array_[i] = max;
      array_[i] = std::numeric_limits<a_type>::min();
    }
    
    rootIndex_ = 0;
    endIndex_ = 0;
      
  }
  ~sampleMaxHeap(){
    delete [] array_;
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

  bool  isFull(){
    return size_ == capacity_;
  }
  bool  isEmpty(){
    return size_ == 0;
  }
  
  void insert(a_type data){
    if(isEmpty()){
      array_[endIndex_] = data;     
      size_++;
      return;
    }
    if(!isFull()){
      // insert 
      endIndex_++;
      array_[endIndex_] = data;     

      size_++;

      int parent = 0;
      int dataIndex = getEnd();
      
      parent = parentIndex(dataIndex);
      // bubble up
      while(array_[dataIndex] > array_[parent] ){
	swap(dataIndex, parent);
	dataIndex = parent;
	parent = parentIndex(dataIndex);
      }
      //      std::cout<<"insert: "<<data<<" at: "<<dataIndex<<std::endl;
    }
    
  }
  void printOut(){
    std::cout<<"The heap is: ";
    
    while(size()!=0){
      std::cout<<extractMax()<<" ";
    }

    std::cout<<"from max to min. "<<std::endl;
  }
  void printTest(){
    std::cout<<"The heap is: ";
    
    for(int i = 0; i< 8; i++){
      std::cout<<array_[i]<<" ";
    }

    std::cout<<std::endl;
  }
  a_type readMax(){
    return array_[rootIndex_];
  }
  a_type extractMax(){
    // std::cout<<"last  is: "<<getEnd()<<std::endl;
    // std::cout<<"root  is: "<<getRoot()<<std::endl;
    
    a_type max = array_[rootIndex_];
    // std::cout<<"min is: "<<min<<std::endl;

    // delete root and move end to root. 
    deleteRootAndReplace();
    //       std::cout<<"delete root"<<std::endl;
    if(size()>0){
      // // bubble down.
      int currentIndex = getRoot();
      //      std::cout<<"root: "<<array_[rootIndex_]<<std::endl;

      //      std::cout<<"currentIndex: "<<currentIndex<<std::endl;
      int status = 0;
      while(!properHeapNode(currentIndex, status)){
	int biggerChild = 0;
	switch(status){
	case 0:
	  std::cout<<"ERROR: proper node and no child left "<<std::endl;
	  break;
	case 2: //right 
	  biggerChild = currentIndex*2 + 1;
	  break;
	case 4: //left 
	  biggerChild = currentIndex*2;
	  break;
	case 6: //left 
	  biggerChild = maxer(currentIndex*2, currentIndex*2 + 1);
	  break;
	default:
	  std::cout<<"ERROR: "<<std::endl;
	}

	
	//	int smallerChild = miner(currentIndex*2, currentIndex*2 + 1);
	//	std::cout<<"smallerChild calculated: "<<smallerChild<<", currentIndex: "<<currentIndex<<std::endl;
	swap(currentIndex, biggerChild);
	currentIndex = biggerChild;
	//	std::cout<<"smallerChild calculated: "<<smallerChild<<", currentIndex: "<<currentIndex<<std::endl;

      }// end of while
    }  
    // std::cout<<std::endl;
    // std::cout<<std::endl;

    //    std::cout<<"finish one extract min"<<std::endl;

    return max;
  } // end of extractMax




  
};
// int main(){
  

//   sampleMinHeap <int>  a(50);

//   a.insert(1);
//   a.insert(10);
//   a.insert(11);
//   a.insert(13);
//   a.insert(14);
//   a.insert(11);
//   a.insert(2);
//   a.insert(121);
//   a.insert(191);
//   a.insert(211);
//   a.insert(1);
//   a.insert(1);
//   a.insert(11);
//   a.insert(3);
//   a.insert(5);
//   a.insert(2);
//   a.insert(1110);

//   std::cout<<"The heap size is: "<<a.size()<<std::endl;
//   std::cout<<"last  is: "<<a.getEnd()<<std::endl;
//   std::cout<<"root  is: "<<a.getRoot()<<std::endl;

//   a.printOut();


//   sampleMaxHeap <int>  b(50);
//   b.insert(1);
//   b.insert(10);
//   b.insert(11);
//   b.insert(13);
//   b.insert(14);
//   b.insert(11);
//   b.insert(2);
//   b.insert(121);
//   b.insert(191);
//   b.insert(211);
//   b.insert(1);
//   b.insert(1);
//   b.insert(11);
//   b.insert(3);
//   b.insert(5);
//   b.insert(2);
//   b.insert(1110);

//   std::cout<<"The heap size is: "<<b.size()<<std::endl;
//   std::cout<<"last  is: "<<b.getEnd()<<std::endl;
//   std::cout<<"root  is: "<<b.getRoot()<<std::endl;

//   b.printOut();
//   b.printTest();


//   return 1;
// }
# endif
