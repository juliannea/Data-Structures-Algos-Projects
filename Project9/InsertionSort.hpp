/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
InsertionSort.hpp declares the functions insertionSort and median3
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include <iostream>
#include <vector>

/**
 Sourced from geeksforgeeks, sorts vector using insertion sort 
 @param: a int vector of data values, size of vector 
 @post: data vector is sorted from least to greatest
*/
void insertionSort(std::vector<int>& a);

/**
 Finds the median of the left, center, and right of a vector 
 @param: a int vector of data values, an int representing the left side of vector, int representing 
         right side of vector 
 @return: returns the chosen pivot of the vector by using median of three partitioning
*/
const int & median3(std::vector<int> & a, int left, int right );

std::vector<int> createSubVector(const std::vector<int>& originalVector, int leftIndex, int rightIndex);