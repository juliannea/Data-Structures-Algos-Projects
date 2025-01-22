/*
CSCI235 Fall 2023
Project 6 - C-C-Combat!
Original Owner: Georgina Woo
Julianne Aguilar
November 28, 2023
Character.cpp defines the constructors and private and public function implementation of the Character class
Project Description: Allows the main character to combat enemies in the Tavern, original file was modified for project 6
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
        @param     	: A reference to the right hand side of the == operator.
        @return     : Returns true if the right hand side character is "equal", false otherwise. 									
                     Two characters are equal if they have the same name, same race, same level 									
                     and are either both an enemy or not.

        Note: By this definition, only some of the character's attributes must be equal for two characters to be deemed "equal".

        Example: In order for character1 to be == to character2 we only need:
        - The same name
        - The same race
         - The same level
        - They must either be both an enemy or not
*/
bool Character::operator==(const Character& rhs) const
{
    return(name_ == rhs.getName() && getRace() == rhs.getRace() && level_ == rhs.getLevel() && enemy_ == rhs.isEnemy());
}

/**
            @param     `: A reference to the right hand side of the != operator.
            @return     : Returns true if the right hand side character is NOT "equal" (!=), false 				
						 otherwise. Two characters are NOT equal if any of their name, race or level are
						not equal, or if one is an enemy and the other is not.
*/
bool Character::operator!=(const Character& rhs) const
{
    return(!(*this == rhs));
}

/**
 @post     : displays Character data in the form:
"[name_] is a Level [level_] [race_]. \nVitality: [vitality_] \nMax Armor: [armor_] \n[They are / They are not] an enemy.\n"     
*/
void Character::display() const
{
    std::cout<<name_<<" is a Level "<<level_<<" "<<getRace()<<
    ". \nVitality: "<<vitality_<<
    "\nMax Armor: "<<armor_<<" \n"<<
    (enemy_ ? "They are an enemy.\n" : "They are not an enemy.\n");
}

/**
  Allows the character to perform heal action
  @pre: This function is called to execute the Action BUFF_Heal
  @post: Increases the character's vitality by 2
*/
void Character::heal(){
  vitality_+=2;
}

/**
  Allows the character to perform mendmetal action
  @pre: This function is called to execute the Action BUFF_MendMetal
  @post: Increases the character's armor by 2
*/
void Character::mendMetal(){
  armor_+=2;
}

/**
  Allows the character to perform strike action
  @pre: This function is called to execute the Action ATT_Strike
  @param: A pointer to a character target
  @post: Deals 2 points of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they lose 1 vitality point.
*/
void Character::strike(Character *target){
  if(target -> armor_ > 1){
    target -> armor_ -= 2;
  }
  else if(target -> armor_  == 1){
    target -> armor_ = 0;
    target -> vitality_ -= 1;
  }
  else{
    target -> vitality_ -= 2;
  }
  
}

/**
  Allows that character to perform throw tomato action
  @pre: This function is called to execute the Action ATT_ThrowTomato
  @param: A pointer to a character target
  @post: Deals 1 point of damage to the target character. If the target has armor, their armor absorbs the damage but is depleted by the same number of points. For example, if the target has 1 armor point, their armor becomes 0 and they don't lose any vitality points. Your character gains 1 vitality point (as laughter is the best medicine).
*/
void Character::throwTomato(Character *target){
  if(target -> armor_ >= 1){
    target -> armor_ -=1;
  }
  else if(target -> armor_ == 0){
    target -> vitality_ -= 1;
  }
  vitality_ +=1;
}

/**
  Empties the action queue
  @post: empties the characters action queue
*/
void Character::emptyActionQueue(){
  while(!action_queue_.empty()){
    action_queue_.pop();
  }
}

/**
  Adds and action to the action queue
  @pre: An integer between 1-4 inclusive
  @param: An integer representing an action type
  @post: Adds the integer action representation into the action queue
*/
void Character::addAction(int num){
  if(num >=1 && num <= 4){
    action_queue_.push(num);
  }
}

/**
 Prints all items stored in the action queue 
 @pre: The action queue is not empty
 @post: prints all the items in the action queue
*/
void Character::printAction()
{
  if(!action_queue_.empty()){
    std::queue<int> temp = action_queue_;
    while(!temp.empty()){
      std::cout << temp.front() << "\n";
      temp.pop();
    }
  }
}

/**
 Adds the buff into the buff stack 
 @param: A buff type 
 @post: adds the buff into the buff stack
*/
void Character::addBuff(Buff type){
  buff_stack_.push(type);
}

/**
 Checks if the characters action queue is empty or not 
 @return: Returns false if the action queue is empty, returns true if action queue has actions
*/
bool Character::hasActions(){
  if(action_queue_.empty()){
    return false;
  }
  return true;
}

/**
  Checks if the characters buff stack is empty or not 
  @return: Returns false if buff stack is empty, returns true if buff stack has buffs
*/
bool Character::hasBuff(){
  if(buff_stack_.empty()){
    return false;
  }
  return true;
}

/**
  Gets the action in front of the action queue 
  @return: the action queue's front action
*/
int Character::getAction() const
{
  return action_queue_.front();
}

/**
  Gets the action in string form 
  @pre: A int between 1-4 inclusive 
  @param: An int representing an action type
  @return: Returns the action that the int represents in string form
*/
std::string Character::getActionString(int num)
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

/**
  Applies the actions in the action queue to the given target 
  @pre: The action queue is not empty
  @param: A pointer to a Character object representing a target 
  @post:- take the next action off the queue
        - if the next action is a buff, apply once and push it onto the buff stack after 
          decrementing the turns. 
          BUFF_Heal lasts for 3 turns in total, while BUFF_MendMetal lasts
          for 2 turns in total. Print out the results of the action as described below.
        - if the next action is an attack, execute it against the target 
*/
void Character::applyActions(Character* target){
    int action = action_queue_.front(); //stores action type before removing from queue
    action_queue_.pop(); //take next action off the queue
    std::string action_str = getActionString(action); //action type to string

    //if its a buff apply the buff 
    if(action_str.find("BUFF") !=std::string::npos){
      Buff temp;
      temp.name_ = action_str;
      if(action_str.find("Heal") != std::string::npos ){ // if the buff is heal 
        heal(); //apply heal once
        temp.turns_ = 2;
      }
      else if(action_str.find("MendMetal") != std::string::npos ){//if the buff is mendmetal
        mendMetal(); //apply mendMetal once
        temp.turns_ = 1;
      }
      buff_stack_.push(temp); //push it into the buff stack 
    }
    //if its an attack action
    else if(action_str.find("ATT") !=std::string::npos){
      //execute attack against enemy 
      if(action_str.find("Strike") != std::string::npos ){ // if Strike attack
        strike(target); //strike target
        
      }
      else if(action_str.find("ThrowTomato") != std::string::npos ){//if ThrowTomato attack
        throwTomato(target); //throw tomato at target 
      }
    }
    
}

/**
  Applies the buff at the top of the Buff stack once 
  @pre: The buff stack is not empty 
  @post: -apply the buff once and decrement the turns.
         -any time a Buff's turns_ goes to zero, it is removed from the stack.
*/
void Character::applyTopBuff(){
  if(!buff_stack_.empty()){
    //name of the buff
    size_t underscore = buff_stack_.top().name_.find("_");
    std::string buff_type = buff_stack_.top().name_.substr(underscore +1, buff_stack_.top().name_.length());
    if(buff_type.find("Heal") != std::string::npos){ //if buff type is Heal 
      heal(); //apply heal 
    }
    //if top buff mendmetal apply mendmetal
    else if(buff_type.find("MendMetal") != std::string::npos){ //if buff type is MendMetal
      mendMetal(); //apply MendMetal
    }
  }
  buff_stack_.top().turns_ -= 1; 
  //if turn is 0 remove from stack;
  if(buff_stack_.top().turns_ == 0){ 
    buff_stack_.pop(); 
  }
 
}

/*
  Prints the items stored in the buff stack
  @post: print all items in the buff stack
*/
void Character::printBuffStack(){
  std::stack <Buff> temp = buff_stack_;
  while(!temp.empty()){
    std::cout << "Name: " << temp.top().name_ << "\n";
    std::cout << "Turns: " << temp.top().turns_ << "\n";
    temp.pop();
  }
}

/**
 Clears all items in the buff stack 
 @post: empties the buff stack
*/
void Character::clearBuffStack(){
  while(!buff_stack_.empty()){
    buff_stack_.pop();
  }
}


/**
  Gets the name of the buff at the top of the buff stack
  @pre: the buff stack is not empty 
  @return: returns the top items name of the buff stack
*/
std::string Character::getTopBuff()
{
  size_t underscore = buff_stack_.top().name_.find("_");
  std::string buff_type = buff_stack_.top().name_.substr(underscore +1, buff_stack_.top().name_.length());

  return buff_type;
}


