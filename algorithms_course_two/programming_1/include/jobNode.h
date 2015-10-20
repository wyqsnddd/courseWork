# ifndef JOBNODE_H
# define JOBNODE_H
# include <iostream>

class jobNode{
 private: 
  int weight_, length_;
  
 public: 
  jobNode(int weight, int length){
    weight_ = weight;
    length_ = length;
  }

  ~jobNode(){

  }
  
  int readKey() const{
    return weight_ - length_;
  }
  int readWeight()const{
    return weight_;
  }
  int readLength()const{
    return length_;
  }

  bool operator<(const jobNode& newNode){
    
    int diffKey = readKey() - newNode.readKey();

    if(diffKey < 0)
      return true;
    else if(diffKey > 0)
      return false;
    else if(diffKey == 0)
      return (readWeight() < newNode.readWeight());
  }// end of operator < 
  
  bool operator>(const jobNode& newNode){
    
    int diffKey = readKey() - newNode.readKey();

    if(diffKey > 0)
      return true;
    else if(diffKey < 0)
      return false;
    else if(diffKey == 0)
      return (readWeight() > newNode.readWeight());
  }// end of operator < 
  
  
  friend std::ostream &operator<<(std::ostream &output,
				  const jobNode &node){
    output<<"Node key: "<<node.readKey()<<", weight: "<<node.readWeight();
    return output;
  }

    
};
# endif
