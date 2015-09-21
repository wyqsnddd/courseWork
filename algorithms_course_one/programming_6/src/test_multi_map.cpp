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

void readIntegerFile(std::string inputFile, std::multimap<sampleType, int> &mapSample ){
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
  //  std::cout<<"If the above two are not equal, then it means there are : "<<lineCounter<<std::endl;
} // end of reader 


int main(int argc, char ** argv )
{

  std::string inputFile("../benchmarkData/algo1_programming_prob_2sum.txt"); 
  int numberOfNodes; 
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
  std::multimap<sampleType, int> hashTableInt;
  readIntegerFile(inputFile, hashTableInt );
  std::cout<<"The hash table size is: "<<hashTableInt.size()<<std::endl;
  std::cout<<"  Look for the first two element: "<<std::endl;
  
  sampleType test = -21123414637;
  std::cout<<"  key: "<<hashTableInt.find(test)->first<<std::endl;
  std::cout<<"  assigned value: "<<hashTableInt.find(test)->second<<std::endl;

  sampleType test_2 = 68037543430;
  std::cout<<"  key: "<<hashTableInt.find(test_2)->first<<std::endl;
  std::cout<<"  assigned value: "<<hashTableInt.find(test_2)->second<<std::endl;

  std::cout<<"  The begin of the hash table is not 1, 2: "<<std::endl;
  std::cout<<"  key: "<<hashTableInt.begin()->first<<std::endl;
  std::cout<<"  assigned value: "<<hashTableInt.begin()->second<<std::endl;

  int j = 0;
  for(std::multimap<sampleType, int>::iterator  i = hashTableInt.begin();j<5;i++){
    std::cout<<"iterate: "<<j<<" item in hash table:";
    std::cout<<"key: "<<i->first<<", assigned data: "<<i->second<<std::endl;
    j++;
  }


  // for(std::multimap<sampleType, int>::iterator  i = hashTableInt.begin();i != hashTableInt.end();i++){
  //   int size = hashTableInt.count(i->first);
  //   if(size!=1){
  //     std::cout<<"key: "<<i->first<<", has size: "<<size<<std::endl;
  //   }
  // }

  // test double size case: 
  
  std::cout<<std::endl;
  std::cout<<std::endl;
  sampleType test_3 = 86149365355;
  std::cout<<"key: "<<test_3;  
  std::pair <std::multimap<sampleType,int>::iterator, std::multimap<sampleType,int>::iterator> ret;
  std::cout<<", count: "<<hashTableInt.count(test_3);  
  ret = hashTableInt.equal_range(test_3);

  
  for(std::multimap<sampleType,int>::iterator i = ret.first; i!=ret.second; i++){
    std::cout<<": "<<i->second;
  }
  std::cout<<std::endl;
  std::cout<<std::endl;

  std::cout<<"key: "<<hashTableInt.find(test_3)->first<<std::endl;
  std::cout<<"assigned value: "<<hashTableInt.find(test_2)->second<<std::endl;


}// end of main
