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
  jobNode(){
    weight_ = 0;
    length_ = 0;
  }

  jobNode& operator=(const jobNode& other){
    weight_ = other.readWeight();
    length_ = other.readLength();
    return *this;
  }
  
  ~jobNode(){

  }
  
  double readKey() const{
    /* return weight_ - length_; */
    return (double)weight_/(double)length_;
  }
  int readWeight()const{
    return weight_;
  }
  int readLength()const{
    return length_;
  }

  bool operator<=(const jobNode& otherNode){
    
    double diffKey = readKey() - otherNode.readKey();

    if(diffKey < 0)
      return true;
    else if(diffKey > 0)
      return false;
    else if(diffKey == 0)
      return (readWeight() <= otherNode.readWeight());
  }// end of operator < 


  bool operator<(const jobNode& otherNode){
    
    double diffKey = readKey() - otherNode.readKey();

    if(diffKey < 0)
      return true;
    else if(diffKey > 0)
      return false;
    else if(diffKey == 0)
      return (readWeight() < otherNode.readWeight());
  }// end of operator < 
  
  bool operator>=(const jobNode& otherNode){
    
    double diffKey = readKey() - otherNode.readKey();

    if(diffKey > 0)
      return true;
    else if(diffKey < 0)
      return false;
    else if(diffKey == 0)
      return (readWeight() >= otherNode.readWeight());
  }// end of operator > 


  bool operator>(const jobNode& otherNode){
    
    double diffKey = readKey() - otherNode.readKey();

    if(diffKey > 0)
      return true;
    else if(diffKey < 0)
      return false;
    else if(diffKey == 0)
      return (readWeight() > otherNode.readWeight());
  }// end of operator > 
  
  
  friend std::ostream &operator<<(std::ostream &output,
				  const jobNode &node){
    output<<"Node key: "<<node.readKey()<<", weight: "<<node.readWeight();
    return output;
  }

    
};
# endif
