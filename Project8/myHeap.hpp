/*
CSCI335 Spring 2023
Project 2 
Julianne Aguilar
April 10, 2024
myHeap.hpp declares the functions heaprMedian and returnableHeap
Project Description: For each of the 4 data structures: vector, list, heap, & AVL tree create functions that output 
and pop the median from a vector of integers
*/
#ifndef myHeap_HPP
#define myHeap_HPP
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <chrono>

/**
 Insert elements from instructions vector, if less than or equal to current median inserted in maxHeap,
 else inserted in minHeap if greater than current median. When -1 is found median is popped, median is 
 always max element in maxHeap, balances after each insert and pop, maxHeap must be 1 greater or equal to
 minHeap 
 @param: a pointer to a int vector 
 @post: outputs all the medians found and popped 
*/
void heapMedian (const std::vector<int> * instructions);

/**
 Helper function that returns a int vector of medians found and popped from sorted vector, so can use assignment 
 operator "==" to check that returned vector equal the one read from the text file
 Insert elements from instructions vector, if less than or equal to current median inserted in maxHeap,
 else inserted in minHeap if greater than current median. When -1 is found median is popped, median is 
 always max element in maxHeap, balances after each insert and pop, maxHeap must be 1 greater or equal to
 minHeap 
 @param: a pointer to a int vector 
 @return: returns vector of medians found and popped
*/
std::vector<int> returnableHeap (const std::vector<int> * instructions);

#endif