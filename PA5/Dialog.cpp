#include <string>
#include <map>
#include <iostream>
#include <sstream>

#include "Dialog.h"
#include "Image.h"
#include "Character.h"
#include "Clear.h"

using namespace std;

void dialog(Character PC, string text, map<string, Image> UIS) {
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
