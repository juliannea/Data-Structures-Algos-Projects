/*
CSCI335 Spring 2023
Project 2 
Julianne Aguilar
April 10, 2024
myVector.cpp defines the functions vectorMedian and returnableVector
Project Description: For each of the 4 data structures: vector, list, heap, & AVL tree create functions that output 
and pop the median from a vector of integers
*/
#include "myVector.hpp"

/**
 Sorts instructions vector at insertion to new vSorted vector, 
 whenever -1 element is found adds median to outputs vector & pops it from vSorted vector
 @param: a pointer to a int vector 
 @post: outputs all the medians found and popped 
*/
void vectorMedian(const std::vector<int> * instructions){
  std::vector<int> outputs; //vector store the popped medians 
  //Timer start: 
  const auto t1_start = std::chrono::steady_clock::now();
  std::vector<int> vSorted; //sorted vector 
  auto instructionsItr = instructions->begin(); //O(1)
  while(instructionsItr != instructions-> end()){ //O(n)
    //int element =  *instructionsItr;
    if(*instructionsItr == -1){  //find median, pop median 
      int medianIndex;
      //if size is odd 
      if(vSorted.size() % 2 != 0){
        //equation to find median n/2 b/c we start at index 0 no need to round up 1
        medianIndex = (vSorted.size()/2);
      }
      //size is even median is the lesser of the two so just n/2 -1 b/c we start at 0
      else{
        medianIndex = (vSorted.size()/2) -1;
      }
      //add it to outputs 
      outputs.push_back(vSorted[medianIndex]);
      //remove from sorted 
      vSorted.erase(vSorted.begin() + medianIndex);
    }
    //inserting & sorting
    else{
      std::vector<int>::iterator low;
      low = std::lower_bound(vSorted.begin(), vSorted.end(),*instructionsItr); //returns iterator equal to or greater than element 
      //if there is no element greater than or equal to means it's the largest 
      if(low == vSorted.end()){
        vSorted.push_back(*instructionsItr);
      }
      else{
        //insert at index, shifts the one greater than or equal to it, to the right 
        vSorted.insert(low, *instructionsItr);
      }
    }
    ++instructionsItr;
  }

  /*
  Timer
  */
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "algo time " << t1 << " microseconds." << std::endl;
  
  
  /*
  for(auto it = outputs.begin(); it != outputs.end(); ++it){
    std::cout << *it << " ";
  }
  */
  
  
}

/**
 Helper function that returns a int vector of medians found and popped from sorted vector, so can use assignment 
 operator "==" to check that returned vector equal the one read from the text file
 Sorts instructions vector at insertion to new vSorted vector, 
 whenever -1 element is found adds median to outputs vector & pops it from vSorted vector
 @param: a pointer to a int vector 
 @return: a vector of outputs of the medians found and popped
*/
std::vector<int> returnableVector (const std::vector<int> * instructions){
  std::vector<int> outputs; //vector store the popped medians 
  std::vector<int> vSorted; //sorted vector 
  int i = 0;
  while(i < instructions -> size()){
    int element =  instructions -> at(i); 
    //find median, pop median 
    if(element == -1){
      int medianIndex;
      //if size is odd 
      if(vSorted.size() % 2 != 0){
        //equation to find median n/2 b/c we start at index 0 no need to round up 1
        medianIndex = (vSorted.size()/2);
      
      }
      //size is even median is the lesser of the two so just n/2 -1 b/c we start at 0
      else{
        medianIndex = (vSorted.size()/2) -1;
      }
      //add it to outputs 
        outputs.push_back(vSorted[medianIndex]);
        //remove from sorted 
        vSorted.erase(vSorted.begin() + medianIndex);
    }
    //inserting & sorting
    else{
      std::vector<int>::iterator low;
      low = std::lower_bound(vSorted.begin(), vSorted.end(),element); //returns iterator equal to or greater than element 
      //if there is no element greater than or equal to means it's the largest 
      if(low == vSorted.end()){
        
        vSorted.push_back(element);
      }
      else{
        //insert at index, shifts the one greater than or equal to it, to the right 
        vSorted.insert(low, element);
      }
    }
    i++;
  }
  return outputs;
  
}

