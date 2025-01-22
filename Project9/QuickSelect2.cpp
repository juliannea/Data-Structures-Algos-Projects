/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
QuickSelect2.cpp defines the functions QuickSelectMod, quickSelect2
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"

/**
  Finds each of the kth smallest elements inside the keys vector and moves them to it's proper index in the vector
  originally sourced from Data Structures and Algorithms textbook but with mods 
  @param: a vector with data values, int for left side of vector, int for right side of vector, a vector of keys searching for 
  @post: the vector of keys contain position 0, the 25% mark, the 50% mark, the 75% mark, and the last position of the data vector.
         the recursive portion checks whether it needs to recurse on both sides , or if it only needs to recurse on one side. Defaults 
         to insertion sort once reach size 20 or less. Credit: got help from Raitah Jinnat on how to appraoch the problem
*/
void quickSelect3( std::vector<int> & data, int left, int right, std::vector<int> keys){
  std::vector<int> leftKey;
  std::vector<int> rightKey;

  if( left + 20 <= right ){
    const int pivot = median3(data, left, right );
    // Begin partitioning
   int i = left, j = right - 1;
   for( ; ; ){
    while( data[ ++i ] < pivot ) { }
    while( pivot < data[ --j ] ) { }
    if( i < j )
    std::swap( data[ i ], data[ j ] );
    else
    break;
   }
   std::swap( data[ i ], data[ right - 1 ] ); // Restore pivot

    //iterating through the keys
   for(auto k : keys){
    if( k <= i )
      leftKey.push_back(k);
    else if( k>i+1)
      rightKey.push_back(k);
   }
   if(!leftKey.empty()){
    quickSelect3(data, left, i - 1, leftKey);
   }
   if(!rightKey.empty()){
    quickSelect3(data, i + 1, right, rightKey);
   }
  }
  else // Do an insertion sort on the subarray
    insertionSort(data);
}

/**
  Finds the 5 number summary using quickSelectMod
  @param: the header, a vector of data values 
  @post: finds the 5 number summary of the vector by calling quickSelectMod
*/
void quickSelect2 (const std::string & header, std::vector<int> data){
    int max = data.size()-1;
    std::vector<int> keys = {1, max};
    //P25 
    int P25 = ((data.size()-1)/2)/2;
    keys.push_back(P25);
    //P50 
    int P50 = .5 * (data.size()-1);  
    keys.push_back(P50);
    //P75 
    int P75 = .75 * (data.size()-1);
    keys.push_back(P75);
    quickSelect3(data, 0, data.size()-1, keys);
    
  
  
  std::cout << header << "\n";
    std::cout << "Min: " << data[0] << "\n";
    std::cout << "P25: " << data[P25] << "\n";
    std::cout << "P50: " << data[P50] << "\n";
    std::cout << "P75: " << data[P75] << "\n";
    std::cout << "Max: " << data.back()<< "\n";
  
  
   
   
}

