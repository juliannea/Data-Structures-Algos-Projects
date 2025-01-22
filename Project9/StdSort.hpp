/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
StdSort.hpp declares the functions stdSort
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include <iostream>
#include <algorithm>

/**
 Finds the 5 number summary using std::sort 
 @param: a string of the header, and int vector of data values 
 @post: sorts the data vector using std::sort and finds & outputs the 5 number summary
*/
void stdSort (const std::string & header, std::vector<int> data);