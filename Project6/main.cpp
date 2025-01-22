#include <iostream>
#include "Tavern.hpp"
#include "Character.hpp"

int main(){
  /*
    Character test("test1", "HUMAN", 10, 10, 10, false);
  std::cout << "------------------------------------------------\n";
  std::cout << "Character heal tests\n";
  test.heal();
  std::cout << "vitality after heal: " << test.getVitality() << "\n";
///
  std::cout << "------------------------------------------------\n";
  std::cout << "Character mendMetal test\n";
  test.mendMetal();
  std::cout << "armor after mendmental: " << test.getArmor() << "\n";
///
  std::cout << "------------------------------------------------\n";
  std::cout << "Character strike test\n";
  Character *test2 = new Character("test2", "HUMAN", 10, 10, 10, false);
  test.strike(test2);
  std::cout << "test 2 armor after strike: " << test2 -> getArmor() << "\n";
  std::cout << "test 2 vitality after strike: " << test2 -> getVitality() << "\n";
  test2 -> setArmor(1);
  test.strike(test2);
  std::cout << test2 -> getArmor() << "\n";
  std::cout << "test 2 armor after armor is to 1 and strike: " << test2 -> getArmor() << "\n";
  std::cout << "test 2 vitality after armor is to 1 and strike: " << test2 -> getVitality() << "\n";
///
  std::cout << "------------------------------------------------\n";
  std::cout << "Character throw tomato test\n";
  test2 -> setArmor(10);
  test2 -> setVitality(10);
  test.throwTomato(test2);
  std::cout << "test 2 armor after tomato: " << test2 -> getArmor() << "\n";
  std::cout << "test 2 vitality after tomato: " << test2 -> getVitality() << "\n";
  test2 -> setArmor(1);
  test2->throwTomato(test2);
  std::cout << "test 2 armor after armor is to 1 and strike: " << test2 -> getArmor() << "\n";
  std::cout << "test 2 vitality after armor is to 1 and strike: " << test2 -> getVitality() << "\n";
///
  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern set & get main character test \n";
  Character *Bryce = new Character("Bryce", "ELF", 10, 10, 10, false);
  Tavern MoonHaven;
  MoonHaven.setMainCharacter(Bryce);
  MoonHaven.getMainCharacter() -> display();
///
  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern level is less test \n";
  Character *Hunt = new Character("Hunt", "UNDEAD", 20, 20, 20, false);
  Hunt->display();
  std::cout << "\n";
  std::cout << "Level is less true test: " << std::boolalpha << MoonHaven.levelIsLess(Bryce, Hunt) << "\n";
  std::cout << "Level is less false test: " << std::boolalpha << MoonHaven.levelIsLess(Hunt, Bryce) << "\n";
///
  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern level is greater test \n";
  std::cout << "Level is greater false test: " << std::boolalpha << MoonHaven.levelIsGreater(Bryce, Hunt) << "\n";
  std::cout << "Level is greate true test: " << std::boolalpha << MoonHaven.levelIsGreater(Hunt, Bryce) << "\n";
//
  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern vitality is less test \n";
  std::cout << "Vitality is true test: " << MoonHaven.vitalityIsLess(Bryce, Hunt) << "\n";
  std::cout << "Vitality is false test: " << MoonHaven.vitalityIsLess(Hunt, Bryce) << "\n";
//
  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern vitality is greater test \n";
  std::cout << "Vitality is false test: " << MoonHaven.vitalityIsLess(Hunt, Bryce) << "\n";
  std::cout << "Vitality is true test: " << MoonHaven.vitalityIsLess(Bryce, Hunt) << "\n";
  */


//
  
  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern Create Combat queue test \n";
  std::cout << "        Filter NONE     \n";
  Tavern enemeies("enemies.csv");
  enemeies.createCombatQueue();
  enemeies.printCombatQueue();
  std::cout << "--------------------------\n";
  std::cout << "        Filter LVLASC     \n";
  enemeies.createCombatQueue("LVLASC");
  enemeies.printCombatQueue();
  std::cout << "--------------------------\n";
  std::cout << "        Filter LVLDES     \n";
  enemeies.createCombatQueue("LVLDES");
  enemeies.printCombatQueue();
  std::cout << "--------------------------\n";
  std::cout << "        Filter HPASC     \n";
  enemeies.createCombatQueue("HPASC");
  enemeies.printCombatQueue();
  std::cout << "--------------------------\n";
  std::cout << "        Filter HPDES     \n";
  enemeies.createCombatQueue("HPDES");
  enemeies.printCombatQueue();
  /*
    std::cout << "------------------------------------------------\n";
  std::cout << "\nTavern action selection test \n";
  //Character *Bryce = new Character("Bryce", "ELF", 10, 10, 10, false);
  Character *Morbin = new Character("MORBIN", "UNDEAD", 10, 5, 10, false);
  enemeies.setMainCharacter(Morbin);
  enemeies.setMainCharacter(Morbin);
  std::cout << "Enemies tavern main character: \n";
  enemeies.getMainCharacter() -> display();
  std::cout << "\n";
  std::cout << "Enemies tavern first target: \n";
  enemeies.getTarget() -> display();
  
  std::cout << "--------------------------\n";
  enemeies.actionSelection();
  std::cout << "main characters action queue after selection: \n";
  Morbin->printAction();

  

  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern turn resolution with buffs in stack test \n";
  Buff heal;
  heal.name_ = "BUFF_Heal";
  heal.turns_ = 3;
  Morbin -> addBuff(heal);

  enemeies.turnResolution();
  */

  //std::cout << "\n\n main characters stack after turn resolution\n";
  //Bryce -> printBuffStack();
  //Bryce -> clearStack();

  /*
  std::cout << "------------------------------------------------\n";
  std::cout << "Tavern enemy turn test \n";
  enemeies.enemyTurn(enemeies.getTarget());
  std::cout << "------------------------------------------------\n";
  std::cout << "\nTavern enemy with buff turn test \n";
  Character *enemy = new Character("enemy", "HUMAN", 2, 2, 2, true);
  Tavern testEnemy;
  Buff heal2;
  heal2.name_ ="HEAL";
  heal2.turns_ = 2;
  enemy->addBuff(heal2);
  testEnemy.enterTavern(enemy);
  testEnemy.createCombatQueue();
  testEnemy.setMainCharacter(Morbin);
  testEnemy.actionSelection();
  std::cout << "enemy Buff stack info: \n";
  enemy->printBuffStack();
  enemy -> applyTopBuff();
  std::cout << "Buff stack after apply once: \n";
  enemy->printBuffStack();
  std::cout << "--------------------------------\n";
  testEnemy.enemyTurn(testEnemy.getTarget());


std::cout << "------------------------------------------------\n";
std::cout << "\nTavern combat turn test \n";
Tavern tavern;
Character c1("MAINCHARACTER", "HUMAN", 1, 1, 1, false);
Character c2("FIRSTENEMY", "ELF", 50, 50, 1, true);

tavern.enterTavern(&c1);
tavern.enterTavern(&c2);
tavern.setMainCharacter(&c1);
tavern.printCombatQueue();

//tavern.combat(); // combat should terminate after printing "NO MORE ENEMIES"
std::cout << "---------------------\n";
std::cout << "one enemy in combat queue\n";
tavern.createCombatQueue();
tavern.printCombatQueue();
// Call the combat function
//tavern.combat();
std::cout << "---------------------\n";


c1.setVitality(100);
c1.setArmor(100);
tavern.exitTavern(&c2);
Character c3("SECONDENEMY", "DWARF", 2, 2, 2, true);
Character c4("THIRDENEMY", "LIZARD", 4, 2, 3, true);

tavern.enterTavern(&c3);
tavern.enterTavern(&c4);
tavern.createCombatQueue("HPDES");
tavern.printCombatQueue();
// Call the combat function again
tavern.combat();

  */
  
 

  








}