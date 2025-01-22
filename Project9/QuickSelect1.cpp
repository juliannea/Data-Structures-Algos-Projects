/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
QuickSelect1.cpp defines the functions QuickSelect1, quickSelect
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"


void printVector(const std::vector<int>& vec, int endIndex) {
    // Check if endIndex is valid
    if (endIndex < 0 || endIndex >= vec.size()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    // Print elements up to the specified index
    for (int i = 0; i <= endIndex; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
/**
 Finds the kth smallest number in data vector and puts it in it's right index
 Sourced from Data Structures and Algorithms textbook
 @param: data vector, int for left side of vector, int for right side of vector, int k for the kth smallest value 
 @post: Internal selection method that makes recursive calls, Uses median-of-three partitioning and a cutoff of 10,
        Places the kth smallest item in data[k-1], defaults to insertion sort when vector size less then 20
*/
void quickSelect( std::vector<int> & data, int left, int right, int k ){
  if( left + 20 <= right ){
    const int pivot = median3(data, left, right );
    // Begin partitioning
    int i = left, j = right - 1;
    for( ; ; )
    {
    while( data[ ++i ] < pivot ) { }
    while( pivot < data[ --j ] ) { }
    if( i < j )
    std::swap( data[ i ], data[ j ] );
    else
    break;
  }

  std::swap( data[ i ], data[ right - 1 ] ); // Restore pivot
  // Recurse; only this part changes
  if( k <= i )
  quickSelect( data, left, i - 1, k );
  else if( k>i+1)
  quickSelect( data, i + 1, right, k );
}
else{
  std::vector<int> vectorSub;
  vectorSub = createSubVector(data, left, right);
  insertionSort(data);
}

    
  
    
  
}

/**
 Finds the 5 number summary by using quickSelect
 @param: header and int vector of data values 
 @post: using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. 
 This will give the median, around which the vector will be partitioned. Then, call quickSelect on the half of the vector before the median with the 25% mark of the vector as k.
 Then, call quickSelect on the half of the vector after the median with the 75% mark as k. Then, search for the minimum only before the 25% mark, 
 and the maximum only after the 75% mark.
*/
void quickSelect1 (const std::string & header, std::vector<int> data){
  //P50 
  int P50 = .5 * (data.size()-1);
  quickSelect(data, 0, data.size()-1, P50);


  
  //P25 
  int P25 = (P50-1)/2;
  quickSelect(data, 0, P50 , P25+1);

  //P75 
  int P75 = .75 * (data.size()-1);
  quickSelect(data, P50 , data.size()-1, P25); //for right side of vector of median, passing P25 b/c same for finding index for P75

  auto itr25 = data.begin();
  std::advance(itr25, P25-1);
  auto min = min_element(data.begin(), itr25);

  auto itr75 = data.begin();
  std::advance(itr75, P75-1);
  auto max = max_element(itr75, data.end());

  
  std::cout << header << "\n";
  std::cout << "Min: " << *min << "\n";
  std::cout << "P25: " << data[P25] << "\n";
  std::cout << "P50: " << data[P50] << "\n";
  std::cout << "P75: " << data[P75] << "\n";
  std::cout << "Max: " << *max << "\n";
 
  
  

  
  
}


