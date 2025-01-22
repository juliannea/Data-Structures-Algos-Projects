#include <iostream>
#include "Character.hpp"
#include "ArrayBag.hpp"
#include "Tavern.hpp"

int main(){
  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Character operator == test" << std::endl;
  Character Naksu("Naksu", "UNDEAD", 10, 10, 15, false);
  Character Naksu2("Naksu", "UNDEAD", 10, 10, 15, false);
  bool same_test1 = Naksu == Naksu2;
  std::cout << "same character true test: " << std::boolalpha << same_test1 << std::endl;
  Character Uk("Uk", "UNDEAD", 10, 10 , 15, true);
  bool same_test2 = Naksu == Uk;
  std::cout << "same character false test: " << std::boolalpha << same_test2 << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Character operator != test" << std::endl;
  bool not_same1 = Naksu != Uk;
  std::cout << "!= character true test: " << std::boolalpha << not_same1 << std::endl;
  bool not_same2 = Naksu != Naksu2;
  std::cout << "!= character false test: " << std::boolalpha << not_same2 << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Character display test" << std::endl;
  Naksu.display();
  std::cout << "\n";
  Uk.display();

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Array bag /= test" << std::endl;
  ArrayBag<int> bag1;
  bag1.add(1);
  bag1.add(2);
  bag1.add(3);

  ArrayBag<int> bag2;
  bag2.add(1);
  bag2.add(3);
  bag2.add(4);
  bag2.add(2);
  
  bag1 /= bag2;

  std::cout << "items in bag 1 after /= bag 2: \n";

  std::cout << "checking frequency for no duplicates: \n";
  std::cout << "frequency of 1: " << bag1.getFrequencyOf(1) << "\n";
  std::cout << "frequency of 2: " << bag1.getFrequencyOf(2) << "\n";
  std::cout << "frequency of 3: " << bag1.getFrequencyOf(3) << "\n";
  std::cout << "frequency of 4: " << bag1.getFrequencyOf(4) << "\n";

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Array bag += test" << std::endl;
  ArrayBag<int> bag3;
  bag3.add(1);
  bag3.add(2);
  bag3.add(3);

  ArrayBag<int> bag4;
  bag4.add(1);
  bag4.add(3);
  bag4.add(4);
  bag4.add(2);

  bag3 += bag4;

  std::cout << "checking frequency for duplicates: \n";
  std::cout << "frequency of 1: " << bag3.getFrequencyOf(1) << "\n";
  std::cout << "frequency of 2: " << bag3.getFrequencyOf(2) << "\n";
  std::cout << "frequency of 3: " << bag3.getFrequencyOf(3) << "\n";
  std::cout << "frequency of 4: " << bag3.getFrequencyOf(4) << "\n";

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Default Tavern test" << std::endl;
  Tavern Moonwood;


  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Enter Tavern test" << std::endl;
  Character Bryce("Bryce", "HUMAN", 3, 4, 5, false);
  std::cout << "Bryce enter tavern: " << Moonwood.enterTavern(Bryce) << "\n";
  std::cout << "Tavern after Level 5 Bryce not enemy enters: \n";

  std::cout << "Testing Bryce frequency: " << Moonwood.getFrequencyOf(Bryce) << "\n";
  std::cout << "\n";

  Character Aidas("Aidas", "UNDEAD", 2, 3, 4, true);
  Moonwood.enterTavern(Aidas);
  std::cout << "Tavern after Level 4 Aidas enemy enters: \n";

  std::cout << "Testing Aidas frequency: " << Moonwood.getFrequencyOf(Aidas) << "\n";

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Exit Tavern test" << std::endl;
  std::cout << "Aidas exits Tavern: " << Moonwood.exitTavern(Aidas) << "\n";
  std::cout << "Tavern after Level 4 Aidas enemy exits: \n";
  
  std::cout << "Testing Aidas frequency: " << Moonwood.getFrequencyOf(Aidas) << "\n";

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Level Sum get Tavern test" << std::endl;
  std::cout << "Level Sum 5: " << Moonwood.getLevelSum() << "\n";

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Get avg level Tavern test" << std::endl;
  Character Hunt("Hunt", "ELF", 5, 4, 4, false);
  Moonwood.enterTavern(Hunt);
  std::cout << "Level after Hunt enters 9: " << Moonwood.getLevelSum() << "\n";
  std::cout << "Avg level: " << Moonwood.calculateAvgLevel() << "\n";

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Get enemy count Tavern test" << std::endl;
  Moonwood.enterTavern(Aidas);
  Character Asteri("Asteri", "UNDEAD", 3,4,9, true);
  Moonwood.enterTavern(Asteri);
  std::cout << "enemy count after Aidas and Asteri enter: " << Moonwood.getEnemyCount() << "\n";
  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Enemy percentage Tavern test" << std::endl;
  std::cout << "Current size: " << Moonwood.getCurrentSize() << "\n";
  std::cout << "Enemy count: " << Moonwood.getEnemyCount() << "\n";
  std::cout << "Avg enemy percent: " << Moonwood.calculateEnemyPercentage() << "\n";
  std::cout << "enemy count after Aidas and Asteri enter: " << Moonwood.getEnemyCount() << "\n";
  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Tally race test\n";
  //Bryce = Human, Aidas = Undead, Asteri = Undead, Hunt = Elf
  std::cout << "Humans: " << Moonwood.tallyRace("HUMAN") << "\n";
  std::cout << "Undead: " << Moonwood.tallyRace("UNDEAD") << "\n";
  std::cout << "Elf: " << Moonwood.tallyRace("ELF") << "\n";
  std::cout << "Lizard: " << Moonwood.tallyRace("LIZARD") << "\n";
  std::cout << "Dwarf: " << Moonwood.tallyRace("DWARF") << "\n";
  std::cout << "None: " << Moonwood.tallyRace("NONE") << "\n";
  std::cout << "Fae: " << Moonwood.tallyRace("FAE") << "\n";

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "Tavern Report test\n";
  Moonwood.tavernReport();

  int x = 3;
  double y = x/2;
  std::cout << y << "\n";
  
} 