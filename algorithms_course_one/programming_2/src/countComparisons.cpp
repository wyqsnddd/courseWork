# include <string>
# include <sstream>
# include <iostream>
# include <fstream>
# include <algorithm>


void swap(int* array, int i, int j ){
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
  return;
}

void countComparisonsFirst(int* array, int left, int right, long* numberComparison){

  if( left == right )
    return;
  else{
    //    *numberComparison += right - left - 1;
    *numberComparison += right - left;
    // std::cout<<"left is: "<<left<<std::endl;
    // std::cout<<"right is: "<<right<<std::endl;
    //    std::cout<<"numberComparison increments: "<< right - left - 1<<std::endl;
    // std::cout<<"numberComparison increments: "<< right - left<<std::endl;

    int pivot = array[left];//
    int i = left + 1;// a[i - 1] < pivot
    // int j = left + 1;// 

      
    for(int j = left + 1; j <=right; j++ ){
      //      std::cout<<"j is: "<<j<<std::endl;
      if(array[j] < pivot){
	swap(array, i, j);
	i++;
      }
    }
    //    std::cout<<"i is: "<<i<<std::endl;
    
    swap(array, left, i - 1);
    
    if( (i - left) >= 2 )
      countComparisonsFirst(array, left, i-2, numberComparison);
    if(i<right)
      countComparisonsFirst(array, i, right, numberComparison);
    return;
  }
  
}

void countComparisonsFinal(int* array, int left, int right, long* numberComparison){

  if( left == right )
    return;
  else{
    //    *numberComparison += right - left - 1;
    *numberComparison += right - left;

    // Use the last element as the pivot
    int pivot = array[right];
    swap(array, left, right);
    
    int i = left + 1;// a[i - 1] < pivot
    int j = left + 1;// 
    // std::cout<<"left is: "<<left<<std::endl;
    // std::cout<<"right is: "<<right<<std::endl;
      
    for(j = left + 1; j <=right; j++ ){
      //      std::cout<<"j is: "<<j<<std::endl;
      if(array[j] < pivot){
	swap(array, i, j);
	i++;
      }
    }
    //    std::cout<<"i is: "<<i<<std::endl;
    
    swap(array, left, i - 1);
    
    if( (i - left) >= 2 )
      countComparisonsFinal(array, left, i-2, numberComparison);
    if(i<right)
      countComparisonsFinal(array, i, right, numberComparison);
    return;
  }

}
void countComparisonsMedian(int* array, int left, int right, long* numberComparison){

  if( left == right )
    return;
  else{
    //    *numberComparison += right - left - 1;
    *numberComparison += right - left;

    // Use the last element as the pivot
    
    int pivot = 0;
    int median = 0;
    int middle =  left + (right - left)/2 ;

    if(array[left] >= array[middle]){
      if(array[left] <= array[right])
	median = left;
      else if(array[middle]<=array[right])
	median = right;
      else
	median = middle;
    }else{
      if(array[left] >= array[right])
	median = left;
      else if(array[middle]>=array[right])
	median = right;
      else
	median = middle;
    }

    pivot = array[median];
    swap(array, left, median);
    
    int i = left + 1;// a[i - 1] < pivot
    int j = left + 1;// 
    // std::cout<<"left is: "<<left<<std::endl;
    // std::cout<<"right is: "<<right<<std::endl;
      
    for(j = left + 1; j <=right; j++ ){
      //      std::cout<<"j is: "<<j<<std::endl;
      if(array[j] < pivot){
	swap(array, i, j);
	i++;
      }
    }
    //    std::cout<<"i is: "<<i<<std::endl;
    
    swap(array, left, i - 1);
    
    if( (i - left) >= 2 )
      countComparisonsMedian(array, left, i-2, numberComparison);
    if(i<right)
      countComparisonsMedian(array, i, right, numberComparison);
    return;
  }

}

int main(int argc, char ** argv )
{
  int pivotMode = 2;
  std::string inputFile("../benchmarkData/data.txt"); 

  if(argc == 5){    
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
      if(param == "-m"){
    	argumentSS>>pivotMode;
      }else if(param == "-data"){
    	//  positionMotionRaw
    	argumentSS>>inputFile;

      }else if(param == "-help"){
    	  std::cout << "Usage is: \n \t  -m pivotMode: 0:Choose the first element as pivot,  1:Choost the final element as pivot, 2:Choose the pivot using the 'median of three' rule. \n \t -data <path to the file to be sorted sample.txt > \n "; 
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

    }
else{

      std::cout << "Usage is: \n \t -m pivotMode: 0:Choose the first element as pivot;  1:Choost the final element as pivot 2:Choose the pivot using the 'median of three' rule. \n \t-data <path to the file to be sorted sample.txt > \n"; 
      std::cin.get();
      exit(0);

    } // end of argument parsing 


    std::ifstream integerReader;
    integerReader.open(inputFile, std::ios::in);

    if(
       !integerReader.is_open()
       )
      {
	std::cout<<"Text files are not open."<<std::endl;
	exit(0);
      }else{
      int pre_reading = integerReader.tellg();
      std::cout<<"The reader position is: "<<pre_reading<<std::endl;

      int linesN =  std::count(std::istreambuf_iterator<char>(integerReader), 
			       std::istreambuf_iterator<char>(), '\n');

      std::cout<<"There are "<<linesN<<" lines in the file."<<std::endl;
    
      int * inputBuffer = new int[linesN];     
      // int * playGround = new int[linesN];     
      int pos_reading = integerReader.tellg();
      std::cout<<"The reader position is: "<<pos_reading<<std::endl;
    
      //    integerReader.seekg(0, integerReader.beg);
      integerReader.seekg(0);
      int post_reading = integerReader.tellg();
      std::cout<<"The reader position is: "<<post_reading<<std::endl;

      //      if((inputBuffer!=NULL)&&(playGround!=NULL)){
      if(inputBuffer!=NULL){
	for(int i = 0; i < linesN; i++){
	  integerReader>>inputBuffer[i];
	}
	std::cout<<"Integers are read."<<std::endl;
      }else{
	std::cout<<"Memory are not allocatd."<<std::endl;
	exit(0);
      }

      integerReader.close();

      //-----------
      std::cout<<" Start sorting ! "<<std::endl;
      // mergeSort(inputBuffer, playGround, 0, (linesN - 1));
      long numberComparison = 0;

      //      countInversion(inputBuffer, playGround, 0, (linesN - 1), &numberInversion);
      switch(pivotMode){
      case 0: // first element
      	countComparisonsFirst(inputBuffer, 0, (linesN-1), &numberComparison);
	break;
      case 1: // final element
      	countComparisonsFinal(inputBuffer, 0, (linesN-1), &numberComparison);
	break;
      case 2: // median of the three 
      	countComparisonsMedian(inputBuffer, 0, (linesN-1), &numberComparison);
	break;
      default: 
      	std::cout<<" Use the default median method for selecting pivot "<<std::endl;
	countComparisonsMedian(inputBuffer, 0, (linesN-1), &numberComparison);
	break;
      }
      // cancel out the first time
      //      numberComparison -= linesN - 2; 
      // for(int i = 0; i<= 10; i++)
      // 	std::cout<<"i is: "<<i<<std::endl;
      
      std::cout<<" Sorted ! "<<std::endl;

      //-----------
      std::cout<<"test output: "<<std::endl;
      for(int i = 0; i < linesN; i++){

        std::cout<<inputBuffer[i];
        std::cout<<std::endl;
      }
      std::cout<<std::endl;
      std::cout<<" The number of comparisons is: "<<numberComparison<<std::endl;

      free(inputBuffer);
      // free(playGround);
    
    }

    exit(0);
  }
