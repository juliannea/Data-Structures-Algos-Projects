/*
CSCI335 Spring 2023
Project 2 
Julianne Aguilar
April 10, 2024
myList.cpp defines the functions listMedian and returnableList
Project Description: For each of the 4 data structures: vector, list, heap, & AVL tree create functions that output 
and pop the median from a vector of integers
*/
#ifndef myList_HPP
#define myList_HPP
#include <list>
#include <iostream>
#include <chrono>
#include <algorithm>

/**
 Sorts instructions vector at insertion to sorted list, whenever -1 element is found adds median to outputs vector
 & pops it from vSorted vector
 @param: a pointer to a int vector 
 @post: outputs all the medians found and popped 
*/
void listMedian (const std::vector<int> * instructions);

/**
 Helper function that returns a int vector of medians found and popped from sorted list, so can use assignment 
 operator "==" to check that returned vector equal the one read from the text file
 Sorts instructions vector at insertion to sorted list, whenever -1 element is found adds median to outputs vector
 & pops it from vSorted vector
 @param: a pointer to a int vector 
 @return: a vector of outputs of the medians found and popped
*/
std::vector<int> returnableList (const std::vector<int> * instructions);


#endif