#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

void printVector(const std::vector<int>& vec) {
    // Loop through each element in the vector and print it
    for (int element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main(){
  //reading file 
  std::string header;
  std::vector<int> data;
  std::string filename = "test_input.txt";
  std::ifstream fin(filename);
  if (!fin.is_open()) {
      std::cerr << "Error: Unable to open file " << filename << std::endl;  
    }
  else{
   std::string line;
   getline(fin, header);
   getline(fin, line);
   std::istringstream iss(line);
   int num;
   while (iss >> num) {
    data.push_back(num);
   }
   fin.close(); // Close the file
  }
  /*---------------------------------------------------------------------------------*/
                            //Quick Sort test case
  std::cout << "---------------------------------------------------\n";
  std::cout << "std::sort test\n";
  stdSort(header, data);
  /*---------------------------------------------------------------------------------*/
                           /* Insertion Sort test*/
  std::cout << "---------------------------------------------------\n";
                
  std::cout << "        insertion sort test\n";
  std::vector<int> insert = { 12, 11, 13, 5, 6 };
  //insertionSort(insert, insert.size());
  printVector(insert);
  /*------------------------------------------------------------------------------*/
                             /* kth smallest test*/
  std::cout << "-----------------------------------------------------\n";
  std::cout << "             kth smalles test\n";

  quickSelect1(header,data);
  /*-------------------------------------------------------------*/
                    /* Quick Select 1 test*/
  std::cout << "-----------------------------------------------------\n";
  std::cout << "             Quick Select 1\n";
  quickSelect1(header, data);

  
   /*-------------------------------------------------------------*/
                    /* Quick Select 12test*/
  
  
   std::cout << "-----------------------------------------------------\n";
  std::vector<int> select2 = {2,10,5,7,9,3,1,4,8,6};
  quickSelect2(header, data);     
  /*-------------------------------------------------------------*/
                    /* Counting Sort */
  std::cout << "-----------------------------------------------------\n";
  std::cout << "             Counting Sort test\n";
  std::cout << "\nvector test\n";
  countingSort(header,data);

  
  
   std::cout << "-----------------------------------------------------\n";
  std::cout << "             1K test\n";
  
  //std::cout << "std::Sort: \n";
  //stdSort(header, data);
  std::cout << "\nselect1 \n";
  quickSelect1(header,data);
   std::cout << "\nselect2: \n";
  quickSelect2(header, data);
  
  
  
  
   std::cout << "\ncountingSort: \n";
  countingSort(header, data);

  std::cout << "-----------------------------------------------------\n";
  std::cout << "             100K test\n";
  //reading file 
  std::string header2;
  std::vector<int> data2;
  std::string filename2 = "test_input2.txt";
  std::ifstream fin2(filename2);
  if (!fin2.is_open()) {
      std::cerr << "Error: Unable to open file " << filename2 << std::endl;  
    }
  else{
   std::string line2;
   getline(fin2, header2);
   getline(fin2, line2);
   std::istringstream iss2(line2);
   int num2;
   while (iss2 >> num2) {
    data2.push_back(num2);
   }
   fin2.close(); // Close the file
  }



  std::cout << "std::Sort: \n";
  stdSort(header2, data2);
  std::cout << "\nselect1 \n";
  quickSelect1(header2,data2);
   std::cout << "\nselect2: \n";
  quickSelect2(header2, data2);
  
 
 
   std::cout << "\ncountingSort: \n";
  countingSort(header2, data2);


  /*
   std::cout << "-----------------------------------------------------\n";
  std::cout << "             10 mil test\n";
  //reading file 
  std::string header3;
  std::vector<int> data3;
  std::string filename3 = "test_input3.txt";
  std::ifstream fin3(filename3);
  if (!fin3.is_open()) {
      std::cerr << "Error: Unable to open file " << filename3 << std::endl;  
    }
  else{
   std::string line3;
   getline(fin3, header3);
   getline(fin3, line3);
   std::istringstream iss3(line3);
   int num3;
   while (iss3 >> num3) {
    data3.push_back(num3);
   }
   fin3.close(); // Close the file
  }

  //std::cout << "std::Sort: \n";
  //stdSort(header3, data3);
  
  std::cout << "\ncountingSort: \n";
  countingSort(header3, data3);
  
 //  std::cout << "\nselect2: \n";
 // quickSelect2(header3, data3);

 // std::cout << "\nselect1 \n";
 // quickSelect1(header3,data3);
  
  
  
  */
  std::cout << "-----------------------------------------------------\n";
  std::vector<int> test;
  test.push_back(1);
  test.push_back(2);
  test.push_back(3);
  test.push_back(3);
  std::cout << std::boolalpha << hasDuplicate(test) << "\n";
 


}