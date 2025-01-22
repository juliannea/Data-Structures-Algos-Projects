/*
CSCI235 Fall 2023
Project 2 - Ranger Class
Julianne Aguilar 
September 22, 2023
Ranger.hpp declares the Ranger class along with its private and public members
*/
#pragma once
#include "Character.hpp"
#include <vector>

struct Arrows{
  std::string type_;
  int quantity_;
};

class Ranger: public Character{
  private:
    std::vector<Arrows> arrows_;
    std::vector<std::string> affinities_;
    bool has_companian_;

    /**
    Captilizes every character of a string 
    @param: a reference to a string that needs to be ensured that all characters are capitalized
    @return: returns the string with characters all capitalized
    **/
    std::string to_upper(const std::string& name);

    /**
    Filters a vector of arrows so that only the valid types are added
    to the characters vector of arrows.
    Valid arrow types are: [WOOD,FIRE,WATER,POISON,BLOOD]
    Lowercase valid arrow types are retained but converted to uppercase
    If vector contains invalid arrows, arrows are not added to the returned vector
    @param:  a reference to a vector of arrows of Arrow type
    @post: adds the valid arrow types to the characters vectorin all uppercase
    **/
    void filter_arrows(const std::vector<Arrows>& arrow_vector);

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
    void filter_affinities(const std::vector<std::string>& affinity_arrow);

  public:
    /**
    Default constructor.
    Default-initializes all private members. 
    Default character name: "NAMELESS". Booleans are default-initialized to False. 
    Default school of magic and weapon: "NONE". 
    */
    Ranger();

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
    Ranger(const std::string& name, const std::string& race, int vitality = 0,int max_armor_level = 0, int level = 0, bool enemy = false, const std::vector<Arrows>& arrows = std::vector<Arrows>(), const std::vector<std::string>& affinities = std::vector<std::string>(), bool has_companion = false);

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
    bool addArrows(const std::string& arrow_type, const int& quantity);

    /**
    Returns the vector of the character arrows
    @return: a vector of the Character's arrows
    **/
    std::vector<Arrows> getArrows() const;

    /**
    Allows the character to fire one of their arrows from their vector
    @param: a reference to string representing the arrow type
    @post: If the character has the listed arrow AND enough arrows to fire one, 
           the quantity of remaining arrows in the vector is updated.
           Lowercase valid arrow types are accepted but converted to uppercase.
           If firing the last arrow, simply decrement the quantity to 0.
    @return: True if the character had the listed arrow AND enough arrows, False otherwise.
    **/
    bool fireArrow(const std::string& arrow_type);

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
    bool addAffinity(const std::string& affinity);

    /**
    Returns all of the characters affinities in their vector
    @return: a vector of the Character's affinities
    **/
    std::vector<std::string> getAffinities() const;

    /**
    Sets whether or not the character can recruit and animal companion based on the input
    @param: a reference to a boolean indicating whether the character is able to recruit 
            an animal companion
    @post: sets the private member variable to the value of the parameter.
    **/
    void setCompanion(const bool& recruit);

    /**
    Returns whether or not the character can recruit an animal conpanion
    @return: a boolean indicating whether the character is able to recruit an animal companion
    **/
    bool getCompanion() const;

};

