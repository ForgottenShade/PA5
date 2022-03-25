#include <string>
#include <map>
#include <iostream>
#include <sstream>

#include "GameEvents.h"
#include "Image.h"
#include "Character.h"
#include "Clear.h"

using namespace std;

void rollForWeapon(Character &PC, map<string, Weapon> Weapon_table){ 
    // // roll
    // int roll = PC.roll();

    // // weapon depending on roll
    
    //     cout << "Your roll is: " << roll << endl;
    //     if (roll > 9) {
    //         cout << "You found something!" << endl;
    //         if (roll <= 13){
    //             if (abilityMod == "Str"){
    //                 // Club, right?
    //                 cout << "Adding Club to Intventory" << endl;
    //                 cout << "Current Items in Inventory" << PC.GetWeaponInv().size() << endl;
    //                 Weapon Club = Weapon("Club", 10, 1, 6, 1, false);
    //                 PC.AddWeaponToInv(Club);
    //                 cout << "Current Items in Inventory" << PC.GetWeaponInv().size() << endl;
    //             } else if (abilityMod == "Dex") {
    //                 // Something else..
    //             }
    //         }
    //         else if (roll <= 17){

    //         }
    //         else if (roll <= 20){

    //         }
    //         else if (roll > 20){
            
    //         }
    //     }
    //     else{
    //         cout << "Sadly you lack the intelligence to find anything.";
    //     }
    //     cin.ignore();  
}


void rollForArmor(Character &PC, map<string, Armor> Armor_table){

}


void rollForConsumable(Character &PC, map<string, Consumable> Consumable_Table){


}


void getHealing(Character &PC, map<string, Consumable> Consumable_Table) {

}


void getCustomItem(Character &PC, int){

}


void getMiscItem(){

}


void changeStat(Character &PC, char effect, string stat) {
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


void dialog(Character& PC, string text, map<string, Image> UIS, map<string, Weapon> Weapon_table, map<string, Armor> Armor_table, map<string, Consumable> Consumable_table) { // Take in Weapon table
    clear();
    istringstream iss (text);

    string line;
    cout << UIS.find("Border.txt")->second.GetImage();
    while (getline(iss, line, '\n')) {
        if (line.empty()) {
            cout << UIS.find("Border.txt")->second.GetImage();
            cout << "Hit Enter to continue.";
            cin.ignore();
            clear();
            cout << UIS.find("Border.txt")->second.GetImage();
        }
        else if (line[0] == '+'){ 
            if (line == "+ WEAPON"){
                //call Weeapon funciton
                rollForWeapon(PC, Weapon_table);     
            }  
            // + ARMOR 
            else if( line == "+ ARMOR"){
                rollForArmor(PC, Armor_table);
            }

            // + CONSUMABLE
            else if (line == "+ CONSUMABLE"){
                rollForConsumable(PC, Consumable_table);
            }

            // + Healing
            else if( line == "+ HEALING"){
                getHealing(PC, Consumable_table);
            }

            // + CUSTOM int

            else if (line.substr(0, 8) == "+ CUSTOM"){
                int number = atoi(line.substr (9, 1).c_str());
                getCustomItem(PC, number);
            }

            // + MISC
            // Leaving this empty for now
        } else {
            cout << line << endl;
        }      
    }
}
