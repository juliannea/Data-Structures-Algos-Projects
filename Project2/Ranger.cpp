/*
CSCI235 Fall 2023
Project 2 - Ranger Class
Julianne Aguilar 
September 22, 2023
Ranger.cpp defines the constructors and private and public function implementation of the Ranger class
*/
#include "Ranger.hpp"

/**
Default constructor.
Default-initializes all private members. Default character name: "NAMELESS". 
Booleans are default-initialized to False. 
**/
Ranger::Ranger(){
  arrows_ = std::vector<Arrows>();
  affinities_ = std::vector<std::string>();
  has_companian_ = false;
}

/**
Parameterized constructor.
@param: The name of the character (a const string reference)
@param: The race of the character (a const string reference)
@param: The character's vitality (an integer). Default to 0
@param: The character's max armor level (an integer). Default to 0
@param: The character's level (an integer). Default to 0
@param: A flag indicating whether the character is an enemy. Default to false
@param: A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
        Lowercase valid arrow types are retained but converted to uppercase.
        Invalid arrows are those with non-positive quantities or invalid types.
        If the vector contains invalid arrows, those arrows are discarded. 
        Default to empty vector
@param: A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
        String inputs can be in lowercase, but must be converted to uppercase.
        If the vector contains invalid affinities, those affinities are discarded.
        Default to empty vector
@param: A flag indicating whether the character is able to recruit an animal companion. 
        Default to false
@post: The private members are set to the values of the corresponding parameters
**/
Ranger::Ranger(const std::string &name, const std::string &race, int vitality, int max_armor_level, int level, bool enemy, const std::vector<Arrows>& arrows, const std::vector<std::string>& affinities, bool has_companion)
: Character(name, race, vitality, max_armor_level, level, enemy){
  filter_arrows(arrows);
  filter_affinities(affinities);
  has_companian_ = has_companion;
}

/**
Adds valid arrow types and quantity to the characters vector of arrows
@param: a reference to string representing the arrow type
@param: a reference to an integer quantity
@post: If the character already has that type of arrow, the quantity in the vector 
       is updated. If not, the arrow is added to the vector. 
       Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
       Lowercase valid arrow types are retained but converted to uppercase.
       Quantity of arrows must be greater than 0
       Invalid arrows are those with non-positive quantities or invalid types.
       If the arrows are invalid, they are not added.
@return: True if the arrows were added successfully, false otherwise
**/
bool Ranger::addArrows(const std::string &arrow_type, const int &quantity)
{
  //to_upper() capitalizes all characters of the string 
  std::string valid_arrows[5] = {"WOOD", "FIRE", "POISON", "BLOOD", "WATER"};
  bool valid = false;
  for(int i = 0; i < 5; i++){
    if(to_upper(arrow_type) == valid_arrows[i] && quantity > 0){
      valid = true;
      //iterates over arrow vector to check if type already in the vector
      //so it only adds the quantity
      for(int j = 0; j < arrows_.size(); j++){
        if(to_upper(arrow_type) == arrows_[j].type_ && quantity > 0){
          arrows_[j].quantity_ += quantity;
          return true;
        }
      }
    }
  }
  //in the case it's a valid type not already in the arrows vector 
  if(valid == true){
    Arrows new_arrow;
    new_arrow.type_ = to_upper(arrow_type);
    new_arrow.quantity_ = quantity;
    arrows_.push_back(new_arrow);
    return true;
  }
  return false;
}

/**
Returns the vector of the character arrows
@return: a vector of the Character's arrows
**/
std::vector<Arrows> Ranger::getArrows() const
{
  return arrows_;
}

/**
Allows the character to fire one of their arrows from their vector
@param: a reference to string representing the arrow type
@post: If the character has the listed arrow AND enough arrows to fire one, 
       the quantity of remaining arrows in the vector is updated.
       Lowercase valid arrow types are accepted but converted to uppercase.
       If firing the last arrow, simply decrement the quantity to 0.
@return: True if the character had the listed arrow AND enough arrows, False otherwise.
**/
bool Ranger::fireArrow(const std::string& arrow_type){
  for(int i = 0; i < arrows_.size(); i++){
    if(to_upper(arrow_type) == arrows_[i].type_ && arrows_[i].quantity_ > 0){
      arrows_[i].quantity_ -= 1;
      return true;
    }
  }
  return false;
}

/**
Adds a valid infinty type to the characters vector of affinities
@param: a reference to string representing an affinity 
@post: If the affinity does not already exist in the vector, add it to the vector.
       Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
       String inputs can be in lowercase, but must be converted to uppercase when 
       setting the variable. There should be no duplicate affinities.
       If the affinity is invalid, it is NOT added.
@return: True if the affinity was added successfully, false otherwise
**/
bool Ranger::addAffinity(const std::string& affinity)
{
  std::string valid_affinities[4] = {"FIRE", "WATER", "POISON", "BLOOD"};
  bool valid = false;
  for(int i = 0; i < 4; i++){
    if(to_upper(affinity) == valid_affinities[i]){
      valid = true;
      //checks if already exists in vector
      for(int j = 0; j < affinities_.size(); j++){
        if(to_upper(affinity) == affinities_[j]){
          return false;
        }
      }
    }
  }
  if(valid == true){
    affinities_.push_back(to_upper(affinity));
    return true;
  }
  return false;
}

/**
Returns all of the characters affinities in their vector
@return: a vector of the Character's affinities
**/
std::vector<std::string> Ranger::getAffinities() const
{
  return affinities_;
}

/**
Sets whether or not the character can recruit and animal companion based on the input
@param: a reference to a boolean indicating whether the character is able to recruit 
        an animal companion
@post: sets the private member variable to the value of the parameter.
**/
void Ranger::setCompanion(const bool &recruit)
{
  has_companian_ = recruit;
}

/**
Returns whether or not the character can recruit an animal conpanion
@return: a boolean indicating whether the character is able to recruit an animal companion
**/
bool Ranger::getCompanion() const
{
  return has_companian_;
}

/**
Captilizes every character of a string 
@param: a reference to a string that needs to be ensured that all characters are capitalized
@return: returns the string with characters all capitalized
**/
std::string Ranger::to_upper(const std::string& name){
  std::string fixed_name;
  for(int i = 0; i < name.length(); i++){
    fixed_name += toupper(name[i]);
  }
  return fixed_name;
}

/**
 Filters a vector of arrows so that only the valid types are added
 to the characters vector of arrows.
 Valid arrow types are: [WOOD,FIRE,WATER,POISON,BLOOD]
 Lowercase valid arrow types are retained but converted to uppercase
 If vector contains invalid arrows, arrows are not added to the returned vector
 @param:  a reference to a vector of arrows of Arrow type
 @post: adds the valid arrow types to the characters vectorin all uppercase
**/
void Ranger::filter_arrows(const std::vector<Arrows>& arrow_vector){
  for(int i = 0; i < arrow_vector.size(); i++){
    addArrows(to_upper(arrow_vector[i].type_), arrow_vector[i].quantity_);
  }
}

/**
  Filters a vector of affinities so that only valid types are added 
  to the characters vector of affinities
  Valid affinity types are: [FIRE, WATER, POISON, BLOOD]
  Lowercase valid affinity types are retained but converted to uppercase 
  If vector contains invalid arrows, arrows are not added to the returned vector
  @param:a reference to a vector of affinities of string type 
  @post: adds a valid affinity type in all uppercase to the affinities_ vector 
  if it didn't exist prior. 
**/
void Ranger::filter_affinities(const std::vector<std::string>& affinity_arrow){
  for(int i = 0; i < affinity_arrow.size(); i++){
    std::string affinity = to_upper(affinity_arrow[i]);
    addAffinity(affinity);
  }
}

