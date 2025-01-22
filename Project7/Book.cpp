#include "Book.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>  

    // write and document all methods in this file.
    /**
    Defaultlt Constructor 
    @post: Initializes private member variables 
    */
    Book::Book()
    {
      title_ = "";
      author_ = "";
      ISBN_ = 0;
      icon_ = nullptr;
      price_ = 0;
      keywords_; 
      blurb_;
    }
    
    /**
     Destructor 
     @post: sets icon to nullptr 
    */
    Book::~Book()
    { 
      //icon is pointer so must set to null
      //delete icon_;
      icon_ = nullptr;
    }

    /**
     Copy Constructor 
     @param: a book object to copy 
     @post: copies the data member values of the parameter
    */
    Book::Book(const Book& rhs)
    {
     
      title_ = rhs.title_;
      author_ = rhs.author_;
      ISBN_ = rhs.ISBN_;
      //deep copy prevent unwanted changes 
      icon_ = new int[80];
      // Copy values from rhs.icon_ to icon_
      for (int i = 0; i < 80; ++i) {
        icon_[i] = rhs.icon_[i];
      }
      price_ = rhs.price_;
      blurb_ = rhs.blurb_;
      keywords_ = rhs.keywords_;
        
    
    }
    /**
    Copy Assignment Operator 
    @param: a book object to copy 
    @post: Copies the data maember values of the parameter
    @return: returns reference to object
    */
    Book& Book::operator=(const Book& rhs)
    {
      if(this != &rhs){
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        icon_ = new int[80];
        // Copy values from rhs.icon_ to icon_
        for (int i = 0; i < 80; ++i) {
          icon_[i] = rhs.icon_[i];
        }
        price_ = rhs.price_;
        blurb_ = rhs.blurb_;
        keywords_ = rhs.keywords_;
      }
      return *this;
     
    }
    /**
     Move Constructor 
     @param: An r value of a book object 
     @post: moves the data member values of the parameter to this book
    */
    Book::Book(Book&& rhs):
      title_{std::move(rhs.title_)}, author_{std::move(rhs.author_)}, ISBN_{rhs.ISBN_}, icon_{rhs.icon_}, price_{rhs.price_},keywords_{std::move(rhs.keywords_)},blurb_{std::move(rhs.blurb_)}
    {
      rhs.ISBN_ = 0;
      rhs.price_ = 0;
      rhs.icon_ = nullptr;
    }

    /**
     Move assignment operator 
     @param: An r value of a book object
     @post: swaps the value in the rhs to the objects variables, swaps with an r value so gets destrcuted in the system after swap
    */
    Book& Book::operator=(Book&& rhs)
    {
      title_ = std::move(rhs.title_);
      author_ = std::move(rhs.author_);
      ISBN_ = rhs.ISBN_;
      rhs.ISBN_ = 0;
      icon_ = rhs.icon_;
      rhs.icon_ = nullptr;
      price_ = rhs.price_;
      rhs.price_ = 0;
      keywords_ = std::move(rhs.keywords_);
      blurb_ = rhs.blurb_;
      return *this;
  
    }
    /**
     Gets title of Book 
     @return: Returns the title of the Book
    */
    const std::string& Book::getTitle() const
    {
      return title_;
    }

    /**
     Sets the title of Book
     @param: title of book 
     @post: title_ is assigned to the parameter 
    */
    void Book::setTitle(const std::string& title)
    {
      title_ = title;
    }
    /**
     Gets the author of Book
     @return: Returns the author of Book
    */
    const std::string& Book::getAuthor() const
    {
      return author_;
    }
    /**
     Sets the author of Book 
     @param: the author of book  
     @post: Assigns author_ to parameter 
    */
    void Book::setAuthor(const std::string& author)
    {
      author_ = author;
    }
    /**
     Gets the ISBN of Book
     @return: ISBN of Book
    */
    long long int Book::getISBN() const
    {
      return ISBN_;
    }
    /**
     Sets ISBN of Book
     @param: the ISBN number 
     @post: Assigns value of ISBN to parameter 
    */
    void Book::setISBN(long long int ISBN)
    {
      ISBN_ = ISBN;
    }
    /**
     Gets Icon of Book
     @return: Icon of Book
    */
    const int* Book::getIcon() const
    {
      return icon_;
    }
    /**
     Sets Icon
     @param: a pointer icon 
     @post: Sets icon_ to parameter 
    */
    void Book::setIcon(int* icon)
    {
    icon_ = icon; 
    }
    /**
     Gets Price of Book
     @return: Price of Book
    */
    float Book::getPrice() const
    {
      return price_;
    }
    /**
     Sets Price of Book
     @param: float price of book 
     @post: sets price_ to parameter 
    */
    void Book::setPrice(float price)
    {
      price_ = price;
    }
    /**
     Gets vector of Book keywords 
     @return: String vector Book keywords 
    */
    const std::vector<std::string>& Book::getKeywords() const
    {
      return keywords_;
    }
    /**
     Sets keyword vector 
     @param: a vector of keywords
     @post: Sets keyword_ to parameter 
    */
    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
      keywords_ = keywords;
    }
    /**
     Gets blurb of Book 
     @return: blurb of Book
    */
    const std::string& Book::getBlurb() const
    {
      return blurb_;
    }
    /**
    Sets blurb 
    @param: the blurb of book 
    @post:Sets Blurb of book to parameter
    */
    void Book::setBlurb(const std::string& blurb)
    {
      blurb_ = blurb;
    }

    /**
     Prints the data members of a Book object 
     @post: Prints the book objects info 
    */
    void Book::print() const
    {
      std::cout << "Title: " << title_ << std::endl;
      std::cout << "Author: " << author_ << std::endl;
      std::cout << "ISBN: " << ISBN_<< std::endl;
      //Icon containts 80 integers in an array so use iterator to traverse to each int and cout
      
       std::cout << "Icon:";
    
      for(int* itr = icon_; itr != icon_ + 80; itr ++){
        std::cout << " " << *itr;
      }
  
      std::cout << std::endl;
      std::cout << std::fixed;
      std::cout << std::setprecision(2);
      std::cout << "Price: $" << price_ << std::endl;
      std::cout << "Keywords:";
      for(auto itr = keywords_.begin(); itr != keywords_.end(); itr++){
        std::cout << " " << *itr;
        if(itr!= keywords_.end()-1){
          std::cout << ",";
        }
      }
      std::cout << std::endl;
      std::cout << "Blurb: " << blurb_ << std::endl;
    

    }

