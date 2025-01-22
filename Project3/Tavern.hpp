
/*
CSCI235 Fall 2023
Project 3 - Tavern Class
Julianne Aguilar
October 6, 2023
Tavern.hpp declares the Tavern class along with its private and public members
Project Description: This programs allows to keep track of characters entering and exiting a tavern as well 
                     as displaying the characters data.
*/
#pragma once
#include "ArrayBag.hpp"
#include "Character.hpp"
#include <cmath>

class Tavern: public ArrayBag<Character>{
  private:
    int level_sum_;
    int enemy_count_;

  public:
    /**
    Default constructor.
    Default-initializes all private members. 
    **/
    Tavern();

    /** 
    Allows to add a character to the Tavern indicating their entrance
    @param: A const reference to a Character entering the Tavern
    @return: returns true if a Character was successfully added to the tavern (i.e. items_), false otherwise
    @post: adds Character to the Tavern and updates the level sum and the enemy count if the character is an 
           enemy.
    **/
    bool enterTavern(const Character& character);

    /** 
    Allows to remove a Character from the Tavern, indicating their exit
    @param: A const reference to a Character leaving the Tavern  
    @return: returns true if a character was successfully removed from the tavern (i.e. items_),               false otherwise
    @post: removes the character from the Tavern and updates the level sum and the enemy count
           if the character is an enemy.
    **/
    bool exitTavern(const Character& character);

    /** 
    Indicates the sum of all the characters levels that are in the Tavern
    @return: The integer level count of all the characters currently in the Tavern
    **/
    int getLevelSum() const;

    /** 
    Indicates all of the characters in the Tavern average level
    @return: The average level of all the characters in the Tavern
    @post: Computes the average level of the Tavern rounded to the NEAREST integer.
    **/
    int calculateAvgLevel() const;

    /** 
    Indicates the amount of enemies in the Tavern
    @return:  The integer enemy count of the Tavern
    **/
    int getEnemyCount() const;

    /** 
    Indicates the percent of enemies in the Tavern
    @return: The percentage (double) of all the enemy characters in the Tavern
    @post: Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
    **/
    double calculateEnemyPercentage() const;

    /** 
    Indicates the amount of Characters in the Tavern are of the inputted race
    @param: A const reference to a string representing a character Race with value in 
            ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
    @return: An integer tally of the number of characters in the Tavern of the given race. 
             If the argument string does not match one of the expected race values, 
             the tally is zero. 
    NOTE: no pre-processing of the input string necessary, only uppercase input will match.
    **/
    int tallyRace(const std::string& race);

    /**
    Displays the Tavern Data 
    @post: Outputs a report of the characters currently in the tavern in the form:
          "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x]\n\nThe average level is: 
          [x]\n[x]% are enemies.\n"
    NOTE: that the average level should be rounded to the NEAREST integer, and the enemy percentage should 
          be rounded to 2 decimal places.
    **/
    void tavernReport() const;


};
