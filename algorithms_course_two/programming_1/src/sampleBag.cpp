# include <iostream>

template<class a_type> class sampleBag{

private:
  class Node{
  public:
    a_type node;
    a_type length;
    Node * next;
    //    Node * previous;
    ~Node(){}
  };
  
  int n_;// number of elements
  Node *first_;
  Node *last_;
  //  Node *secondLast_;
  //  Node 
  bool byNode_;
public:
  Node* iterator;
  sampleBag( bool byNode){// default argument: 0
    n_ = 0;
    first_ = NULL;
    last_ = NULL;
    byNode_ = byNode;
    //    iterator = first_;
  }  
  ~sampleBag( ){// default argument: 0

  }  


  bool isEmpty(){
    if (first_ == NULL)
      return true;
    else 
      return false;
  }

  int getSize() {
    return n_;
  }
  Node* getLast(){
    return last_;
  }
  //  a_type 
  Node* getFirst(){
    return first_;
  }
  //  void add(a_type node, a_type length){
  void add(a_type node, a_type length){
    
    if(first_ == NULL){
      first_ = new Node();
      first_->node = node;
      first_->length = length;
      first_->next = NULL;
      //      first_->previous = NULL;
      last_  = first_;
      //      secondLast_ = NULL;
      n_++;
    }else{ // add in by order 
      bool decision = false;
      // min-> max
      
      if(byNode_){
	decision = last_->node<node;
      }else{
	decision = last_->length<length;
      }
      
      if(decision){
	// link new edge to the end
	Node* temp = new Node();
	temp->node = node;
	temp->length = length;
	temp->next = NULL;
	// move last;
	last_->next = temp;
	last_ = temp;
	// // move second last 
	// secondLast_ = secondLast_->next;
      }else{
	// swap new edge with the end 
	Node* temp = new Node();
	temp->node = last_->node;
	temp->length = last_->length;
	temp->next = NULL;

	
	// No need for second last
	last_->node = node;
	last_->length = length;
	last_->next = temp;

	last_ = temp;
	// // second last: 
	// secondLast_->next = temp;
      }
    }
    // increase the size;
    n_++;
  }

  void printBag(){
    std::cout<<"The bag is: ";
    for(iterator = first_; iterator!=NULL; iterator = iterator->next){
      std::cout<<" [node: "<<iterator->node<<", length: "<<iterator->length<<"] ";
    }
    std::cout<<std::endl;
    std::cout<<"The bag printed out."<<std::endl;;

  }

  void deleteFirstNode(){
    if(first_ !=NULL){      // there is data
      // ready to delete 
      Node* trash;
      trash = first_; 
      first_ = first_->next;
      free(trash);
      n_--;
    }
  }
    

};

// int main(){

//   sampleBag<int> test(true);

//   test.add(1,2);
//   test.add(1,10);
//   test.add(2,50);
//   test.add(19,10);
//   test.add(8,60);
//   test.add(8,100);
//   test.add(8,200);

//   test.printBag();
//   test.deleteFirstNode();
//   test.deleteFirstNode();
//   test.deleteFirstNode();
//   test.deleteFirstNode();
//   test.deleteFirstNode();
//   test.deleteFirstNode();
//   test.deleteFirstNode();
//     std::cout<<"The bag is: ";
//     for(test.iterator = test.getFirst(); test.iterator!=NULL; test.iterator = test.iterator->next){
//       std::cout<<" [node: "<<test.iterator->node<<", length: "<<test.iterator->length<<"] ";
//     }
//     std::cout<<std::endl;
//     std::cout<<"The bag printed out."<<std::endl;;

//   return 0;
// }
