#include <string>
#include <vector>
#include <list>
#include <chrono>
#include "Book.hpp"

/**
 Moves all book objects that contain a key word into a vector representing the book cart 
 @param: a string keyword, a vector of a source of books, a vector to move the books into representing the book cart
 @post: moves all book objects in source with the specified keyword into the vector representing the book cart
*/
void moveAll (const std::string, std::vector<Book> &, std::vector<Book> &);