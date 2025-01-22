#include <iostream>
#include <vector>
#include <algorithm>

/**
  Finds each of the kth smallest elements inside the keys vector and moves them to it's proper index in the vector
  originally sourced from Data Structures and Algorithms textbook but with mods 
  @param: a vector with data values, int for left side of vector, int for right side of vector, a vector of keys searching for 
  @post: the vector of keys contain position 0, the 25% mark, the 50% mark, the 75% mark, and the last position of the data vector.
         the recursive portion checks whether it needs to recurse on both sides , or if it only needs to recurse on one side. Defaults 
         to insertion sort once reach size 20 or less. Credit: got help from Raitah Jinnat on how to appraoch the problem
*/
void quickSelect3( std::vector<int> & data, int left, int right, std::vector<int> keys);
/**
  Finds the 5 number summary using quickSelectMod
  @param: the header, a vector of data values 
  @post: finds the 5 number summary of the vector by calling quickSelectMod
*/
void quickSelect2 (const std::string & header, std::vector<int> data);

