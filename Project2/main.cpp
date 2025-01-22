#include <iostream>
#include "Character.hpp"
#include "Mage.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"

int main(){
  
    std::cout << "mage bool set school test" << std::endl;
    Mage Uk;
    std::cout << "Uk invalid schhol hogwarts test: " << std::boolalpha << Uk.setSchool("hogwarts") << std::endl;
    std::cout << "Uk getschool invlaid test: " << Uk.getSchool() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk schhol necromancy test: " << std::boolalpha << Uk.setSchool("necromancy") << std::endl;
    std::cout << "Uk getschool necromancy test: " << Uk.getSchool()<<std::endl;
    std::cout << std::endl;
    std::cout << "Uk schhol elemental test: " << std::boolalpha << Uk.setSchool("elemental") << std::endl;
    std::cout << "uk get school elemental test: " << Uk.getSchool() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk schhol illusion test: " << std::boolalpha << Uk.setSchool("illusion") << std::endl;
    std::cout << "Uk getschool illusion test: " << Uk.getSchool() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk schhol NECROMANCY test: " << std::boolalpha << Uk.setSchool("NECROMANCY") << std::endl;
    std::cout << "Uk getschool NECROMANCY test: " << Uk.getSchool() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk schhol ILLUSION test: " << std::boolalpha << Uk.setSchool("ILLUSION") << std::endl;
    std::cout << "Uk getschool ILLUSION  test: " << Uk.getSchool() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk schhol ELEMENTAL test: " << std::boolalpha << Uk.setSchool("ELEMENTAL") << std::endl;
    std::cout << "Uk getschool ELEMENTAL  test: " << Uk.getSchool() << std::endl;
    std::cout << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "mage Uk casting weapon tests" << std::endl;
    std::cout << "Uk set weapon invalide sword: " << Uk.setCastingWeapon("sword") << std::endl;
    std::cout << "Uk get weapon invalide sword: " << Uk.getCastingWeapon() <<std::endl;
    std::cout << std::endl;
    std::cout << "Uk set weapon staff: " << Uk.setCastingWeapon("staff") << std::endl;
    std::cout << "Uk get weapon staff: " << Uk.getCastingWeapon() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk set weapon wand: " << Uk.setCastingWeapon("wand") << std::endl;
    std::cout << "Uk get weapon wand: " << Uk.getCastingWeapon() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk get weapon STAFF2: " << Uk.setCastingWeapon("STAFF2") << std::endl;
    std::cout << "Uk get weapon STAFF2: " << Uk.getCastingWeapon() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk set weapon WAND: " << Uk.setCastingWeapon("WAND") << std::endl;
    std::cout << "Uk get weapon WAND: " << Uk.getCastingWeapon() << std::endl;
    std::cout << std::endl;
    std::cout << "Uk set weapon STAFF: " << Uk.setCastingWeapon("STAFF") << std::endl;
    std::cout << "Uk get weapon STAFF: " << Uk.getCastingWeapon() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "mage Uk can summon incarnate test" << std::endl;
    Uk.setIncarnateSummon(true);
    std::cout << "has incarnate summon true test: " << Uk.hasIncarnateSummon() << std::endl;
    std::cout << std::endl;
    Uk.setIncarnateSummon(false);
    std::cout << "has incarnate summon false test: " << Uk.hasIncarnateSummon() << std::endl;
    std::cout << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "mage default constructor test" << std::endl;
    Mage mageD;
    std::cout << "name: " << mageD.getName() << std::endl;
    std::cout << "race: " << mageD.getRace() << std::endl;
    std::cout << "level: " << mageD.getLevel() << std::endl;
    std::cout << "vitality: " << mageD.getVitality() << std::endl;
    std::cout << "armor level: " << mageD.getArmor() << std::endl;
    std::cout << "enemy: " << mageD.isEnemy() << std::endl;
    std::cout << "school: " << mageD.getSchool() << std::endl;
    std::cout << "weapon: " << mageD.getCastingWeapon() << std::endl;
    std::cout << "can summon incarnate: " << mageD.hasIncarnateSummon() << std::endl;
    
    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "mage parameterized constructor defaulkt values test" << std::endl;
    Mage mageDP("Stella2", "UNDEAD");
    std::cout << "name: " << mageDP.getName() << std::endl;
    std::cout << "race: " << mageDP.getRace() << std::endl;
    std::cout << "level: " << mageDP.getLevel() << std::endl;
    std::cout << "vitality: " << mageDP.getVitality() << std::endl;
    std::cout << "armor level: " << mageDP.getArmor() << std::endl;
    std::cout << "enemy: " << mageDP.isEnemy() << std::endl;
    std::cout << "school: " << mageDP.getSchool() << std::endl;
    std::cout << "weapon: " << mageDP.getCastingWeapon() << std::endl;
    std::cout << "can summon incarnate: " << mageDP.hasIncarnateSummon() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "mage parameterized constructor all values test" << std::endl;
    Mage parametized = Mage("Nesta3", "ELF", 1, 2, 3, true, "elemental", "wand", true);
    std::cout << "name: Nesta3 " << parametized.getName() << std::endl;
    std::cout << "ELF race: " << parametized.getRace() << std::endl;
    std::cout << "3 level: " << parametized.getLevel() << std::endl;
    std::cout << "1 vitality: " << parametized.getVitality() << std::endl;
    std::cout << "2 armor level: " << parametized.getArmor() << std::endl;
    std::cout << "true enemy: " << parametized.isEnemy() << std::endl;
    std::cout << "elemental school: " << parametized.getSchool() << std::endl;
    std::cout << "wand weapon: " << parametized.getCastingWeapon() << std::endl;
    std::cout << "true can summon incarnate: " << parametized.hasIncarnateSummon() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "mage parameterized constructor all negative values  and invalid argumentstest" << std::endl;
    Mage parametized2 = Mage("Nesta3", "ELF", -1, -2, -3, true, "invalid", "invalid", true);
    std::cout << "name: " << parametized2.getName() << std::endl;
    std::cout << "race: " << parametized2.getRace() << std::endl;
    std::cout << "-3 level: " << parametized2.getLevel() << std::endl;
    std::cout << "-1 vitality: " << parametized2.getVitality() << std::endl;
    std::cout << "-2 armor level: " << parametized2.getArmor() << std::endl;
    std::cout << "enemy: " << parametized2.isEnemy() << std::endl;
    std::cout << "school: " << parametized2.getSchool() << std::endl;
    std::cout << "weapon: " << parametized2.getCastingWeapon() << std::endl;
    std::cout << "can summon incarnate: " << parametized2.hasIncarnateSummon() << std::endl;
    //-------------------------------//
    
    
    std::cout << std::endl;
    std::cout<< "----------------------------------------" << std::endl;
    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "SCOUNDREL CLASS TEST" << std::endl;
    std::cout<< "----------------------------------------" << std::endl;
    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "scoundrel dagger test" << std::endl;
    Scoundrel scoundrel1;
    scoundrel1.setDagger("wood");
    std::cout << "setDagger wood test: " << scoundrel1.getDagger() << std::endl;
    scoundrel1.setDagger("BRONZE");
    std::cout << std::endl;
    std::cout << "setDagger BRONZE test: " << scoundrel1.getDagger() << std::endl;
    scoundrel1.setDagger("paper");
    std::cout << std::endl;
    std::cout << "setDagger invalid paper test: " << scoundrel1.getDagger() << std::endl;
    scoundrel1.setDagger("iron");
    std::cout << std::endl;
    std::cout << "setDagger iron test: " << scoundrel1.getDagger() << std::endl;
    scoundrel1.setDagger("steel");
    std::cout << std::endl;
    std::cout << "setDagger steel test: " << scoundrel1.getDagger() << std::endl;
    scoundrel1.setDagger("mithril");
    std::cout << std::endl;
    std::cout << "setDagger mithril test: " << scoundrel1.getDagger() << std::endl;
    scoundrel1.setDagger("adamant");
    std::cout << std::endl;
    std::cout << "setDagger adamant test: " << scoundrel1.getDagger() << std::endl;
    scoundrel1.setDagger("rune");
    std::cout << std::endl;
    std::cout << "setDagger rune test: " << scoundrel1.getDagger() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "scoundrel faction test" << std::endl;
    std::cout << "set faction cutpurse: " << std::boolalpha << scoundrel1.setFaction("cutpurse") << std::endl;
    std::cout << "get faction cutpurse: " << scoundrel1.getFaction() << std::endl;
    std::cout << std::endl;
    std::cout << "set faction NONE: " << std::boolalpha << scoundrel1.setFaction("NONE") << std::endl;
    std::cout << "get faction NONE: " << scoundrel1.getFaction() << std::endl;
    std::cout << std::endl;
    std::cout << "set faction shadowblade: " << std::boolalpha << scoundrel1.setFaction("shadowblade") << std::endl;
    std::cout << "get faction shadowblade: " << scoundrel1.getFaction() << std::endl;
    std::cout << std::endl;
    std::cout << "set faction silvertongue: " << std::boolalpha << scoundrel1.setFaction("silvertongue") << std::endl;
    std::cout << "get faction silvertongue: " << scoundrel1.getFaction() << std::endl;
    std::cout << std::endl;
    std::cout << "set faction invalid dauntless: " << std::boolalpha << scoundrel1.setFaction("dauntless") << std::endl;
    std::cout << "get faction dauntless: " << scoundrel1.getFaction() << std::endl;
    std::cout << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "scoundrel has disguise test" << std::endl;
    bool disguise = true;
    scoundrel1.setDisguise(disguise);
    std::cout << "true disguise test: " << std::boolalpha << scoundrel1.hasDisguise() << std::endl;
    bool disguisef = false;
    scoundrel1.setDisguise(disguisef);
    std::cout << "false disguise test: " << std::boolalpha << scoundrel1.hasDisguise() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "scoundrel default constructor test" << std::endl;
    Scoundrel defaultTest;
    std::cout << "name: " << defaultTest.getName() << std::endl;
    std::cout << "race: " << defaultTest.getRace() << std::endl;
    std::cout << "vitality: " << defaultTest.getVitality() << std::endl;
    std::cout << "armor: " << defaultTest.getArmor() << std::endl;
    std::cout << "level: " << defaultTest.getLevel() << std::endl;
    std::cout << "dagger: " << defaultTest.getDagger() << std::endl;
    std::cout << "faction: " << defaultTest.getFaction() << std::endl;
    std::cout << "has disguise: " << defaultTest.hasDisguise() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "scoundrel parametized constructor with arguments test" << std::endl;
    Scoundrel param1("Tamlin2", "LIZARD", 1, 1, 4, true, "bronze", "cutpurse", true);
    std::cout << "name Tamlin2: " << param1.getName() << std::endl;
    std::cout << "race lizard: " << param1.getRace() << std::endl;
    std::cout << "vitality 1: " << param1.getVitality() << std::endl;
    std::cout << "armor 1: " << param1.getArmor() << std::endl;
    std::cout << "level 4: " << param1.getLevel() << std::endl;
    std::cout << "enemy true: " << param1.isEnemy() << std::endl;
    std::cout << "dagger bronze: " << param1.getDagger() << std::endl;
    std::cout << "faction cutpurse: " << param1.getFaction() << std::endl;
    std::cout << "has disguise true: " << std::boolalpha << param1.hasDisguise() << std::endl; 

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "scoundrel parametized constructor with negative arguments & invalid input test" << std::endl;
    Scoundrel param2("Tamlin2", "LIZARD", -1, -1, -4, true, "stone", "dauntless", true);
    std::cout << "name Tamlin2: " << param2.getName() << std::endl;
    std::cout << "race lizard: " << param2.getRace() << std::endl;
    std::cout << "vitality -1: " << param2.getVitality() << std::endl;
    std::cout << "armor -1: " << param2.getArmor() << std::endl;
    std::cout << "level -4: " << param2.getLevel() << std::endl;
    std::cout << "enemy true: " << param2.isEnemy() << std::endl;
    std::cout << "dagger stone: " << param2.getDagger() << std::endl;
    std::cout << "faction dauntless: " << param2.getFaction() << std::endl;
    std::cout << "has disguise true: " << std::boolalpha << param2.hasDisguise() << std::endl; 

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "scoundrel parametized constructor with default arguments test" << std::endl;
    Scoundrel param3("Tamlin2", "LIZARD");
    std::cout << "name Tamlin2: " << param3.getName() << std::endl;
    std::cout << "race lizard: " << param3.getRace() << std::endl;
    std::cout << "vitality 0: " << param3.getVitality() << std::endl;
    std::cout << "armor 0: " << param3.getArmor() << std::endl;
    std::cout << "level 0: " << param3.getLevel() << std::endl;
    std::cout << "enemy false: " << param3.isEnemy() << std::endl;
    std::cout << "dagger wood: " << param3.getDagger() << std::endl;
    std::cout << "faction none: " << param3.getFaction() << std::endl;
    std::cout << "has disguise false: " << std::boolalpha << param3.hasDisguise() << std::endl; 
    

    std::cout<< "----------------------------------------" << std::endl;
    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "RANGER CLASS TEST" << std::endl;
    Ranger defaultRanger;
    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "ranger default constructor test" << std::endl;
    std::cout << "name: " << defaultRanger.getName() << std::endl;
    std::cout << "race: " << defaultRanger.getRace() << std::endl;
    std::cout << "vitality: " << defaultRanger.getVitality() << std::endl;
    std::cout << "armor: " << defaultRanger.getArmor() << std::endl;
    std::cout << "level: " << defaultRanger.getLevel() << std::endl;
    std::cout << "enemy: " << std::boolalpha << defaultRanger.isEnemy() << std::endl;
    std::vector<Arrows> default_arrows = defaultRanger.getArrows();
    std::cout << "arrows empty: " << std::boolalpha << default_arrows.empty() << std::endl;
    std::vector<std::string> default_affinities = defaultRanger.getAffinities();
    std::cout << "affinities empty: " << std::boolalpha << default_affinities.empty() << std::endl;
    std::cout << "companion: " << std::boolalpha << defaultRanger.getCompanion() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "Arrows vector setup" << std::endl;
    std::vector<Arrows> arrows;
    Arrows wood;
    wood.type_ = "wood";
    wood.quantity_ = 5;
    arrows.push_back(wood);
    Arrows invalid;
    invalid.type_ = "stone";
    invalid.quantity_ = 3;
    arrows.push_back(invalid);
    Arrows invalid_num;
    invalid_num.type_ = "FIRE";
    invalid_num.quantity_ = -2;
    arrows.push_back(invalid_num);
    Arrows fire;
    fire.type_ = "FIRE";
    fire.quantity_ = 2;
    arrows.push_back(fire);
    Arrows water;
    water.type_ = "water";
    water.quantity_ = 10;
    arrows.push_back(water);
    Arrows poison;
    poison.type_ = "poison";
    poison.quantity_ = 3;
    arrows.push_back(poison);
    Arrows blood;
    blood.type_ = "blood";
    blood.quantity_ = 6;
    arrows.push_back(blood);
    Arrows fire2;
    fire2.type_ = "FIRE";
    fire2.quantity_ = 4;
    arrows.push_back(fire2);

    for(int i = 0; i < arrows.size(); i++){
      std::cout << "type: " << arrows[i].type_ << " quantity: " << arrows[i].quantity_ << std::endl;
    }

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "affinities vector setup" << std::endl;
  
    std::vector<std::string> affinities{"FIRE", "water","poison", "BLOOD", "invalid", "poison"};
    std::cout << "affinity vector added to parametized constructor:\n";
    std::cout << "FIRE, water, poison, BLOOD, invalid, poison: \n";

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "ranger Parametized constructor with all arguments test" << std::endl;
    Ranger paramRanger1("Azriel", "ELF", 1, 2, 3, true, arrows, affinities,true);
    std::cout << "name: " << paramRanger1.getName() << std::endl;
    std::cout << "race: " << paramRanger1.getRace() << std::endl;
    std::cout << "vitality: " << paramRanger1.getVitality() << std::endl;
    std::cout << "armor: " << paramRanger1.getArmor() << std::endl;
    std::cout << "level: " << paramRanger1.getLevel() << std::endl;
    std::cout << "enemy: " << paramRanger1.isEnemy() << std::endl;
    std::cout << "arrows: " <<std::endl;

    std::vector<Arrows> rangerparam1 = paramRanger1.getArrows();
    for(int i = 0; i < rangerparam1.size(); i++){
      std::cout << "arrow type: " << rangerparam1[i].type_ << "| quantity: " << rangerparam1[i].quantity_ << std::endl;
    }
    std::cout << "affinities: " <<std::endl;
    std::vector<std::string> param1_affinities = paramRanger1.getAffinities();
    for(int q = 0; q < param1_affinities.size(); q++){
      std::cout << "affinity type: " << param1_affinities[q] << std::endl;
    }

    std::cout << "has companion: " << paramRanger1.getCompanion() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "ranger Parametized constructor with default arguments test" << std::endl;
    Ranger paramRanger2("Azriel", "ELF");
    std::cout << "name: " << paramRanger2.getName() << std::endl;
    std::cout << "race: " << paramRanger2.getRace() << std::endl;
    std::cout << "vitality: " << paramRanger2.getVitality() << std::endl;
    std::cout << "armor: " << paramRanger2.getArmor() << std::endl;
    std::cout << "level: " << paramRanger2.getLevel() << std::endl;
    std::cout << "enemy: " << paramRanger2.isEnemy() << std::endl;
    
    std::vector<Arrows> rangerparam2 = paramRanger2.getArrows();
    std::cout << "arrows empty: " << std::boolalpha << rangerparam2.empty() << std::endl;
    std::vector<std::string> param2_affinities = paramRanger2.getAffinities();
    std::cout << "affinities empty: " <<std::boolalpha << param2_affinities.empty()<<std::endl;
    std::cout << "has companion: " << paramRanger2.getCompanion() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "ranger Parametized constructor with negative arguments test" << std::endl;
    Ranger paramRanger3("Azriel", "ELF", -1, -2, -3, true, arrows, affinities,true);
    std::cout << "name: " << paramRanger3.getName() << std::endl;
    std::cout << "race: " << paramRanger3.getRace() << std::endl;
    std::cout << "vitality: " << paramRanger3.getVitality() << std::endl;
    std::cout << "armor: " << paramRanger3.getArmor() << std::endl;
    std::cout << "level: " << paramRanger3.getLevel() << std::endl;
    std::cout << "enemy: " << paramRanger3.isEnemy() << std::endl;
    std::cout << "arrows: " <<std::endl;
    std::vector<Arrows> rangerparam3 = paramRanger3.getArrows();
    for(int i = 0; i < rangerparam3.size(); i++){
      std::cout << "arrow type: " << rangerparam3[i].type_ << "| quantity: " << rangerparam3[i].quantity_ << std::endl;
    }
    std::cout << "affinities: " <<std::endl;
    std::vector<std::string> param3_affinities = paramRanger3.getAffinities();
    for(int q = 0; q < param3_affinities.size(); q++){
      std::cout << "affinity type: " << param3_affinities[q] << std::endl;
    }

    std::cout << "has companion: " << paramRanger3.getCompanion() << std::endl;

    std::cout<< "----------------------------------------" << std::endl;
    std::vector<Arrows> arrows2;
    arrows2.push_back(wood);
    arrows2.push_back(fire);
    arrows2.push_back(water);
    arrows2.push_back(poison);
    std::vector<std::string> affinities2{"FIRE", "water", "BLOOD", "invalid"};
    Ranger ranger3("Feyre", "elf", 1, 2, 3, false, arrows2, affinities2, true);
    std::cout << "ranger add arrows test" << std::endl;
    std::cout << "arrows before addArrows: " << std::endl;
    std::vector <Arrows> Feyres = ranger3.getArrows();
    for(int i = 0; i < Feyres.size(); i++){
      std::cout << "arrow type: " << Feyres[i].type_ << "| quantity: " << Feyres[i].quantity_ << std::endl;
    }
    std::cout << std::endl;
    //arrows.push_back(blood);
    std::cout << "add Arrows invalid stone test: " << std::boolalpha << ranger3.addArrows("stone", 3) << std::endl;
    std::cout << "add Arrows invalid -3 test: " << std::boolalpha << ranger3.addArrows("fire", -3) << std::endl;
    std::cout << "add Arrows blood, 3: " << std::boolalpha << ranger3.addArrows("blood", 3) << std::endl;
    std::cout << "add Arrows poison, 5: " << std::boolalpha << ranger3.addArrows("POISOn", 5) << std::endl;
    std::cout << "add Arrows invalid poison, 0: " << std::boolalpha << ranger3.addArrows("POISOn", 0) << std::endl;

    std::vector <Arrows> Feyres2 = ranger3.getArrows();
    std::cout << std::endl;
    std::cout << "arrows after addArrows (added 5 to poison, add blood,3): " << std::endl;
    for(int i = 0; i < Feyres2.size(); i++){
      std::cout << "arrow type: " << Feyres2[i].type_ << "| quantity: " << Feyres2[i].quantity_ << std::endl;
    }

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "ranger fire arrows test" << std::endl;
    std::cout << "invalid stone test: " << std::boolalpha << ranger3.fireArrow("stone") << std::endl;
    std::cout << "wood test: " << std::boolalpha << ranger3.fireArrow("wood") << std::endl;
    std::cout << "fire test: " << std::boolalpha << ranger3.fireArrow("fire") << std::endl;
    std::cout << "fire test: " << std::boolalpha << ranger3.fireArrow("fire") << std::endl;
    std::cout << "fire now invalid test: " << std::boolalpha << ranger3.fireArrow("fire") << std::endl;
    std::cout << "water test: " << std::boolalpha << ranger3.fireArrow("water") << std::endl;
    std::cout << "poison test: " << std::boolalpha << ranger3.fireArrow("poison") << std::endl;
    std::cout << "Blood test: " << std::boolalpha << ranger3.fireArrow("Blood") << std::endl;
    std::vector <Arrows> Feyres3 = ranger3.getArrows();
    std::cout << std::endl;
    std::cout << "arrows after fire arrows (1 wood, 2 fire,1 water, 1 poison, 1 blood): " << std::endl;
    for(int i = 0; i < Feyres3.size(); i++){
      std::cout << "arrow type: " << Feyres3[i].type_ << "| quantity: " << Feyres3[i].quantity_ << std::endl;
    }
    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "ranger add Affinities test" << std::endl;
    std::cout << "before add affinities: " << std::endl;
    std::vector<std::string> Feyre4 = ranger3.getAffinities();
    for(int i = 0; i < Feyre4.size(); i++){
      std::cout << Feyre4[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "invalid shadow: " << ranger3.addAffinity("shadow") << std::endl;
    std::cout << "invalid fire: " << ranger3.addAffinity("fire") << std::endl;
    std::cout << "posioN : " << ranger3.addAffinity("poisoN") << std::endl;
    std::cout << "invalid poison: " << ranger3.addAffinity("poison") <<std::endl;
    std::cout << "invalid WATER: " << ranger3.addAffinity("WATER") << std::endl;
     std::cout << "invalid blood: " << ranger3.addAffinity("blood") << std::endl;

    std::cout << std::endl;
    std::cout << "after add affinities: " << std::endl;
    std::vector<std::string> Feyre5 = ranger3.getAffinities();
    for(int i = 0; i < Feyre5.size(); i++){
      std::cout << Feyre5[i] << std::endl;
    }

    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "ranger set companion test" << std::endl;
    std::cout << "before set companion: " << ranger3.getCompanion() << std::endl;
    ranger3.setCompanion(false);
    std::cout << "after ser companion: " << ranger3.getCompanion() << std::endl;

  
    std::cout<< "----------------------------------------" << std::endl;
    std::cout<< "----------------------------------------" << std::endl;
    std::cout << "BARBARIAN CLASS TEST" << std::endl;
    std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian default constructor test" << std::endl;
  Barbarian barb1;
  std::cout << "name: " << barb1.getName() << std::endl;
  std::cout << "race: " << barb1.getRace() << std::endl;
  std::cout << "vitality: " << barb1.getVitality() << std::endl;
  std::cout << "armor: " << barb1.getArmor() << std::endl;
  std::cout << "level: " << barb1.getLevel() << std::endl;
  std::cout << "enemy: " << std::boolalpha << barb1.isEnemy() << std::endl;
  std::cout << "main weapon: " << barb1.getMainWeapon() << std::endl;
  std:: cout << "secondary weapon: " << barb1.getSecondaryWeapon() << std::endl;
  std::cout << "enrage: " << std::boolalpha << barb1.getEnrage() << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian parametized constructor with all arguments test" << std::endl;
  Barbarian barb2("Ianthe", "LIZARD", 1, 2, 3, true, "staff", "sword", true);
  std::cout << "name: " << barb2.getName() << std::endl;
  std::cout << "race: " << barb2.getRace() << std::endl;
  std::cout << "vitality: " << barb2.getVitality() << std::endl;
  std::cout << "armor: " << barb2.getArmor() << std::endl;
  std::cout << "level: " << barb2.getLevel() << std::endl;
  std::cout << "enemy: " << std::boolalpha << barb2.isEnemy() << std::endl;
  std::cout << "main weapon: " << barb2.getMainWeapon() << std::endl;
  std:: cout << "secondary weapon: " << barb2.getSecondaryWeapon() << std::endl;
  std::cout << "enrage: " << std::boolalpha << barb2.getEnrage() << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian parametized constructor with default arguments test" << std::endl;
  Barbarian barb3("Ianthe", "LIZARD");
  std::cout << "name: " << barb3.getName() << std::endl;
  std::cout << "race: " << barb3.getRace() << std::endl;
  std::cout << "vitality: " << barb3.getVitality() << std::endl;
  std::cout << "armor: " << barb3.getArmor() << std::endl;
  std::cout << "level: " << barb3.getLevel() << std::endl;
  std::cout << "enemy: " << std::boolalpha << barb3.isEnemy() << std::endl;
  std::cout << "main weapon: " << barb3.getMainWeapon() << std::endl;
  std:: cout << "secondary weapon: " << barb3.getSecondaryWeapon() << std::endl;
  std::cout << "enrage: " << std::boolalpha << barb3.getEnrage() << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian parametized constructor with negative and invalid arguments test" << std::endl;
  Barbarian barb4("Ianthe", "LIZARD", -1, -2, -3, true, "staff3", "swo4rd", true);
  std::cout << "name: " << barb4.getName() << std::endl;
  std::cout << "race: " << barb4.getRace() << std::endl;
  std::cout << "vitality: " << barb4.getVitality() << std::endl;
  std::cout << "armor: " << barb4.getArmor() << std::endl;
  std::cout << "level: " << barb4.getLevel() << std::endl;
  std::cout << "enemy: " << std::boolalpha << barb4.isEnemy() << std::endl;
  std::cout << "main weapon: " << barb4.getMainWeapon() << std::endl;
  std:: cout << "secondary weapon: " << barb4.getSecondaryWeapon() << std::endl;
  std::cout << "enrage: " << std::boolalpha << barb4.getEnrage() << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian set Main weapon test" << std::endl;
  Barbarian barb5;
  std::cout << "lightning valide test: " << barb5.setMainWeapon("lightning") << " " << barb5.getMainWeapon() << std::endl;
  std::cout << "f1re3 invalide test: " << barb5.setMainWeapon("f1re3") << " " << barb5.getMainWeapon() << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian set second weapon test" << std::endl;
  std::cout << "wind valide test: " << barb5.setSecondaryWeapon("wind") << " " << barb5.getSecondaryWeapon() << std::endl;
  std::cout << "f1re3 invalide test: " << barb5.setSecondaryWeapon("f1re3") << " " << barb5.getSecondaryWeapon() << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian set enraged test" << std::endl;
  std::cout << "before set enraged: " << barb5.getEnrage() << std::endl;
  barb5.setEnrage(true);
  std::cout << "after set enrage " << barb5.getEnrage() << std::endl;

  std::cout<< "----------------------------------------" << std::endl;
  std::cout << "barabrian toogle enraged test" << std::endl;
  std::cout << "before toggle enraged: " << barb5.getEnrage() << std::endl;
  barb5.toggleEnrage();
  std::cout << "after toggle  enrage " << barb5.getEnrage() << std::endl;
  barb5.toggleEnrage();
  std::cout << "after toggle  enrage again: " << barb5.getEnrage() << std::endl;
  
  int x = 5;
  double y = x;
  

}