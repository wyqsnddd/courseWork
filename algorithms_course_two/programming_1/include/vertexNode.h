# ifndef VERTEXNODE_H
# define VERTEXNODE_H

class vertexNode{
 private:
  int key_;
  int number_;
 public:

  vertexNode(int nodeNumber, int key){
    number_ = nodeNumber;
    setKey(key);
  }
  vertexNode(){
    number_ = 0;
    setKey(0);
  }
  // assignment constructor 
  vertexNode& operator=(const vertexNode& other){
    setKey(other.readKey());
    setNodeNumber(other.readNodeNumber());
    return *this;
  }
  ~vertexNode(){
  }

  int readNodeNumber()const{
    return number_;
  }
  int readKey()const{
    return key_;
  }
  void setKey(int key){
    key_ = key;
  }
  void setNodeNumber(int number){
    number_ = number;
  }
  
  bool operator<=(const vertexNode& otherNode){
    
    return readKey()<=otherNode.readKey();
  }  
  bool operator>=(const vertexNode& otherNode){
    
    return readKey()>=otherNode.readKey();
  }
  bool operator<(const vertexNode& otherNode){
    
    return readKey()<otherNode.readKey();
  }  
  bool operator>(const vertexNode& otherNode){
    
    return readKey()>otherNode.readKey();
  }
  
  friend std::ostream &operator<<(std::ostream &output,
				  const vertexNode &node){
    output<<"Node number: "<<node.readNodeNumber()<<", key: "<<node.readKey();
    return output;
  }
  


};

# endif
