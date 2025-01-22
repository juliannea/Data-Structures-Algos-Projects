#include<iostream>
#include "DoublyLinkedList.hpp"
#include "Node.hpp"
#include "QuestList.hpp"

//same idea as the last display, but include the member variables and subs and deps and their ptrs
/**
 * @post: prints the titles of all quest withing the list along with their pointer value and all their details 
*/


std::string printD(QuestList object, std::string title){
  std::string list = "";
  for(int i = 0; i < object.getItem(object.getPosOf(title)) -> dependencies_.size(); i++){
    list += object.getItem(object.getPosOf(title)) -> dependencies_[i] ->title_ + " ";
  }
  
   return list;
}
std::string prints(QuestList object, std::string title){
  std::string list = "";
  for(int i = 0; i < object.getItem(object.getPosOf(title)) -> subquests_.size(); i++){
    list += object.getItem(object.getPosOf(title)) -> subquests_[i] ->title_ + " ";
  }
  
   return list;
}

void printList(QuestList object){
  std::cout << object.getLength() << "\n";
  for(int i = 0; i < object.getLength(); i++){
    std::cout << object.getPosOf(object.getItem(i)->title_) << "\n";
    std::cout << "Title: " << object.getItem(i) -> title_ << "\n";
    std::cout << "Description: " << object.getItem(i) -> description_ << "\n";
    std::cout << "completion: " << object.getItem(i) -> completed_ << "\n";
    std::cout << "experience: " << object.getItem(i) -> experience_points_ << "\n";
    std::cout << "dependencies: " << printD(object, object.getItem(i) ->title_) << "\n";
    std::cout << "subquests: " << prints(object, object.getItem(i) ->title_) << "\n\n";
  }
}

void printQuests(Quest * object){
  std::cout << "Name: " << object -> title_ << "\n" << "Description:" << object -> description_ << "\n";
  std::cout << "completion: " << std::boolalpha << object -> completed_ << "\n";
  std::cout << "experience: " << object -> experience_points_ <<  "\n";
  if(object->dependencies_.empty()){
    std::cout << "empty dependency vector\n";
  }
  if(object->subquests_.empty()){
    std::cout << "empty subquests vector\n";
  }
  else{
    std::cout << "Dependencies: ";
    for(int i = 0; i < object->dependencies_.size(); i++){
      std::cout << object->dependencies_[i] -> title_ << " ";
    }
    std::cout << "\nSubquests: ";
    for(int j = 0; j < object->subquests_.size(); j++){
      std::cout << object->subquests_[j] -> title_<< " ";
    }
  }
  std::cout << "\n";
}

int main(){

  std::cout << "-------------------------------------\n";
  std::cout << "Quest Default Constructor Test\n";
  Quest * test1 = new Quest();
  printQuests(test1);
  /////
  std::cout << "-------------------------------------\n";
  std::cout << "Quest Parametized Test\n";
  Quest * dEmpireOfStorms = new Quest();
  dEmpireOfStorms -> title_ = "Empire Of Storms";
  Quest *dQueenOfShadows = new Quest();
  dQueenOfShadows -> title_ = "Queen Of Shadows";
  Quest * dTowerOfDawn = new Quest();
  dTowerOfDawn -> title_ = "Tower Of Dawn";
  Quest*  dHeirOfFire = new Quest();
  dHeirOfFire -> title_ = "Heir Of Fire";
  std::vector<Quest*> kDependencies = {dEmpireOfStorms, dQueenOfShadows};
  std::vector<Quest*> kSubquests = {dTowerOfDawn, dHeirOfFire};
  Quest *  KingdomOfAsh = new Quest("Kingdom Of Ash", "Defeat the valg", false, 100, kDependencies, kSubquests);
  printQuests(KingdomOfAsh);
///////
  std::cout << "-------------------------------------\n";
  std::cout << "Add,Contains, getPosOf test\n";
  QuestList Aelin;
  std::cout << "Add Kingdom of Ash: " << std::boolalpha << Aelin.addQuest(KingdomOfAsh) << "\n";
  std::cout << "List contains Kingdom of Ash: " << Aelin.contains("Kingdom Of Ash") << "\n";
  std::cout << "List returns Kingdom of Ash position: " << Aelin.getPosOf("Kingdom Of Ash") << "\n";
  std::cout << "List added Kingdom of Ash dependencies & subquests: \n";
  printList(Aelin);
  std::cout << "\ncontains false test case: " << Aelin.contains("Acotar") << "\n";
  std::cout << "getPosOf false test case: " << Aelin.getPosOf("Acotar") << "\n";
//////
  std::cout << "-------------------------------------\n";
  std::cout << "AddQuest test for object alr in list & a object marked as UNDISCOVERED\n";
  Quest* KOA = new Quest();
  KOA -> title_ = "Kingdom Of Ash";
  std::cout << "Try to add Kingdom of Ash object again: " << std::boolalpha << Aelin.addQuest(KingdomOfAsh) << "\n";
  std::cout << "Try to add object with same title: " << std::boolalpha << Aelin.addQuest(KOA) << "\n";
  std::cout << "List check length no change: " << Aelin.getLength() << "\n";
  Quest * pirate = new Quest();
  pirate -> title_ = "Befriend Pirate";
  Quest * manon = new Quest();
  manon -> title_ = "Lead the 13";
  pirate -> completed_ = true;
  manon -> completed_ = true;
  std::vector<Quest*> eDependencies = {manon};
  std::vector<Quest*> eSubquests = {pirate};
  Quest * EmpireOfStorms = new Quest("Empire Of Storms", "Gather court", false, 80, eDependencies, eSubquests);
  std::cout << "Add Empire of Storms: " << std::boolalpha << Aelin.addQuest(EmpireOfStorms);
  std::cout << "\nUpdate after adding object Empire of Storms: \n";
  printList(Aelin);
  std::cout << "-------------------------------------\n";
  std::cout << "AddQuest Parameterized \n";
  std::cout << "Test for updating alr existing title Tower of Dawn thats UNDISCOVERED: ";
  std::cout << "Note Tower of Dawn same dependencies & subquests as Empire of Storms : ";
  std::cout << Aelin.addQuest("Tower Of Dawn", "Recruit healers", true, 80, eDependencies, eSubquests) << "\n";
//////  
  std::cout << "\nUpdate after adding Tower of Dawn: \n";
  printList(Aelin);
  std::cout << "False test: ";
  std::cout << Aelin.addQuest("Tower Of Dawn", "Fight spiders", false, 80, eDependencies, eSubquests) << "\n";
  std::cout << "\nUpdate after adding false test: \n";
  printList(Aelin);
////
  std::cout << "-------------------------------------\n";
  std::cout << "Testing Subquests & Dependencies are in list \n";
  std::cout << "Heir of Fire Subquest test\n";
  std::cout << Aelin.contains("Heir Of Fire") << "\n";
  std::cout << Aelin.getPosOf("Heir Of Fire");
  std::cout << "\n" << Aelin.getItem(2) -> title_ << "\n";

  std::cout << "Queen of Shadows dependency test\n";
  std::cout << Aelin.contains("Queen Of Shadows") << "\n";
  std::cout << Aelin.getPosOf("Queen Of Shadows");
  std::cout << "\n" << Aelin.getItem(4) -> title_ << "\n";
  //std::cout << Aelin.getItem(Aelin.getPosOf("Heir Of Fire")) -> dependencies_[0] -> title_;
/////
  std::cout << "-------------------------------------\n";
  std::cout << "Dependencies Complete tests\n";
  std::cout << "Tower of Dawn Dependencies complete test: " << Aelin.dependenciesComplete(Aelin.getItem(Aelin.getPosOf("Tower Of Dawn"))) << "\n";
  std::cout << "Empire Of Storms true test: " << Aelin.dependenciesComplete(Aelin.getItem(Aelin.getPosOf("Empire Of Storms"))) << "\n";
  std::cout << "Kingdom of Ash false test: " << Aelin.dependenciesComplete(Aelin.getItem(Aelin.getPosOf("Kingdom Of Ash"))) << "\n";
  std::cout << "Heir of Fire true test: " <<  Aelin.dependenciesComplete(Aelin.getItem(Aelin.getPosOf("Heir Of Fire"))) << "\n";
///
  std::cout << "-------------------------------------\n";
  std::cout << "Quest Available tests\n";
    //Heir of fire not completed & no dependencies 
  std::cout << "Heir of Fire true test: " << Aelin.questAvailable(Aelin.getItem(2)) << "\n";
    //Tower of Dawn Marked as Completed 
  std::cout << "Tower of Dawn false test: " << Aelin.questAvailable(Aelin.getItem(Aelin.getPosOf("Tower Of Dawn"))) << "\n";
    //Kingdom of Ash One dependency not completed -Queen of Shadows 
  std::cout << "Kingdom of Ash false test: " << Aelin.questAvailable(Aelin.getItem(Aelin.getPosOf("Kingdom Of Ash"))) << "\n";
    //Empire of Storms not completed but depenencies completed 
  std::cout << "Empire of Storms true test: " << Aelin.questAvailable(Aelin.getItem(Aelin.getPosOf("Empire Of Storms"))) << "\n";
////
  std::cout << "-------------------------------------\n";
  std::cout << "Print Quest tests\n\n";
  //Heir of Fire not completed
  Aelin.printQuest(Aelin.getItem(2));
  //Tower of Dawn Completed 
  Aelin.printQuest(Aelin.getItem(Aelin.getPosOf("Tower Of Dawn")));
  //Kingdom Of Ash not completed
  Aelin.printQuest(Aelin.getItem(Aelin.getPosOf("Kingdom Of Ash")));
  //Empire of Storms not completed
  Aelin.printQuest(Aelin.getItem(Aelin.getPosOf("Empire Of Storms")));




  //std::cout << "-------------------------------------\n";
  //std::cout << "Parameterized Constructor with test.csv test\n\n";
  //QuestList test("test3.csv");
  //printList(test);

 std::cout << "-------------------------------------\n";
  std::cout << "Parameterized Constructor with quest.csv test\n\n";
 QuestList quests("quests.csv");
 printList(quests);
///
  std::cout << "-------------------------------------\n";
  std::cout << "Parameterized Constructor with debug test\n\n";
  QuestList debug("debug.csv");
  printList(debug);

  std::cout << "-------------------------------------\n";
  /*
 
  std::cout << "Helper Function unfinished quests test\n";
  debug.unfinishedQuests("Quest 3");
  std::cout << "\n\n";
  debug.unfinishedQuests("Quest 5");
  std::cout << "\n\n";
  debug.unfinishedQuests("Quest 6");
 */
  std::cout << "-------------------------------------\n";
  /*
   std::cout << "Quest Query Test \n\n";
  //debug.questQuery("Non existents");
  //std::cout << "\n";
  debug.questQuery("Quest 1");
  std::cout << "\n";
  debug.questQuery("Quest 2");
  std::cout << "\n";
  debug.questQuery("Quest 3");
  std::cout << "\n";
  debug.questQuery("Quest 4");
  std::cout << "\n";
  debug.questQuery("Quest 5");
  std::cout << "\n";
  std::string title = "Quest 5";
  //std::cout << "dependency: " << debug.dependenciesComplete(debug.getItem(debug.getPosOf(title))) << "\n";
 // std::cout << "available: " << debug.questAvailable(debug.getItem(debug.getPosOf(title))) << "\n";
  debug.questQuery("Quest 6");
  std::cout << "\n";
  debug.questQuery("Quest 7");
  std::cout << "\n";
  debug.questQuery("Quest 8");
  std::cout << "\n";
  debug.questQuery("Quest 9");
  std::cout << "\n";
  debug.questQuery("Quest 12");
  std::cout << "\n";

  std::cout << "-------------------------------------\n";
  std::cout << "Quest Query quests.csv Test \n\n";
  quests.questQuery("My First Backpack");
  std::cout << "\n";
  quests.questQuery("Enter The Tavern");
  std::cout << "\n";
  quests.questQuery("Talk to the Chef");
  std::cout << "\n";
  quests.questQuery("House Stew");
  std::cout << "\n";
  quests.questQuery("Talk to the Barkeep");
   std::cout << "\n";
  quests.questQuery("Pest Control");
  std::cout << "\n";
  quests.questQuery("Talk to the Mysterious Figure");
  quests.questQuery("Pest Control");
  std::cout << "\n";
  quests.questQuery("Lost and Found");
  std::cout << "\n";
  quests.questQuery("The Melodeon");
   std::cout << "\n";
  quests.questQuery("Talk to Songcatcher");
   std::cout << "\n";
  quests.questQuery("The Melodeon's Song");
   std::cout << "\n";
  quests.questQuery("Great. We Have A Melodeon");
   std::cout << "\n";
  quests.questQuery("Reunited");
  std::cout << "\n";
  quests.questQuery("Auroran Sunset");
///
std::cout << "-------------------------------------\n";
  std::cout << "calculate gained experience Test\n";
  std::cout << "debug total: " << debug.calculateGainedExperience() << "\n";
  std::cout << "quests total: " << quests.calculateGainedExperience() << "\n";
  
///
///
  
  
  std::cout << "-------------------------------------\n";
  std::cout << "Project experience Test \n\n";
  std::cout << "Quest 1 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 1"))) << "\n";
  std::cout << "Quest 2 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 2"))) << "\n";
  std::cout << "Quest 3 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 3"))) << "\n";
  std::cout << "Quest 4 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 4"))) << "\n";
  std::cout << "Quest 5 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 5"))) << "\n";
  std::cout << "Quest 6 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 6"))) << "\n";
  std::cout << "Quest 7 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 7"))) << "\n";
  std::cout << "Quest 8 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 8"))) << "\n";
  std::cout << "Quest 9 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 9"))) << "\n";
  std::cout << "\n";
  /*
  std::cout << "Talk to Songcatcher: " << quests.calculateProjectedExperience(quests.getItem(quests.getPosOf("Talk to Songcatcher"))) << "\n";
  std::cout << "The Melodeon's Song: " << quests.calculateProjectedExperience(quests.getItem(quests.getPosOf("The Melodeon's Song"))) << "\n";
   std::cout << "Great. We Have A Melodeon: " << quests.calculateProjectedExperience(quests.getItem(quests.getPosOf("Great. We Have A Melodeon"))) << "\n";
  std::cout << "The Meledeon Points:
  */

  /*
  std::cout << "-------------------------------------\n";
  std::cout << "Calculate Pathway Experience\n";
  std::cout << "Quest 1: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 1"))) << "\n";
  std::cout << "Quest 2: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 2"))) << "\n";
  std::cout << "Quest 3: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 3"))) << "\n";
  std::cout << "Quest 4: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 4"))) << "\n";
  std::cout << "Quest 5: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 5"))) << "\n";
  std::cout << "Quest 6: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 6"))) << "\n";
  std::cout << "Quest 7: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 7"))) << "\n";
  std::cout << "Quest 8: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 8"))) << "\n";
  std::cout << "Quest 9: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 9"))) << "\n\n";

  /*
  std::cout << "Pest Control: " << quests.calculatePathwayExperience(quests.getItem(quests.getPosOf("Pest Control"))) << "\n";
  std::cout << "Talk to the Barkeep: " << quests.calculatePathwayExperience(quests.getItem(quests.getPosOf("Talk to the Barkeep"))) << "\n";
    std::cout << "Talk to the Mysterious Figure: " << quests.calculatePathwayExperience(quests.getItem(quests.getPosOf("Talk to the Mysterious Figure"))) << "\n";
  std::cout << "Explore The Tavern: " << quests.calculatePathwayExperience(quests.getItem(quests.getPosOf("Explore The Tavern"))) << "\n";
  */
  
  
/*
 std::cout << "-------------------------------------\n";
  std::cout << "Print Quest Test \n\n";
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 1")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 2")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 3")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 4")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 5")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 6")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 7")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 8")));
  debug.printQuest(debug.getItem(debug.getPosOf("Quest 9")));

 
 std::cout << "-------------------------------------\n";
  std::cout << "Quest History Test\n\n";
  std::cout << "    NONE\n";
  debug.questHistory();
  std::cout << "    \nCOMPLETE\n";
  debug.questHistory("COMPLETE");
  std::cout << "    \nINCOMPLETE\n";
  debug.questHistory("INCOMPLETE");
  std::cout << "    \nAVAILABLE\n";
  debug.questHistory("AVAILABLE");
   std::cout << "    \IVALID\n";
  debug.questHistory("INVALID");
  
  std::cout << "-------------------------------------\n";
  std::cout << "print quest details test\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 1")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 2")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 3")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 4")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 5")));
  std::cout << "\n";
   debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 6")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 7")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 8")));
  std::cout << "\n";
   debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 9")));
  std::cout << "\n";
  
 */ 

 std::cout << "-------------------------------------\n";
  std::cout << "Project experience Test \n\n";
  std::cout << "Quest 1 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 1"))) << "\n";
  std::cout << "Quest 2 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 2"))) << "\n";
  std::cout << "Quest 3 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 3"))) << "\n";
  std::cout << "Quest 4 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 4"))) << "\n";
  std::cout << "Quest 5 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 5"))) << "\n";
  std::cout << "Quest 6 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 6"))) << "\n";
  std::cout << "Quest 7 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 7"))) << "\n";
  std::cout << "Quest 8 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 8"))) << "\n";
  std::cout << "Quest 9 Points: " << debug.calculateProjectedExperience(debug.getItem(debug.getPosOf("Quest 9"))) << "\n";
  std::cout << "\n";
  
  std::cout << "Calculate Pathway Experience\n";
  std::cout << "Quest 1: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 1"))) << "\n";
  std::cout << "Quest 2: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 2"))) << "\n";
  std::cout << "Quest 3: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 3"))) << "\n";
  std::cout << "Quest 4: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 4"))) << "\n";
  std::cout << "Quest 5: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 5"))) << "\n";
  std::cout << "Quest 6: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 6"))) << "\n";
  std::cout << "Quest 7: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 7"))) << "\n";
  std::cout << "Quest 8: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 8"))) << "\n";
  std::cout << "Quest 9: " << debug.calculatePathwayExperience(debug.getItem(debug.getPosOf("Quest 9"))) << "\n\n";

  std::cout << "Quest Query Test \n\n";
  //debug.questQuery("Non existents");
  //std::cout << "\n";
  debug.questQuery("Quest 1");
  std::cout << "\n";
  debug.questQuery("Quest 2");
  std::cout << "\n";
  debug.questQuery("Quest 3");
  std::cout << "\n";
  debug.questQuery("Quest 4");
  std::cout << "\n";
  debug.questQuery("Quest 5");
  std::cout << "\n";
  std::string title = "Quest 5";
  //std::cout << "dependency: " << debug.dependenciesComplete(debug.getItem(debug.getPosOf(title))) << "\n";
 // std::cout << "available: " << debug.questAvailable(debug.getItem(debug.getPosOf(title))) << "\n";
  debug.questQuery("Quest 6");
  std::cout << "\n";
  debug.questQuery("Quest 7");
  std::cout << "\n";
  debug.questQuery("Quest 8");
  std::cout << "\n";
  debug.questQuery("Quest 9");
  std::cout << "\n";
  debug.questQuery("Quest 12");
  std::cout << "\n";

   std::cout << "-------------------------------------\n";
  std::cout << "print quest details test\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 1")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 2")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 3")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 4")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 5")));
  std::cout << "\n";
   debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 6")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 7")));
  std::cout << "\n";
  debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 8")));
  std::cout << "\n";
   debug.printQuestDetails(debug.getItem(debug.getPosOf("Quest 9")));
  std::cout << "\n";


   std::cout << "-------------------------------------\n";
     std::cout << "Quest History Test\n\n";
  std::cout << "    NONE\n";
  debug.questHistory();
  std::cout << "    \nCOMPLETE\n";
  debug.questHistory("COMPLETE");
  std::cout << "    \nINCOMPLETE\n";
  debug.questHistory("INCOMPLETE");
  std::cout << "    \nAVAILABLE\n";
  quests.questHistory("AVAILABLE");
   std::cout << "    \IVALID\n";
  debug.questHistory("INVALID");
   //debug.KyleFullDisplay();
  
}