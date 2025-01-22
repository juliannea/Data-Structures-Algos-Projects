#include <iostream>
#include "Character.hpp"

int main(){

    std::cout<< "----------------------------------------" << std::endl;
    std::cout <<"Character Name Tests" << std::endl;
    std::cout<< std::endl;

    std::cout <<"testing default contsructor name" <<std::endl;

    Character default_character;
    default_character = Character();
    std::string dname = default_character.getName();
    std::cout << "default character name: " << dname << std::endl;
    std::cout<< std::endl;

    std::cout <<"testing param contsructor name" <<std::endl;
    Character param; 
    param = Character("I2RiS3", "unDead", 2, 4, 3, true);
    std::string pname = param.getName();
    std::cout << "param I2RiS3 character name: " << pname << std::endl;
    std::cout<< std::endl;

    std::cout <<"testing setname" <<std::endl;
    Character test;
    //std::string setTestName = "TWE3edleDUm2";
    test.setName("TWE3edleDUm2");
    //std::string tname = test.getName();
    std::cout << "TWE3edleDUm2 name test: " << test.getName() << std::endl;
    //setTestName = "12345";
    test.setName("12345");
    //tname = test.getName();
    std::cout << "12345 name test: " << test.getName() << std::endl;
    //setTestName = "nEstA";
    test.setName("nEstA");
    //tname = test.getName();
    std::cout << "nEstA name test: " << test.getName() << std::endl;


    std::cout<< "----------------------------------------" << std::endl;
    std::cout <<"Character Race Tests" << std::endl;
    std::cout << "Default race test: " << default_character.getRace() << std::endl;
    std::cout << "Param race test: " << param.getRace() << std::endl; 

    test.setRace("unDead");
    std::cout << "test setRace undead: " << test.getRace() << std::endl;

    test.setRace("fairy");
    std::cout << "test setRace invalid fairy: " << test.getRace() << std::endl;
    
    std::cout<< "----------------------------------------" << std::endl;
    std::cout <<"Character Vitality Tests" << std::endl;
    std::cout << "Default vitality: " << default_character.getVitality()<< std::endl;
    std::cout << "Param vitality: " << param.getVitality() << std::endl;
    test.setVitality(-1);
    std::cout << "setVitality -1 test: " << test.getVitality() << std::endl;
    test.setVitality(11);
    std::cout << "setVitality 11 test:" << test.getVitality() << std::endl;
    test.setVitality(5);
    std::cout << "setVitality 5 test:" << test.getVitality() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout <<"Character Armor Tests" << std::endl;
    std::cout << "Default Armor test: " << default_character.getArmor() << std::endl;
    std::cout << "Param Armor test: " << param.getArmor() << std::endl;
    test.setArmor(-2);
    std::cout << "test armor invalid -2: " << test.getArmor() << std::endl;
    test.setArmor(13);
    std::cout << "test armor 13: " << test.getArmor() << std::endl;
    
    std::cout<< "----------------------------------------" << std::endl;
    std::cout <<"Character Level Tests" << std::endl;
    std::cout << "Default Level test: " << default_character.getLevel() << std::endl;
    std::cout << "Param Level test: " << param.getLevel() << std::endl;
    test.setLevel(-1);
    std::cout << "test level invalid -2: " << test.getLevel() << std::endl;
    test.setLevel(10);
    std::cout << "test level 10 : " << test.getLevel() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout <<"Character isEnemy Tests" << std::endl;
    std::cout << "Default isEnemy test: " << std::boolalpha << default_character.isEnemy() << std::endl;
    std::cout << "Param isEnemy test: " << std::boolalpha<< param.isEnemy() << std::endl;
    std::cout << "test default is enemy test: " << std::boolalpha << test.isEnemy() << std::endl;
    test.setEnemy();
    std::cout << "test set enemy: " << std::boolalpha << test.isEnemy() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "Default values in param tests" << std::endl;
    Character paramDefault = Character("T3est2", "dwarf");
    std::cout << "paramDefault name: " << paramDefault.getName() << std::endl;
    std::cout << "paramDefault race: " << paramDefault.getRace() << std::endl;
    std::cout << "paramDefault vitality: " << paramDefault.getVitality() << std::endl;
    std::cout << "paramDefault Armor: " << paramDefault.getArmor() << std::endl;
    std::cout << "paramDefault Level: " << paramDefault.getLevel() << std::endl;
    std::cout << "paramDefault Enemy: " << paramDefault.isEnemy() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "Paremtized Constructor with all arguments test" << std::endl;
    Character test2 = Character("test2", "lizard", 1, 2, 3, true);
    std::cout << "test2 name: " << test2.getName() << std::endl;
    std::cout << "test2 race: " << test2.getRace() << std::endl;
    std::cout << "test2 vitality: " << test2.getVitality() << std::endl;
    std::cout << "test2 armor: " << test2.getArmor() << std::endl;
    std::cout << "test2 level: " << test2.getLevel() << std::endl;
    std::cout << "test2 enemy: " << std::boolalpha << test2.isEnemy() << std::endl;

    std::cout << "testing git add\n";

}