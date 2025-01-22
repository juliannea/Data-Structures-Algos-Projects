#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

/**
 Moves all book objects that contain a key word into a vector representing the book cart 
 @param: a string keyword, a vector of a source of books, a vector to move the books into representing the book cart
 @post: moves all book objects in source with the specified keyword into the vector representing the book cart
*/
void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  // erase this comment and write your code here
 
  //iterating through source 
  auto itr = source.begin();
  while(itr != source.end()){
    bool found = false;

    auto key_itr = itr -> getKeywords().begin(); //points to vector of keywords 

     while(found == false && key_itr!= itr ->getKeywords().end()){
      if(*key_itr == keyword){
        found = true;
      }
      ++key_itr;
    }
    
    if(found){
      books_moved ++;
      Book temp = std::move(*itr);
      dest.push_back(temp);
      itr = source.erase(itr);
    }
    else{ //don't itr++ if erased b/c erasing shifts every element in vector to left 
      itr++;
    }
    
  }

  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}