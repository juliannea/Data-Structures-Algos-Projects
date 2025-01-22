/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
StdSort.cpp defines the functions stdSort
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include "StdSort.hpp"
#include <vector>

/**
 Finds the 5 number summary using std::sort 
 @param: a string of the header, and int vector of data values 
 @post: sorts the data vector using std::sort and finds & outputs the 5 number summary
*/
void stdSort (const std::string & header, std::vector<int> data){
  int min, P25, P50, P75, max;

  //sort vector with std::sort 
  std::sort(data.begin(), data.end());
  //min = first element 
  min = data.front();
  //P25
  int index25 = .25 * (data.size()-1); 
  P25 = data[index25]; 
  //P50
  int index50 = .50 * (data.size()-1);
  P50 = data[index50]; 
  //P75
  int index75 = .75 * (data.size()-1);
  P75 = data [index75];
  //max
  max = data.back();

  
    std::cout << header << "\n";
  std::cout << "Min: " << min << "\n";
  std::cout << "P25: " << P25 << "\n";
  std::cout << "P50: " << P50 << "\n";
  std::cout << "P75: " << P75 << "\n";
  std::cout << "Max: " << max << "\n";
  

  
}
