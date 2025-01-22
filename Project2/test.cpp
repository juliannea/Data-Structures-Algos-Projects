#include <iostream>
#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"

/**
Helper function that couts whether or not a character is an enemy 
@param: a bool value indicating whether or not a character is an enemy
@return: Returns a string indicating the they're an enemy if bool value us true,
         returns a string indicating they're not an enemy if bool value is false
**/
std::string an_enemy(bool enemy){
  if(enemy == false){
    return "They are not an enemy";
  }
  else{
    return "They are an enemy";
  }
}

int main(){
  /*Mage Default Constructor test*/
  Mage mage1 = Mage();
  mage1.setName("defaultMage");
  mage1.setRace("ELF");
  mage1.setVitality(5);
  mage1.setArmor(3);
  mage1.setLevel(2);
  mage1.setEnemy();
  std::cout << mage1.getName() << " is a Level " << mage1.getLevel() << " " << mage1.getRace() << ".\n";
  std::cout << "Vitality: " << mage1.getVitality() << "\n";
  std::cout << "Armor: " << mage1.getArmor() << "\n";
  std::cout << an_enemy(mage1.isEnemy()) << "\n";
  std::cout << "School of Magic: " << mage1.getSchool() << "\n";
  std::cout << "Weapon: " << mage1.getCastingWeapon() << "\n";
  std::cout << "Summon Incarnate: " << (mage1.hasIncarnateSummon() ? "TRUE" : "FALSE") << "\n";
  std::cout << "\n";

  /*Mage Parameter Constructor and Setters test*/
  Mage mage2("SPYNACH", "ELF", 6, 4, 4, false);
  mage2.setSchool("Illusion");
  mage2.setCastingWeapon("Wand");
  mage2.setIncarnateSummon(true);
  std::cout << mage2.getName() << " is a Level " << mage2.getLevel() << " " << mage2.getRace() << ".\n";
  std::cout << "Vitality: " << mage2.getVitality() << "\n";
  std::cout << "Armor: " << mage2.getArmor() << "\n";
  std::cout << an_enemy(mage2.isEnemy()) << "\n";
  std::cout << "School of Magic: " << mage2.getSchool() << "\n";
  std::cout << "Weapon: " << mage2.getCastingWeapon() << "\n";
  std::cout << "Summon Incarnate: " << (mage2.hasIncarnateSummon() ? "TRUE" : "FALSE") << "\n";
  std::cout << "\n";

  /*Scoundrel Default Constructor test*/
  Scoundrel scoundrel1 = Scoundrel();
  scoundrel1.setName("defaultScoundrel");
  scoundrel1.setRace("HUMAN");
  scoundrel1.setVitality(6);
  scoundrel1.setArmor(4);
  scoundrel1.setLevel(3);
  scoundrel1.setEnemy();

  std::cout << scoundrel1.getName() << " is a Level " << scoundrel1.getLevel() << " " << scoundrel1.getRace() << ".\n";
  std::cout << "Vitality: " << scoundrel1.getVitality() << "\n";
  std::cout << "Armor: " << scoundrel1.getArmor() << "\n";
  std::cout << an_enemy(scoundrel1.isEnemy()) << "\n";
  std::cout << "Dagger: " << scoundrel1.getDagger() << "\n";
  std::cout << "Faction: " << scoundrel1.getFaction() << "\n";
  std::cout << "Disguise: " << (scoundrel1.hasDisguise() ? "TRUE" : "False") << "\n";
  std::cout << "\n";

  /*Scoundrel Parameterized Constructor and Setters test*/
  Scoundrel scoundrel2("FLEA", "DWARF", 12, 7, 5, false);
  scoundrel2.setDagger("Adamant");
  scoundrel2.setFaction("Cutpurse");
  scoundrel2.setDisguise(true);
  std::cout << scoundrel2.getName() << " is a Level " << scoundrel2.getLevel() << " " << scoundrel2.getRace() << "\n";
  std::cout << "Vitality: " << scoundrel2.getVitality() << "\n";
  std::cout << "Armor: " << scoundrel2.getArmor() << "\n";
  std::cout << an_enemy(scoundrel2.isEnemy()) << "\n";
  std::cout << "Dagger: " << scoundrel2.getDagger() << "\n";
  std::cout << "Faction: " << scoundrel2.getFaction() << "\n";
  std::cout << "Disguise: " << (scoundrel2.hasDisguise() ? "TRUE" : "FALSE") << "\n";
  std::cout << "\n";

  /*Ranger Default Parameter test*/
  Ranger ranger1 = Ranger();
  ranger1.setName("defaultRanger");
  ranger1.setRace("UNDEAD");
  ranger1.setVitality(8);
  ranger1.setArmor(4);
  ranger1.setLevel(5);
  ranger1.setEnemy();
  std::cout << ranger1.getName() << " is a Level " << ranger1.getLevel() << " " << ranger1.getRace() << ".\n";
  std::cout << "Vitality: " << ranger1.getVitality() << "\n";
  std::cout << "Armor: " << ranger1.getArmor() << "\n";
  std::cout << an_enemy(ranger1.isEnemy()) << "\n";
  std::cout << "Vector of Arrows: " << (ranger1.getArrows().empty() ? "NONE" : "TRUE") << "\n";
  std::cout << "Affinities: " << (ranger1.getAffinities().empty() ? "NONE" : "TRUE") << "\n";
  std::cout << "Animal Companion: " << (ranger1.getCompanion() ? "TRUE" : "FALSE") << "\n";
  std::cout << "\n";

  /*Ranger Parametized Constructor and setters test*/
  Ranger Marrow("Marrow", "UNDEAD", 9, 6, 5, true);
  std::vector <Arrows> arrows;
  Arrows wood;
  wood.type_ = "WOOD";
  wood.quantity_ = 30;
  arrows.push_back(wood);
  Arrows fire2;
  fire2.type_ = "FIRE";
  fire2.quantity_ = 5;
  arrows.push_back(fire2);
  Arrows water;
  water.type_ = "WATER";
  water.quantity_ = 5;
  arrows.push_back(water);
  Arrows poison;
  poison.type_ = "poison";
  poison.quantity_ = 5;
  arrows.push_back(poison);
  for(int i = 0; i < arrows.size(); i++){
    bool added = Marrow.addArrows(arrows[i].type_, arrows[i].quantity_);
  }
  //Marrow.addArrows("blood", 10);
  Marrow.addAffinity("Fire");
  Marrow.addAffinity("Poison");
  Marrow.setCompanion(true);
  bool fire = Marrow.fireArrow("fire");
  std::cout << Marrow.getName() << " is a Level " << Marrow.getLevel() << " " << Marrow.getRace() << ".\n";
  std::cout << "Vitality: " << Marrow.getVitality() << "\n";
  std::cout << "Armor: " << Marrow.getArmor() << "\n";
  std::cout << an_enemy(Marrow.isEnemy()) << "\n";
  std::cout << "Vector of Arrows: ";
  for(int i = 0; i < Marrow.getArrows().size(); i++){
    std::cout << Marrow.getArrows()[i].type_ << ", " << Marrow.getArrows()[i].quantity_ << "";
    if(i < Marrow.getArrows().size()-1){
      std::cout << ", ";
    }
  }
  std::cout << "\n";
  std::cout << "Affinities: ";
  for(int j = 0; j < Marrow.getAffinities().size(); j++){
    std::cout << Marrow.getAffinities()[j];
      if(j < Marrow.getAffinities().size()-1){
      std::cout << ", ";
    }
  }
  std::cout << "\nAnimal Companion: " << (Marrow.getCompanion() ? "TRUE" : "FALSE") << "\n";

  /*Barbarian Default Constructor test*/
  Barbarian barb = Barbarian();
  barb.setName("defaultbarbarian");
  barb.setRace("HUMAN");
  barb.setVitality(10);
  barb.setArmor(5);
  barb.setLevel(5);
  barb.setEnemy();
  std::cout << "\n" << barb.getName() << " is a Level " << barb.getLevel() << " " << barb.getRace() << "\n";
  std::cout << "Vitality: " << barb.getVitality() << "\n";
  std::cout << "Armor: " << barb.getArmor() << "\n";
  std::cout << an_enemy(barb.isEnemy()) << "\n";
  std::cout << "Main Weapon: " << barb.getMainWeapon() << "\n";
  std::cout << "Offhand Weapon: " << barb.getSecondaryWeapon() << "\n";
  std::cout << "Enraged: " << (barb.getEnrage() ? "TRUE": "FALSE") << "\n";
  std::cout << "\n";

  Barbarian Bonk("Bonk", "HUMAN", 11, 5, 5, true);
  Bonk.setMainWeapon("MACE");
  Bonk.setSecondaryWeapon("anothermace");
  Bonk.setEnrage(true);
  Bonk.toggleEnrage();
  std::cout << Bonk.getName() << " is a Level " << Bonk.getLevel() << " " << Bonk.getRace() << "\n";
  std::cout << "Vitality: " << Bonk.getVitality() << "\n";
  std::cout << "Armor: " << Bonk.getArmor() << "\n";
  std::cout << an_enemy(Bonk.isEnemy()) << "\n";
  std::cout << "Main Weapon: " << Bonk.getMainWeapon() << "\n";
  std::cout << "Offhand Weapon: " << Bonk.getSecondaryWeapon() << "\n";
  std::cout << "Enraged: " << (Bonk.getEnrage() ? "TRUE" : "FALSE") << "\n";
  Bonk.toggleEnrage();
}