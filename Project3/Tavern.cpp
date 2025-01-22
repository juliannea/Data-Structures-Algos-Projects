/*
CSCI235 Fall 2023
Project 3 - Tavern Class
Julianne Aguilar
October 6, 2023
Tavern.cpp defines the constructors and private and public function implementation of the Tavern class
Project Description: This programs allows to keep track of characters entering and exiting a tavern as well 
                     as displaying the characters data.
*/
#include "Tavern.hpp"

/**
Default constructor.
Default-initializes all private members. 
**/
Tavern::Tavern() : ArrayBag<Character>(){
  level_sum_ = 0;
  enemy_count_ = 0;
}

/** 
Allows to add a character to the Tavern indicating their entrance
@param: A const reference to a Character entering the Tavern
@return: returns true if a Character was successfully added to the tavern (i.e. items_), false otherwise
@post: adds Character to the Tavern and updates the level sum and the enemy count if the character is an 
       enemy.
**/
bool Tavern::enterTavern(const Character& character){
  items_[item_count_] = character;
  item_count_++;

  if(contains(character) == true){
    level_sum_ += character.getLevel();
    if(character.isEnemy() == true){
      enemy_count_++;
    }
    return true;
  }

  return false;
}

/** 
Allows to remove a Character from the Tavern, indicating their exit
@param: A const reference to a Character leaving the Tavern  
@return: returns true if a character was successfully removed from the tavern (i.e. items_),               false otherwise
@post: removes the character from the Tavern and updates the level sum and the enemy count
       if the character is an enemy.
**/
bool Tavern::exitTavern(const Character& character){
  remove(character);
  if(contains(character) == false){
    level_sum_ -= character.getLevel();
    if(character.isEnemy() == true){
      enemy_count_ -= 1;
    }
    return true;
  }
  return false;
}

/** 
Indicates the sum of all the characters levels that are in the Tavern
 @return: The integer level count of all the characters currently in the Tavern
**/
int Tavern::getLevelSum() const{
  return level_sum_;
}

/** 
Indicates all of the characters in the Tavern average level
@return: The average level of all the characters in the Tavern
@post: Computes the average level of the Tavern rounded to the NEAREST integer.
**/
int Tavern::calculateAvgLevel() const{
  int avg = std::round(((level_sum_*1.0)/(getCurrentSize()*1.0))/1.0);
  return avg;
}

/** 
Indicates the amount of enemies in the Tavern
@return:  The integer enemy count of the Tavern
**/
int Tavern::getEnemyCount() const{
  return enemy_count_;
}

/** 
Indicates the percent of enemies in the Tavern
@return: The percentage (double) of all the enemy characters in the Tavern
@post: Computes the enemy percentage of the Tavern rounded up to 2 decimal places.
**/
double Tavern::calculateEnemyPercentage() const{
  double current_size = getCurrentSize() * 1.0;
  double enemy_count = enemy_count_ * 1.0;
  double avg = std::round(enemy_count/current_size* 10000.0)/100.0;
  return avg;
}

/** 
Indicates the amount of Characters in the Tavern are of the inputted race
@param: A const reference to a string representing a character Race with value in 
        ["NONE", "HUMAN", "ELF", "DWARF", "LIZARD", "UNDEAD"]
@return: An integer tally of the number of characters in the Tavern of the given race. 
         If the argument string does not match one of the expected race values, 
         the tally is zero. 
NOTE: no pre-processing of the input string necessary, only uppercase input will match.
**/
int Tavern::tallyRace(const std::string& race){
  std::string arrRace[6] = {"UNDEAD", "ELF", "NONE", "HUMAN", "DWARF", "LIZARD"};
  bool valid = false;
  for(int i = 0; i < 6; i++){
    if(race == arrRace[i]){
      valid = true;
    }
  }
  int tally = 0;
  if(valid == true){
    for(int j = 0; j < item_count_; j++){
      if(race == items_[j].getRace()){
        tally++;
      }
    } 
    return tally;     
  }
  return 0;
}

 /**
Displays the Tavern Data 
@post: Outputs a report of the characters currently in the tavern in the form:
       "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x]\n\nThe average level is: 
        [x]\n[x]% are enemies.\n"
NOTE: that the average level should be rounded to the NEAREST integer, and the enemy percentage should 
      be rounded to 2 decimal places.
**/
void Tavern::tavernReport() const{
  Tavern current;
  for(int i = 0; i < item_count_; i++){
    current.add(items_[i]);
  }
  std::cout << "Humans: " << current.tallyRace("HUMAN") << "\n";
  std::cout << "Elves: " << current.tallyRace("ELF") << "\n";
  std::cout << "Dwarves: " << current.tallyRace("DWARF") << "\n";
  std::cout << "Lizards: " << current.tallyRace("LIZARD") << "\n";
  std::cout << "Undead: " << current.tallyRace("UNDEAD") << "\n";
  std::cout << "The average level is: " << calculateAvgLevel() << "\n";
  std::cout << calculateEnemyPercentage() << "% are enemies.\n";

}
