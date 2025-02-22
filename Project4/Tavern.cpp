/*
CSCI235 Fall 2023
Project 4 - The Tainted Stew
Original Owner: Georgina Woo
Julianne Aguilar 
October 27, 2023
Tavern.cpp defines the constructors and private and public function implementation of the Tavern class
Project Description: This program utilizes polymorphism and inheritence to allow for the display of 
                     Character data unique to their status of being a Barbarian, Mage, Ranger, or Scoundrel. 
                     Allows for changes to private members of subclasses in response to the character eating 
                     tainted stew.
*/
#include "Tavern.hpp"
#include <fstream>
#include <vector>
#include <sstream>
/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}

/**
Parametized Constructor that reads a csv file containing Character data and dynamically allocates Character derived objects corressponding to their subclass,
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
Tavern::Tavern(const std::string& file){
  std::ifstream find(file);
  if(find.fail()){
    std::cerr << "File cannot be opened for reading." <<std::endl;
    exit(1);
  }
  std::string ignore,current_line, name, race, subclass, main, offhand, school_or_faction, affinities, temp;
  std::getline(find,ignore); //used to ignore the first line of the file that represent the column names
  int level, vitality, armor;
  bool enemy, summoning, disguise, enraged;
  //Sets each characters data in the current line to their corresponding variable 
  while(std::getline(find,current_line)){
    if(item_count_ < DEFAULT_CAPACITY){
      std::istringstream ss(current_line);
      std::getline(ss, name, ','); 
      std::getline(ss, race, ',');
      std::getline(ss, subclass, ',');
      std::getline(ss, temp, ','); 
      level = stoi(temp); //converts string type to an int type
      std::getline(ss, temp, ',');
      vitality = stoi(temp);
      std::getline(ss, temp, ',');
      armor = stoi(temp);
      std::getline(ss, temp, ',');
      enemy = stoi(temp);
      std::getline(ss, main, ',');
      std::getline(ss, offhand, ',');
      std::getline(ss, school_or_faction, ',');
      std::getline(ss, temp, ',');
      summoning = stoi(temp);
      std::getline(ss, affinities, ',');
      std::getline(ss, temp, ',');
      disguise = stoi(temp);
      std::getline(ss, temp, ',');
      enraged = stoi(temp);
      if(subclass == "BARBARIAN"){
        Barbarian * barb = new Barbarian(name, race, vitality, armor, level, enemy, main, offhand, enraged);
        add(barb);
      }
      else if(subclass == "MAGE"){
        Mage * mag = new Mage(name, race, vitality, armor, level, enemy, school_or_faction, main, summoning);
        add(mag);
      }
      else if(subclass == "SCOUNDREL"){
        Scoundrel * scou = new Scoundrel(name, race, vitality, armor, level, enemy, main, school_or_faction, disguise);
        add(scou);
      }
      else if(subclass == "RANGER"){
        Ranger * rang = new Ranger(name, race, vitality, armor, level, enemy);
        insertArrows(main, rang); 
        insertAffinities(affinities, rang); 
        rang -> setCompanion(summoning);
        add(rang);     
      } 
    }
  }
}

/** 
    Allows to add a character to the Tavern indicating their entrance
    @param:   A pointer to a character object entering Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character * a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character -> getLevel();
    if(a_character -> isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/**
    Allows to remove a Character from the Tavern, indicating their exit
    @param:   A pointer to a character object exiting Tavern
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character * a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character -> getLevel();
    if(a_character -> isEnemy())
      num_enemies_--;
      
    return true;
  }
  return false;
}



/** 
    @return:  The integer level count of all the characters currently in the Tavern
    **/
    int Tavern::getLevelSum()
    {
      return level_sum_;
    }



/** 
    @return:  The average level of all the characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the average level of the Tavern rounded to the NEAREST integer, and returns the integer value.
**/
int Tavern::calculateAvgLevel()
{
   return (level_sum_>0) ? round(double(level_sum_) / item_count_) : 0.0;

}



/** 
    @return:  The integer enemy count of the Tavern
    **/
    int Tavern::getEnemyCount()
    {
      return num_enemies_;
    }



/** 
    @return:  The percentage (double) of all the enemy characters in the Tavern
    @post:    Considers every character currently in the Tavern, updates the enemy percentage of the Tavern rounded to 2 decimal places, and returns the double value.
**/
double Tavern::calculateEnemyPercentage()
{
  double enemy_percent = (num_enemies_>0) ?  (double(num_enemies_) / item_count_) * 100: 0.0;
  return std::ceil(enemy_percent*100.0) / 100.0; //round up to to decimal places
 
}


/** 
    @param:   A string reference to a race 
    @return:  An integer tally of the number of characters in the Tavern of the given race
**/
int Tavern::tallyRace(const std::string &race)
{
  int frequency = 0;
  int curr_index = 0;   
  while (curr_index < item_count_)
  {
    if (items_[curr_index] -> getRace() == race)
    {
      frequency++;
    } 

    curr_index++; 
  }
  
  return frequency;
}


/**
  @post:    Outputs a report of the characters currently in the tavern in the form:
  "Humans: [x] \nElves: [x] \nDwarves: [x] \nLizards: [x] \nUndead: [x] \n\nThe average level is: [x] \n[x]% are enemies.\n\n"

  Example output: 
  Humans: 5
  Elves: 8
  Dwarves: 3
  Lizards: 7
  Undead: 2

  The average level is: 16
  24% are enemies.
*/
void Tavern::tavernReport()
{
  int humans = tallyRace("HUMAN");
  int elves = tallyRace("ELF");
  int dwarves = tallyRace("DWARF");
  int lizards = tallyRace("LIZARD");
  int undead = tallyRace("UNDEAD");
  
  std::cout << "Humans: " << humans << std::endl;
  std::cout << "Elves: " << elves << std::endl;
  std::cout << "Dwarves: " << dwarves << std::endl;
  std::cout << "Lizards: " << lizards << std::endl;
  std::cout << "Undead: " << undead << std::endl;
  std::cout << "\nThe average level is: " << calculateAvgLevel() << std::endl;
  std::cout << std::fixed << std::setprecision(2) << calculateEnemyPercentage() << "% are enemies.\n\n";
}

/**
Displays the data of all the characters in Tavern 
@post: For every character in the tavern, displays each character's information
**/
void Tavern::displayCharacters() const{
  for(int i = 0; i < getCurrentSize(); i++){
    items_[i] -> display();
  }
}

/**
Displays the characters in Tavern of a specified race
@param: a string reference to a race
@post: For every character in the tavern of the given race (only exact matches to the input string), 
       displays each character's information
**/
void Tavern::displayRace(const std::string& race){
  for(int i = 0; i < getCurrentSize(); i++){
    if(items_[i] -> getRace() == race){
      items_[i] -> display();
    }
  }
}

/**
Causes every character in tavern to eat tainted stew, and make changes to the characters
private member variables
@post: Every character in the tavern eats a tainted stew.
**/
void Tavern::taintedStew(){
  for(int i = 0; i < getCurrentSize(); i++){
    items_[i] -> eatTaintedStew();
  }
}

/**
Helper function that inserts the arrow type and quantity to the specified Ranger object
@param: a string containing the arrow type and quantity in the format: [TYPE] [QUANTITY];[TYPE] [QUANTITY]
        a pointer to a Ranger object 
@post: adds the arrow type and quantity to the ranger object passed in the parameter
**/
void Tavern::insertArrows(std::string main, Ranger* obj)
{
  std::string temp;
  std::istringstream ss2(main);
  while(std::getline(ss2, temp, ' ')){
    std::string arrow = temp;
    std::getline(ss2, temp, ';');
    int quantity = stoi(temp);
    obj -> addArrows(arrow, quantity);
  }
}

/**
Helper function that inserts the affinities to the specified Ranger object
@param: a string containing the affinities in the format: [AFFINITY1];[AFFINITY2]
        a pointer to a Ranger object 
@post: adds the affinities to the ranger object passed in the parameter
**/
void Tavern::insertAffinities(std::string affinities, Ranger *obj)
{
  size_t semi;
  while(!affinities.empty()){
    semi = affinities.find(";");
    std::string affinity = affinities.substr(0, semi);
    affinities.erase(0, affinity.length() + 1);
    obj -> addAffinity(affinity);
  }
  
}
