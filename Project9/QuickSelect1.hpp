/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
QuickSelect1.cpp declares the functions QuickSelect1, quickSelect
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "InsertionSort.hpp"

/**
 Finds the kth smallest number in data vector and puts it in it's right index 
 Sourced from Data Structures and Algorithms textbook
 @param: data vector, int for left side of vector, int for right side of vector, int k for the kth smallest value 
 @post: Internal selection method that makes recursive calls, Uses median-of-three partitioning and a cutoff of 10,
        Places the kth smallest item in data[k-1], defaults to insertion sort when vector size less then 20
*/
void quickSelect( std::vector<int> & a, int left, int right, int k );

/**
 Finds the 5 number summary by using quickSelect
 @param: header and int vector of data values 
 @post: using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. 
 This will give the median, around which the vector will be partitioned. Then, call quickSelect on the half of the vector before the median with the 25% mark of the vector as k.
 Then, call quickSelect on the half of the vector after the median with the 75% mark as k. Then, search for the minimum only before the 25% mark, 
 and the maximum only after the 75% mark.
*/
void quickSelect1 (const std::string & header, std::vector<int> data);