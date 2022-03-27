#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include<random>
#include<time.h>
#include<algorithm>

#include "GameEvents.h"
#include "Image.h"
#include "Character.h"
#include "Clear.h"

using namespace std;

//Check if string is number
bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Consumable GetConsumableByQuality(int quality, map<string, Consumable> Table) {
    int count = 0;
    vector<Consumable> qualityTable;
    srand(time(NULL));

    for (auto& entry : Table) {
        if (entry.second.GetQuality() == quality) {
            qualityTable.push_back(entry.second);
            count++;
        }
    }

    return qualityTable[rand() % count];
}

Armor GetArmorByQuality(int quality, map<string, Armor> Table) {
    int count = 0;
    vector<Armor> qualityTable;
    srand(time(NULL));

    for (auto& entry : Table) {
        if (entry.second.GetQuality() == quality) {
            qualityTable.push_back(entry.second);
            count++;
        }
    }

    return qualityTable[rand() % count];
}

Weapon GetWeaponByQuality(int quality, map<string, Weapon> Table) {
    int count = 0;
    vector<Weapon> qualityTable;
    srand(time(NULL));

    for (auto& entry : Table) {
        if (entry.second.GetQuality() == quality) {
            qualityTable.push_back(entry.second);
            count++;
        }
    }

    return qualityTable[rand() % count];
}

void RollForWeapon(Character &PC, map<string, Weapon> Weapon_table, int quality_cap, bool loot_bypass){
    // roll
    int roll = PC.Roll(1, 20) + PC.GetBonus(PC.GetInt());

    // weapon depending on roll

    cout << "Your investigation (int) roll is: " << roll << endl;
    Weapon found_weapon;
    if (roll > 9) {
        cout << "You found something!" << endl;
        if (roll <= 13){
            found_weapon = GetWeaponByQuality(1, Weapon_table);
            cout << "You found " << found_weapon.GetName() << "!" << endl;
            PC.AddWeaponToInv(found_weapon);
        }
        else if (roll <= 17){
            found_weapon = GetWeaponByQuality(max(2, quality_cap), Weapon_table);
            cout << "You found " << found_weapon.GetName() << "!" << endl;
            PC.AddWeaponToInv(found_weapon);
        }
        else if (roll <= 20){
            found_weapon = GetWeaponByQuality(max(3, quality_cap), Weapon_table);
            cout << "You found " << found_weapon.GetName() << "!" << endl;
            PC.AddWeaponToInv(found_weapon);
        }
        else if (roll > 20){
            found_weapon = GetWeaponByQuality(max(4, quality_cap), Weapon_table);
            cout << "You found " << found_weapon.GetName() << "!" << endl;
            PC.AddWeaponToInv(found_weapon);
        }
    }
    else{
        if (loot_bypass) {
            found_weapon = GetWeaponByQuality(1, Weapon_table);
            cout << "You found " << found_weapon.GetName() << "!" << endl;
            PC.AddWeaponToInv(found_weapon);
        }
        else {
            cout << "Sadly you lack the intelligence to find anything.";
        }
    }  
}


void RollForArmor(Character &PC, map<string, Armor> Armor_table, int quality_cap, bool loot_bypass){
    // roll
    int roll = PC.Roll(1, 20) + PC.GetBonus(PC.GetInt());

    // weapon depending on roll

    cout << "Your investigation (int) roll is: " << roll << endl;
    Armor found_armor;
    if (roll > 9) {
        cout << "You found something!" << endl;
        if (roll <= 13) {
            found_armor = GetArmorByQuality(1, Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(found_armor);
        }
        else if (roll <= 17) {
            found_armor = GetArmorByQuality(max(2, quality_cap), Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(found_armor);
        }
        else if (roll <= 20) {
            found_armor = GetArmorByQuality(max(3, quality_cap), Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(found_armor);
        }
        else if (roll > 20) {
            found_armor = GetArmorByQuality(max(4, quality_cap), Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(found_armor);
        }
    }
    else {
        if (loot_bypass) {
            found_armor = GetArmorByQuality(1, Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(found_armor);
        }
        else {
            cout << "sadly you lack the intelligence to find anything.";
        }
    }
    cin.ignore();
}


void RollForConsumable(Character &PC, map<string, Consumable> Consumable_Table, int quality_cap, bool loot_bypass){
    // roll
    int roll = PC.Roll(1, 20) + PC.GetBonus(PC.GetInt());

    // weapon depending on roll

    cout << "Your investigation (int) roll is: " << roll << endl;
    Consumable found_consum;
    if (roll > 9) {
        cout << "You found something!" << endl;
        if (roll <= 13) {
            found_consum = GetConsumableByQuality(1, Consumable_Table);
            cout << "You found " << found_consum.GetName() << "!" << endl;
            PC.AddConsumableToInv(found_consum);
        }
        else if (roll <= 17) {
            found_consum = GetConsumableByQuality(max(2, quality_cap), Consumable_Table);
            cout << "You found " << found_consum.GetName() << "!" << endl;
            PC.AddConsumableToInv(found_consum);
        }
        else if (roll <= 20) {
            found_consum = GetConsumableByQuality(max(3, quality_cap), Consumable_Table);
            cout << "You found " << found_consum.GetName() << "!" << endl;
            PC.AddConsumableToInv(found_consum);
        }
        else if (roll > 20) {
            found_consum = GetConsumableByQuality(max(4, quality_cap), Consumable_Table);
            cout << "You found " << found_consum.GetName() << "!" << endl;
            PC.AddConsumableToInv(found_consum);
        }
    }
    else {
        if (loot_bypass) {
            found_consum = GetConsumableByQuality(1, Consumable_Table);
            cout << "You found " << found_consum.GetName() << "!" << endl;
            PC.AddConsumableToInv(found_consum);
        }
        else {
            cout << "sadly you lack the intelligence to find anything.";
        }
    }
    cin.ignore();
}

int RollSkill(Character &PC, string skill, string stat, int dc) {
    int roll = PC.Roll(1, 20);
    int bonus = 0;

    if (stat == "STR") {
        bonus = PC.GetBonus(PC.GetStr());
    }
    else if (stat == "DEX") {
        bonus = PC.GetBonus(PC.GetDex());
    }
    else if (stat == "CON") {
        bonus = PC.GetBonus(PC.GetCon());
    }
    else if (stat == "INT") {
        bonus = PC.GetBonus(PC.GetInt());
    }
    else if (stat == "WIS") {
        bonus = PC.GetBonus(PC.GetWis());
    }
    else if (stat == "CHA") {
        bonus = PC.GetBonus(PC.GetCha());
    }

    roll = roll + bonus;
    cout << PC.GetName() << " rolled: " << roll << " against a DC of " << dc << endl;

    if (roll >= dc) {
        cout << "You succeed the " << skill << " check!" << endl;
        cin.ignore();
        return 1;
    }
    else {
        cout << "You fail the " << skill << " check!" << endl;
        cin.ignore();
        return 0;
    }
}


void GetHealing(Character &PC, map<string, Consumable> Consumable_Table) {

}


void GetCustomItem(Character &PC, int){

}


void GetMiscItem(){

}


void ChangeStat(Character &PC, char effect, string stat) {
    if ( effect == '+'){
        if (stat == "STR"){
            PC.StatChange('+', "Str"); 
            cout << "You gained 1 Strength!" << endl;
            cout << "Current Strength is " << PC.GetStr() << endl;

        } else if (stat == "DEX") {
            PC.StatChange('+', "Dex"); 
            cout << "You gained 1 Dexterity!" << endl;
            cout << "Current Dexterity is " << PC.GetDex() << endl;
            

        } else if (stat == "CON") {
            PC.StatChange('+', "Con"); 
            cout << "You gained 1 Constitution!" << endl;
            cout << "Current Constitution is " << PC.GetCon() << endl;
            
        } else if (stat == "INT") {
            PC.StatChange('+', "Int"); 
            cout << "You gained 1 Intelligence!" << endl;
            cout << "Current Intelligence is " << PC.GetInt() << endl;
            
        } else if (stat == "WIS") {
            PC.StatChange('+', "Wis"); 
            cout << "You gained 1 Wisdom!" << endl;
            cout << "Current Wisdom is " << PC.GetWis() << endl;
            
        } else if (stat == "CHA") {
            PC.StatChange('+', "Cha"); 
            cout << "You gained 1 Charisma!" << endl;
            cout << "Current Charisma is " << PC.GetCha() << endl; 
        }
    }

    else if (effect == '-'){   
        if (stat == "STR"){
            PC.StatChange('-', "Str"); 
            cout << "You lost 1 Strength!" << endl;
            cout << "Current Strength is " << PC.GetStr() << endl;

        } else if (stat == "DEX") {
            PC.StatChange('-', "Dex"); 
            cout << "You lost 1 Dexterity!" << endl;
            cout << "Current Dexterity is " << PC.GetDex() << endl;

        } else if (stat == "CON") {
            PC.StatChange('-', "Con"); 
            cout << "You lost 1 Constitution!" << endl;
            cout << "Current Constitution is " << PC.GetCon() << endl;
            
        } else if (stat == "INT") {
            PC.StatChange('-', "Int"); 
            cout << "You lost 1 Intelligence!" << endl;
            cout << "Current Intelligence is " << PC.GetInt() << endl;
            
        } else if (stat == "WIS") {
            PC.StatChange('-', "Wis"); 
            cout << "You lost 1 Wisdom!" << endl;
            cout << "Current Wisdom is " << PC.GetWis() << endl;
            
        } else if (stat == "CHA") {
            PC.StatChange('-', "Cha"); 
            cout << "You lost 1 Charisma!" << endl;
            cout << "Current Charisma is " << PC.GetCha() << endl;
        }
    }
}

int Dialog(Character& PC, string text, map<string, Image> UIS, map<string, Weapon> Weapon_table, map<string, Armor> Armor_table, map<string, Consumable> Consumable_table, int quality_cap, bool loot_bypass) { // Take in Weapon table
    clear();
    istringstream iss (text);
    bool outcome = true;

    string line;
    cout << UIS.find("Border.txt")->second.GetImage() << endl;
    while (getline(iss, line, '\n')) {
        if (line.empty()) {
            cout << endl;
            cout << UIS.find("Border.txt")->second.GetImage() << endl; 
            cout << "Hit Enter to continue.";
            cin.ignore();
            clear();
            cout << UIS.find("Border.txt")->second.GetImage() << endl;
        }
        else if (line[0] == '+'){ 
            if (line == "+ WEAPON"){
                //call Weeapo funciton
                RollForWeapon(PC, Weapon_table, quality_cap, loot_bypass);
            }  
            // + ARMOR 
            else if( line == "+ ARMOR"){
                cout << "Calling + ARMOR" << endl;
                cin.ignore();
                RollForArmor(PC, Armor_table, quality_cap, loot_bypass);
            }

            // + CONSUMABLE
            else if (line == "+ CONSUMABLE"){
                cout << "Calling + CONSUMABLE" << endl;
                cin.ignore();
                RollForConsumable(PC, Consumable_table, quality_cap, loot_bypass);
            }

            // + CHECK SKILL STAT DC
            else if (line.substr(0, 7) == "+ CHECK") {
                string space_delimiter = " ";
                vector<string> words{};

                size_t pos = 0;
                while ((pos = line.find(space_delimiter)) != string::npos) {
                    words.push_back(line.substr(0, pos));
                    line.erase(0, pos + space_delimiter.length());
                }

                outcome = RollSkill(PC, words[2], words[3], stoi(line));
            }

            else if (line.substr(0, 8) == "+ CHOICE") {
                string userInput;
                string space_delimiter = " ";
                vector<string> words{};

                size_t pos = 0;
                while ((pos = line.find(space_delimiter)) != string::npos) {
                    words.push_back(line.substr(0, pos));
                    line.erase(0, pos + space_delimiter.length());
                }

                int choiceCount = stoi(line);
                text.erase(0, 12);
                cout << text << endl;
                cout << UIS.find("Border.txt")->second.GetImage() << endl;

                while (true) {
                    cin >> userInput;

                    for (int i = 1; i <= choiceCount; i++) {
                        if (strcmp(userInput.c_str(), to_string(i).c_str()) == 0) {
                            return i;
                        }
                    }
                }
            }

            // + CUSTOM int

            // else if (line.substr(0, 8) == "+ CUSTOM"){
            //     int number = atoi(line.substr (9, 1).c_str());
            //     GetCustomItem(PC, number);
            // }

            // + MISC
            // Leaving this empty for now
        } else {
            cout << line << endl;
        }
    }

    return outcome;
}
