#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
# include <limits>
// Main method, most your code should go here
int main()
{
  // Load in the grid and initialize the output
  int size, tmp;
  std::cin >> size;
  while(std::cin.fail() ){ //if type wasn't right
    std::cin.clear(); //clear stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore left over data
    std::cin >> size;
  }

  std::vector<int> numbers;

  for (int i = 0; i < size*size; i++)
    {
      std::cin >> tmp;
      while(std::cin.fail() ){ //if type wasn't right
	std::cin.clear(); //clear stream
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore left over data
	std::cin >> tmp;
      }

      numbers.push_back(tmp);
    }

  // Your awesome code goes here! The following is a hard coded
  // example that passes the first test case. You should replace it
  // with a more general algorithm that solves the problem and passes
  // all of the test cases.
  std::vector<int> out = numbers;
  // number of row  
  for (int y = 0; y < size; y++)
    {
      int x;
    
      // number of column  
      for (x = 0; x < size; x++){
	if(y>0 && y < (size-1) && x>0 && x<(size-1)){
	  out[y*size + x] = numbers[(y-1)*size + x-1] + numbers[(y-1)*size + x]  + numbers[(y-1)*size + x +1]
	    + numbers[y*size + x-1]   + numbers[y*size + x +1]
	    +numbers[(y+1)*size + x-1] + numbers[(y+1)*size + x]  + numbers[(y+1)*size + x +1];
	}else if(y==0 && x>0 && x<(size-1)){
	  out[y*size + x] =  numbers[y*size + x-1] + numbers[y*size + x]  + numbers[y*size + x +1]
	    + numbers[(y+1)*size + x-1]   + numbers[(y+1)*size + x +1];
	}else if(y==(size-1) && x>0 && x<(size-1)){
	  out[y*size + x] = numbers[(y-1)*size + x-1] + numbers[(y-1)*size + x]  + numbers[(y-1)*size + x +1]
	    +numbers[y*size + x-1]  + numbers[y*size + x +1];
	}else if(y>0 && y < (size-1) && x==0){
	  out[y*size + x] =  numbers[(y-1)*size + x]  + numbers[(y-1)*size + x +1]
	     + numbers[y*size + x +1]
	    + numbers[(y+1)*size + x]  + numbers[(y+1)*size + x +1];
	}
	else if(y>0 && y < (size-1) && x==(size-1)){
	  out[y*size + x] =  numbers[(y-1)*size + x-1] + numbers[(y-1)*size + x]
	    + numbers[y*size + x-1]
	    +numbers[(y+1)*size + x-1] + numbers[(y+1)*size + x];
	}
	else if(y==0 && x==0){
	  out[y*size + x] = 
	    numbers[y*size + x +1]
	    + numbers[(y+1)*size + x]  + numbers[(y+1)*size + x +1];
	}
	else if(y==(size-1) && x==(size-1)){
	  out[y*size + x] = numbers[(y-1)*size + x-1] + numbers[(y-1)*size + x]
	    + numbers[y*size + x-1];
	}
	else if(y==0 && x==(size-1)){
	  out[y*size + x] = 
	    numbers[y*size + x-1] 
	    +numbers[(y+1)*size + x-1] + numbers[(y+1)*size + x];
	}
	else if(y==(size-1) && x==0){
	  out[y*size + x] = numbers[(y-1)*size + x]  + numbers[(y-1)*size + x +1]
	    + numbers[y*size + x +1];
	}
      } // end  of case 
      
    }// end of array 
  // Write out the solution
  for (int y = 0; y < size; y++)
    {
      int x;
      for (x = 0; x < size - 1; x++)
	{
	  std::cout << out[y*size + x] << " ";
	}
      std::cout << out[y*size + x] << std::endl;
    }
  return 0;
}
