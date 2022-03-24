#include <string>
#include <map>
#include <iostream>
#include <sstream>

#include "Dialog.h"
#include "Image.h"
#include "Character.h"
#include "Clear.h"

using namespace std;

void rollForWeapon(Character &PC){ // Weapons table
    // roll

    // weapon depending on roll
}

void dialog(Character &PC, string text, map<string, Image> UIS) { // Take in Weapon table
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
            }  
            // + ARMOR 

            // + HEaling

            // + Custom int

            // + MISC



            // if (line == "+ WEAPON") {
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
            // }
            if (line == "+ STR"){
                PC.StatChange('+', "Str"); 
                cout << "You gained 1 Strength!" << endl;
                cout << "Current Strength is " << PC.GetStr() << endl;

            } else if (line == "+ DEX") {
                PC.StatChange('+', "Dex"); 
                cout << "You gained 1 Dexterity!" << endl;
                cout << "Current Dexterity is " << PC.GetDex() << endl;
                

            } else if (line == "+ CON") {
                PC.StatChange('+', "Con"); 
                cout << "You gained 1 Constitution!" << endl;
                cout << "Current Constitution is " << PC.GetCon() << endl;
                
            } else if (line == "+ INT") {
                PC.StatChange('+', "Int"); 
                cout << "You gained 1 Intelligence!" << endl;
                cout << "Current Intelligence is " << PC.GetInt() << endl;
                
            } else if (line == "+ WIS") {
                PC.StatChange('+', "Wis"); 
                cout << "You gained 1 Wisdom!" << endl;
                cout << "Current Wisdom is " << PC.GetWis() << endl;
                
            } else if (line == "+ CHA") {
                PC.StatChange('+', "Cha"); 
                cout << "You gained 1 Charisma!" << endl;
                cout << "Current Charisma is " << PC.GetCha() << endl;
                
            }
        }
        else if (line[0] == '-'){   
            if (line == "- STR"){
                PC.StatChange('-', "Str"); 
                cout << "You lost 1 Strength!" << endl;
                cout << "Current Strength is " << PC.GetStr() << endl;

            } else if (line == "- DEX") {
                PC.StatChange('-', "Dex"); 
                cout << "You lost 1 Dexterity!" << endl;
                cout << "Current Dexterity is " << PC.GetDex() << endl;

            } else if (line == "- CON") {
                PC.StatChange('-', "Con"); 
                cout << "You lost 1 Constitution!" << endl;
                cout << "Current Constitution is " << PC.GetCon() << endl;
                
            } else if (line == "- INT") {
                PC.StatChange('-', "Int"); 
                cout << "You lost 1 Intelligence!" << endl;
                cout << "Current Intelligence is " << PC.GetInt() << endl;
                
            } else if (line == "- WIS") {
                PC.StatChange('-', "Wis"); 
                cout << "You lost 1 Wisdom!" << endl;
                cout << "Current Wisdom is " << PC.GetWis() << endl;
                
            } else if (line == "- CHA") {
                PC.StatChange('-', "Cha"); 
                cout << "You lost 1 Charisma!" << endl;
                cout << "Current Charisma is " << PC.GetCha() << endl;
            }
        } else {
            cout << line << endl;
        }      
    }
}
