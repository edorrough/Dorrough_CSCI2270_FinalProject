#ifndef CHARACTERASSISTANT_H
#define CHARACTERASSISTANT_H
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Character{
    string characterName;
    string className;
    int level;
    int hitDie;
    int hitPoints=0;
    int xp;
    Character *next;
    Character *previous;
    int stats[6]={0,0,0,0,0,0};

    Character(){};//default constructor

    Character(string initCharName, string initClassName, int initLevel, int initHitDie, Character *initNext, Character *initPrevious)
    {
        characterName=initCharName;
        className=initClassName;
        level=initLevel;
        hitDie=initHitDie;
        next=initNext;
        previous=initPrevious;
    }

};

class CharacterAssistant
{
    public:
        CharacterAssistant();
        int hitDie(string);
        int rollHitDie(Character*);
        int rolld20();
        void insertChar(string, string);
        void deleteChar(string);
        void printChars();
        void levelUp(Character*);
        int profBonus(int);
        void addXP(int, int, int, Character*);
        Character searchChar(string);
        ~CharacterAssistant();
    protected:
    private:
        Character *head;
        Character *tail;
};

#endif // CHARACTERASSISTANT_H
