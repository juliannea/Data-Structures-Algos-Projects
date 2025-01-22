/*
CSCI235 Fall 2023
Project 6 - C-C-Combat!
Original Owner: Georgina Woo
Julianne Aguilar
November 28, 2023
Taven.cpp defines the constructors and private and public function implementation of the Tavern class
Project Description: Allows the main character to combat enemies in the Tavern, original file was modified for project 6
*/
#include "Tavern.hpp"

/** Default Constructor **/
Tavern::Tavern() : ArrayBag<Character*>(), level_sum_{0}, num_enemies_{0}
{
}

/**
    @param: the name of an input file
    @pre: Formatting of the csv file is as follows:
      Name: An uppercase string
      Race: An uppercase string [HUMAN, ELF, DWARF, LIZARD, UNDEAD]
      Vitality/Armor/Level: A positive integer
      Enemy: 0 (False) or 1 (True)
    
    @post: Each line of the input file corresponds to a Character that enters the Tavern.
  */
    Tavern::Tavern(const std::string& filename)
    {
      std::ifstream fin(filename);
      std::string line;
      std::getline(fin, line);
      std::string name, race, string_vitality, string_armor, string_level, string_enemy;
      int vitality, armor, level;
      bool enemy;
      
      while(std::getline(fin, line))
      {
        std::istringstream iss(line);
        std::getline(iss, name, ',');
        std::getline(iss, race, ',');

        std::getline(iss, string_vitality, ',');
        std::istringstream(string_vitality) >> vitality;

        std::getline(iss, string_armor, ',');
        std::istringstream(string_armor) >> armor;

        std::getline(iss, string_level, ',');
        std::istringstream(string_level) >> level;

        std::getline(iss, string_enemy, ',');
        std::istringstream(string_enemy) >> enemy;
        Character* character = new Character(name, race, vitality, armor, level, enemy);
        enterTavern(character);
      }
    }


/** 
    @param:   A reference to a Character entering the Tavern
    @return:  returns true if a Character was successfully added to items_, false otherwise
    @post:    adds Character to the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::enterTavern(Character* a_character)
{
  if(add(a_character))
  {
    level_sum_ += a_character->getLevel();
    if(a_character->isEnemy())
      num_enemies_++;
     
    return true;
  }
  else
  {
    return false;
  }
}

/** @param:   A reference to a Character leaving the Tavern  
    @return:  returns true if a character was successfully removed from items_, false otherwise
    @post:    removes the character from the Tavern and updates the level sum and the enemy count if the character is an enemy.
**/
bool Tavern::exitTavern(Character* a_character)
{
  if(remove(a_character))
  {
    level_sum_ -= a_character->getLevel();
    if(a_character->isEnemy())
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
    if (items_[curr_index]->getRace() == race)
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
    @post: For every character in the tavern, displays each character's information
*/
void Tavern::displayCharacters()
{
  for(int i = 0; i < item_count_; i++)
  {
    items_[i]->display();
  }
}

/**
    @param: a string reference to a race
    @post: For every character in the tavern of the given race, displays each character's information
*/
void Tavern::displayRace(const std::string &race)
{
  for(int i = 0; i < item_count_; i++)
  {
    if(items_[i]->getRace() == race)
    {
      items_[i]->display();
    }
  }
}

/**
Assigns the main character of the Tavern 
@param: a Character pointer 
@post: sets the Tavern's main character to the pointer that is given
*/
void Tavern::setMainCharacter(Character* main){
  main_character = main;
}

/**
Returns the main characters pointer in the Tavern 
@return: a pointer to the main character in the Tavern, nullptr if there is no main character
*/
Character *Tavern::getMainCharacter() const{
  if(main_character != nullptr){
    return main_character;
  }
  return nullptr;
}

/**
Compares which character is in a lesser level
@param: two Character pointers
@return: true if the lhs Character's level is less than the rhs Character's level
*/
bool Tavern::levelIsLess(const Character *lhs, const Character *rhs)
{
  if(lhs -> getLevel() < rhs -> getLevel()){
    return true;
  }
  return false;
}

/**
Compares which character is in a higher level
@param: two Character pointers
@return: true if the lhs Character's level is greater than the rhs Character's level
*/
bool Tavern::levelIsGreater(const Character *lhs, const Character *rhs)
{
  if(lhs -> getLevel() > rhs -> getLevel()){
    return true;
  }
  return false;
}

/**
Compares which character has less vitality
@param: two Character pointers
@return: true if the lhs Character's vitality is less than the rhs Character's vitality
*/
bool Tavern::vitalityIsLess(const Character *lhs, const Character *rhs)
{
  if(lhs -> getVitality() < rhs -> getVitality()){
    return true;
  }
  return false;
}

/**
Compares which character has the higher vitality
@param: two Character pointers
@return: true if the lhs Character's vitality is more than the rhs Character's vitality
*/
bool Tavern::vitalityIsGreater(const Character *lhs, const Character* rhs)
{
  if(lhs -> getVitality() > rhs -> getVitality()){
    return true;
  }
  return false;
}

/**
Adds characters that are markes as an enemy in the combat queue, sorting depends on param input 
@pre: The combat queue should be emptied before the characters are added to the queue
@param: A string reference to a sorting filter with a default value of "NONE"
@post: With default filter "NONE": add every character marked as an enemy to the combat queue
: With the filter "LVLASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their level.
: With the filter "LVLDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their level.
: With the filter "HPASC": add every character in the Tavern marked as an enemy to the combat queue, in ascending order based on their vitality.
: With the filter "HPDES": add every character in the Tavern marked as an enemy to the combat queue, in descending order based on their vitality.
*/
void Tavern::createCombatQueue(const std::string &filter){
    //if the queue is not empty, empty it out
  if(!combat_queue.empty()){
    while(!combat_queue.empty()){
      combat_queue.pop(); //continues to remove the front element of the queue until empty
    }
  }
  if(filter == "NONE"){
    for(int i = 0; i < item_count_; i++){
      if(items_[i] -> isEnemy() == true){
        combat_queue.push(items_[i]);
      }
    }
  }
  else if(filter == "LVLASC"){
    std::vector<Character*> temp_vector;
    for(int i = 0; i < item_count_; i++){
      if(items_[i] -> isEnemy() == true){
        temp_vector.push_back(items_[i]);
      }
    }
    //sorts the vector in ascending order based on their level
    std::sort(temp_vector.begin(), temp_vector.end(), [] (Character* lhs, Character* rhs){
      return levelIsLess(lhs, rhs);
    });
    //adds to combat queue in ascending order based on level
    for(int j = 0; j < temp_vector.size(); j++){
      combat_queue.push(temp_vector[j]);
    }
  }
  else if(filter == "LVLDES"){
    std::vector<Character*> temp_vector;
    for(int i = 0; i < item_count_; i++){
      if(items_[i] -> isEnemy() == true){
        temp_vector.push_back(items_[i]);
      }
    }
    //sorts the vector in descending order based on their level
    std::sort(temp_vector.begin(), temp_vector.end(), [] (Character* lhs, Character* rhs){
      return levelIsGreater(lhs, rhs);
    });
    //adds to combat queue in descending order based on level
    for(int j = 0; j < temp_vector.size(); j++){
      combat_queue.push(temp_vector[j]);
    }
  }
  else if(filter == "HPASC"){
    std::vector<Character*> temp_vector;
    for(int i = 0; i < item_count_; i++){
      if(items_[i] -> isEnemy() == true){
        temp_vector.push_back(items_[i]);
      }
    }
    //sorts the vector in ascending order based on their vitality
    std::sort(temp_vector.begin(), temp_vector.end(), [] (Character* lhs, Character* rhs){
      return vitalityIsLess(lhs, rhs);
    });
    //adds to combat queue in ascending order based on vitality
    for(int j = 0; j < temp_vector.size(); j++){
      combat_queue.push(temp_vector[j]);
    }
  }
  else if(filter == "HPDES"){
    std::vector<Character*> temp_vector;
    for(int i = 0; i < item_count_; i++){
      if(items_[i] -> isEnemy() == true){
        temp_vector.push_back(items_[i]);
      }
    }
    //sorts the vector in descending order based on their vitality
    std::sort(temp_vector.begin(), temp_vector.end(), [] (Character* lhs, Character* rhs){
      return vitalityIsGreater(lhs, rhs);
    });
    //adds to combat queue in descending order based on vitality
    for(int j = 0; j < temp_vector.size(); j++){
      combat_queue.push(temp_vector[j]);
    }
  }
}

/**
Returns the character at the front of the Combat Queue
@post: returns a pointer to the Character at the front of the Combat Queue. 
      : If there are no characters in the queue, return nullptr
*/
Character *Tavern::getTarget() const
{
  if(!combat_queue.empty()){
    return combat_queue.front();
  }
  return nullptr;
}

/**
Shows the details of each character in the combat queue
@post: Prints the details of each character in the combat queue in the following form:
     : [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
*/
void Tavern::printCombatQueue() const{
  std::queue<Character*> temp = combat_queue;
  while(!temp.empty()){
    std::cout << "(ENEMY) " << temp.front() -> getName() <<": LEVEL " << temp.front() -> getLevel() << " " << temp.front() -> getRace() << ".";
    std:: cout << "\nVITALITY: " << temp.front() -> getVitality() << "\nARMOR: " << temp.front() -> getArmor() << "\n";
    temp.pop();

  }
}

/** 
Shows and allows the selection of main characters actions and displays enemy targets details
@post: If there are no enemies in the combat queue, do nothing.
      : Otherwise do all of the following
      :     - The action queue must be emptied before the new actions are added.
      :     - Print out the start of turn and details of the target enemy in the form:
              : YOUR TURN\n
              : (ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n\n 

      :     - Repeat the following process thrice (i.e. read three actions from input): 
      :           - Print the actions that are available to the main character, and read 
                    a non-negative number from input, corresponding to an action. 
                    Printing the available options should be of the following form. 
                    You may consider writing a helper function for this.
                    :Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n
      :           - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
                  keep prompting for a non-negative number that is within range, by
                  printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n" and prompt for input again.
      :           - When a valid action is read, 
                  it is added to the main character's action queue.    
*/
void Tavern::actionSelection(){
  if(!combat_queue.empty()){
    main_character -> emptyActionQueue();
    std::cout << "YOUR TURN\n";
    std::cout << "(ENEMY) " << getTarget() -> getName() << ": LEVEL " << getTarget() -> getLevel() << " " << getTarget() -> getRace() << "."; 
    std::cout << "\nVITALITY: " << getTarget() -> getVitality() << "\nARMOR: " << getTarget() -> getArmor() << "\n\n";
    for(int i = 0; i < 3; i++){
      chooseActions();
    }
  }
}

/**
@post: If there are no actions in the main character's action queue, 
        or there are no enemies in the combat queue, do nothing.
        
        Otherwise do all of the following:            
        
        1. If the Buff stack is not empty, apply the buff once and decrement the turns.
            Any time a Buff's turns_ goes to zero, it is removed
            from the stack. Print out the results of the action as described below.
        2. While there are actions on the action queue:
        - take the next action off the queue
        - if the next action is  a buff, apply once and push it onto the buff stack after 
          decrementing the turns. 
          BUFF_Heal lasts for 3 turns in total, while BUFF_MendMetal lasts
          for 2 turns in total. Print out the results of the action as described below.
        - if the next action is an attack, execute it against the enemy at the front of
          the combat queue. Print out the results of the action as described below. 
          - if after this action there are no more enemies to fight, clear the action
            queue and return.
        3. Print "END OF TURN\n" 
  
    : More details:

    : After applying each action, print out the results of the action as follows:
    : [MAINCHARACTER NAME] used [ACTION NAME]!
    : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
    : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 

      Where [ACTION NAME] is one of [Heal, MendMetal, Strike, ThrowTomato]
    
    :   Whenever an enemy's vitality becomes <=0 after an attack, also print out 
        "[CHARACTER NAME] DEFEATED\n" 
        and remove the enemy from the combat queue AND let them exit the tavern. 
        Then carry out the remaining actions, if any, against the next enemy on the
        combat queue.
  
*/
void Tavern::turnResolution(){

  if(main_character -> hasActions() || !combat_queue.empty()){
    //if buff stack not empty 
    if(main_character -> hasBuff()){ 
      std::string top_buff = main_character -> getTopBuff();
      //apply top of Buff stack, decrements its turns, removes from stack if turns = 0
      main_character -> applyTopBuff(); 
      //print main characters info
      std::cout << main_character -> getName() << " used " << top_buff << "!";
      std::cout <<"\n(YOU) " << main_character -> getName() << ": LEVEL" << main_character -> getLevel() << " " << main_character -> getRace() << ".";
      std::cout << "\nVITALITY: " << main_character -> getVitality();
      std::cout << "\nARMOR: " << main_character -> getArmor() << "\n";
      //print enemies info
      std::cout << "\n(ENEMY) " << getTarget() -> getName() << ": LEVEL " << getTarget() -> getLevel() << " " << getTarget() -> getRace() << ".";
      std::cout << "\nVITALITY: " << getTarget() -> getVitality();
      std::cout << "\nARMOR: " << getTarget() -> getArmor() << "\n\n"; 
    }
    
    while(main_character -> hasActions()){
      //if there are no more enemeies to fight clear action queue 
      if(combat_queue.empty()){
        main_character -> emptyActionQueue();
      }
      //if the enemy has vitality  
      else if(getTarget() -> getVitality() > 0 && !combat_queue.empty()){
        //gets the int rep of the first action being applied 
        int action = main_character -> getAction();
        std::string action_str = actionToString(action);
        //removes up to underscore from the string
        size_t underscore = action_str.find("_");
        action_str = action_str.substr(underscore +1, action_str.length());
        main_character -> applyActions(getTarget());
        //print main character info 
        std::cout << main_character -> getName() << " used " << action_str << "!";
        std::cout <<"\n(YOU) " << main_character -> getName() << ": LEVEL" << main_character -> getLevel() << " " << main_character -> getRace() << ".";
        std::cout << "\nVITALITY: " << main_character -> getVitality();
        std::cout << "\nARMOR: " << main_character -> getArmor() << "\n";
        //print enemy info
        std::cout << "\n(ENEMY) " << getTarget() -> getName() << ": LEVEL " << getTarget() -> getLevel() << " " << getTarget() -> getRace() << ".";
        std::cout << "\nVITALITY: " << getTarget() -> getVitality();
        std::cout << "\nARMOR: " << getTarget() -> getArmor() << "\n\n"; 
      }
      else if(getTarget() -> getVitality() <= 0 && !combat_queue.empty()){
        std::cout << getTarget() -> getName() << " DEFEATED\n";
        //let enemy exit tavern
        exitTavern(getTarget());
        //remove enemy from combat queue 
        combat_queue.pop();
        //apply action to new target if the combat queue is not empty 
        if(!combat_queue.empty()){
          main_character -> applyActions(getTarget());
          std::cout << "\n(ENEMY) " << getTarget() -> getName() << ": LEVEL " << getTarget() -> getLevel() << " " << getTarget() -> getRace() << ".";
          std::cout << "\nVITALITY: " << getTarget() -> getVitality();
          std::cout << "\nARMOR: " << getTarget() -> getArmor() << "\n\n"; 

        }
      
      }
      
    }
    std::cout << "END OF YOUR TURN\n";
  }
}

/**
@param: A pointer to the enemy
@post: Do all of the following:
    : 1. If the enemy's buff stack is not empty, apply buff once and decrement the
      turns. Any time a Buff's turns_ goes to zero, it is removed
      from the stack. Print out the results of the action as described below.
    : 2. Pick a random Action 
        (one of BUFF_Heal, BUFF_MendMetal, ATT_Strike, ATT_ThrowTomato). 
    : If the selected action is a buff, apply once immediately and add it to the 
      enemy's buff stack, performing the necessary turns update. 
      Print out the results of the action as described below.
    : If the selected action is an attack, execute it against the main character.
      Print out the results of the action as described below. 
    : More details:
    
    : After applying each action, print out the results of the action as follows:
    : [ENEMY NAME] used [ACTION NAME]!
    : \n(ENEMY) [ENEMY NAME]: LEVEL [ENEMY LEVEL] [ENEMY RACE]. \nVITALITY: [ENEMY VITALITY] \nARMOR: [ENEMY ARMOR]\n 
    : \n(YOU) [MAINCHARACTER NAME]: LEVEL [MAINCHARACTER LEVEL] [MAINCHARACTER RACE]. \nVITALITY: [MAINCHARACTER VITALITY] \nARMOR: [MAINCHARACTER ARMOR]\n
*/
void Tavern::enemyTurn(Character *enemy){
  if(enemy -> hasBuff()){
    std::string top_buff = enemy -> getTopBuff();
    enemy -> applyTopBuff();
    std::cout << enemy -> getName() << " used " << top_buff << "!\n";
  }
  int random_action = rand()% 4 + 1; //pick random action, range from 1 to 4 
  std::string random_action_str = actionToString(random_action);
  //if the action is  buff 
  if(random_action_str.find("BUFF") !=std::string::npos){
      Buff temp;
      temp.name_ = random_action_str;
      if(random_action_str.find("Heal") != std::string::npos ){ // if the buff is heal 
        enemy -> heal(); //apply heal once
        temp.turns_ = 2; 
      }
      else if(random_action_str.find("MendMetal") != std::string::npos ){//if the buff is mendmetal
        enemy -> mendMetal(); //apply mendMetal once
        temp.turns_ = 1; 
      }
      enemy -> addBuff(temp); //push it into the buff stack 
  }
   //if its an attack action
  else if(random_action_str.find("ATT") !=std::string::npos){
    //execute attack against main character 
    if(random_action_str.find("Strike") != std::string::npos ){ // if Strike attack
      enemy -> strike(main_character);
      
    }
    else if(random_action_str.find("ThrowTomato") != std::string::npos ){//if ThrowTomato attack
      enemy -> throwTomato(main_character);
    }
  }
  //removes the "BUFF_" or "ATT_" for printing 
  size_t underscore = random_action_str.find("_");
  random_action_str = random_action_str.substr(underscore +1, random_action_str.length());
  //print info 
  std::cout << enemy -> getName() << " used " << random_action_str << "!";
  std::cout << "\n(ENEMY) " << enemy -> getName() << ": LEVEL " << getTarget() -> getLevel() << " " << getTarget() -> getRace() << ".";
  std::cout << "\nVITALITY: " << enemy -> getVitality();
  std::cout << "\nARMOR: " << enemy -> getArmor() << "\n"; 

  std::cout << "\n(YOU) " << main_character -> getName() << ": LEVEL " << main_character -> getLevel() << " " << main_character -> getRace() << ".";
  std::cout << "\nVITALITY: " << main_character -> getVitality();
  std::cout << "\nARMOR: " << main_character -> getArmor() << "\n"; 
  std::cout << "END OF ENEMY TURN\n\n";
}

/**
@post: While the main character's vitality is > 0, and there are still enemies 
          in the combat queue, do the following:
      :     - Call actionSelection()
            - Call turnResolution()
            - Call enemyTurn() with a pointer to the first enemy on combat queue.

      : If the main character's vitality has fallen to 0, print "YOU HAVE PERISHED."
      : If there are no more enemies in the combat queue, print "NO MORE ENEMIES."
*/
void Tavern::combat(){
  if(combat_queue.empty()){
      std::cout<< "NO MORE ENEMIES.\n";
    }
  while(main_character -> getVitality() > 0 && !combat_queue.empty()){
    actionSelection();
    turnResolution();
    if(!combat_queue.empty()){
      enemyTurn(getTarget());
    }
    if(main_character -> getVitality() <= 0){
      std::cout << "YOU HAVE PERISHED.\n";
    }
    if(combat_queue.empty()){
      std::cout<< "NO MORE ENEMIES.\n";
    }
  }
}

/**
    @post: all characters leave the tavern
*/
void Tavern::emptyTavern()
{
  for(int i = 0; i < item_count_; i++)
  {
    delete items_[i];
    items_[i] = nullptr;
  }
  item_count_ = 0;
}

/**
 Allows character to choose 3 actions to add to the action queue
 @pre: The action queue is empty 
 @post: Repeat the following process thrice (i.e. read three actions from input): 
        - Print the actions that are available to the main character, and read 
          a non-negative number from input, corresponding to an action. 
          Printing the available options should be of the following form. 
          You may consider writing a helper function for this.
          :Choose an action(1-4):\n1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike\t\t4: ATT_ThrowTomato\n
        - If the input is invalid (valid inputs will be 1,2,3, or 4 only.), 
          keep prompting for a non-negative number that is within range, by
          printing "Invalid input. Please enter a number between 1 and 4 inclusive.\n" and prompt for input again.
        - When a valid action is read, 
          it is added to the main character's action queue.    
*/
void Tavern::chooseActions(){
  int num;
  std::cout << "Choose an action(1-4):\n";
  std::cout << "1: BUFF_Heal\t\t2: BUFF_MendMetal\t\t3: ATT_Strike";
  std::cout << "\t\t4: ATT_ThrowTomato\n";
  std::cin >> num;
 //std::cout << num << "\n";
 while(num < 1 || num > 4){
  std::cout << "Invalid input. Please enter a number between 1 and 4 inclusive.\n";
  std::cin >> num;
 }
 main_character -> addAction(num); //adds the action to the action queue

}

/**
Gets the action in string form 
@pre: A int between 1-4 inclusive 
@param: An int representing an action type
@return: Returns the action that the int represents in string form
*/
std::string Tavern::actionToString(int num)
{
 if(num == 1){
    return "BUFF_Heal";
  }
  else if(num == 2){
    return "BUFF_MendMetal";
  }
  else if(num == 3){
    return "ATT_Strike";
  }
  else if(num == 4){
    return "ATT_ThrowTomato";
  }
  return "invalid";
}
