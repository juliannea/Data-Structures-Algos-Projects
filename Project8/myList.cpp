/*
CSCI335 Spring 2023
Project 2 
Julianne Aguilar
April 10, 2024
myList.cpp defines the functions listMedian and returnableList
Project Description: For each of the 4 data structures: vector, list, heap, & AVL tree create functions that output 
and pop the median from a vector of integers
*/
#include "myList.hpp"

/**
 Sorts instructions vector at insertion to sorted list, whenever -1 element is found adds median to outputs vector
 & pops it from vSorted vector
 @param: a pointer to a int vector 
 @post: outputs all the medians found and popped 
*/
void listMedian (const std::vector<int> * instructions){
  std::vector<int> output;
  //Timer starts: 
  const auto t1_start = std::chrono::steady_clock::now();
  std::list<int> sorted;
  auto vectorItr = instructions -> begin();
  while(vectorItr != instructions -> end()){
    if(*vectorItr == -1){//if -1 pop median from sorted & add to outputs
      int medianIndex;
      //if size is odd
      if(sorted.size() % 2 != 0){
        //equation to find median n/2 b/c we start at index 0 no need to round up 1
        medianIndex = sorted.size()/2;
      }
      //size is even median is the lesser of the two so just n/2 -1 b/c we start at 0
      else{
        medianIndex = (sorted.size()/2) -1;
      }
      //find the itr to position of median 
      auto medItr = sorted.begin();
      advance(medItr, medianIndex); //advances itr to index of median 
  
      output.push_back(*medItr);
      sorted.erase(medItr);
    }
    //inserting & sorting
    else{ //insert to list in order
      if(sorted.empty()){//if list empty make it as the head 
        sorted.push_front(*vectorItr);
      }
      else if(*vectorItr < sorted.front()){ //check if value is less than head node 
        sorted.push_front(*vectorItr); //make the value the new head 
      }
      else{
        //insert right before the first element in list w/ value greater than inserted input
        auto listItr = sorted.begin();
        bool greater = false;
        while(listItr != sorted.end() && greater == false){
          if(*vectorItr < *listItr ){
            sorted.insert(listItr, *vectorItr);
            greater = true;
          }
          ++listItr;
        }
        if(greater == false){//if greater is still false then no element in list is greater so add to back 
          sorted.push_back(*vectorItr);
        }
      }
    }
    ++vectorItr;
  }
  /*
  Timer
  */
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "algo time " << t1 << " microseconds." << std::endl;
  
  /*
  for (auto it = output.begin(); it != output.end(); ++it) { 
        std::cout << *it <<  " "; 
    } 
  */
 
  
}

/**
 Helper function that returns a int vector of medians found and popped from sorted list, so can use assignment 
 operator "==" to check that returned vector equal the one read from the text file
 Sorts instructions vector at insertion to sorted list, whenever -1 element is found adds median to outputs vector
 & pops it from vSorted vector
 @param: a pointer to a int vector 
 @return: a vector of outputs of the medians found and popped
*/
std::vector<int> returnableList(const std::vector<int> * instructions){
  std::list<int> sorted;
  std::vector<int> output;
  auto vectorItr = instructions -> begin();
  while(vectorItr != instructions -> end()){
    if(*vectorItr == -1){//if -1 pop median from sorted & add to outputs
      int medianIndex;
      //if size is odd
      if(sorted.size() % 2 != 0){
        //equation to find median n/2 b/c we start at index 0 no need to round up 1
        medianIndex = sorted.size()/2;
      }
      //size is even median is the lesser of the two so just n/2 -1 b/c we start at 0
      else{
        medianIndex = (sorted.size()/2) -1;
      }
      //find the itr to position of median 
      auto medItr = sorted.begin();
      advance(medItr, medianIndex); //advances itr to index of median 
  
      output.push_back(*medItr);
      sorted.erase(medItr);
    }
    //inserting & sorting
    else{ //insert to list in order
      if(sorted.empty()){//if list empty make it as the head 
        sorted.push_front(*vectorItr);
      }
      else if(*vectorItr < sorted.front()){ //check if value is less than head node 
        sorted.push_front(*vectorItr); //make the value the new head 
      }
      else{
        //insert right before the first element in list w/ value greater than inserted input
        auto listItr = sorted.begin();
        bool greater = false;
        while(listItr != sorted.end() && greater == false){
          if(*vectorItr < *listItr ){
            sorted.insert(listItr, *vectorItr);
            greater = true;
          }
          ++listItr;
        }
        if(greater == false){//if greater is still false then no element in list is greater so add to back 
          sorted.push_back(*vectorItr);
        }
      }
    }
    ++vectorItr;
  }
  return output;
}