# include "jobNode.h"


int main(){
  jobNode node1(1, 10);
  jobNode node2(3, 12);
  jobNode node3(2, 11);
  std::cout<<"node1: "<<node1<<std::endl;
  std::cout<<"node2: "<<node2<<std::endl;
  std::cout<<"node3: "<<node3<<std::endl;

  std::cout<<"node1 < node2: "<<(node1<node2)<<std::endl;
  std::cout<<"node2 < node3: "<<(node2<node3)<<std::endl;
  
  std::cout<<"node1 > node2: "<<(node1>node2)<<std::endl;
  std::cout<<"node2 > node3: "<<(node2>node3)<<std::endl;

  return 0;
}
