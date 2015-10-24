# ifndef METAEDGE_H
# define METAEDGE_H

class metaEdge{
 private:
  int key_;
  int nodeOne_;
  int nodeTwo_;

 public:
  metaEdge(int nodeOne, int nodeTwo, int key){
    key_ = key;
    nodeOne_ = nodeOne;
    nodeTwo_ = nodeTwo;
  }
  metaEdge(){
    nodeOne_ = -1;
    nodeTwo_ = -1;
    key_ = 0;
  }
  metaEdge& operator=(const metaEdge& other){
    setKey(other.readKey());
    setNodeOne(other.readNodeOne());
    setNodeTwo(other.readNodeTwo());
    return *this;
  }

  ~metaEdge(){
  }  
  int readKey()const{
    return key_;
  }
  void setKey(int key){
    key_ = key;
  }
  int readNodeOne()const{
    return nodeOne_;
  }  
  int readNodeTwo()const{
    return nodeTwo_;
  }
  void setNodeOne(int number){
    nodeOne_ = number;
  }
  void setNodeTwo(int number){
    nodeTwo_ = number;
  }
  bool operator<(const metaEdge& otherEdge){
    
    return readKey()<otherEdge.readKey();
  }  
  bool operator>(const metaEdge& otherEdge){
    
    return readKey()>otherEdge.readKey();
  }
  bool operator<=(const metaEdge& otherEdge){
    
    return readKey()<=otherEdge.readKey();
  }  
  bool operator>=(const metaEdge& otherEdge){
    
    return readKey()>=otherEdge.readKey();
  }
  friend std::ostream &operator<<(std::ostream &output,
				  const metaEdge &edge){
    output<<"Node one: "<<edge.readNodeOne()<<", Node two: "<<edge.readNodeTwo()
	  <<", key: "<<edge.readKey();
    return output;
  }
  

};
# endif
