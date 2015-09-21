# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
// I could play with the different data types 

// typedef long long sampleType;
// Using "int" or "long" may truncate the values read from the file.
// typedef double sampleType; 
// typedef int sampleType; 
typedef long sampleType; 

void readIntegerFile(std::string inputFile, std::map<sampleType, int> &mapSample ){
  std::ifstream integerReader;
  std::string line;
  integerReader.open(inputFile, std::ios::in);
  int lineCounter = 0;  
  int diff = 1;
  while(std::getline(integerReader, line)){
    // read in the integer 
    std::istringstream iss(line);
    sampleType intSample(0);
    iss>>intSample; 
    // add it to the hash table 
    // mapSample[key] = data;
    // mapSample[intSample] = lineCounter;
    mapSample.insert(std::pair<sampleType, int>(intSample, lineCounter));

    lineCounter++;

    if((lineCounter - mapSample.size()) == diff){
      std::cout<<"At line: "<<lineCounter<<" , key: "<<intSample<<" is not inserted. "<<"Map size is: "<< mapSample.size()<<std::endl;
      diff++;
    }

  }// end of while 
  std::cout<<"The hash table size is: "<<mapSample.size()<<std::endl;
  std::cout<<"line counter is: "<<lineCounter<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  //  std::cout<<"If the above two are not equal, then it means there are : "<<lineCounter<<std::endl;
} // end of reader 


int main(int argc, char ** argv )
{

  std::string inputFile("../benchmarkData/algo1_programming_prob_2sum.txt"); 
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


  // Build the hash table 
  std::map<sampleType, int> hashTableInt;
  readIntegerFile(inputFile, hashTableInt );
  int counter = 0; 
  for(int t = -10000; t<=10000; t++ ){
    std::cout<<"t: "<<t<<std::endl;

    for(std::map<sampleType, int>::iterator  i = hashTableInt.begin(); 
	i != hashTableInt.end(); 
	i++){
      std::map<sampleType, int>::iterator keyFound = hashTableInt.find(t - i->first);
      if(keyFound!=hashTableInt.end()&&keyFound!=i){

	// std::cout<<"The pair is: "<< keyFound->first
	// 	 <<" and "
	// 	 << i->first<<". "<<std::endl;
	counter++;
	break;
      }

    } // end of inner hash table loop
  } // end of t loop 
  std::cout<<"There are "<<counter<<" pairs. "<<std::endl;
  
}// end of main
