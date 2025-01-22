/*
CSCI235 Fall 2023
Project 2 - Scoundrel Class
Julianne Aguilar 
September 22, 2023
Scoundrel.hpp declares the Scoundrel class along with its private and public members
*/
#pragma once
#include "Character.hpp"

enum Dagger{WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE};

class Scoundrel: public Character{
  private:
    Dagger dagger_;
    std::string faction_;
    bool has_disguise_;

    /**
    Captilizes every character of a string 
    @param: a string that needs to be ensured that all characters are capitalized
    @return: returns the string with characters all capitalized
    **/
    std::string to_upper(const std::string& name);

    /**
    Checks if the faction type is a valid type by traversing through a list of 
    valid faction types
    @param: a reference to a string that represents a faction type, string inputs can be lower 
            case but are changed to all upper case
    @post:  The string input is changed to all uppercased 
    @return:  The string input faction type in all uppercase if it detected as valid, if invalid 
              input returns false.
*/
    std::string check_valid_faction(const std::string& input);

  public:
    /**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default dagger: WOOD. Default faction: "NONE". 
    **/
    Scoundrel();

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
    Scoundrel(const std::string& name, const std::string& race, int vitality = 0, int max_armor_level = 0, int level = 0, bool enemy = false, const std::string& dagger_type = "WOOD", const std::string& faction = "NONE", bool has_disguise = false);

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
    void setDagger(const std::string& dagger_type);

    /**
    Returns what characters dagger type is
    @return: the string indicating the character's dagger type
    **/
    std::string getDagger() const;

    /**
    Sets the input as the characters faction
    @param: a reference to a string representing the character's Faction
    @post:  sets the private member variable to the value of the parameter. 
            String inputs can be in lowercase, but must be converted to 
            uppercase when setting the variable.
            If the provided faction is not one of the following: 
            [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
            do nothing and return false.
    @return: true if setting the variable was successful, false otherwise.
    **/
    bool setFaction(const std::string& faction);

    /** Returns the characters faction
    @return: the string indicating the character's Faction
    **/
    std::string getFaction() const;

    /**
    Sets the user input to whether or not the character has a disguise
    @param: a reference to boolean
    @post: sets the private member variable indicating whether the character has a disguise
    **/
    void setDisguise(const bool& has_disguise);

    /**
    Returns whether or not the character has a disguise
    @return: the visual aid flag
    **/
    bool hasDisguise() const;

};
