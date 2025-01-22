#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"

std::vector<int> fileVector(std::string file){
  //Reading text file 
  std::vector<int> mainVector;
  // open file
  std::string filename = file;
  std::ifstream fin(filename);
   if (!fin.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;  
    }

  // define expected format
  std::string line;
  std::string instruction;
  std::string value;

  //Reading the file 
  while(getline(fin,line)){
    std::istringstream iss(line);
    iss >> instruction >> value; //instruction = "pop" or "insert" value = "#" or "median"
    //if instruction is a insert 
    if(instruction == "insert"){
      int num = std::stoi(value);
      mainVector.push_back(num);
    }
    //if instruction is a pop insert -1 
    if(instruction == "pop"){
      mainVector.push_back(-1);
    }
  }
  return mainVector;
}
int main(){
   //--------------------------------------------------------------------------------------------
  //                                  reading file 
  //Reading text file 
  std::vector<int> mainVector;
  // open file
  std::string filename = "testinput.txt";
  std::ifstream fin(filename);
   if (!fin.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return 1; // Exit the program with an error code
    }

  // define expected format
  std::string line;
  std::string instruction;
  std::string value;

  //Reading the file 
  while(getline(fin,line)){
    std::istringstream iss(line);
    iss >> instruction >> value; //instruction = "pop" or "insert" value = "#" or "median"
    //if instruction is a insert 
    if(instruction == "insert"){
      int num = std::stoi(value);
      mainVector.push_back(num);
    }
    //if instruction is a pop insert -1 
    if(instruction == "pop"){
      mainVector.push_back(-1);
    }
  }
  
  //--------------------------------------------------------------------------------------------
  //                                  read input test
  //testing to see if read file correctly by reading input integer file and adding to a vector to be used as reference to a correct vector
  std::vector<int> numbers;
  std::string testIntegerFormat = "testinput_in_integer_format.txt";
  std::ifstream fin2(testIntegerFormat);
  while(getline(fin2, testIntegerFormat)){
     std::istringstream iss(testIntegerFormat); // Create a stringstream from the line
            int number;
            while (iss >> number) { // Read each number from the stringstream
                numbers.push_back(number); // Add the number to the vector
            }
  }
 //--------------------------------------------------------------------------------------------
 //                           Read median output test 
 //used for testing, vector will contain the correct medians from file
  std::vector<int> numbers2;
  std::string testIntegerFormat2 = "testinput_medians.txt";
  std::ifstream fin3(testIntegerFormat2);
  while(getline(fin3, testIntegerFormat2)){
     std::istringstream iss(testIntegerFormat2); // Create a stringstream from the line
            int number2;
            while (iss >> number2) { // Read each number from the stringstream
                numbers2.push_back(number2); // Add the number to the vector
            }
  }
  
//--------------------------------------------------------------------------------------------
 //testing to see if both vectors equal each other 
 std::cout << "--------------------------------------------\n";
 std::cout << "adding to main vector test\n";
 if(mainVector == numbers){
  std::cout << "EQUAL \n";
 }
 
 

 //--------------------------------------------------------------------------------------------
 //                              Vector testing
 if(returnableVector(&mainVector) == numbers2){
  std::cout << "median vectors EQUAL \n";
 }
 else{
  std::cout << "BOOO\n";
 }
 vectorMedian(&mainVector);
 //--------------------------------------------------------------------------------------------
 //                                       List testing 
 std::cout << "\n--------------------------------------------\n";
 if(returnableList(&mainVector) == numbers2){
  std::cout << "AVL median lists EQUAL\n";
 }
 listMedian(&mainVector);
 //--------------------------------------------------------------------------------------------
 //                               Heap Testing

std::cout << "\n--------------------------------------------\n";
std::cout << "Heap testfile test\n";
if(returnableHeap(&mainVector) == numbers2){
  std::cout << "median vectors EQUAL \n";
}
else{
  std::cout << "OH NOO\n";
}

heapMedian(&mainVector);

  //--------------------------------------------------------------------------------------------
 //            AVL Tree testing
  std::cout << "\n--------------------------------------------\n";
  std::cout << "median file testing \n";
  //treeMedian(&mainVector);
  treeMedian(&mainVector);
  if(returnableTree(&mainVector) == numbers2){
    std::cout << "CONGRATS\n";
  }
  else{
    std::cout << "NOO WHYY :(\n";
  }
                       
  //treeMedian(&mainVector);
  //--------------------------------------------------------------------------------------------
 //                                 Reading input files 
  std::vector<int> input1 = fileVector("input1.txt");
  std::vector<int> input2 = fileVector("input2.txt");
  std::vector<int> input3 = fileVector("input3.txt");
 
 /*
  //--------------------------------------------------------------------------------------------
 //                              Vector timings
 std::cout << "\n-----------------------------------------------------------------\n";
 std::cout << "                          Vector timings \n";
 std::cout << "input1 size: " << input1.size() << "\n";
 std::cout << "Input 1 vector: \n";
 vectorMedian(&input1);
 std::cout << "\n--------------------------------------------\n";
  std::cout << "input 2 size: " << input2.size() << "\n";
 std::cout << "Input 2 vector: \n";
 vectorMedian(&input2);
 std::cout << "\n--------------------------------------------\n";
 std::cout << "Input 3 vector: \n";
 std::cout << "input3 size: " << input3.size() << "\n";
 vectorMedian(&input3);

  //--------------------------------------------------------------------------------------------
 //                              List timings
 std::cout << "\n-----------------------------------------------------------------\n";
 std::cout << "                            List timings \n";
 std::cout << "input1 size: " << input1.size() << "\n";
 std::cout << "Input 1 list: \n";
 listMedian(&input1);
 std::cout << "\n--------------------------------------------\n";
  std::cout << "input 2 size: " << input2.size() << "\n";
 std::cout << "Input 2 list: \n";
 listMedian(&input2);
 std::cout << "\n--------------------------------------------\n";
 std::cout << "Input 3 list: \n";
 std::cout << "input3 size: " << input3.size() << "\n";
 listMedian(&input3);

 //--------------------------------------------------------------------------------------------
 //                              Heap timings
 std::cout << "\n-----------------------------------------------------------------\n";
 std::cout << "                            Heap timings \n";
 std::cout << "input1 size: " << input1.size() << "\n";
 std::cout << "Input 1 heap: \n";
 heapMedian(&input1);
 std::cout << "\n--------------------------------------------\n";
  std::cout << "input 2 size: " << input2.size() << "\n";
 std::cout << "Input 2 heap: \n";
 heapMedian(&input2);
 std::cout << "\n--------------------------------------------\n";
 std::cout << "Input 3 heap: \n";
 std::cout << "input3 size: " << input3.size() << "\n";
 heapMedian(&input3);
 */
 
 
 //--------------------------------------------------------------------------------------------
 //                              AVL timings
 
 
 std::cout << "\n-----------------------------------------------------------------\n";
 std::cout << "                            AVL timings \n";
 std::cout << "input1 size: " << input1.size() << "\n";
 std::cout << "Input 1 AVL: \n";
 treeMedian(&input1);
 std::cout << "\n--------------------------------------------\n";
  std::cout << "input 2 size: " << input2.size() << "\n";
 std::cout << "Input 2 AVL: \n";
 treeMedian(&input2);
 std::cout << "\n--------------------------------------------\n";
 std::cout << "Input 3 AVL: \n";
 std::cout << "input3 size: " << input3.size() << "\n";
 treeMedian(&input3);
 
 
 
 
 
 std::cout << "median testing\n";
   std::vector<int> vtree = {5,2,8,10,1,7,-1,6,-1,-1};
   treeMedian(&vtree);
 
 
  
}

