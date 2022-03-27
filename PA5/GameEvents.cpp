#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include<random>
#include<time.h>

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

void RollForWeapon(Character &PC, map<string, Weapon> Weapon_table, bool loot_bypass){
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
            found_weapon = GetWeaponByQuality(2, Weapon_table);
            cout << "You found " << found_weapon.GetName() << "!" << endl;
            PC.AddWeaponToInv(found_weapon);
        }
        else if (roll <= 20){
            found_weapon = GetWeaponByQuality(3, Weapon_table);
            cout << "You found " << found_weapon.GetName() << "!" << endl;
            PC.AddWeaponToInv(found_weapon);
        }
        else if (roll > 20){
            found_weapon = GetWeaponByQuality(4, Weapon_table);
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


void RollForArmor(Character &PC, map<string, Armor> Armor_table, bool loot_bypass){
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
            found_armor = GetArmorByQuality(2, Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(GetArmorByQuality(2, Armor_table));
        }
        else if (roll <= 20) {
            found_armor = GetArmorByQuality(3, Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(GetArmorByQuality(3, Armor_table));
        }
        else if (roll > 20) {
            found_armor = GetArmorByQuality(4, Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(GetArmorByQuality(4, Armor_table));
        }
    }
    else {
        if (loot_bypass) {
            found_armor = GetArmorByQuality(1, Armor_table);
            cout << "You found " << found_armor.GetName() << "!" << endl;
            PC.AddArmorToInv(GetArmorByQuality(1, Armor_table));
        }
        else {
            cout << "sadly you lack the intelligence to find anything.";
        }
    }
    cin.ignore();
}


void RollForConsumable(Character &PC, map<string, Consumable> Consumable_Table, bool loot_bypass){
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
            found_consum = GetConsumableByQuality(2, Consumable_Table);
            cout << "You found " << found_consum.GetName() << "!" << endl;
            PC.AddConsumableToInv(found_consum);
        }
        else if (roll <= 20) {
            found_consum = GetConsumableByQuality(3, Consumable_Table);
            cout << "You found " << found_consum.GetName() << "!" << endl;
            PC.AddConsumableToInv(found_consum);
        }
        else if (roll > 20) {
            found_consum = GetConsumableByQuality(4, Consumable_Table);
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

void Dialog(Character& PC, string text, map<string, Image> UIS, map<string, Weapon> Weapon_table, map<string, Armor> Armor_table, map<string, Consumable> Consumable_table, bool loot_bypass) { // Take in Weapon table
    clear();
    istringstream iss (text);

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
                RollForWeapon(PC, Weapon_table, loot_bypass);     
            }  
            // + ARMOR 
            else if( line == "+ ARMOR"){
                cout << "Calling + ARMOR" << endl;
                cin.ignore();
                RollForArmor(PC, Armor_table, loot_bypass);
            }

            // + CONSUMABLE
            else if (line == "+ CONSUMABLE"){
                cout << "Calling + CONSUMABLE" << endl;
                cin.ignore();
                RollForConsumable(PC, Consumable_table, loot_bypass);
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
}
