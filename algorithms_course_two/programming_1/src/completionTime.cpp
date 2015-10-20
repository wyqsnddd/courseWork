# include <fstream>
# include <sstream>
# include <iostream>
# include <stdlib.h>
# include "sampleHeap.h" 
# include "jobNode.h"
// # include "temp.cpp"
int main(int argc, char ** argv ){

std::string inputFile("../data/jobs.txt"); 
 if(argc == 3){    
   std::stringstream argumentSS(argv[1]);
   std::string param;
   std::string paramContainer;
    
   for (int i = 1; i< argc; i++){
     argumentSS.clear();
     argumentSS.str(argv[i]);
     argumentSS>>param;
     paramContainer = paramContainer + " " + param;
   }// end of if
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
     }// end of if
   } // end of while;

 }else{
  
   std::cout << "Usage is: \n \t-data <path to the file to be sorted sample.txt > \n"<<std::endl; 
   std::cin.get();
   exit(0);
 } // end of argument parsing 



 std::ifstream integerReader;
 std::string line;
 integerReader.open(inputFile.c_str(), std::ios::in);
 int counter = 0;
  
 int jobNumber = 0;
  
 std::getline(integerReader, line);
 std::istringstream iss(line);
 iss>>jobNumber;  
 std::cout<<"The number of jobs are: "<<jobNumber<<std::endl;
  
 // int inputArray [jobNumber];
 jobNode inputArray [jobNumber];

 while(std::getline(integerReader, line)){
   std::istringstream iss(line);
   int weight(0), length(0);
   iss>>weight;
   iss>>length;
    
     std::cout<<"Getting weight: "<<weight<<", length: "<<length<<std::endl;
   int difference = weight - length;
   // inputArray[counter] = difference;
   inputArray[counter] = jobNode(weight, length);
   counter++;
    
 }// end of while 	

 if(counter==jobNumber){
   // sampleMinHeap <int>  jobHeap(counter, inputArray);
   sampleMinHeap <jobNode>  jobHeap(counter, inputArray);
   std::cout<<"Created min heap."<<std::endl;
   std::cout<<"Indeed created min heap."<<std::endl;
   std::cout<<"The heap size is: "<<jobHeap.size()<<std::endl;
   std::cout<<"The min value is: "<<jobHeap.readMin()<<std::endl;

   jobHeap.printOut();

   // sampleMaxHeap <int>  jobHeap2(counter, inputArray);
   sampleMaxHeap <jobNode>  jobHeap2(counter, inputArray);
   std::cout<<"Created max heap."<<std::endl;
   jobHeap2.printOut();


 }else{
   std::cout<<"The input mis-match the number of jobs."<<std::endl;
 }
  
 return 0;
}
