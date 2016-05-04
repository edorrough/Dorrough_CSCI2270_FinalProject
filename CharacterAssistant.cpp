#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "CharacterAssistant.h"

CharacterAssistant::CharacterAssistant()
{
    //ctor
    head=NULL;
    tail=NULL;

}
void CharacterAssistant::addXP(int xpNew, int xpTotal, int level, Character* current)
{
    xpTotal=xpTotal+xpNew;
    cout<<"xp: "<<xpTotal<<endl;
    if((xpTotal>300 && level==1)||(xpTotal>900 && level==2)||(xpTotal>2700 && level==3)||(xpTotal>6500 && level==4)||(xpTotal>14000 && level==5)
       ||(xpTotal>23000 && level==6)||(xpTotal>34000 && level==7)||(xpTotal>48000 && level==8)||(xpTotal>64000 && level==9)||(xpTotal>85000 && level==10)
       ||(xpTotal>100000 && level==11)||(xpTotal>120000 && level==12)||(xpTotal>140000 && level==13)||(xpTotal>165000 && level==14)||(xpTotal>195000 && level==15)
       ||(xpTotal>225000 && level==16)||(xpTotal>265000 && level==17)||(xpTotal>305000 && level==18)||(xpTotal>355000 && level==19))
    {
        levelUp(current);
    }
}

void CharacterAssistant::deleteChar(string name)
{
    Character *temp=head;
    while(temp!=NULL)
    {
        if(temp->characterName==name and temp->previous!=NULL and temp->next!=NULL)//it's found and in the middle
        {
            temp->previous->next=temp->next;
            temp->next->previous=temp->previous;
            delete temp;
            break;
        }
        else if(temp->characterName==name and temp->previous==NULL and temp->next!=NULL)//it's found and it's the head
        {
            head=temp->next;
            head->previous=NULL;
            delete temp;
            break;
        }
        else if(temp->characterName==name and temp->previous!=NULL and temp->next==NULL)//it's found and it's the tail
        {
            temp->previous->next=NULL;
            delete temp;
            break;
        }
        else if(temp->characterName==name and temp->previous==NULL and temp->next==NULL)//it's found and it's the tail AND the head
        {
            delete temp;
            head = NULL;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }
}
int CharacterAssistant::hitDie(string charClass)
{
    if((charClass=="10")||(charClass=="12"))
    {
        return 6;
    }
    else if((charClass=="2")||(charClass=="3")||(charClass=="4")||(charClass=="6")||(charClass=="9")||(charClass=="11"))
    {
        return 8;
    }
    else if((charClass=="5")||(charClass=="7")||(charClass=="8"))
    {
        return 10;
    }
    else if(charClass=="1")
    {
        return 12;
    }
}

void CharacterAssistant::levelUp(Character* current)
{
    current->level=current->level+1;
    current->hitPoints=current->hitPoints + rollHitDie(current) + ((current->stats[2]-10)/2);
    if((current->level==4)||(current->level==8)||(current->level==12)||(current->level==16)||(current->level==19))
    {
        string choice;
        int upped;
        cout<<"Ability Score Improvement! Improve one score by two or two scores by one."<<endl;
        cout<<"'two' or 'one' scores being improved?"<<endl;
        getline(cin, choice);
        if(choice=="two")
        {
            cout<<"First ability score? (Enter an integer)"<<endl;
            cout<<"1. Strength"<<endl;
            cout<<"2. Dexterity"<<endl;
            cout<<"3. Constitution"<<endl;
            cout<<"4. Intelligence"<<endl;
            cout<<"5. Wisdom"<<endl;
            cout<<"6. Charisma"<<endl;
            cin>>upped;
            cin.ignore();
            current->stats[upped]++;
            cout<<"Second ability score? (Enter an integer)"<<endl;
            cout<<"1. Strength"<<endl;
            cout<<"2. Dexterity"<<endl;
            cout<<"3. Constitution"<<endl;
            cout<<"4. Intelligence"<<endl;
            cout<<"5. Wisdom"<<endl;
            cout<<"6. Charisma"<<endl;
            cin>>upped;
            cin.ignore();
            current->stats[upped]++;
        }
        else if(choice=="one")
        {
            cout<<"Which ability score? (Enter an integer)"<<endl;
            cout<<"1. Strength"<<endl;
            cout<<"2. Dexterity"<<endl;
            cout<<"3. Constitution"<<endl;
            cout<<"4. Intelligence"<<endl;
            cout<<"5. Wisdom"<<endl;
            cout<<"6. Charisma"<<endl;
            cin>>upped;
            cin.ignore();
            current->stats[upped]=current->stats[upped]+2;
        }
    }
}

int CharacterAssistant::profBonus(int level)
{
    if(level<5)
    {
        return 2;
    }
    else if(level<9 && level>4)
    {
        return 3;
    }
    else if(level<13 && level>8)
    {
        return 4;
    }
    else if(level<17 && level>12)
    {
        return 5;
    }
    else if(level>16)
    {
        return 6;
    }
}

void CharacterAssistant::insertChar(string name, string charClass)
{
    Character *newChar=new Character(name, charClass, 1, hitDie(charClass), NULL, NULL);
    newChar->hitPoints=0+rollHitDie(newChar);
    newChar->xp=0;
    cout<<"Starting Hit Points: "<<newChar->hitPoints<<endl;
    if(head==NULL)
    {
        head=newChar;
    }
    else
    {
        Character *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newChar;
        newChar->previous=temp;
    }
}

int CharacterAssistant::rolld20()
{
    srand((unsigned)time(NULL));
    int result=(rand()%20)+1;
    return result;
}

void CharacterAssistant::printChars()
{
    Character *temp=head;
    if(head!=NULL)
    {
       while(temp->next!=NULL)
       {
           cout<<temp->characterName<<endl;
           temp=temp->next;
       }
       cout<<temp->characterName<<endl;
    }
}

Character CharacterAssistant::searchChar(string name)
{
    Character *temp=head;
    while(temp!=NULL)
    {
        if(temp->characterName==name)
        {
            return *temp;
        }
        else
        {
            temp=temp->next;
        }
    }
    temp=NULL;
    return *temp;
}

int CharacterAssistant::rollHitDie(Character* current)
{
    srand((unsigned)time(NULL));
    int result=(rand()%current->hitDie)+1;
    return result;
}

CharacterAssistant::~CharacterAssistant()
{
    //dtor
}
