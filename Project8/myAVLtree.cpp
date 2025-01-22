/*
CSCI335 Spring 2023
Project 2 
Julianne Aguilar
April 10, 2024
myAVLtree.cpp defines the functions treeMedian and returnableTree
Project Description: For each of the 4 data structures: vector, list, heap, & AVL tree create functions that output 
and pop the median from a vector of integers
*/
#include "myAVLtree.hpp"

/**
 Insert elements from instructions vector, if less than or equal to current median inserted in small AVL tree,
 else inserted in large AVL tree if greater than current median. When -1 is found median is popped, median is 
 always max element in small, balances after each insert and pop, small must be 1 greater or equal to
 large
 @param: a pointer to a int vector 
 @post: outputs all the medians found and popped 
*/
void treeMedian (const std::vector<int> * instructions){
  std::vector<int> outputs;
  //Timer start
  const auto t1_start = std::chrono::steady_clock::now();
  AvlTree<int> small;
  AvlTree<int>large;
  int smallSize =0; //to keep of tree size 
  int largeSize = 0;
  int median = 0; //assuming start at 0 b/c both trees empty intially
  auto vectorItr = instructions -> begin();
  while(vectorItr != instructions -> end()){
    if(*vectorItr == -1){ //if -1 remove median & add to outputs 
      median = small.findMax();//find median 
      //add to outputs and remove from smallest 
      outputs.push_back(median);
      small.remove(median);
      smallSize -=1; //update tree size when inserting & removing
      //after removing must balance & set new median after balancing
      //balance check small must be 1 larger or equal to large, else rebalance
      int difference = smallSize - largeSize;
      if(difference < 0){ //means small has less than large
        //move smallest in large to small 
        int smallest = large.findMin();
        small.insert(smallest);
        smallSize +=1;
        large.remove(smallest);
        largeSize -=1;
      }
      else if(difference > 1){ //means smallest has more than 1 greater than large
        //move largest in small to large 
        int largest = small.findMax();
        large.insert(largest);
        largeSize +=1;
        small.remove(largest);
        smallSize -=1;
      }
      median = small.findMax();//median will always be max element in small 
    }
    else{//insert
      if(*vectorItr <= median){//value <= median add to small
        small.insert(*vectorItr);
        smallSize +=1;
      }
      else{
        large.insert(*vectorItr);
        largeSize +=1;
      }
      //balance check small must be 1 larger or equal to large, else rebalance
      int difference = smallSize - largeSize;
      if(difference < 0){ //means small has less than large
        //move smallest in large to small 
        int smallest = large.findMin();
        small.insert(smallest);
        smallSize +=1;
        large.remove(smallest);
        largeSize -=1;
      }
      else if(difference > 1){ //means smallest has more than 1 greater than large
        //move largest in small to large 
        int largest = small.findMax();
        large.insert(largest);
        largeSize +=1;
        small.remove(largest);
        smallSize -=1;
      }
      median = small.findMax(); //median will always be max element in small 
    }
    ++vectorItr;
  }
  /*
  Timer
  
  for(auto it = outputs.begin(); it != outputs.end(); ++it){
    std::cout << *it << " ";
  }
  */
 const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "algo time " << t1 << " microseconds." << std::endl;
  
 
}

/**
 Helper function that returns a int vector of medians found and popped from sorted vector, so can use assignment 
 operator "==" to check that returned vector equal the one read from the text file
 Insert elements from instructions vector, if less than or equal to current median inserted in small AVL tree,
 else inserted in large AVL tree if greater than current median. When -1 is found median is popped, median is 
 always max element in small, balances after each insert and pop, small must be 1 greater or equal to
 large
 @param: a pointer to a int vector 
 @return: returns vector of all the medians found and popped 
*/
std::vector<int> returnableTree(const std::vector<int> * instructions){
  std::vector<int> outputs;
  //Timer start const auto t1_start = std::chrono::steady_clock::now();
  AvlTree<int> small;
  AvlTree<int>large;
  int smallSize =0;
  int largeSize = 0;
  int median = 0; //assuming start at 0 b/c both trees empty intially
  auto vectorItr = instructions -> begin();
  while(vectorItr != instructions -> end()){
    if(*vectorItr == -1){ //if -1 remove median & add to outputs 
      median = small.findMax();//find median 
      //add to outputs and remove from smallest 
      outputs.push_back(median);
      small.remove(median);
      smallSize -=1;
      //after removing must balance & set new median after balancing
      //balance check small must be 1 larger or equal to large, else rebalance
      int difference = smallSize - largeSize;
      if(difference < 0){ //means small has less than large
        //move smallest in large to small 
        int smallest = large.findMin();
        small.insert(smallest);
        smallSize +=1;
        large.remove(smallest);
        largeSize -=1;
      }
      else if(difference > 1){ //means smallest has more than 1 greater than large
        //move largest in small to large 
        int largest = small.findMax();
        large.insert(largest);
        largeSize +=1;
        small.remove(largest);
        smallSize -=1;
      }
      median = small.findMax();//median will always be max element in small 
    }
    else{//insert
      if(*vectorItr <= median){//value <= median add to small
        small.insert(*vectorItr);
        smallSize +=1;
      }
      else{
        large.insert(*vectorItr);
        largeSize +=1;
      }
      //balance check small must be 1 larger or equal to large, else rebalance
      int difference = smallSize - largeSize;
      if(difference < 0){ //means small has less than large
        //move smallest in large to small 
        int smallest = large.findMin();
        small.insert(smallest);
        smallSize +=1;
        large.remove(smallest);
        largeSize -=1;
      }
      else if(difference > 1){ //means smallest has more than 1 greater than large
        //move largest in small to large 
        int largest = small.findMax();
        large.insert(largest);
        largeSize +=1;
        small.remove(largest);
        smallSize -=1;
      }
      median = small.findMax(); //median will always be max element in small 
    }
    ++vectorItr;
  }
  return outputs;
}