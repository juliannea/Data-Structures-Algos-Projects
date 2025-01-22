/*
CSCI235 Fall 2023
Project 5 - Quest Management with Doubly Linked Lists 
Julianne Aguilar 
November 10, 2023
QuestList.hpp declares the QuestList class along with its private and public members as well as the Quest struct with its members
Project Description: This program allows Characters to manage their own personlized quests. 
*/
#pragma once
#include "DoublyLinkedList.hpp"
#include <fstream>
#include <vector>
#include <sstream>

/*
A Quest struct that defines its data members and constructors
*/
struct Quest{
  //A string representing the quest title
  std::string title_; 
  //A string representing the quest description
  std::string description_; 
  //A boolean representing if the quest is completed
  bool completed_;
  //An int representing experience points the quest rewards upon completion
  int experience_points_;
  //A vector of Quest pointers representing the quest's dependencies
  std::vector<Quest*> dependencies_;
  //A vector of Quest pointers representing the quest's subquests
  std::vector<Quest*> subquests_;
  /**
  Default Constructor
  @post: Creates a new Quest object with default values (zero-initialized)
  **/
  Quest();
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
  Quest(const std::string& title, const std::string& description, const bool& completed,const int& experience, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests);
};

class QuestList: public DoublyLinkedList<Quest*>{
  public:
  /**
  Default Constructor
  **/
  QuestList();

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
  QuestList(const std::string& file);

  /**
  Determines the integer position of a given quest in the QuestList 
  @param: A string reference to a quest title
  @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
  **/
  int getPosOf(const std::string & title) const;

  /**
  Determines if the given quest is in the QuestList 
  @param: A string reference to a quest title
  @return: True if the quest with the given title is already in the QuestList
  **/
  bool contains(const std::string& title) const;

  /**
  Adds the given quest object to the QuestList
  @pre: The given quest is not already in the QuestList
  @param:  A pointer to a Quest object
  @post:  Inserts the given quest pointer into the QuestList. Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
          If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)       
  @return: True if the quest was added or updated successfully, False otherwise
  **/
  bool addQuest(Quest* object);

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
  bool addQuest(const std::string& title, const std::string& description, const bool& completed, const int& experience, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquests);

  /**
  Determines if the given Quest object's dependencies are complete 
  @param:  A Quest pointer
  @return: A boolean indicating if all the given quest's dependencies are completed
  **/
  bool dependenciesComplete(const Quest * object) const;

  /**
  Determines if the given quest is available for a character to do
  @param: A Quest pointer
  @return: A boolean if the given quest is available.
  Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
  **/
  bool questAvailable(Quest * object) const;

  /**
  Shows the quests title and completion status in the QuestList
  @param: A Quest pointer
  @post: Prints the quest title and completion status
  The output should be of the form:
  [Quest Title]: [Complete / Not Complete]
  [Quest Description]\n\n
  **/
  void printQuest(Quest * object);

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
  void questQuery(const std::string& title) const;

  /**
  Calculates the sum of experienced gained from completed quests in the QuestList
  @return: An integer sum of all the experience gained
  Note: This should only include experience from completed quests 
  **/
  int calculateGainedExperience() const;

  /**
  Calculates the sum of all experience that can be gained from completing the given quests and all its subquests
  @param: A quest pointer to a main quest
  @return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
  Note: Also consider the potential experience if a subquest itself has subquests.
  **/
  int calculateProjectedExperience(const Quest * quest) const;

  /**
  Calculates the sum of all experience already gained from completing the given quest and it's subquests
  @param: A quest pointer to a main quest
  @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
  Note: Also consider the experience gained if a completed subquest itself has subquests.  
  */
  int calculatePathwayExperience(const Quest * quest) const;

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
  void questHistory(const std::string & filter = "NONE");

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
  void printQuestDetails(Quest * quest) const;

  
  private:
    /**
    A helper function that recursively prints out the given quests unfinished dependencies
    @param: A quest title 
    @post: Outputs the unfinished quest in the form: 
              Ready: [Last Unfinished dependency]
              [Title of Unfinished Dependency 1]
              [Title of Unifinihsed Dependency 2]
    **/
    void unfinishedQuests(const std::string& title) const;

    /**
    A helper function that recursively prints the given quests subquests and it's completion status 
    @param:A quest object representing the main quest, an integer representing the number of spaces to print the subquest with
    @post: Prints the main quests subquests with two spaces of indentation in the format: 
            [Subquest0]: [Complete / Not Complete]
                [Sub-Subquest01]: [Complete / Not Complete]
                    Sub-Subquest011]: [Complete / Not Complete]
                [Subquest02]: [Complete / Not Complete]
    **/
    void printSubquests(Quest* main, int spaces) const;

    /**
    A helper function that prints the amount of spaces given 
    @param: An integer that representes the amount of spaces to be printed 
    @post: Outputs the amount of spaces given
    **/
    void printSpace(int spaces) const;

  
    
    
};

    
    
   
