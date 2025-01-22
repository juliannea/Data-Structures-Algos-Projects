#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "Book.hpp"
#include "MoveAll.hpp"
#include "quickSelect.hpp"
//----------------------------
  //helper function to print every book in either catalog or cart 
void printContainer(std::vector<Book> container){
  for(std::vector<Book>::iterator itr = container.begin(); itr != container.end(); itr++){
    itr -> print();
    std::cout << "\n\n";
  }
}

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(){

  std::vector<int> data = {7, 14, 3, 9, 22, 5, 18, 11, 2, 16};
  quickSelect(data, 0, data.size() -1, 1);
  printVector(data);
  
  /*
  std::vector<Book> catalog, cart;

  // open file
  std::string filename = "1000bookInputFile.txt";
  //std::string filename = "book1test.txt";
  std::ifstream fin(filename);

  // define expected format
  std::regex title("(Title: )(.*)");
  std::regex author("(Author: )(.*)");
  std::regex ISBN("(ISBN: )(.*)");
  std::regex icon("(Icon: )(.*)");
  std::regex price("(Price: \\$)(.*)");
  std::regex keywords("(Keywords: )(.*)");
  std::regex blurb("(Blurb: )(.*)");
  // declare helper variables for reading from file
  std::string line;
  std::smatch match;
  Book temp;

  // reads all 7 fields in each iteration and copies the value of each field into Book "temp"
  // pushes "temp" onto the back of "catalog" at the end of the iteration
  while (getline(fin,line)){

    // Title
    if (!std::regex_search(line, match, title)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setTitle(match[2]);

    // Author
    getline(fin,line);
    if (!std::regex_search(line, match, author)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setAuthor(match[2]);

    // ISBN
    getline(fin,line);
    if (!std::regex_search(line, match, ISBN)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setISBN(std::stoll(match[2]));

    // Icon
    getline(fin,line);
    if (!std::regex_search(line, match, icon)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream numstring(match[2]);
    int next_number;
    int* numarray = new int[80];
    for (int i=0 ; i<80; ++i){
      if (!(numstring >> next_number))
        std::cout << "Error reading file format" << std::endl;
      numarray[i] = next_number;
    }
    temp.setIcon(numarray);
    numarray = nullptr;
    //temp.print();

    // Price
    getline(fin,line);
    if (!std::regex_search(line, match, price)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setPrice(std::stof(match[2]));

    // Keywords
    getline(fin,line);
    if (!std::regex_search(line, match, keywords)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream keyword_string(match[2]);
    std::vector<std::string> keywords;
    while (keyword_string){
      std::string keyword;
      if (!getline(keyword_string >> std::ws, keyword, ',' )) break;
      keywords.push_back(keyword);
    }
    temp.setKeywords(keywords);

    // Blurb
    getline(fin,line);
    if (!std::regex_search(line, match, blurb)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setBlurb(match[2]);

    getline(fin,line);  // skip line between entries
    catalog.push_back(temp);

  }
  // write your test cases here
  std::cout << "Print & setters & getters test: \n";
  catalog.front().print();
  
  std::cout << "-------------------------------------\n";
  std::cout << "Copy Constructor test \n";
  Book copy1(catalog.front());
  copy1.print();

  std::cout << "-------------------------------------\n";
  std::cout << "Copy Assignment Operator test \n";
  Book copy2;
  copy2 = copy1;
  copy2.print();
  std::cout << "-------------------------------------\n";
  std::cout << "Move test \n";
  Book move1(std::move(copy2));
  std::cout << "Move 1: \n";
  move1.print();
  std::cout << "Copy2 after moving: (get seg fault bc icon = nullptr\n";
  //copy2.print();
  //copy2.print();
  std::cout << "-------------------------------------\n";
  std::cout << "Move Operator test \n";
  std::cout << "Moving move1 to move 2: \n";
  Book move2 = std::move(move1);
  move2.print();
  std::cout << "---------------------\n";
  std::cout << "move1 after: (seg fault bc icon set to nnull)\n";
  //move1.print();

  //----------------------------
  //helper function to print every book in either catalog or cart 
  std::cout << "-------------------------------------\n";
  std::cout << "Printing containter test \n";
  //printContainer(catalog);
  std::cout << "-------------------------------------\n";
 std::cout << "MoveALl test \n";
 std::cout << "#of items in Catalog before: " << catalog.size() << "\n";
 std::cout << "#of items in Cart before: " << cart.size() << "\n";
 moveAll("Amish Fiction", catalog, cart);
 std::cout << "#of items in Catalog after: " << catalog.size() << "\n";
 std::cout << "#of items in Cart after: " << cart.size() << "\n";
 //printContainer(cart);
  */
  
  return 0;
}