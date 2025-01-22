/*
CSCI235 Fall 2023
Project 4 - The Tainted Stew
Original Owner: Georgina Woo
Julianne Aguilar 
October 27, 2023
Barbarian.cpp defines the constructors and private and public function implementation of the Barbarian class
Project Description: This program utilizes polymorphism and inheritence to allow for the display of 
                     Character data unique to their status of being a Barbarian, Mage, Ranger, or Scoundrel. 
                     Allows for changes to private members of subclasses in response to the character eating 
                     tainted stew.
*/

#include "Barbarian.hpp"

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
    Default weapons: "NONE". 
*/
Barbarian::Barbarian() : Character(), main_weapon_{"NONE"},secondary_weapon_{"NONE"},enraged_{false}
{
}

/**
    Parameterized constructor.
    @param      : The name of the character (a string)
    @param      : The race of the character (an enum)
    @param      : The character's vitality (an integer)
    @param      : The character's max armor level (an integer)
    @param      : The character's level (an integer)
    @param      : A flag indicating whether the character is an enemy
    @param      : The character's main weapon (a string). String inputs can be in lowercase, 
                  but must be converted to uppercase when setting the variable.
                  Only alphabetical characters are allowed.
    @param      : The character's offhand weapon (a string). String inputs can be in lowercase, 
                  but must be converted to uppercase when setting the variable.
                  Only alphabetical characters are allowed.
    @param      : A flag indicating whether the character is enraged, false by default
    @post       : The private members are set to the values of the corresponding parameters. 
                  If the main and secondary weapons are not provided or invalid, the variables are set to "NONE".
*/
Barbarian::Barbarian(const std::string& name, const std::string& race, int vitality, int armor, int level, bool enemy, const std::string& main_weapon, const std::string& secondary_weapon, bool enraged)
: Character(name, race, vitality, armor, level, enemy), enraged_(enraged)
{
    if(!setMainWeapon(main_weapon))
    {
        main_weapon_ = "NONE";
    }
    if(!setSecondaryWeapon(secondary_weapon))
    {
        secondary_weapon_ = "NONE";
    }
}

/**
    @param  : a reference to a string representing the Character's main weapon
    @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
            : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setMainWeapon(const std::string& main_weapon)
{
    std::string temp = main_weapon;
    for (int i = 0; i < temp.length(); i++)
    {
        if (!isalpha(temp[i]))
        {
            return false;
        }
        else
        {
            temp[i] = toupper(temp[i]);
        }
    }
    main_weapon_ = temp;
    return true;
}

/**
    @return  : a string of the Character's main weapon
**/
std::string Barbarian::getMainWeapon() const
{
    return main_weapon_;
}

/**
    @param  : a reference to a string representing the Character's secondary weapon
    @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
            : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            : If the given input is invalid (i.e contains numbers), do nothing and return false
    @return : true if setting the variable was successful, false otherwise.
**/
bool Barbarian::setSecondaryWeapon(const std::string& secondary_weapon)
{
    std::string temp = secondary_weapon;
    for (int i = 0; i < temp.length(); i++)
    {
        if (!isalpha(temp[i]))
        {
            return false;
        }
        else
        {
            temp[i] = toupper(temp[i]);
        }
    }
    secondary_weapon_ = temp;
    return true;
}

/**
    @return  : a string of the Character's secondary weapon
**/
std::string Barbarian::getSecondaryWeapon() const
{
    return secondary_weapon_;
}

/**
    @param  : a reference to a bool
    @post   : sets the private member variable to the value of the parameter.
**/
void Barbarian::setEnrage(const bool& enraged)
{
    enraged_ = enraged;
}

/**
    @return  : a boolean of whether the Character is enraged
**/
bool Barbarian::getEnrage() const
{
    return enraged_;
}

/**
    @post   : sets the enraged variable to the opposite of what it was
**/
void Barbarian::toggleEnrage()
{
    enraged_ = !enraged_;
}

/**
  Displays the Barbarian characters data (overrides the function in Character base class)
  @post: displays Barbarian data in the form:
         "[NAME] is a Level [LEVEL] [RACE] BARBARIAN.
          \nVitality: [VITALITY]
          \nArmor: [ARMOR]
          \nThey are [an enemy/not an enemy].
          \nMain Weapon: [MAINWEAPON]
          \nOffhand Weapon: [OFFHANDWEAPON]
          \nEnraged: [TRUE/FALSE]\n\n"
**/
void Barbarian::display() const {
  std::cout << getName() << " is a Level " << getLevel() << " " << getRace() << " BARBARIAN.";
  std::cout << "\nVitality: " << getVitality();
  std::cout << "\nArmor: " << getArmor();
  std::cout << "\nThey are " << (isEnemy() ? "an enemy." : "not an enemy.");
  std::cout << "\nMain Weapon: " << getMainWeapon();
  std::cout << "\nOffhand Weapon: " << getSecondaryWeapon();
  std::cout << "\nEnraged: " << (getEnrage() ? "TRUE" : "FALSE");
  std::cout << "\n\n";
}

 /**
    Changes the Barbarian characters private member variables as an effect of the character eating a 
    tainted stew, the type of change depends on the race of the character.
    (overrides the function in Character base class)
    @post: If the character is UNDEAD, gain 3 Vitality points. Nothing else happens.
           If the character is NOT UNDEAD, Vitality is set to 1. 
           In addition, as a Barbarian: 
           Become enraged if the character was not enraged, and not enraged if they were already enraged. 
           If they have now become enraged, the offhand weapon is replaced with "TABLE". 
           If they are now not enraged, the main weapon is replaced with "BUCKET".
 **/
void Barbarian::eatTaintedStew(){
  if(getRace() == "UNDEAD"){
    setVitality(getVitality() + 3);
  }
  else{
    setVitality(1);
    toggleEnrage();
    if(getEnrage() == true){
      setSecondaryWeapon("TABLE");
    }
    else{
      setMainWeapon("BUCKET");
    }
  }
  

}