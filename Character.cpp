/**
  File Title: Character.cpp
  Name: Julianne Aguilar 
  Class: CSCI 235
  Project-1: The Character class: A Review of OOP
  Description: A review of OOP, this program allows the user to assign the name, race,vitality,
              armor level, and level of a character and declare if it's a enemy. 
  Date: September 5, 2023 
*/
#include "Character.hpp"


/**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default enum value: NONE. 
    Default Vitality, Max Armor, and Level: 0.
*/
Character::Character(){
  character_name_ = "NAMELESS";
  race_ = NONE;
  vitality_ = 0;
  max_armor_level_ = 0;
  character_level_ = 0;
  enemy_ = false;
}

/**
  Parameterized constructor.
  @param : The name of the character: name (a string in UPPERCASE)
  @param : The race of the character: character_race (a string)
  @param : The character's vitality: CH_VITALITY (a non-negative integer) , with default  
          value 0
  @param : The character's max armor level: CH_MAX_ARMOR_LEVEL (a non-negative integer), with 
          default value 0
  @param : The character's level: CH_LEVEL (non-negative integer), with default value 0
  @param : A flag indicating whether the character is an enemy: ch_enemy, with default 
          value false
  @post  :If the user inputs a name with numeric characters and lowercase characters,
          the string name will remove all non alphabetical characters and change all 
          lowercase to uppercase 
  @post  :IF the user inputs negative integers for any of the int parameters,
          it will set the int private members to the default value of 0 
  @post  : The private members are set to the values of the corresponding 
          parameters.
*/
Character::Character(const std::string& name, const std::string& character_race, const int& vitality, const int& max_armor_level, const int& level,const bool& enemy){
  setName(name);
  if(vitality >=0){
    vitality_ = vitality;
  }
  else{
    vitality_ = 0;
  }

  if(max_armor_level >=0){
    max_armor_level_ = max_armor_level;
  }
  else{
   max_armor_level_ = 0;
  }
  if(level >= 0){
    character_level_ = level;
  }
  else{
    character_level_ = 0;
  }

  enemy_ = enemy;
}

/**
  Sets the characters name to the user's input  
  @param  : the name of the Character that is set as a string constant: name
  @post   : sets the Character's name: character_name_ to the value of the parameter, 
            in UPPERCASE. Only alphabetical characters are allowed. 
            For example, attempting to create a character named 
            "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
          : If the given parameter does not have any valid alphabetical
            characters, the character's name should be set to "NAMELESS".
*/
void Character::setName(const std::string& name){
  std::string fixed_name;
  //Capitalizes every alphabetical character in name and add it to fixed_name string
  for(int i = 0; i < name.length(); i++){
    if(isalpha(name[i])){
      fixed_name += toupper(name[i]); 
    }
  }
   
  if(fixed_name.empty()){
    character_name_ = "NAMELESS";
  }
  else{
    character_name_ = fixed_name;
  }
 }

/**
  Shows the user the name of the character
  @return : the name of the Character: character_name_
*/
std::string Character::getName() const{
  return character_name_;
}

/**
  Sets the race of the character to the users input 
  @param  : the race of the Character (a string set to const): character_race
  @post   : sets the Character's race: character_race_ to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
*/

void Character::setRace(const std::string& character_race){
  std::string upper_character_race;
  for(int i = 0; i < character_race.length(); i++){
    upper_character_race += toupper(character_race[i]);
  }
  if(upper_character_race == "HUMAN"){
    race_ = HUMAN;
  }
  else if(upper_character_race == "ELF"){
    race_ = ELF;
  }
  else if(upper_character_race == "DWARF"){
    race_ = DWARF;
  }
  else if(upper_character_race == "LIZARD"){
    race_ = LIZARD;
  }
  else if (upper_character_race == "UNDEAD"){
    race_ = UNDEAD;
  }
  else{
    race_ = NONE;
  }
}

/**
  Shows the user the race of the character
  @return : the race of the Character: character_race_,
            as a string with all UPPERCASE 
*/
std::string Character::getRace() const{
  std::string upper_character_race;
  switch(race_){
        case HUMAN : upper_character_race = "HUMAN"; break;
        case ELF : upper_character_race = "ELF"; break;
        case DWARF : upper_character_race = "DWARF"; break;
        case LIZARD: upper_character_race = "LIZARD"; break;
        case UNDEAD: upper_character_race = "UNDEAD"; break;
        case NONE: upper_character_race = "NONE"; break;
    }
    return upper_character_race;
}

/**
  Sets the vitality of the character to the user input 
  @param  : an integer for vitality: VITALITY_
  @pre    : vitality >= 0 : Characters cannot have negative health
  @post   : sets the VITALITY_ private member to the value of the parameter
*/

void Character::setVitality(const int& vitality){
  if(vitality >= 0){
    vitality_ = vitality;
  }
}

/**
  Shows the user the vitaltiy of the character 
  @return : the value stored in VITALITY_
*/
int Character::getVitality() const{
  return vitality_;
}
/**
  Sets the armor to the users input 
  @param  : an integer for armor level: MAX_ARMOR_LEVEL_
  @pre    : armor >= 0 : Characters cannot have negative armor
  @post   : sets the MAX_ARMOR_LEVEL_ private member to the value of the parameter
*/
void Character::setArmor(const int& armor)
{
  if(armor >= 0){
    max_armor_level_ = armor;
  }
}
/**
  Shows the user the max armor level
  @return : the value stored in MAX_ARMOR_LEVEL_
*/
int Character::getArmor() const{
  return max_armor_level_;
}
/**
  Sets the level to the users input 
  @param  : an integer level
  @pre    : level >= 0 : Characters cannot have a negative
  @post   : sets the CHARACTER_LEVEL private member to the value of the parameter
*/
void Character::setLevel(const int& level){
  if(level >= 0){
    character_level_ = level;
  }
}
/**
  Shows the user the characters level
  @return : the value stored in CHARACTER_LEVEL_
*/
int Character::getLevel() const{
  return character_level_;
}
/**
  Sets a character as an enemy
  @post   : sets the enemy flag to true
*/
void Character::setEnemy(){
  enemy_ = true;
}
/**
  Shows the user if the character is an enemy 
  @return true if the character is an enemy, false otherwise
*/
bool Character::isEnemy() const{
  if(enemy_ == true){
    return true;
  }
  else{
    return false;
  }
}
std::string Character:: to_upper(const std::string& name){
  std::string fixed_name;
  for(int i = 0; i < name.length(); i++){
    if(isalpha(name[i])){
      fixed_name += toupper(name[i]); 
    }
  }
  return fixed_name;
}