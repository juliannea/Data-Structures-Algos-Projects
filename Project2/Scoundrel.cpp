/*
CSCI235 Fall 2023
Project 2 - Scoundrel Class
Julianne Aguilar 
September 22, 2023
Scoundrel.cpp defines the constructors and private and public function implementation of the Scoundrel class
*/
#include "Scoundrel.hpp"

/**
Default constructor.
Default-initializes all private members. 
Default character name: "NAMELESS". Booleans are default-initialized to False. 
Default dagger: WOOD. Default faction: "NONE". 
**/
Scoundrel::Scoundrel(){
  dagger_ = WOOD;
  faction_ = "NONE";
  has_disguise_ = false;
  
}

/**
Parameterized constructor.
@param: The name of the character (a const string reference)
@param: The race of the character (a const string reference)
@param: The character's vitality (an integer). Default to 0
@param: The character's max armor level (an integer). Default to 0
@param: The character's level (an integer). Default to 0
@param: A flag indicating whether the character is an enemy. Default to false.
@param: The character's dagger type (a const string reference).
        String inputs can be in lowercase, but must be converted to 
        uppercase when setting the dagger enum. Default to WOOD
@param: The character's Faction (a const string reference). 
        Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
        String inputs can be in lowercase, but must be converted to 
        uppercase when setting the variable. Default to "NONE"
@param: A flag indicating whether the character has a disguise. Default to false
@post:  The private members are set to the values of the corresponding 
        parameters. If the dagger type is not provided or invalid, the variable should 
        be set to WOOD.If the Faction is not provided or invalid, the variable should
        be set to "NONE". 
**/
Scoundrel::Scoundrel(const std::string &name, const std::string &race, int vitality, int max_armor_level, int level, bool enemy, const std::string &dagger_type, const std::string &faction, bool has_disguise)
:Character(name, race, vitality, max_armor_level, level, enemy){

  faction_ = check_valid_faction(faction);
  has_disguise_ = has_disguise;
  setDagger(dagger_type);
  
}

/**
Sets the user input as the dagger type for the character
@param: a reference to a string representing the dagger type
@post:  sets the private member variable to the value of the parameter. 
        String inputs can be in lowercase, but must be converted to 
        uppercase when setting the variable.
        If the dagger type is not valid (i.e, is one of the following: 
        [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
        the variable should be set to WOOD. 
**/
void Scoundrel::setDagger(const std::string& dagger_type){
  std::string upper_dagger_type = to_upper(dagger_type);
  if(upper_dagger_type == "WOOD"){
    dagger_ = WOOD;
  }
  else if(upper_dagger_type == "BRONZE"){
    dagger_ = BRONZE;
  }
  else if(upper_dagger_type == "IRON"){
    dagger_ = IRON;
  }
  else if(upper_dagger_type == "STEEL"){
    dagger_ = STEEL;
  }
  else if(upper_dagger_type == "MITHRIL"){
    dagger_ = MITHRIL;
  }
  else if(upper_dagger_type == "ADAMANT"){
    dagger_ = ADAMANT;
  }
  else if(upper_dagger_type == "RUNE"){
    dagger_ = RUNE;
  }
  else{
    dagger_ = WOOD;
  }
}

/**
  Returns what characters dagger type is
  @return: the string indicating the character's dagger type
**/
std::string Scoundrel::getDagger() const{
  std::string dagger;

  switch(dagger_){
    case WOOD : dagger = "WOOD"; break;
    case BRONZE : dagger = "BRONZE"; break;
    case IRON : dagger = "IRON"; break;
    case STEEL : dagger = "STEEL"; break;
    case MITHRIL : dagger = "MITHRIL"; break;
    case ADAMANT : dagger = "ADAMANT"; break;
    case RUNE : dagger = "RUNE"; break;
  }
  return dagger;
}

/**
Sets the input as the characters faction
@param: a reference to a string representing the character's Faction
@post: sets the private member variable to the value of the parameter. 
       String inputs can be in lowercase, but must be converted to 
       uppercase when setting the variable.
       If the provided faction is not one of the following: 
       [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
       do nothing and return false.
 @return: true if setting the variable was successful, false otherwise.
**/
bool Scoundrel::setFaction(const std::string &faction)
{
  std::string upper_faction = to_upper(faction);
  std::string faction_arr[4] = {"NONE","CUTPURSE", "SHADOWBLADE", "SILVERTONGUE"};
  for(int i = 0; i < 4; i++){
    if(upper_faction == faction_arr[i]){
      faction_ = upper_faction;
      return true;
    }
  }
  return false;
}

/** Returns the characters faction
@return: the string indicating the character's Faction
**/
std::string Scoundrel::getFaction() const{
  return faction_;
}

/**
Sets the user input to whether or not the character has a disguise
@param: a reference to boolean
@post: sets the private member variable indicating whether the character has a disguise
**/
void Scoundrel::setDisguise(const bool& has_disguise)
{
  has_disguise_ = has_disguise;
}

/**
Returns whether or not the character has a disguise
@return: the visual aid flag
**/
bool Scoundrel::hasDisguise() const{
  return has_disguise_;
}

/**
Captilizes every character of a string 
@param: a string that needs to be ensured that all characters are capitalized
@return: returns the string with characters all capitalized
**/
std::string Scoundrel::to_upper(const std::string& name){
  std::string fixed_name;
  for(int i = 0; i < name.length(); i++){
    fixed_name += toupper(name[i]);
  }
  return fixed_name;
}

/**
Checks if the faction type is a valid type by traversing through a list of 
valid faction types
@param: a reference to a string that represents a faction type, string inputs can be lower 
        case but are changed to all upper case
@post:  The string input is changed to all uppercased 
@return:  The string input faction type in all uppercase if it detected as valid, if invalid 
          input returns false.
*/
std::string Scoundrel::check_valid_faction(const std::string& input)
{
  std::string faction = to_upper(input);
  std::string faction_arr[3] = {"CUTPURSE", "SHADOWBLADE", "SILVERTONGUE"};
  for(int i = 0; i < 3; i++){
    if(faction == faction_arr[i]){
      return faction;
    }
  }
  return "NONE";
}



