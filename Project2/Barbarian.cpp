/*
CSCI235 Fall 2023
Project 2 - Barbarian Class
Julianne Aguilar 
September 22, 2023
Barbarian.cpp defines the constructors and private and public function implementation of the Barbarian class
*/
#include "Barbarian.hpp"

/**
Default constructor.
Default-initializes all private members. Default character name: "NAMELESS". 
Booleans are default-initialized to False. 
Default weapons: "NONE". 
*/
Barbarian::Barbarian(){
  main_weapon_ = "NONE";
  secondary_weapon_ = "NONE";
  enraged_ = false;
}

/**
Parameterized constructor.
@param: The name of the character (a const string reference)
@param: The character's vitality (an integer). Default to 0
@param: The character's max armor level (an integer). Default to 0
@param: The character's level (an integer). Default to 0
@para: A flag indicating whether the character is an enemy. Default to false
@param: The character's main weapon (a const string reference). 
        String inputs can be in lowercase, but must be converted to uppercase 
        when setting the variable. Only alphabetical characters are allowed.
        Default to "NONE"            
@param: The character's offhand weapon (a const string reference). 
        String inputs can be in lowercase, but must be converted to uppercase 
        when setting the variable. Only alphabetical characters are allowed.
        Default to "NONE"               
@param: A flag indicating whether the character is enraged. Default to false
@post: The private members are set to the values of the corresponding parameters. 
@post: If the main and secondary weapons are not provided or invalid, the variables are set to "NONE".
**/
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int max_armor_level, int level, bool enemy, const std::string& main_weapon, const std::string& secondary_weapon, bool enraged)
: Character(name, race, vitality, max_armor_level, level, enemy){
  
  if(contains_num(main_weapon) == false){
    main_weapon_ = to_upper(main_weapon);
  }
  else{
    main_weapon_ = "NONE";
  }
  if(contains_num(secondary_weapon) == false){
    secondary_weapon_ = to_upper(secondary_weapon);
  }
  else{
    secondary_weapon_ = "NONE";
  }
  enraged_ = enraged;
  
}

/**
Sets the input as the characters weapon if it's valid
@param: a reference to a string representing the Character's main weapon
@post: sets the private member variable to the value of the parameter. 
       Only alphabetical characters are allowed.
       String inputs can be in lowercase, but must be converted to uppercase when 
       setting the variable.
       If the given input is invalid (i.e contains numbers), do nothing and return false
@return: true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setMainWeapon(const std::string& main_weapon){
  if(contains_num(main_weapon) == false){
    main_weapon_ = to_upper(main_weapon);
    return true;
  }
  return false;
}

/**
Returns the main weapon of the character 
@return: a string of the Character's main weapon
**/
std::string Barbarian::getMainWeapon() const{
  return main_weapon_;
}

/**
Sets the input as the character secondary weapon if it's valid
@param: a reference to a string representing the Character's secondary weapon
@post: sets the private member variable to the value of the parameter. 
       Only alphabetical characters are allowed.
       String inputs can be in lowercase, but must be converted to uppercase when 
       setting the variable.
@post: If the given input is invalid (i.e contains numbers), do nothing and return false
@return: true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setSecondaryWeapon(const std::string &secondary_weapon)
{
  if(contains_num(secondary_weapon) == false){
    secondary_weapon_ = to_upper(secondary_weapon);
    return true;
  }
  return false;
}

/**
Returns the secondary weapon of the character
@return: a string of the Character's secondary weapon
**/
std::string Barbarian::getSecondaryWeapon() const{
  return secondary_weapon_;
}

/**
Sets whether or not the character is enraged based on the input
@param: a reference to a bool
@post: sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage(const bool& enrage)
{
  enraged_ = enrage;
}

/**
Returns whether the Character is enraged or not
@return: a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage() const{
  return enraged_;
}

/**
Changes the characters enraged state to the opposite of what it was
@post: sets the enraged variable to the opposite of what it was
**/
void Barbarian::toggleEnrage(){
  if(enraged_ == true){
    enraged_ = false;
  }
  else{
    enraged_ = true;
  }
}

/**
Captilizes every character of a string 
@param: a reference to a string that needs to be ensured that all characters are capitalized
@return: returns the string with characters all capitalized
**/
std::string Barbarian::to_upper(const std::string& name){
  std::string fixed_name;
  for(int i = 0; i < name.length(); i++){
    fixed_name += toupper(name[i]);
  }
  return fixed_name;
}

/**
Determines if a string input that represents the characters weapon contains
a non alphabetical character
@param: a string representing the characters weapon
@return: true if the string contains a non alphabetical character, false otherwise
**/
bool Barbarian::contains_num(const std::string& weapon){
  for(int i = 0; i < weapon.length(); i++){
    if(isalpha(weapon[i]) == false){
      return true;
    }
  }
  return false;
}

