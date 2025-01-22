#include "quickSelect.hpp"



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

void insertionSort(std::vector<int>& data, int size){
  int i, key, j;
  for(i = 1; i < size; i++){
    key = data[i];
    j = i - 1;
    // Move elements of data[0..i-1],that are greater than key, 
    //to one position ahead of their current position
    while(j >= 0 && data[j] > key){
      data[j+1] = data[j];
      j = j -1;
      data[j + 1] = key;
    }
  }
}


void quickSelect( std::vector<int> & data, int left, int right, int k ){
 
  if( left + 10 <= right ){
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
  else // Do an insertion sort on the subarray
    insertionSort(data, data.size());
  
  
}