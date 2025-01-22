/*
CSCI235 Fall 2023
Project 2 - Mage Class
Julianne Aguilar 
September 22, 2023
Mage.hpp declares the Mage class along with its private and public members
*/
#pragma once
#include "Character.hpp"

class Mage: public Character{
  private:
    std::string school_of_magic_;
    std::string weapon_;
    bool can_summon_incarnate_;

    /**
    Helper Function that checks if the user input is equivalent to an item in the array
    Used to check if the user input for magic school or weapon is valid
    @param:an array, either of the valid magic schools or valid weapons
    @param: a reference to an in representing the size of the array of type 
    @param: a referene to a string  representing the user's input of the magical school or weapon 
    @return:if the user's input is equivalent to an item in the array it returns the user's input
            if the user's input does not match any item in the array it returns "NONE"
    **/
    std::string check_if_valid(std::string arr[], const int& size,const std::string& input);

    /**
     Capitalizes every character in a string
     @param:a reference to a string that needs to be ensured that all characters are capitalized
     @return:returns the string with characters all capitalized
    **/
    std::string to_upper(const std::string& name);

  public:
    /**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default school of magic and weapon: "NONE". 
    **/
    Mage();

    /**
    Parameterized constructor.
    @param:The name of the character (a const string reference)
    @param:The race of the character (a const string reference)
    @param:The character's vitality (an integer). Default to 0
    @param:The character's max armor level (an integer). Default to 0
    @param:The character's level (an integer). Default to 0
    @param:A flag indicating whether the character is an enemy. Default to false.
    @param:The character's school of magic (a const string reference). Valid schools: 
          [ELEMENTAL, NECROMANCY, ILLUSION]. String inputs can be in lowercase, 
          but must be converted to uppercase when setting the variable.
          If the school name is invalid, set it to "NONE"
    @param:The character's choice of weapon (a const string reference). 
          Valid weapons: [WAND, STAFF]
          String inputs can be in lowercase, but must be converted to 
          uppercase when setting the variable.
          If the weapon is invalid, set it to "NONE"
    @param:A flag indicating whether the character is able to summon an 
          incarnate. Default to false.
    @post:The private members are set to the values of the corresponding 
          parameters.             
    **/
    Mage(const std::string& name, const std::string& race, int vitality = 0, int max_armor_level = 0, int level = 0, bool enemy = false, const std::string& school_of_magic = "NONE", const std::string& weapon = "NONE", bool can_summon_incarnate = false);

    /**
    Sets the user input to the school that the mage is in
    @param:a reference to a string representing the school of magic
    @post:sets the private member variable to the value of the parameter. If 
          the provided school of magic is not one of the following: [ELEMENTAL, 
          NECROMANCY, ILLUSION], do nothing and return false.
          String inputs can be in lowercase, but must be converted to 
          uppercase when setting the variable.
    @return:true if setting the variable was successful, false otherwise.
    **/
    bool setSchool(const std::string& school);

    /**
    Shows the user the characters school of magic 
    @return:the string indicating the character's school of magic
    **/
    std::string getSchool() const;

    /**
    Sets the user input for weapon as the characters weapon
    @param:a reference to a string representing the character's weapon
    @post:sets the private member variable to the value of the parameter.
          String inputs can be in lowercase, but must be converted to 
          uppercase when setting the variable.
          If the provided weapon is not one of the following: 
          [WAND, STAFF], do nothing and return false.
    @return:true if setting the variable was successful, false otherwise.
    **/
    bool setCastingWeapon(const std::string& weapon);

    /**
    Shows the user what the caracters weapon is 
    @return:the string indicating the character's weapon
    **/
    std::string getCastingWeapon() const;

    /**
    Sets the user input for the characters ability to summon an incarnate
    @param:a reference to boolean
    @post:sets the private member variable indicating whether the character can 
          summon an incarnate
    **/
    void setIncarnateSummon(const bool& can_summon);

    /**
      Shows the user if character can summon an incarnate
      @return  : the summon-incarnate flag
    **/
    bool hasIncarnateSummon() const;

};


