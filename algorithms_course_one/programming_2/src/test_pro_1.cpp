# include <iostream>
# include <limits>

int fibNumberGreater(int input){
  int first(0), second(1);
  int next = 0;
  while(input >= next){
    next = first + second;
    // std::cout<<"new next is: "<<next<<std::endl;
    first = second;
    second = next;
  }
  return next;
}


int main()
{
  // Don't be afraid to make changes!!
  int num_elements;
  std::cin >> num_elements;
  while(std::cin.fail() ){ //if type wasn't right
    // std::cout<<"the type is not correct "<<std::endl;
    std::cin.clear(); //clear stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore left over data
    // std::cout<<"do it again: "<<std::endl;
    std::cin >> num_elements;
  }
  // std::cout<<"correct number "<<std::endl;

  int* arr = new int[num_elements];

  // Input
  for (int i = 0; i < num_elements; i++)
  {
    std::cin >> arr[i];
    while(std::cin.fail() ){ //if type wasn't right
      // std::cout<<"the type is not correct "<<std::endl;
      std::cin.clear(); //clear stream
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore left over data
      // std::cout<<"do it again: "<<std::endl;
      std::cin >> arr[i];
    }// end of while
    
  }
  // Calculating the bigger Fibonacci number:
  for (int i = 0; i < num_elements; i++){
    std::cout << fibNumberGreater(arr[i]) << std::endl;
  }

  delete[] arr;
  return 0;
}
