/*
CSCI235 Fall 2023
Project 5 - Quest Management with Doubly Linked Lists 
Julianne Aguilar 
November 10, 2023
QuestList.cpp defines the constructors and private and public function implementation of the QuestList class and the Quest struct
Project Description: This program allows Characters to manage their own personlized quests. 
*/
#include "QuestList.hpp"

/**
Default Constructor
@post: Creates a new Quest object with default values (zero-initialized)
**/
Quest::Quest(){
  title_ = "";
  description_= "";
  completed_ = false;
  experience_points_ = 0;
  dependencies_ = {};
  subquests_ = {};
}

/**
Parameterized Constructor 
@param: A reference to string reference to a quest title
@param: A reference to string reference to a quest description
@param: A reference to boolean representing if the quest is completed
@param: An reference to int indicating the experience points
@param: A reference to vector of Quest pointers representing the quest's dependencies
@param: A reference to vector of Quest pointers representing the quest's subquests
@post: Creates a new Quest object with the given parameters
**/
Quest::Quest(const std::string &title, const std::string &description, const bool &completed,const int& experience, const std::vector<Quest *>& dependencies, const std::vector<Quest *>& subquests){
  title_ = title;
  description_ = description;
  completed_ = completed;
  experience_points_ = experience;
  dependencies_ = dependencies;
  subquests_ = subquests;
}

/**
Default Constructor
**/
QuestList::QuestList(): DoublyLinkedList<Quest*>(){
}

/**
Parameterized Constructor 
@param: a reference to string name of an input file
@pre: Formatting of the csv file is as follows:
  Title: A string
  Description: A string
  Completion Status: 0 (False) or 1 (True)
  Experience Points: A non negative integer
  Dependencies: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
  Subquests: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
  Notes:
  - The first line of the input file is a header and should be ignored.
  - The dependencies and subquests are separated by a semicolon and may be NONE.
  - The dependencies and subquests may be in any order.
  - If any of the dependencies or subquests are not in the list, they should be created as new quests with the following information:
      - Title: The title of the quest
      - Description: "NOT DISCOVERED"
      - Completion Status: False
      - Experience Points: 0
      - Dependencies: An empty vector
      - Subquests: An empty vector
  - However, if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, you should update all the quest details.
@post: Each line of the input file corresponds to a quest to be added to the list. No duplicates are allowed.
**/ 
QuestList::QuestList(const std::string &file){
  std::ifstream find(file);
  if(find.fail()){
    std::cerr << "File cannot be opened for reading." <<std::endl;
    exit(1);
  }
  std::string ignore, current_line, temp, title, description, dependencies, subquests;
  size_t semi;
  std::getline(find,ignore); //used to ignore the first line of the file that represent the column names
  while(std::getline(find,current_line)){
    std::istringstream ss(current_line);
    std::getline(ss, title, ','); 
    std::getline(ss, description, ',');
    std::getline(ss, temp, ',');  
    bool completion = stoi(temp);
    std::getline(ss, temp, ','); 
    int experience = stoi(temp);
    std::getline(ss, dependencies, ',');
    std::getline(ss, subquests, '\r');  
    //vector to store the dependencies and subquests 
    std::vector<Quest*> vdependencies = {};
    std::vector<Quest*> vsubquests = {};
    //iterates through each dependency in the string that cotains all the dependencies separated by a comma 
    while(!dependencies.empty()){
      semi = dependencies.find(";");
      std::string dependency = dependencies.substr(0, semi);
      dependencies.erase(0, dependency.length() + 1);
      //if the QuestList already contains the dependency then pushes the Quest object of the dependency to the dependencies vector
      if(contains(dependency)){
        Node<Quest*> *temp1 = first_;
        while(temp1 != nullptr){
          if(temp1 -> getItem() -> title_ == dependency){
            vdependencies.push_back(temp1 -> getItem());
            //addQuest(temp1 -> getItem());
          }
          temp1 = temp1 -> getNext();
        }
      }
      //if dependency is not NONE creates a new Quest Object with the title and pushes it to the dependencies vector
      else if(dependency != "NONE"){
        Quest *temp = new Quest();
        temp ->title_ = dependency;
        temp -> description_ = "NOT DISCOVERED";
        vdependencies.push_back(temp);
        //std::cout << "ADDING: " << temp -> title_ << "\n";
        addQuest(temp);
      }
    }
    //iterates through each subquest in the string that cotains all the subquests separated by a comma 
    while(!subquests.empty()){
      semi = subquests.find(";");
      std::string subquest = subquests.substr(0, semi);
      subquests.erase(0, subquest.length() + 1);
      //if the QuestList already contains the subquest then pushes the Quest object of the subquest to the subquests vector
      if(contains(subquest)){
        Node<Quest*> *temp1 = first_;
        while(temp1 != nullptr){
          if(temp1 -> getItem() -> title_ == subquest){
            vsubquests.push_back(temp1 -> getItem());
          }
          temp1 = temp1 -> getNext();
        }
      }
      //if subquest is not NONE creates a new Quest Object with the title and pushes it to the subquest vector
      else if(subquest != "NONE"){
         Quest *temp = new Quest();
        temp ->title_ = subquest;
        temp -> description_ = "NOT DISCOVERED";
        vsubquests.push_back(temp);
        addQuest(temp);
      }
    }
    addQuest(title, description, completion, experience, vdependencies, vsubquests);
  }

}
   
/**
Determines the integer position of a given quest in the QuestList 
@param: A string reference to a quest title
@return: The integer position of the given quest if it is in the QuestList, -1 if not found.
**/
int QuestList::getPosOf(const std::string &title) const{
  for(int i = 0; i < item_count_ ; i++){
    if(getItem(i)->title_ == title){
      return i;
    }
  }
  return -1;
}

/**
Determines if the given quest is in the QuestList 
@param: A string reference to a quest title
@return: True if the quest with the given title is already in the QuestList
**/
bool QuestList::contains(const std::string &title) const{
  if(getPosOf(title) != -1){ //if able to find integer position of the quest title in the list
    return true;
  }
  return false;
}

/**
Adds the given quest object to the QuestList
@pre: The given quest is not already in the QuestList
@param:  A pointer to a Quest object
@post:  Inserts the given quest pointer into the QuestList. Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
      If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)       
@return: True if the quest was added or updated successfully, False otherwise
**/
bool QuestList::addQuest(Quest *object){
  //if quest is not in QuestList
  if(!contains(object->title_)){
    //insert quest to back of list
    insert(item_count_,object);

    //insert quest's dependencies, if dependencies not already in list
    for(int i = 0; i < object -> dependencies_.size(); i++){
      if(!contains(object -> dependencies_[i] -> title_)){
        object -> dependencies_[i] -> description_ = "NOT DISCOVERED";
        insert(item_count_, object -> dependencies_[i]);
      } 
    }
    //insert quest subquests, if subquests not already in list
    for(int j = 0; j < object -> subquests_.size(); j++){
        if(!contains(object -> subquests_[j] -> title_ )){
        object -> subquests_[j] -> description_ = "NOT DISCOVERED";
        insert(item_count_, object -> subquests_[j]);
        }
    }
    return true;
  }
  //if adding a quest already in list but marked as "NOT DISCOVERED"
  else if(contains(object -> title_) && getItem(getPosOf(object->title_)) -> description_ == "NOT DISCOVERED"){
    getItem(getPosOf(object->title_)) -> description_ = object -> description_;
    getItem(getPosOf(object->title_)) -> completed_ = object -> completed_;
    getItem(getPosOf(object->title_)) ->   experience_points_ = object ->   experience_points_;
    getItem(getPosOf(object->title_)) -> dependencies_ = object -> dependencies_;
    getItem(getPosOf(object->title_)) -> subquests_ = object -> subquests_;

    //insert quest's dependencies, if dependencies not already in list
    if(!object->dependencies_.empty()){
    for(int i = 0; i < object -> dependencies_.size(); i++){
      if(!contains(object -> dependencies_[i] -> title_)){
        object -> dependencies_[i] -> description_ = "NOT DISCOVERED";
        insert(item_count_, object -> dependencies_[i]);
      }
    }
    }
    if(!object -> subquests_.empty()){
      //insert quest subquests, if subquests not already in list
      for(int j = 0; j < object -> subquests_.size(); j++){
        if(!contains(object -> subquests_[j] -> title_)){
        object -> subquests_[j] -> description_ = "NOT DISCOVERED";
        insert(item_count_, object -> subquests_[j]);
      }
    }
    }

    return true;
  }
  return false;
}

/**
Adds a new quest object to the QuestList with the given details
@param:  A reference to string representing the quest title
@param:  A reference to string representing the quest description
@param:  A reference to boolean representing if the quest is completed
@param:  An reference to int representing experience points the quest rewards upon completion 
@param:  A reference to vector of Quest pointers representing the quest's dependencies
@param:  A reference to vector of Quest pointers representing the quest's subquests
@post:   Creates a new Quest object and inserts a pointer to it into the QuestList. 
        If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
        Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
@return: True if the quest was added or updated successfully, False otherwise
**/
bool QuestList::addQuest(const std::string &title, const std::string &description, const bool &completed, const int &experience, const std::vector<Quest *> &dependencies, const std::vector<Quest *> &subquests)
{
  Quest *quest = new Quest(title, description, completed, experience, dependencies, subquests);
  bool added = addQuest(quest);
  if(added == true){
    return true;
  }
  return false;
}

/**
Determines if the given Quest object's dependencies are complete 
@param:  A Quest pointer
@return: A boolean indicating if all the given quest's dependencies are completed
**/
bool QuestList::dependenciesComplete(const Quest *object) const
{
  if(getItem(getPosOf(object ->title_)) -> dependencies_.empty()){
    return true;
  }
  //iterates through the givens quests dependecnies determining if they're complete or incomplete
  for(int i = 0; i < getItem(getPosOf(object->title_)) -> dependencies_.size(); i++){
    std::string title = getItem(getPosOf(object ->title_)) -> dependencies_[i] -> title_;
    if(getItem(getPosOf(title)) ->completed_ == false){
      return false;
    }
  }
  return true;
}


/**
Determines if the given quest is available for a character to do
@param: A Quest pointer
@return: A boolean if the given quest is available.
Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
**/
bool QuestList::questAvailable(Quest *object) const
{
  if(dependenciesComplete(object) && getItem(getPosOf(object->title_)) -> completed_ == false){
    return true;
  }
  return false;
}

/**
Shows the quests title and completion status in the QuestList
@param: A Quest pointer
@post: Prints the quest title and completion status
The output should be of the form:
[Quest Title]: [Complete / Not Complete]
[Quest Description]\n\n
**/
void QuestList::printQuest(Quest *object){ 
  std::cout << object ->title_ << ": " << (object -> completed_ ? "Complete\n" : "Not Complete\n");
  std::cout << object -> description_ << "\n\n";
}

/**
Shows the quests that must be completed before the given quest can be started
@param: A string reference to a quest title
@post:  Prints a list of quests that must to be completed before the given quest can be started (incomplete dependencies).
        If any of the quest's incomplete dependencies have an incomplete dependency, recursively print the quests that need to be done in order, indenting incomplete quests. 
        The indentation for incomplete quests is 2 spaces: "  "    
        The format of the list should be of the following forms for each different case:

        Query: [Quest Title]
        No such quest.

        Query: [Quest Title]
        Quest Complete

        Query: [Quest Title]
        Ready: [Quest Title]

        Query: [Quest Title]
        Ready: [Dependency0]
          [Quest Title]
        
        Query: [Quest Title]
        Ready: [Dependency0]
        Ready: [Dependency1]
          [Quest Title]

        Query: [Quest Title]
        Ready: [Dependency0]
        Ready: [Dependency1]
          [Dependency2]
          [Quest Title]        
  If the given quest title is not found in the list, print "No such quest."
**/
void QuestList::questQuery(const std::string& title) const {
  //base case quest does not exist in list 
  if(getPosOf(title) == -1){
    std::cout << "Query: " << title << "\n";
    std::cout << "No such quest." << std::endl;
  }
  //base case quest already complete 
  else if (getItem(getPosOf(title)) -> completed_ == true){
    std::cout << "Query: " << title << "\n";
    std::cout << "Quest Complete" << std::endl;
  }
  else{
    std::cout << "Query: " << title << "\n";
    //prints the unfinished dependencies of the given quest
    unfinishedQuests(title);
  }
  
};
  
/**
Calculates the sum of experienced gained from completed quests in the QuestList
@return: An integer sum of all the experience gained
Note: This should only include experience from completed quests 
**/
int QuestList::calculateGainedExperience() const{
  int total = 0;
  Node<Quest*> * temp;
  for(int i = 0; i < item_count_; i++){
    temp = getPointerTo(i);
    if(temp -> getItem() -> completed_ == true){
      total += temp -> getItem() -> experience_points_;
    }
  }
  return total;
}

/**
Calculates the sum of all experience that can be gained from completing the given quests and all its subquests
@param: A quest pointer to a main quest
@return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
Note: Also consider the potential experience if a subquest itself has subquests.
**/
int QuestList::calculateProjectedExperience(const Quest* quest) const
{
  
  if(quest -> subquests_.empty()){
    return quest -> experience_points_;
  }
  else{
     int total = quest -> experience_points_;
     for(int i = 0; i < quest -> subquests_.size(); i++){
      total += calculateProjectedExperience(quest -> subquests_[i]);
    }
    return total;
  }
  
}

/**
Calculates the sum of all experience already gained from completing the given quest and it's subquests
@param: A quest pointer to a main quest
@return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
Note: Also consider the experience gained if a completed subquest itself has subquests.  
**/
int QuestList::calculatePathwayExperience(const Quest *quest) const
{
  if(quest -> subquests_.empty()){
    return quest -> experience_points_;
  }

  int total = 0;
  if(quest -> completed_){
    total = total + quest -> experience_points_;
  }
  for(int i = 0; i < quest -> subquests_.size(); i++){
    if(quest -> subquests_[i] -> completed_ == true){
      total = total + quest -> subquests_[i] -> experience_points_;
    }
  }
  return total;
  
}
   
/**
Prints out the quest history in the list based on the filter given
@param: A string reference to a filter with a default value of "NONE".
@post: With default filter "NONE": Print out every quest in the list.
        With filter "COMPLETE":   Only print out the completed quests in the list.
        With filter "INCOMPLETE": Only print out the incomplete quests in the list.
        With filter "AVAILABLE":  Only print out the available quests in the list.
        If an invalid filter is passed, print "Invalid Filter\n"
        Printing quests should be of the form:
        [Quest title]: [Complete / Not Complete]  
        [Quest description]\n
**/
void QuestList::questHistory(const std::string &filter)
{
  Node<Quest*> * temp = first_;
  if(filter == "NONE"){
    while(temp != nullptr){
      std::cout << temp -> getItem() ->title_ << ": " << (temp -> getItem() -> completed_ ? "Complete\n" : "Not Complete\n");
      std::cout << temp -> getItem() -> description_ << "\n";
      temp = temp ->getNext();
    }
  }
  else if(filter == "COMPLETE"){
    while(temp != nullptr){
      if(temp -> getItem() -> completed_ == true){
         std::cout <<temp -> getItem() -> title_ << ": " << (temp -> getItem() -> completed_ ? "Complete\n" : "Not Complete\n");
        std::cout << temp -> getItem() -> description_ << "\n";
      }
      temp = temp -> getNext();
    }
  }
  else if(filter == "INCOMPLETE"){
    while(temp != nullptr){
      if(temp -> getItem() -> completed_ == false){
        std::cout << temp -> getItem() -> title_ << ": " << (temp -> getItem() -> completed_ ? "Complete\n" : "Not Complete\n");
        std::cout << temp -> getItem() -> description_ << "\n";
      }
      temp = temp -> getNext();
    }
   
  }
  else if(filter == "AVAILABLE"){
    while(temp != nullptr){
      if(questAvailable(temp -> getItem()) == true){
        std::cout << temp -> getItem() -> title_ << ": " << (temp -> getItem() -> completed_ ? "Complete\n" : "Not Complete\n");
        std::cout << temp -> getItem() -> description_ << "\n";
      }
      temp = temp -> getNext();
    }
  }
  else{
    std::cout << "Invalid Filter\n";
  }
}

/**
Prints the given quest's percentage of experience gained from its pathway along with its subquests completion status 
@param: A quest pointer to a main quest
@post:  Outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
        Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
        The format should be of the form:
        [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
            [Subquest0]: [Complete / Not Complete]
                [Sub-Subquest01]: [Complete / Not Complete]
                    [Sub-Subquest011]: [Complete / Not Complete]
                [Subquest02]: [Complete / Not Complete]
**/
void QuestList::printQuestDetails(Quest *quest) const
{
  //no subquest case 
  if(quest -> subquests_.empty()){
    double pathway = calculatePathwayExperience(quest) * 1.0;
    double projected = calculateProjectedExperience(quest) * 1.0;
    int avg = (pathway/projected)*100;
    std::cout << quest -> title_ << " (" << avg << "% Complete)\n";
  }
  else{
    double pathway = calculatePathwayExperience(quest) * 1.0;
    double projected = calculateProjectedExperience(quest) * 1.0;
    int avg = (pathway/projected)*100;
    std::cout << quest -> title_ << " (" << avg << "% Complete)\n";
    for(int i = 0; i < quest -> subquests_.size(); i++){
        int space = 2;
        //recursively prints the given quests subquests and it's completion status 
        printSubquests(quest->subquests_[i], space);
    }
  }


}

/**
A helper function that recursively prints out the given quests unfinished dependencies
@param: A quest title 
@post: Outputs the unfinished quest in the form: 
      Ready: [Last Unfinished dependency]
          [Title of Unfinished Dependency 1]
          [Title of Unifinihsed Dependency 2]
**/
void QuestList::unfinishedQuests(const std::string &title) const{
  //base case if all its dependenices are complete 
  if(dependenciesComplete(getItem(getPosOf(title)))){
    std::cout << "Ready: " << getItem(getPosOf(title)) -> title_ << "\n";
  }
  else{
    //Iterates through the each of the givens quests dependencies and passes each one recursively to the function
    for(int i = 0; i < getItem(getPosOf(title)) -> dependencies_.size(); i++){
      std::string dependency = getItem(getPosOf(title)) -> dependencies_[i] -> title_;
      if(getItem(getPosOf(dependency)) -> completed_ == false){
        unfinishedQuests(dependency);
      }
    }
    std::cout << "  " << title << "\n";
  }
  
}

/**
A helper function that recursively prints the given quests subquests and it's completion status 
@param:A quest object representing the main quest, an integer representing the number of spaces to print the subquest with
@post: Prints the main quests subquests with two spaces of indentation in the format: 
        [Subquest0]: [Complete / Not Complete]
            [Sub-Subquest01]: [Complete / Not Complete]
                [Sub-Subquest011]: [Complete / Not Complete]
            [Subquest02]: [Complete / Not Complete]
**/
void QuestList::printSubquests(Quest *main, int spaces) const
{
   std::string title = main -> title_;
    if(getItem(getPosOf(title)) -> subquests_.empty()){
       std::cout << "  " << title << ": " << (main -> completed_ ? "Complete\n" : "Not Complete\n");
    }
    else{
      //spaces printed increase by 2 with each subquests of a subquests print
      spaces += 2;
      std::cout << "  " << title << ": " << (getItem(getPosOf(main -> title_)) -> completed_ ? "Complete\n" : "Not Complete\n");
      for(int i = 0; i < main-> subquests_.size(); i++){
         printSpace(spaces);
         printSubquests(main-> subquests_[i], spaces);
      }
    }
}

/**
A helper function that prints the amount of spaces given 
@param: An integer that representes the amount of spaces to be printed 
@post: Outputs the amount of spaces given
**/
void QuestList::printSpace(int spaces) const{
  for(int i = 0; i < spaces; i++){
    std::cout << " ";
  }

}

