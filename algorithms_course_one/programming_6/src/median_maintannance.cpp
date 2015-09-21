# include <iostream>
# include <sstream>
# include <fstream>
# include "sampleHeap.cpp"

void reBalance(sampleMinHeap<int>& bigValue, sampleMaxHeap<int>& smallValue){

  int diff =  bigValue.size() - smallValue.size();
  switch(diff){
  case -2:
    bigValue.insert(smallValue.extractMax());
    break;
  case -1:
    break;
  case 0:
    break;
  case 1:
    break;
  case 2:
    smallValue.insert(bigValue.extractMin());
    break;
  default:
    std::cout<<"error, the size is not balanced, the diff is:"<<diff<<std::endl;
    break;
  };
    
}

int median(sampleMinHeap<int> &bigValue, sampleMaxHeap<int> & smallValue, int numberSize){

  int order = (numberSize + 1)/2; // according to the description
  int diff = order - smallValue.size();
  //  std::cout<<"\t counter is: "<<numberSize<<", want: "<<order<<", diff is: "<<diff<<std::endl;
  //  std::cout<<"\t big size is: "<<bigValue.size()<<", small size is: "<<smallValue.size()<<std::endl;
  
  if(diff <= 0){
    return   smallValue.readMax();
  }else{
    return  bigValue.readMin();

  }
  // int big = bigValue.readMin();
  // int min = smallValue.readMax();
}

int main(int argc, char ** argv )
{

  std::string inputFile("../benchmarkData/Median.txt"); 
  if(argc == 3){    
    std::stringstream argumentSS(argv[1]);
    std::string param;
    std::string paramContainer;
    
    for (int i = 1; i< argc; i++){
      argumentSS.clear();
      argumentSS.str(argv[i]);
      argumentSS>>param;
      paramContainer = paramContainer + " " + param;
    }
    argumentSS.clear();
    argumentSS.str(paramContainer);

    while(argumentSS>>param){
      if(param == "-data"){
    	//  positionMotionRaw
    	argumentSS>>inputFile;

      }else if(param == "-help"){
	std::cout << "Usage is: \n \t -data <path to the file to be sorted sample.txt > \n "; 
	std::cin.get();
	exit(0);
      }else{
	std::cout << std::endl
		  <<argv[0]
		  << " Error in parameter parsing, please type any key to continue... "
		  <<std::endl; 
	
	std::cin.get();
	exit(0);
      }
    } // end of while;

  }else{
  
    std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt > \n >."<<std::endl; 
    std::cin.get();
    exit(0);
  } // end of argument parsing 


  long medianSum = 0;
  sampleMinHeap <int>  bigValue(5001);
  sampleMaxHeap <int>  smallValue(5001);

  std::ifstream integerReader;
  std::string line;
  integerReader.open(inputFile, std::ios::in);
  int counter = 0;
  while(std::getline(integerReader, line)){
    std::istringstream iss(line);
    int newData(0);
    iss>>newData;
    int big = bigValue.readMin();
    int small = smallValue.readMax();
    // insertion 
    int status = 0;
    if(newData<=small)
      status += 2;
    if(newData>=big)
      status += 4;

    switch (status){
    case 0:  // in the middle does not matter
      bigValue.insert(newData); // go to big then
      break;
    case 2:  // into small
      smallValue.insert(newData);
      break;
    case 4:  // into big 
      bigValue.insert(newData);
      break;
    case 6:  // no child 
      std::cout<<"error"<<std::endl;
      std::cout<<"error"<<std::endl;
      break;

    default: 
      std::cout<<"error"<<std::endl;
      std::cout<<"error"<<std::endl;
      break;	
    };	
    reBalance(bigValue, smallValue);

    counter++;

    // median
    int newMedian = median(bigValue, smallValue, counter);
    
    //std::cout<<"counter: "<<counter<<"The new median is: "<<newMedian<<std::endl;
    
    medianSum+=newMedian;

  }// end of while 
  
  int answer = medianSum%10000;
  std::cout<<"The answer is: "<<answer<<std::endl;
  
} // end of main
