#include <iostream>
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Ranger.hpp"
#include "Scoundrel.hpp"
#include "ArrayBag.hpp"
#include "Tavern.hpp"

int main(){
  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Barbarian display test" << std::endl;
  Barbarian Ianthe("Ianthe", "LIZARD", 4, 2, 3, true, "staff", "sword", true);
  Ianthe.display();
  std::cout << "Ianthe after eatTainted Stew: \n\n";
  Ianthe.eatTaintedStew();
  Ianthe.display();

  std::cout << "Undead test for tainted stew: \n";
  Barbarian Tamlin("Tamlin", "UNDEAD", 3, 2, 5, false, "STAFF", "CLAWS", false);
  Tamlin.display();

  std::cout << "Tamlin after tainted stew: \n";
  Tamlin.eatTaintedStew();
  Tamlin.display();

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "mage display and stew test" << std::endl;
  Mage Nesta("Nesta", "ELF", 6, 2, 3, false, "elemental", "wand", true);
  Nesta.display();
  std::cout << "Nesta after stew\n";
  Nesta.eatTaintedStew();
  Nesta.display();

  Mage Cassian("Cassian", "ELF", 6, 2, 3, true, "elemental", "staff", false);
  Cassian.display();
  std::cout << "Cassian after stew\n";
  Cassian.eatTaintedStew();
  Cassian.display();

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Ranger display and stew test" << std::endl;
  std::vector<Arrows> arrows;
  Arrows wood;
  wood.type_ = "WOOD";
  wood.quantity_ = 5;
  arrows.push_back(wood);
  Arrows poison;
  poison.type_ = "poison";
  poison.quantity_ = 3;
  arrows.push_back(poison);
  std::vector<std::string> affinities{"FIRE", "water","poison"};
  Ranger Azriel("Azriel", "ELF", 7, 2, 3, true, arrows, affinities,true);
  Azriel.display();
  std::cout << "Azriel after eating stew (7/2 = 3.5, so 3 +1 = 4): \n";
  Azriel.eatTaintedStew();
  Azriel.display();
  std::vector<std::string> affinities2{"FIRE", "water"};
  Ranger Gwyn("Gwyn", "ELF", 4, 3, 2, false, arrows, affinities2, false);
  Gwyn.display();
  std::cout << "Gwyn after stew v = 1 : \n";
  Gwyn.eatTaintedStew();
  Gwyn.display();
  Ranger Emerie("Emerie", "UNDEAD", 3);
  Emerie.display();
  std::cout << "Emerie after stew v = 6: \n";
  Emerie.eatTaintedStew();
  Emerie.display();

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Ranger display and stew test" << std::endl;
  std::cout << "scoundrel parametized constructor with arguments test" << std::endl;
  Scoundrel Kaz("Kaz", "HUMAN", 7, 1, 4, true, "bronze", "SILVERTONGUE", true);
  Kaz.display();
  std::cout << "Kaz after stew, silvertongue so v = 5 or 1; : \n";
  Kaz.eatTaintedStew();
  Kaz.display();
  Scoundrel Kaz2("Kaz2", "HUMAN", 7, 1, 4, false, "bronze", "CUTPURSE", true);
  Kaz2.display();
  std::cout << "Kaz2 after stew: \n";
  Kaz2.eatTaintedStew();
  Kaz2.display();
  Scoundrel Kaz3("Kaz3", "HUMAN", 7, 1, 4, true, "bronze", "SHADOWBLADE", true);
  Kaz3.display();
  std::cout << "Kaz3 after stew: \n";
  Kaz3.eatTaintedStew();
  Kaz3.display();
  Scoundrel Kaz4("Kaz4", "UNDEAD", 7, 1, 4, true, "bronze", "CUTPURSE", true);
  Kaz4.display();
  std::cout << "Kaz4 after stew: \n";
  Kaz4.eatTaintedStew();
  Kaz4.display();
  std::cout << "Testing random:";
  for(int i = 1; i < 11; i++){
    std::cout << rand() % 10 + 1 << "\n";
  }

  Tavern Moon;
  Barbarian * test = new Barbarian("Mu", "UNDEAD");
  Moon.add(test);
  Moon.tavernReport();
  Moon.displayCharacters();
  
  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Parametized Constructor & Display test" << std::endl;
  Tavern tavern1("characters.csv");
  tavern1.displayCharacters();

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Display Race test" << std::endl;
  tavern1.displayRace("HUMAN");

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Tainted Stew test" << std::endl;
  tavern1.taintedStew();
  tavern1.displayRace("UNDEAD");

  

}