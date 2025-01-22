/**
  File Title: Character.cpp
  Name: Julianne Aguilar 
  Class: CSCI 235
  Project-1: The Character class: A Review of OOP
  Description: A review of OOP, this program allows the user to assign the name, race,vitality,
              armor level, and level of a character and declare if it's a enemy. 
  Date: September 5, 2023 
*/
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>


enum Race {NONE, HUMAN, ELF, DWARF, LIZARD, UNDEAD};

class Character{
  private:
    std::string character_name_;
    Race race_;
    int vitality_;
    int max_armor_level_;
    int character_level_;
    bool enemy_;
    
  public:
  /** 
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". 
    bool enemy is default-initialized to False. 
    Default enum value: NONE. 
    Default VITALITY_, MAX_ARMOR_LEVEL_, and CHARACTER_LEVEL_: 0.
  */
    Character();
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
   Character(const std::string& name, const std::string& character_race, const int& vitality=0, const int& max_armor_level=0, const int& level=0, const bool& enemy=0);
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
    void setName(const std::string& name);

  /**
  Shows the user the name of the character
  @return : the name of the Character: character_name_
  */
    std::string getName() const;
  
  /**
  Sets the race of the character to the users input 
  @param  : the race of the Character (a string set to const): character_race
  @post   : sets the Character's race: character_race_ to the value of the parameter.
                 If the given race was invalid, set race_ to NONE.
  */
    void setRace(const std::string& character_race);

  /**
  Shows the user the race of the character
  @return : the race of the Character: character_race_,
            as a string with all UPPERCASE 
  */
    std::string getRace() const;
  
  /**
    Sets the vitality of the character to the user input 
    @param  : an integer for vitality: VITALITY_
    @pre    : vitality >= 0 : Characters cannot have negative health
    @post   : sets the VITALITY_ private member to the value of the parameter
  */
    void setVitality(const int& vitality);
  /**
    Shows the user the vitaltiy of the character 
    @return : the value stored in VITALITY_
  */
    int getVitality() const;

   /**
    Sets the armor to the users input 
    @param  : an integer for armor level: MAX_ARMOR_LEVEL_
    @pre    : armor >= 0 : Characters cannot have negative armor
    @post   : sets the MAX_ARMOR_LEVEL_ private member to the value of the parameter
  */
    void setArmor(const int& armor);
  
  /**
    Shows the user the max armor level
    @return : the value stored in MAX_ARMOR_LEVEL_
  */
    int getArmor() const;
  
  /**
    Sets the level to the users input 
    @param  : an integer level
    @pre    : level >= 0 : Characters cannot have a negative
    @post   : sets the CHARACTER_LEVEL private member to the value of the parameter
  */
    void setLevel(const int& level);

  /**
    Shows the user the characters level
    @return : the value stored in CHARACTER_LEVEL_
  */
    int getLevel() const;
  
  /**
    Sets a character as an enemy
    @post   : sets the enemy flag to true
  */
  void setEnemy();

  /**
    Shows the user if the character is an enemy 
    @return true if the character is an enemy, false otherwise
  */
    bool isEnemy() const;

    std::string to_upper(const std::string& name);
};



#endif
