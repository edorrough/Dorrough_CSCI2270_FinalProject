#include <iostream>
#include "CharacterAssistant.h"
/*
Evan Dorrough
CSCI 2270
TA: Guohui Ding
*/
using namespace std;
/*
My driver file is a little wordy and messy
This is due to the pre-set rules of D&D that needed to be adapted into the program
This program asks for your input a LOT, take care when entering values
*/
int main()
{
    CharacterAssistant ca=CharacterAssistant();//creating an instance of my class
    string userInput;
    while(userInput!="quit")//menu
    {
        cout<<"Select a choice, type 'quit' to quit!"<<endl;
        cout<<"('new' character, 'delete' character, 'print' characters, 'select' character)"<<endl;//things inside of quotations are the desired inputs
        getline(cin, userInput);
        if(userInput=="new")//this runs the insertChar function, which appends a new Character to the back of the linked list
        {
            string name;
            cout<<"enter character name"<<endl;
            getline(cin, name);
            string charClass;
            cout<<"choose class by number"<<endl;
            cout<<"1. Barbarian"<<endl<<"2. Bard"<<endl<<"3. Cleric"<<endl;
            cout<<"4. Druid"<<endl<<"5. Fighter"<<endl<<"6. Monk"<<endl;
            cout<<"7. Paladin"<<endl<<"8. Ranger"<<endl<<"9. Rogue"<<endl;
            cout<<"10. Sorcerer"<<endl<<"11. Warlock"<<endl<<"12. Wizard"<<endl;
            getline(cin, charClass);
            ca.insertChar(name, charClass);
        }
        else if(userInput=="delete")//runs the delete function, which has multiple cases for the head, middle, and tail deletions
        {
            string name;
            cout<<"name of character to delete?"<<endl;
            getline(cin, name);
            ca.deleteChar(name);
        }
        else if(userInput=="print")
        {
            ca.printChars();//cycles through the linked list and prints them in order from head->tail
        }
        else if(userInput=="select")//enters a MENU WITHIN A MENU
        {//this is where most of the usefulness of the program comes from, this is where it does math for you
            int modPlace;
            int modValue;
            string name;
            cout<<"Select a character to use:"<<endl;
            ca.printChars();//lists all possible characters to be used
            cout<<"Enter character name:"<<endl;
            getline(cin, name);
            Character current=ca.searchChar(name);//searches for the Character given the name of the Character
            cout<<"Current character: "<<current.characterName<<endl;
            cout<<"Enter 'back' to quit from this sub-menu"<<endl;
            while(userInput!="back")//nested while loop
            {
                cout<<"'mod' character stats, 'display' stats, 'roll' a d20, 'level' up, add 'xp'"<<endl;//choices are here
                cout<<"attack bonus: Dex: "<<((current.stats[1]-10)/2) + ca.profBonus(current.level)<<endl;//listing commonly needed stats at a glance
                cout<<"attack bonus: Str: "<<((current.stats[0]-10)/2) + ca.profBonus(current.level)<<endl;//same stat, different modifier
                getline(cin, userInput);
                if(userInput=="level")
                {
                    ca.levelUp(&current);//forcibly adds a level
                }
                else if(userInput=="display")//displays more useful information that would traditionally be found on a character sheet
                {
                    cout<<"Level: "<<current.level<<endl;
                    cout<<"Proficiency Bonus: "<<ca.profBonus(current.level)<<endl;
                    cout<<"Hit Points: "<<current.hitPoints<<endl;
                    cout<<"1. Strength: "<<current.stats[0]<<endl;
                    cout<<"2. Dexterity: "<<current.stats[1]<<endl;
                    cout<<"3. Constitution: "<<current.stats[2]<<endl;
                    cout<<"4. Intelligence: "<<current.stats[3]<<endl;
                    cout<<"5. Wisdom: "<<current.stats[4]<<endl;
                    cout<<"6. Charisma: "<<current.stats[5]<<endl;
                }
                else if(userInput=="mod")//forcibly changes ability scores, useful for setting up your character for use with the program
                {
                    cout<<"Select Ability Score to modify"<<endl;
                    cout<<"1. Strength"<<endl;
                    cout<<"2. Dexterity"<<endl;
                    cout<<"3. Constitution"<<endl;
                    cout<<"4. Intelligence"<<endl;
                    cout<<"5. Wisdom"<<endl;
                    cout<<"6. Charisma"<<endl;
                    cin>>modPlace;
                    cin.ignore();
                    cout<<"Set ability score"<<endl;
                    cin>>modValue;
                    cin.ignore();
                    current.stats[modPlace-1]=modValue;//sets the ability score equal to the user's input
                }
                else if(userInput=="roll")
                {
                    cout<<ca.rolld20()<<endl;//sometimes you gotta roll a twenty sided die
                }
                else if(userInput=="xp")//useful for adding xp and the end of a session, levels up the character accordingly
                {
                    int xpNew;
                    cout<<"Enter experience earned"<<endl;
                    cin>>xpNew;
                    cin.ignore();
                    ca.addXP(xpNew, current.xp, current.level, &current);
                }
            }
        }
    }
    return 0;
}
