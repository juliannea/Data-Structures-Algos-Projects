/*
CSCI335 Spring 2023
Project 3
Julianne Aguilar
May 7, 2024
CountingSort.cpp defines the functions countingSort
Project Description: Utilize 3 sorting alogirthms StdSort, Quick Select, Counting Sort that each output the 5 number summary
*/
#include "CountingSort.hpp"

/**
  Uses counting sort to find the 5 number summary 
  @param: a string to the header, a vector of unordered numbers
  @post: inserts each value in data into a hashmap, number value is the hash key and frequency  of it is the hash value 
         then each unique number gets added to a paired vector with (value, frequency), vector is sorted, 5 number summary
         is found and outputted
*/
void countingSort (const std::string & header, std::vector<int> data){
   //Timer start
  const auto t1_start = std::chrono::steady_clock::now();
  std::vector<std::pair<int, int> > sorted;
  std::unordered_map<int,int> hashMap;

 

  for(auto itr = data.begin(); itr != data.end(); ++itr){
    //check if already in hash map, if not then add with a freq of 1 
    if(hashMap.find(*itr) == hashMap.end()){
      hashMap.insert(std::make_pair(*itr, 1));
    }
    else{//if already exist in hashmap increase the frequency by 1
      hashMap[*itr]++;
    }
  }
  //push the key value pairs to a vector & sort the vector
  for (auto& it : hashMap) {
    std::pair<int, int> keyValue(it.first, it.second);
    sorted.push_back(keyValue);
  }
  //sort using std::sort 
  std::sort(sorted.begin(), sorted.end());
  //finding counts for  P25, P50, P75,
  int P25Count = .25 * (data.size()-1);
  int P50Count = .50 * (data.size()-1);
  int P75Count = .75 * (data.size()-1);

  int P25 = 0;
  int P50 = 0;
  int P75 = 0;

  int counter = 0;
 
  for(auto values: sorted){
    counter += values.second; //the data points/frequency that the key value occurs 
    if(P25 == 0 && counter > P25Count){ //if P25 not already found & the counter became greater than the P25 count
      P25 = values.first;
    }
    else if(P50 == 0 && counter > P50Count){
      P50 = values.first;
    }
    else if(P75 == 0 && counter > P75Count){
      P75 = values.first;    
    }
  }
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "algo time " << t1 << " microseconds." << std::endl;

  /*
  std::cout << header << "\n";
  std::cout << "Min: " << sorted[0].first << "\n";
  std::cout << "P25: " << P25 << "\n";
  std::cout << "P50: " << P50 << "\n";
  std::cout << "P75: " << P75 << "\n";
  std::cout << "Max: " << sorted.back().first << "\n";
  std::cout << "Unique: " << sorted.size() << "\n";
  */
  
  


}


bool hasDuplicate(std::vector<int>& nums) {
      std::vector<std::pair<int, int>> check;
      std::unordered_map<int,int> hash_map;
      
      for(auto itr = nums.begin(); itr != nums.end(); ++itr){
        std::cout << "num: " << *itr << "\n";
        if(hash_map.find(*itr) == hash_map.end()){
          std::cout << "not found\n";
            hash_map.insert(std::make_pair(*itr,1));
        }
        else{
          std::cout << "not found\n";
            hash_map[*itr]++;
        }
      }

      for(auto& it: hash_map){
        std::pair<int,int> keyValue(it.first,it.second);
        check.push_back(keyValue);
      }
      for(auto freq: check){
        if(freq.second != 1){
            return true;
        }
      }
      return false;
    }