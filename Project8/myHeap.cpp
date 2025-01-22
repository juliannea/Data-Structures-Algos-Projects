/*
CSCI335 Spring 2023
Project 2 
Julianne Aguilar
April 10, 2024
myHeap.cpp defines the functions heaprMedian and returnableHeap
Project Description: For each of the 4 data structures: vector, list, heap, & AVL tree create functions that output 
and pop the median from a vector of integers
*/
#include "myHeap.hpp"
#include <cmath>

/**
 Insert elements from instructions vector, if less than or equal to current median inserted in maxHeap,
 else inserted in minHeap if greater than current median. When -1 is found median is popped, median is 
 always max element in maxHeap, balances after each insert and pop, maxHeap must be 1 greater or equal to
 minHeap 
 @param: a pointer to a int vector 
 @post: outputs all the medians found and popped 
*/
void heapMedian (const std::vector<int> * instructions){
  std::vector<int> outputs;
  //Timer start: 
  const auto t1_start = std::chrono::steady_clock::now();
  std::priority_queue<int> maxHeap; 
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  int median; //0 b/c both queues initally empty 

  auto vectorItr = instructions -> begin();
  while(vectorItr != instructions -> end()){
    if(*vectorItr == -1){//check if -1
      median = maxHeap.top(); // find median, median will always be the max element in small (maxHeap)
      //add to ouputs and remove from max 
      outputs.push_back(median);
      maxHeap.pop();
      //after removing must balance & set new median after balancing
      //check if size differs at most by 1, if not balance by adding top of greater size to lesser 
      int difference = maxHeap.size() - minHeap.size();
      if(difference < 0){ //then small has less than large small = maxHeap large = minHeap
        //move smallest in large (minHeap) to small (maxHeap)
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
      else if(difference > 1){//then small (maxHeap) has more than 1 greater than large (minHeap)
        //move largest in small (maxHeap) to large(minHeap)
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
      //set new median
      median = maxHeap.top();
    }
    else{
      //inserting 
      //compare insertion with current median 
      if(*vectorItr > median){ //greater than median add to minHeap
        minHeap.push(*vectorItr);
      }
      else{
        maxHeap.push(*vectorItr);
      }
      //balancing
      //check if size differs at most by 1, if not balance by adding top of greater size to lesser 
      int difference = maxHeap.size() - minHeap.size();
      if(difference < 0){ //then small has less than large small = maxHeap large = minHeap
        //move smallest in large (minHeap) to small (maxHeap)
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
      else if(difference > 1){//then small has more than 1 greater than large 
        //move largest in small (maxHeap) to large(minHeap)
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
      //median will always be the max element in small (maxHeap)
      median = maxHeap.top();
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
  for(auto it = outputs.begin(); it != outputs.end(); ++it){
    std::cout << *it << " ";
  }
  */
 
  
 
}

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
std::vector<int> returnableHeap (const std::vector<int> * instructions){
  std::priority_queue<int> maxHeap; 
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  std::vector<int> outputs;
  int median; //0 b/c both queues initally empty 

  auto vectorItr = instructions -> begin();
  while(vectorItr != instructions -> end()){
    if(*vectorItr == -1){//check if -1
      median = maxHeap.top(); // find median, median will always be the max element in small (maxHeap)
      //add to ouputs and remove from max 
      outputs.push_back(median);
      maxHeap.pop();
      //after removing must balance & set new median after balancing
      //check if size differs at most by 1, if not balance by adding top of greater size to lesser 
      int difference = maxHeap.size() - minHeap.size();
      if(difference < 0){ //then small has less than large small = maxHeap large = minHeap
        //move smallest in large (minHeap) to small (maxHeap)
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
      else if(difference > 1){//then small (maxHeap) has more than 1 greater than large (minHeap)
        //move largest in small (maxHeap) to large(minHeap)
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
      //set new median
      median = maxHeap.top();
    }
    else{
      //inserting 
      //compare insertion with current median 
      if(*vectorItr > median){ //greater than median add to minHeap
        minHeap.push(*vectorItr);
      }
      else{
        maxHeap.push(*vectorItr);
      }
      //balancing
      //check if size differs at most by 1, if not balance by adding top of greater size to lesser 
      int difference = maxHeap.size() - minHeap.size();
      if(difference < 0){ //then small has less than large small = maxHeap large = minHeap
        //move smallest in large (minHeap) to small (maxHeap)
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
      else if(difference > 1){//then small has more than 1 greater than large 
        //move largest in small (maxHeap) to large(minHeap)
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
      //median will always be the max element in small (maxHeap)
      median = maxHeap.top();
    }
    ++vectorItr;
  }

  /*
  for(auto it = outputs.begin(); it != outputs.end(); ++it){
    std::cout << *it << " ";
  }
  */
  
  return outputs;
}