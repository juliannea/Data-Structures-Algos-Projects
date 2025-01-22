/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
InsertionSort.cpp defines the functions insertionSort and median3
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include "InsertionSort.hpp"

/**
 Sourced from Data Structures and Algos textbook, sorts vector using insertion sort 
 @param: a int vector of data values, size of vector 
 @post: data vector is sorted from least to greatest
*/
void insertionSort(std::vector<int>& a){
  for( int p = 1; p < a.size( ); ++p ){
    int tmp = std::move( a[ p ] );
    int j;
    for( j = p; j > 0 && tmp < a[ j - 1 ]; --j ){
      a[ j ] = std::move( a[ j - 1 ] );
      a[ j ] = std::move( tmp );
    }
  }
}



/**
 Finds the median of the left, center, and right of a vector 
 @param: a int vector of data values, an int representing the left side of vector, int representing 
         right side of vector 
 @return: returns the chosen pivot of the vector by using median of three partitioning
*/
const int & median3(std::vector<int> & a, int left, int right )
{
  int center = ( left + right ) / 2;
  if( a[ center ] < a[ left ] )
  std::swap( a[ left ], a[ center ] );
  if( a[ right ] < a[ left ] )
 std::swap( a[ left ], a[ right ] );
 if( a[ right ] < a[ center ] )
 std::swap( a[ center ], a[ right ] );
 // Place pivot at position right - 1
 std::swap( a[ center ], a[ right - 1 ] );
 return a[ right - 1 ];
}

std::vector<int> createSubVector(const std::vector<int>& originalVector, int leftIndex, int rightIndex) {
    // Check if the indices are valid
    if (leftIndex < 0 || rightIndex >= originalVector.size() || leftIndex > rightIndex) {
        // Return an empty vector or handle the error accordingly
        return {};
    }
    
    // Create a new vector using iterators from the original vector
    return std::vector<int>(originalVector.begin() + leftIndex, originalVector.begin() + rightIndex + 1);
}

