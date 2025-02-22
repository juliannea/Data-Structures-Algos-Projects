/*
CSCI235 Fall 2023
Project 3 - Character Class
Julianne Aguilar
October 6, 2023
Character.cpp defines the constructors and private and public function implementation of the Character class
Project Description: This programs allows to keep track of characters entering and exiting a tavern as well 
                     as displaying the characters data.
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
Character::Character():name_{"NAMELESS"},race_{NONE},vitality_{0},armor_{0},level_{0},enemy_{false}
{
}

/**
Parameterized constructor.
    @param      : The name of the character (a string in UPPERCASE)
    @param      : The race of the character (a string)
    @param      : The character's vitality (a non-negative integer) , with default value 0
    @param      : The character's max armor level (a non-negative integer), with default value 0
    @param      : The character's level (a non-negative integer), with default value 0
    @param      : A flag indicating whether the character is an enemy, with default value false
    @post       : The private members are set to the values of the corresponding parameters. 
                Hint: Notice the default arguments in the parameterized constructor.
                If the given parameters are invalid, the default values are used instead.
*/
Character::Character(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy) : Character()
{
    setName(name); // checks valid name
    setRace(race); // checks valid race
    (vitality >= 0) ? vitality_ = vitality: vitality_ = 0;
    (armor >= 0) ? armor_ = armor: armor_ = 0;
    (level >= 0) ? level_ = level: level_ = 0;
    enemy_ = enemy; 
}

 /**
    @param  : the name of the Character
    @post   : sets the Character's title to the value of the parameter, in UPPERCASE. Only alphabetical characters are allowed. For example, attempting to create a character named "TW3EDLEDUM2" should create a character named "TWEDLEDUM".
    : If the given parameter does not have any valid alphabetical characters, the character's name should be set to "NAMELESS".
*/
void Character::setName(const std::string& name)
{
    std::string nameUpper = "";
    for(int i = 0; i<name.size();i++)
    {
        if(std::isalpha(name[i]))
        {
            nameUpper+= toupper(name[i]);
        }
    }
    if(nameUpper != "")
    {
        name_ = nameUpper;
    }
    else
    {
        name_ = "NAMELESS";
    }
}


/**
    @return : the name of the Character
*/
std::string Character::getName() const
{
    return name_;
}


/**
    @param  : the race of the Character (a string)
    @post   : sets the Character's race to the value of the parameter. Valid races: [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
            : If the given race was invalid, set race_ to NONE.
*/
void Character::setRace(const std::string& race)
{
    
    if(race == "HUMAN")
    {
        race_ = HUMAN;
    }
    else if(race == "ELF")
    {
        race_ = ELF;
    }
    else if(race == "DWARF")
    {
        race_ = DWARF;
    }
    else if(race == "LIZARD")
    {
        race_ = LIZARD;
    }
    else if(race == "UNDEAD")
    {
        race_ = UNDEAD;
    }
    else
    {
        race_ = NONE;
    }
}


/**
    @return : the race of the Character (a string)
*/
std::string Character::getRace() const
{
    if (race_ == Race::HUMAN)
    {
        return "HUMAN";
    }
    else if (race_ == Race::ELF)
    {
        return "ELF";
    }
    else if (race_ == Race::DWARF)
    {
        return "DWARF";
    }
    else if (race_ == Race::LIZARD)
    {
        return "LIZARD";
    }
    else if (race_ == Race::UNDEAD)
    {
        return "UNDEAD";
    }
    else
    {
        return "NONE";
    }

}


/**
    @param  : an integer vitality
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the vitality private member to the value of the parameter
*/
void Character::setVitality(const int& vitality)
{
    if (vitality >= 0)
    {
        vitality_ = vitality;
    }
}


/**
    @return : the value stored in vitality_
*/
int Character::getVitality() const
{
    return vitality_;
}

/**
    @param  : an integer armor level
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the armor private member to the value of the parameter
*/
void Character::setArmor(const int& armor)
{
    if (armor >= 0)
    {
        armor_ = armor;
    }
}


/**
    @return : the value stored in armor_
*/
int Character::getArmor() const
{
    return armor_;
}

/**
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the level private member to the value of the parameter
*/
void Character::setLevel(const int& level)
{
    if (level >= 0)
    {
        level_ = level;
    }
}


/**
    @return : the value stored in level_
*/
int Character::getLevel() const
{
    return level_;
}

/**
    @post   : sets the enemy flag to true
*/
void Character::setEnemy()
{
    enemy_ = true;
}

/**
    @return true if the character is an enemy, false otherwise

Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getEnemy
*/
bool Character::isEnemy() const
{
    return enemy_;
}

/**
Helper function that returns an enum as a string.
@param: a constant enum race reference that represents the characters race 
@return: returns the race as a string type, if race inputted is an invalid type it will return "NONE"
**/
std::string Character::enumToString(const Race& race) const
{   
    if(race == HUMAN){
      return "HUMAN";
    }
    else if(race == ELF){
      return "ELF";
    }
    else if(race == DWARF){
      return "DWARF";
    }
    else if(race == LIZARD){
      return "LIZARD";
    }
    else if(race == UNDEAD){
      return "UNDEAD";
    }
    else{
      return "NONE";
    }
}

/**
An operator that determines if two characters are the same/equal. 
@param: A const reference to the right hand side of the == operator.
@return: Returns true if the right hand side character is "equal", false otherwise. Two characters are equal if they have the 
         same name, same race, same level and are either both an enemy or not.
NOTE: By this definition, only the aforementioned subset of the character's attributes must be equal for two characters to be
      deemed "equal".
**/
bool Character::operator==(const Character& obj) const
{
    bool same = true;
    bool end = false;
    while(same == true && end == false){
      if(name_ != obj.getName()){
         same = false;
      }
      if(level_ != obj.getLevel()){
        same = false;
      }
      if(enemy_ != obj.isEnemy()){
        same = false;
      }  
      if(enumToString(race_) != obj.getRace()){
        same = false;
      }
      end = true;
    }
    return same;
}

/**
An operator that determines if two characters are not the same/equal.
@param: A const reference to the right hand side of the != operator.
@return: Returns true if the right hand side character is NOT "equal" (!=), false otherwise. Two characters are NOT equal if 
         any of their name, race or level are not equal, or if one is an enemy and the other is not.
NOTE: By this definition, one or more of the aforementioned subset of the character's attributes only must be different for 
      two characters to be deemed "NOT equal".
**/
bool Character::operator!=(const Character& obj) const
{
    Character person(name_, enumToString(race_), vitality_, armor_, level_, enemy_);
    bool same = person == obj;
    if(same == true){
      return false;
    }
    return true;
}

/**
Shows the characters data: Name, Level, Race, Vitality, Max Armor, Is an Enemy.
@post: displays Character data in the form: "[name_] is a Level [level_] [race_]. \nVitality: [vitality_] \nMax Armor: [armor_]\n
       They are / They are not] an enemy.\n" 
**/
void Character::display() const
{
    Character person(name_, enumToString(race_), vitality_, armor_, level_, enemy_);
    std::cout << person.getName() << " is a Level " << person.getLevel() << " " << person.getRace() << ".\n";
    std::cout << "Vitality: " << person.getVitality() << "\n";
    std::cout << "Max Armor: " << person.getArmor() << "\n";
    std::cout << (person.isEnemy() ? "They are an enemy.\n": "They are not an enemy.\n");

}
