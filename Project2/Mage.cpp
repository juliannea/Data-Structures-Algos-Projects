/*
CSCI235 Fall 2023
Project 2 - Mage Class
Julianne Aguilar 
September 22, 2023
Mage.cpp defines the constructors and private and public function implementation of the Mage class
*/
#include "Mage.hpp"
/**
Default constructor.
Default-initializes all private members. 
Default character name: "NAMELESS". Booleans are default-initialized to False. 
Default school of magic and weapon: "NONE". 
*/
Mage::Mage(){
  school_of_magic_ = "NONE";
  weapon_ = "NONE";
  can_summon_incarnate_ = false;
}

/**
Parameterized constructor.
@param:The name of the character (a const string reference)
@param:The race of the character (a const string reference)
@param:The character's vitality (an integer). Default to 0
@param:The character's level (an integer). Default to 0
@param:A flag indicating whether the character is an enemy. Default to false.
@param:The character's school of magic (a const string reference). Valid schools: 
      [ELEMENTAL, NECROMANCY, ILLUSION]. String inputs can be in lowercase, 
      but must be converted to uppercase when setting the variable.
      If the school name is invalid, set it to "NONE"
@param:The character's choice of weapon (a const string reference). 
      Valid weapons: [WAND, STAFF] String inputs can be in lowercase, 
      but must be converted to uppercase when setting the variable.
      If the weapon is invalid, set it to "NONE"
@param:A flag indicating whether the character is able to summon an 
      incarnate. Default to false.
@post:The private members are set to the values of the corresponding 
      parameters.             
*/
Mage::Mage(const std::string& name, const std::string& race, int vitality, int max_armor_level, int level, bool enemy, const std::string& school_of_magic, const std::string& weapon, bool can_summon_incarnate)
: Character(name, race, vitality, max_armor_level, level, enemy){
  can_summon_incarnate_ = can_summon_incarnate;
  //sets_school_of_magic to school_of_magic
  std::string magic_schools[3] = {"ELEMENTAL", "NECROMANCY", "ILLUSION"};
  school_of_magic_ = check_if_valid(magic_schools, 3, to_upper(school_of_magic));
  // sets weapon_ to weapon
  std::string weapon_array[2] = {"WAND", "STAFF"};
  weapon_ = check_if_valid(weapon_array, 2, to_upper(weapon));
}

/**
Sets the school the mage is in
@param:a reference to a string representing the school of magic
@post:sets the private member variable to the value of the parameter. If 
      the provided school of magic is not one of the following: [ELEMENTAL, 
      NECROMANCY, ILLUSION], do nothing and return false.
      String inputs can be in lowercase, but must be converted to 
      uppercase when setting the variable.

@return:true if setting the variable was successful, false otherwise.
**/
bool Mage::setSchool(const std::string& school){
  //calls helper function that capitalizes all character of a string and takes out numeric characters
  std::string upper_school = to_upper(school);
  std::string magic_schools[3] = {"ELEMENTAL", "NECROMANCY", "ILLUSION"};
  for(int i = 0; i < 3; i++)
  {
    if(magic_schools[i] == upper_school){
      school_of_magic_ = magic_schools[i];
      return true;
    }
  }
  return false;
}

/**
Shows the user the characters school of magic 
@return:the string indicating the character's school of magic
**/
std::string Mage::getSchool() const{
  return school_of_magic_;
}

/**
Sets the user input for weapon as the characters weapon
@param: a reference to a string representing the character's weapon
@post:sets the private member variable to the value of the parameter.
      String inputs can be in lowercase, but must be converted to 
      uppercase when setting the variable.
      If the provided weapon is not one of the following: 
      [WAND, STAFF], do nothing and return false.
@return:true if setting the variable was successful, false otherwise.
**/
bool Mage::setCastingWeapon(const std::string& weapon){
  std::string upper_weapon = to_upper(weapon);
  std::string weapon_array[2] = {"WAND", "STAFF"};
  for(int i = 0; i < 2; i++){
    if(upper_weapon == weapon_array[i]){
      weapon_ = weapon_array[i];
      return true;
    }
  }
  return false;
}

/**
Shows the user what the caracters weapon is 
@return  : the string indicating the character's weapon
**/
std::string Mage::getCastingWeapon() const{
  return weapon_;
}

/**
Sets the user input for the characters ability to summon an incarnate
@param:a reference to boolean
@post:sets the private member variable indicating whether the character can 
      summon an incarnate
**/       
void Mage::setIncarnateSummon(const bool& can_summon){
  can_summon_incarnate_ = can_summon;
}

/**
Shows the user if character can summon an incarnate
@return:the summon-incarnate flag
**/
bool Mage::hasIncarnateSummon() const{
  return can_summon_incarnate_;
}

/**
Helper Function that checks if the user input is equivalent to an item in the array
Used to check if the user input for magic school or weapon is valid
@param:an array, either of the valid magic schools or valid weapons
@param:a reference to a int representing the size of the array
@param:a reference to a string representing the user's input of the magical school or weapon 
 @return:if the user's input is equivalent to an item in the array it returns the user's input
        if the user's input does not match any item in the array it returns "NONE"
*/
std::string Mage::check_if_valid(std::string arr[], const int& size,const std::string& input)
{
  std::string check_valid;
  for(int i = 0; i < size; i++)
  {
    if(input == arr[i]){
      check_valid = arr[i];
      return check_valid;
    }
  }
  return "NONE";
}

/**
Capitalizes every character in a string 
@param: a reference to a string that needs to be ensured that all characters are capitalized
@return: returns the string with characters all capitalized
*/
 std::string Mage::to_upper(const std::string& name){
  std::string fixed_name;
  for(int i = 0; i < name.length(); i++){
    fixed_name += toupper(name[i]);
  }
  return fixed_name;
}



