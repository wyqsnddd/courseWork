# ifndef GRAPHHEAP_H
# define GRAPHHEAP_H

# include <iostream>
# include <limits>
# include <map>
template<class a_type> class graphMinHeap{


private:
int endIndex_;
int rootIndex_;
int capacity_;
int size_; 
  
a_type * array_;
 

 int parentIndex( int child){
  return child/2;// This is floor operation anyway. 
}
 void heapMapDeletion(int index){
  /* std::cout<<"Size of the heapMap is: "<<nodeHeapMap_.size()<<std::endl; */

  /* testPrintHeap();   */
  /* testPrintHeapMap(); */
  // (1) Erase the old root from the heap
   //  int nodeNumber = readElement(index).readNodeNumber();
  int nodeNumber = readElement(index).readNodeTwo();
  /* std::cout<<"delete node "<<nodeNumber<<" from the heap map"<<std::endl; */
  std::map<int,int>::iterator itHeap;
  itHeap = nodeHeapMap_.find(nodeNumber);
  bool endElement = false;
  if(itHeap->second==(size()-1)){
    endElement = true;
  }

  if(itHeap==nodeHeapMap_.end()){
    std::cout<<"Error: the node: "<< nodeNumber<<" to be deleted is not on the heapMap."<<std::endl;
  }else{
    nodeHeapMap_.erase(itHeap);
  }
  /* std::cout<<"node: "<<itHeap->first<<" is at "<<itHeap->second <<"of the heap"<<std::endl; */
  // (2) Replace the root with the last element; 
  if(nodeHeapMap_.size()!=0){

    if(!endElement){
      /* std::cout<<"Replace the root with the last element"<<std::endl; */
      /* testPrintHeapMap(); */


      //      int nodeNumberEnd = readElement(getEnd()).readNodeNumber();
      int nodeNumberEnd = readElement(getEnd()).readNodeTwo();
      /* std::cout<<"the end element is node "<<nodeNumberEnd<<std::endl;   */
      /* nodeHeapMap_.erase(nodeHeapMap_.find(nodeNumber)); */
      nodeHeapMap_.erase(nodeHeapMap_.find(nodeNumberEnd));
      nodeHeapMap_.insert(
			  std::pair<int, int>(nodeNumberEnd,// Key: node number
					      index)// Value: Position on the heap
			  );

    }// end of replace 
  }
 }
 void heapMapRootDeletion(){

  /* testPrintHeap();   */
  /* testPrintHeapMap(); */
  // (1) Erase the old root from the heap
   //  int nodeNumber = readElement(getRoot()).readNodeNumber();
  int nodeNumber = readElement(getRoot()).readNodeTwo();
  /* std::cout<<"delete node "<<nodeNumber<<" from the heap map"<<std::endl; */
  std::map<int,int>::iterator itHeap;
  itHeap = nodeHeapMap_.find(nodeNumber);
  if(itHeap==nodeHeapMap_.end()){
    std::cout<<"Error: the node: "<< nodeNumber<<" to be deleted is not on the heapMap."<<std::endl;
  }else{
    nodeHeapMap_.erase(itHeap);
  }
  /* testPrintHeapMap(); */

  // (2) Replace the root with the last element; 
  if(nodeHeapMap_.size()!=0){

    //    int nodeNumberEnd = readElement(getEnd()).readNodeNumber();
    int nodeNumberEnd = readElement(getEnd()).readNodeTwo();
    /* nodeHeapMap_.erase(nodeHeapMap_.find(nodeNumber)); */
    nodeHeapMap_.erase(nodeHeapMap_.find(nodeNumberEnd));
    nodeHeapMap_.insert(
			std::pair<int, int>(nodeNumberEnd,// Key: node number
					    0)// Value: Position on the heap
			);
  }
 }
void heapMapSwap(int a, int b){
   /* std::cout<<"swap "<<a<<", "<<b<<std::endl; */

     /* testPrintHeap(); */
     /* testPrintHeapMap(); */


     int nodeNumberA = 0;

     //     nodeNumberA = readElement(a).readNodeNumber();
     nodeNumberA = readElement(a).readNodeTwo();

     int nodeNumberB = 0;

     //     nodeNumberB = readElement(b).readNodeNumber();
     nodeNumberB = readElement(b).readNodeTwo();

     
     /* std::cout<<"heapMap(size:"<<nodeHeapMap_.size()<<") swap node: "<<nodeNumberA<<"(index:"<<a<<") and node "<<nodeNumberB<<"(index:"<<b<<")."<<std::endl; */

     nodeHeapMap_.erase(nodeHeapMap_.find(nodeNumberA));
     nodeHeapMap_.erase(nodeHeapMap_.find(nodeNumberB));


  nodeHeapMap_.insert(
		      std::pair<int, int>(nodeNumberA,// Key: node number
					  b)// Value: Position on the heap
		      );
  nodeHeapMap_.insert(
		      std::pair<int, int>(nodeNumberB,// Key: node number
					  a)// Value: Position on the heap
		      );
}
 void metaInsertion(a_type data){
   /* std::cout<<"meta heap insertion"<<std::endl; */
   /* testPrintHeap(); */
   /* testPrintHeapMap(); */

   array_[endIndex_] = data;     
   size_++;
   nodeHeapMap_.insert(
		       //   		       std::pair<int, int>(data.readNodeNumber(),// Key: node number
   		       std::pair<int, int>(data.readNodeTwo(),// Key: node number
   					   endIndex_)// Value: Position on the heap
   		       );
   /* std::cout<<"meta heap insertion node("<<data.readNodeNumber()<<") at ("<<endIndex_<<")DONE"<<std::endl; */
   /* testPrintHeap(); */
   /* testPrintHeapMap(); */
 }

int bubbleDown(int dataIndex){
  /* std::cout<<"bubble down "<<dataIndex<<std::endl; */
// // bubble down.
  int currentIndex = dataIndex;
  //      std::cout<<"root: "<<array_[rootIndex_]<<std::endl;

  //      std::cout<<"currentIndex: "<<currentIndex<<std::endl;
  int status = 0;
  while(!properHeapNode(currentIndex, status)){
    int smallerChild = 0;
    switch(status){
    case 0:
      /* std::cout<<"INFO: proper node and no child left "<<std::endl; */
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
  return currentIndex;
}
 int bubbleUp(int dataIndex){
   int parent  = parentIndex(dataIndex);

   while(array_[dataIndex] < array_[parent] ){
     swap(dataIndex, parent);
     dataIndex = parent;
     parent = parentIndex(dataIndex);
   }
   return dataIndex;
 }// end of bubbleUp
 int swap(int a, int b){
   /* std::cout<<"swap "<<a<<", "<<b<<std::endl; */
   heapMapSwap(a, b);
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
     /* std::cout<<"index: "<<index<< "left is: "<<childLeft<<"right is: "<<childRight<<". status is: "<<status<<std::endl; */

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
       	/* std::cout<<"array_[index]"<<array_[index]<<", array_[childLeft]: "<<array_[childLeft]<<", array_[childRight]: "<<array_[childRight]<<std::endl; */
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
   }else
     return -1;
 }
 bool  isOne() const{
   return size_ == 1;
 }

 void deleteRootAndReplace(){
   if(!isEmpty()){
     // Do this first!!!
     //     heapMapDeletion(rootIndex_);
     heapMapRootDeletion();
     /* std::cout<<"delete heap map"<<std::endl; */

     array_[getRoot()] = array_[getEnd()];

     
     if(!isOne())
       endIndex_--;

     size_--;
   }
   
  /* testPrintHeap(); */
  /* testPrintHeapMap(); */
  
 }
 public:
std::map<int, int>  nodeHeapMap_;
 graphMinHeap(int size){

   size_ = 0;
   capacity_ = size;
   array_ = new a_type [size];

   for(int i = 0; i<size; i++){
     array_[i] = std::numeric_limits<a_type>::max();
   }
    
   rootIndex_ = 0;
   endIndex_ = 0;
      
 } // end of constructor

 ~graphMinHeap(){
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

 bool  isFull() const{
   return size_ == capacity_;
 }
 bool  isEmpty() const{
   return size_ == 0;
 }
 bool dataOnHeap(a_type data){
   std::map<int,int>::iterator itHeap;
   //   itHeap = nodeHeapMap_.find(data.readNodeNumber());
   itHeap = nodeHeapMap_.find(data.readNodeTwo());
   return (itHeap!=nodeHeapMap_.end());
 }  
int replaceData(a_type data){
   // assume the node is already on the heap and heap map
   std::map<int,int>::iterator itHeap;
   //   itHeap = nodeHeapMap_.find(data.readNodeNumber());
   itHeap = nodeHeapMap_.find(data.readNodeTwo());

   if(data.readKey()<readElement(itHeap->second).readKey()){
     // (0) delete on the heap 
     /* std::cout<<"delete node: "<<data.readNodeNumber()<<std::endl; */
     /* testPrintHeap(); */
     deleteElement(itHeap->second);
     // (1) insert again

     /* std::cout<<"insert node: "<<data.readNodeNumber()<<" with key: "<<data.readKey()<<std::endl; */
     return insert(data);
   }else{
     /* std::cout<<"No need to replace"<<std::endl; */
     return itHeap->second;
   }
 }
 int insert(a_type data){
   if(isEmpty()){
     // Don't need to do collision check as the heap is empty
     metaInsertion(data);
     /* array_[endIndex_] = data;      */
     /* size_++; */
   return endIndex_;
   }
   if(!isFull()){
     // collision check
     if(dataOnHeap(data)){
       /* std::cout<<"Error ====================================================================================="<<std::endl; */
       return replaceData(data);
     }else{
       // the node is not yet on the heap
       // insert 
       endIndex_++;

       /* array_[endIndex_] = data;      */
       /* size_++; */
       metaInsertion(data);

       int dataIndex = getEnd();
       return bubbleUp(dataIndex);
     }
   }
    
 }

 a_type readElement(int index){
   int status(0);
   /* if(properHeapNode(index, status)){ */
   return array_[index];
   // }
 }// end of readElement
 void deleteElement(int index){
   if(index == 0){
     deleteRootAndReplace();
     if(size()>1){
       bubbleDown(getRoot());
     }  

     return;
   }
   bool endElement(false);
   if(!isEmpty()){
     /* testPrintHeap(); */
     /* testPrintHeapMap(); */
     if(index==(size()-1)){
       endElement = true;
     }
     heapMapDeletion(index);      
     array_[index] = array_[endIndex_];
     
     if(!isOne())
       endIndex_--;

     size_--;
     /* testPrintHeap(); */
     /* testPrintHeapMap(); */
     /* std::cout<<"finished delete index:"<<index<<std::endl; */
     /* testPrintHeap(); */
     /* testPrintHeapMap(); */

   }
   // Heap maintainance     
   if(!endElement){
     if(size()>1){
       // bubble up or bubble down? 
       int smallerIndex = miner(index, parentIndex(index));
       if(smallerIndex>=0){
	 if(smallerIndex==index){
	   bubbleUp(index);
	 }else{
	   bubbleDown(index);
	 }
       }else{// out of range no parent
	 /* bubbleDown(index); */
	 std::cout<<"index is: "<<index<<", parent is: "<<parentIndex(index)<<std::endl;
	 std::cout<<"ERROR----------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
       }
     }// If only one element left     

   }// end of heap maintainance
   std::cout<<"Just deleted element index: "<<index<<", size was: "<<size()+ 1<<std::endl;
 }
 void testPrintHeap(){
   std::cout<<"The heap is: "<<std::endl;
    
   for(int i = 0; i < size(); i++){
     std::cout<<"Index "<<i<<": "<<array_[i]<<std::endl;
   }
   std::cout<<"from min to max. "<<std::endl;
 }
 void testPrintHeapMap(){
   if(nodeHeapMap_.size()>0){
   
     std::cout<<"The heap map is: "<<std::endl;

     for(std::map<int,int>::iterator it = nodeHeapMap_.begin(); 
	 it != nodeHeapMap_.end(); 
	 ++it ){
       std::cout<<"node: "<<it->first<<" is at "<<it->second <<"of the heap"<<std::endl;
     }
   }else{
     std::cout<<"The heap map is: empty"<<std::endl;
   }
 }
 
 void printOut(){
   std::cout<<"The heap is: "<<std::endl;
    
   while(size()!=0){
     std::cout<<extractMin()<<" "<<std::endl;
   }

   std::cout<<"from min to max. "<<std::endl;
 }
 a_type readMin() const{
   return array_[rootIndex_];

 }

 a_type extractMin(){
   a_type min = array_[rootIndex_];
   /* std::cout<<"min is: "<<min<<std::endl; */

   // delete root and move end to root. 
   deleteRootAndReplace();
   /* std::cout<<"delete root"<<std::endl; */
   if(size()>1){
     // // bubble down.
     /* std::cout<<"bubble down"<<std::endl; */
     
     bubbleDown(getRoot());
   }  
   // std::cout<<std::endl;
   // std::cout<<std::endl;

   //    std::cout<<"finish one extract min"<<std::endl;

   return min;
 } // end of extractMin

 bool inHeap(int nodeNumber){
   std::map<int,int>::iterator itHeap;
   itHeap = nodeHeapMap_.find(nodeNumber);
   return itHeap!=nodeHeapMap_.end();
 }

 int nodeHeapIndex(int nodeNumber){
   std::map<int,int>::iterator itHeap;
   itHeap = nodeHeapMap_.find(nodeNumber);
   // return the node index in the heap
   return itHeap->second;
 }
 bool properHeap(){
   if(size()>1){
     for(int i = size()/2; i>-1 ; i--){
       int status(0);
       if(!properHeapNode(i, status)){
	 int childLeft = 2*i;
	 int childRight = 2*i + 1;

	 switch (status){
	 case 2:  // rightchild 
	   std::cout<<"array_[index]"<<array_[i]<<", array_[childRight]: "<<array_[childRight]<<std::endl;
	   break;
	 case 4: // left child 
	   std::cout<<"array_[index]"<<array_[i]<<", array_[childLeft]: "<<array_[childLeft]<<std::endl;
	   break;
	 case 6: // left and right 
	   std::cout<<"array_[index]"<<array_[i]<<", array_[childLeft]: "<<array_[childLeft]<<", array_[childRight]: "<<array_[childRight]<<std::endl;
	   break;
	 default:
	   std::cout<<"Cannot find what is wrong"<<std::endl;
	 }
	 std::cout<<"Error: not proper heap"<<std::endl;
	 return false;
       }
     }
   }
   return true;
 }
 
};
# endif
