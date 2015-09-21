# include <algorithm>
# include <iostream>
# include <fstream>
# include <istream>
void copy(int* input, int* pool,  int low, int high ){
  //  std::cin.get();
  for(int k = low; k<=high; k++){
    input[k] = pool[k];
    //    std::cout<<k<<": "<<pool[k]<<std::endl;

  }

}

void metaMerge(int* input, int* pool, int low, int leftMiddle,
	       int rightMiddle, int high){
  // std::cout<<"merging: "<<low<<" "<<high<<std::endl;
  // std::cout<<"leftMiddle: "<<leftMiddle<<" rightMiddle"<<rightMiddle<<std::endl;

  // Note there are three cases:   
  
  for(int k = low, i = low, j = rightMiddle; k<=high; k++){
    // std::cout<<"k: "<<k<<std::endl;
    // std::cout<<"input[i]: "<<input[i]<<std::endl;
    // std::cout<<"input[j]: "<<input[j]<<std::endl;
    if(i>leftMiddle){
      while(k<=high){
	pool[k] = input[j];
	j++;
	k++;
      }
      copy(input, pool, low, high);
      return;
    }else if(j>high){
      // pool[k] = input[i];
      // i++;
      while(k<=high){
	pool[k] = input[i];
	i++;
	k++;
      }
      copy(input, pool, low, high);
      return;
    }else{
      if(input[i]<=input[j]){
	pool[k] = input[i];
	i++;
      }else{
	pool[k] = input[j];
	j++;
      }
    }
  }
  copy(input, pool, low, high);
  return;
}


void mergeSort(int* input, int* pool, int low, int high){
  // std::cin.get();
  // std::cout<<"low: "<<low<<" high:"<<high<<std::endl;
  if(high == low){
    return;
  }else{
    // left: 
    // always floored, since they are integers
    int middle = (high - low)/2;
    // int leftMiddle = low + floor((high - low)/2);
    //    mergeSort(input, pool, low, leftMiddle);
    mergeSort(input, pool, low, low + middle);
    // std::cout<<"half finish "<<std::endl;
    // right:
    // int rightMiddle = low + ceil((high - low)/2);
    // std::cout<<"right middle "<<rightMiddle<<std::endl;
    // mergeSort(input, pool, rightMiddle, high);

    mergeSort(input, pool, low + middle + 1, high);
    
    // merge: 
    // metaMerge(input, pool, low, leftMiddle,
    // 	      rightMiddle, high);
    metaMerge(input, pool, low, low + middle,
	      low + middle + 1, high);
  }

}

void countInversionMerge(int* input, int* pool, int low, int leftMiddle,
			 int rightMiddle, int high,
			 long* numberInversion){
  // std::cout<<"merging: "<<low<<" "<<high<<std::endl;
  // std::cout<<"leftMiddle: "<<leftMiddle<<" rightMiddle"<<rightMiddle<<std::endl;

  // Note there are three cases:   
  
  for(int k = low, i = low, j = rightMiddle; k<=high; k++){
    // std::cout<<"k: "<<k<<std::endl;
    // std::cout<<"input[i]: "<<input[i]<<std::endl;
    // std::cout<<"input[j]: "<<input[j]<<std::endl;
    if(i>leftMiddle){
      while(k<=high){
	pool[k] = input[j];
	j++;
	k++;
      }
      copy(input, pool, low, high);
      return;
    }else if(j>high){
      // pool[k] = input[i];
      // i++;
      while(k<=high){
	pool[k] = input[i];
	i++;
	k++;
	// *numberInversion += leftMiddle - i + 1;
      }
      copy(input, pool, low, high);
      return;
    }else{
      if(input[i]<=input[j]){
	// left to array: normal case 
	pool[k] = input[i];
	i++;
      }else{
	// right to array: this is the only case when inversion happens:  
	pool[k] = input[j];
	j++;
	*numberInversion += leftMiddle - i + 1;
      }
    }
  }
  copy(input, pool, low, high);
  return;
}


void countInversion(int* input, int* pool, int low, int high,
		    long* numberInversion){
  // std::cin.get();
  // std::cout<<"low: "<<low<<" high:"<<high<<std::endl;
  if(high == low){
    return;
  }else{
    // left: 
    // always floored, since they are integers
    int middle = (high - low)/2;
    // int leftMiddle = low + floor((high - low)/2);
    //    mergeSort(input, pool, low, leftMiddle);
    countInversion(input, pool, low, low + middle, numberInversion);
    // std::cout<<"half finish "<<std::endl;
    // right:
    // int rightMiddle = low + ceil((high - low)/2);
    // std::cout<<"right middle "<<rightMiddle<<std::endl;
    // mergeSort(input, pool, rightMiddle, high);

    countInversion(input, pool, low + middle + 1, high, numberInversion);
    
    // merge: 
    // metaMerge(input, pool, low, leftMiddle,
    // 	      rightMiddle, high);
    countInversionMerge(input, pool, low, low + middle,
			low + middle + 1, high, 
			numberInversion);
  }

}

int main(int argc, char ** argv )
{
  if(argc == 2){
    std::cout << "Openning file: ..."<<std::endl;
  }else{
    std::cout << "Usage: "<<argv[0]<<" 'dataSourceFile.txt' "<<std::endl;
    exit(0);
  }

  std::ifstream integerReader;
  integerReader.open(argv[1], std::ios::in);

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
    int * playGround = new int[linesN];     
    int pos_reading = integerReader.tellg();
    std::cout<<"The reader position is: "<<pos_reading<<std::endl;
    
    //    integerReader.seekg(0, integerReader.beg);
    integerReader.seekg(0);
    int post_reading = integerReader.tellg();
    std::cout<<"The reader position is: "<<post_reading<<std::endl;

    if((inputBuffer!=NULL)&&(playGround!=NULL)){
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
    long numberInversion = 0;
    countInversion(inputBuffer, playGround, 0, (linesN - 1), &numberInversion);


    std::cout<<" Sorted ! "<<std::endl;

    //-----------
    // std::cout<<"test output: "<<std::endl;
    // for(int i = 0; i < linesN; i++){

    //   std::cout<<inputBuffer[i];
    //   std::cout<<std::endl;
    //   // std::cout<<playGround[i];
    //   // std::cout<<" ";
    
    // }
    std::cout<<std::endl;
    std::cout<<" The number of inversions is: "<<numberInversion<<std::endl;

    free(inputBuffer);
    free(playGround);
    
  }

  exit(0);
}
