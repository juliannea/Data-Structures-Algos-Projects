/*
CSCI235 Fall 2023
Project 4 - The Tainted Stew
Original Owner: Georgina Woo
Julianne Aguilar 
October 27, 2023
Tavern.hpp declares the Tavern class along with its private and public members
Project Description: This program utilizes polymorphism and inheritence to allow for the display of 
                     Character data unique to their status of being a Barbarian, Mage, Ranger, or Scoundrel. 
                     Allows for changes to private members of subclasses in response to the character eating 
                     tainted stew.
*/
#ifndef TAVERN_
#define TAVERN_

#include "ArrayBag.hpp"
#include "Character.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"
#include "Scoundrel.hpp"
#include "Mage.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

class Tavern : public ArrayBag<Character*>{
  public:
    /** Default Constructor **/
    Tavern(); 

    /**
    Parametized constructor that reads a csv file containing Character data and dynamically allocates Character derived objects corressponding to their subclass, 
    and adds them to Tavern
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows (each numbered item appears separated by comma, only one value for each numbered item):
      1. Name: An uppercase string
      2. Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      3. Subclass: An uppercase string [BARBARIAN, MAGE, SCOUNDREL, RANGER]
      4. Level/Vitality/Armor: A positive integer
      5. Enemy: 0 (False) or 1 (True)
      6. Main: Uppercase string or strings representing the main weapon (Barbarian and Mage), Dagger type (Scoundrel), or arrows (Ranger). 
      A ranger's arrows are of the form [TYPE] [QUANTITY];[TYPE] [QUANTITY], where each arrow type is separated by a semicolon, and the type and
      its quantity are separated with a space.
      7. Offhand: An uppercase string that is only applicable to Barbarians, and may be NONE if the Barbarian does not have an offhand weapon, 
      or if the character is of a different subclass.
      8. School/Faction: Uppercase strings that represent a Mage's school of magic: [ELEMENTAL, NECROMANCY, ILLUSION] or a Scoundrel's faction: 
      [CUTPURSE, SHADOWBLADE, SILVERTONGUE], and NONE where not applicable
      9. Summoning: 0 (False) or 1 (True), only applicable to Mages (summoning an Incarnate) and Rangers (Having an Animal Companion)
      10. Affinity: Only applicable to Rangers. Affinities are of the form [AFFINITY1];[AFFINITY2] where multiple affinities are separated by a 
      semicolon. Th value may be NONE for a Ranger with no affinities, or characters of other subclasses.
      11. Disguise: 0 (False) or 1 (True), only applicable to Scoundrels, representing if they have a disguise.
      12. Enraged: 0 (False) or 1 (True), only applicable to Barbarians, representing if they are enraged.
      @post: Each line of the input file corresponds to a Character subclass and dynamically allocates Character derived objects, adding them to the Tavern.
*/
    Tavern(const std::string& file);

    /** 
        Allows to add a character to the Tavern indicating their entrance
        @param:   A pointer to a character object entering Tavern
        @return:  returns true if a Character was successfully added to items_, false otherwise
        @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
    **/
    bool enterTavern(Character * a_character);

    /**
        Allows to remove a Character from the Tavern, indicating their exit
        @param:   A pointer to a character object exiting Tavern
        @return:  returns true if a character was successfully removed from items_, false otherwise
        @post:    removes the character from the Tavern and updates the level sum  and the enemy if the character is an enemy.
    **/
    bool exitTavern(Character * a_character);

   

    /** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int getLevelSum();


    /** 
        @return:  The average level of all the characters in the Tavern
        @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, 
                  and returns the integer value.
    **/
    int calculateAvgLevel();



    /** 
    @return:  The integer enemy count of the Tavern
    **/
    int getEnemyCount();

    /** 
        @return:  The percentage (double) of all the enemy characters in the Tavern
        @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, 
                 and returns the double value.
    **/
    double calculateEnemyPercentage();



    /** @param:   A string reference to a race 
        @return:  An integer tally of the number of characters in the Tavern of the given race
    **/
    int tallyRace(const std::string &race);




    /**
      @post:    Outputs a report of the characters currently in the tavern in the form:
      "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n"
      Note that the average level should be rounded to the NEAREST integer, and the enemy percentage should be rounded to 2 decimal

      Example output: 
      Humans: 3
      Elves: 5
      Dwarves: 8
      Lizards: 6
      Undead: 0

      The average level is: 7
      46.67% are enemies.
    */
    void tavernReport();

    /**
    Displays the data of all the characters in Tavern 
    @post: For every character in the tavern, displays each character's information
    **/
    void displayCharacters() const;

    /**
    Displays the characters in Tavern of a specified race
    @param: a string reference to a race
    @post: For every character in the tavern of the given race (only exact matches to the input string), 
           displays each character's information
    **/
    void displayRace(const std::string& race);
    
    /**
    Causes every character in tavern to eat tainted stew, and make changes to the characters
    private member variables
    @post: Every character in the tavern eats a tainted stew.
    **/
    void taintedStew();

   


  private:
    int level_sum_; // An integer sum of the levels of all the characters currently in the tavern
    int num_enemies_; //number of enemies currently in the Tavern

    /**
    Helper function that inserts the arrow type and quantity to the specified Ranger object
    @param: a string containing the arrow type and quantity in the format: [TYPE] [QUANTITY];[TYPE] [QUANTITY]
            a pointer to a Ranger object 
    @post: adds the arrow type and quantity to the ranger object passed in the parameter
    */
    void insertArrows(std::string main, Ranger* obj);

    /**
    Helper function that inserts the affinities to the specified Ranger object
    @param: a string containing the affinities in the format: [AFFINITY1];[AFFINITY2]
            a pointer to a Ranger object 
    @post: adds the affinities to the ranger object passed in the parameter
    **/
    void insertAffinities(std::string affinities, Ranger* obj);

};
#endif
