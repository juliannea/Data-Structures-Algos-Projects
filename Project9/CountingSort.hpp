/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
CountingSort.hpp declares the functions countingSort
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

/**
  Uses counting sort to find the 5 number summary 
  @param: a string to the header, a vector of unordered numbers
  @post: inserts each value in data into a hashmap, number value is the hash key and frequency  of it is the hash value 
         then each unique number gets added to a paired vector with (value, frequency), vector is sorted, 5 number summary
         is found and outputted

*/
void countingSort (const std::string & header, std::vector<int> data);
bool hasDuplicate(std::vector<int>& nums);