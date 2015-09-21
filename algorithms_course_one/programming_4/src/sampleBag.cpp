# include <iostream>

template<class a_type> class sampleBag{

private:
  class Node{
  public:
    a_type data;
    Node * next;
    //    Node * previous;
  };
  
  int n_;// number of elements
  Node *first_;
  Node *last_;
  void increaseSize(){
    n_++;
  }
  bool isOne() const{
    return n_ == 1;
  }

public:
  Node* iterator;
  a_type getIteratorData(){
    return iterator->data;
  }
  sampleBag( ){// default argument: 0
    n_ = 0;
    first_ = NULL;
    last_ = NULL;
  }
  ~sampleBag(){
  }
  bool isEmpty() const{
    if (first_ == NULL)
      return true;
    else 
      return false;
  }

  int getSize(){
    return n_;
  }
  a_type getLast(){
    return *last_;
  }
  //  a_type 
  Node* getFirst(){
    return first_;
  }
  void add(a_type data){
    
    if(first_ == NULL){
      first_ = new Node();
      first_->data = data;
      first_->next = NULL;
      //      first_->previous = NULL;
      last_  = first_;
    }else if(isOne() ){
      last_ = new Node();
      last_->data = data;
      last_->next = NULL;

      first_->next = last_;
    }else{
      Node * temp = new Node();
      temp->data = data;
      temp->next = NULL;

      last_->next = temp;
      last_ = temp;
    }

  increaseSize();

  }
  void printBag(){
    Node * temp = getFirst();
    std::cout<<": ";
      while(temp!=NULL){
	std::cout<<" "<<temp->data;
	temp = temp->next;
    }
    std::cout<<std::endl;
  }
  


};


