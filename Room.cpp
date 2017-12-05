#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include "Room.h"

using namespace std;


//Constructor
Room::Room(char* newDescription){
     description = new char[80];
     strcpy(description, newDescription);
}

//Print out the exits
void Room::printExits(){
     cout << "Exits: ";
     //Iterate over the map and find all the exits that exist and go ahead and print them out
     map<char*, Room*>::iterator it;
     for(it = Exits.begin(); it != Exits.end(); it++){
          cout << (it->first) << " ";
     }
     cout << endl;
}
//Print out a description of the room
void Room::printDescription(){
     cout << "You are in a "; 
     cout << description << endl;
}
//Deconstructor
Room::~Room(){
     delete description;
     
}
//Print out all of the items in the room
void Room::printItems(){
     cout << "Items: ";
     for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
          //Get the char array as a part of item that contains the description and go ahead and print it out
          cout << (*it)->name << " ";
     }
    cout << endl; 
}
//Sets the exit for the room
void Room::setExit(char* direction, Room* room){
     char* newDirection = new char[80];
     strcpy(newDirection, direction);
     Exits[newDirection] = room;
}
//When the player drops an item into the room, it needs to add the item to the array
void Room::addItem(Item* item){
     Item *newItem = new Item();
     newItem->name = item->name;
     items.push_back(newItem);
}
//When the player takes an item from the room
int Room::isItem(char* itemName){
     for(int i = 0; i < items.size(); i++){
          if(strcmp(items.at(i)->name, itemName) == 0){
               return 1;            
          }
     }
     return 0;
}

//Create a function that can return what room an exit goes to
Room* Room::getExit(char* exit){
     Room* returnRoom = NULL;
     for (auto &it : Exits){
          if(strcmp(it.first, exit) == 0){
               returnRoom = i.second;
               break;
          }
     }
     return returnRoom;
}
//Function that returns the description of a room
char* Room::getDescription(){
     return description;
}
//Function that can actually take an item from the room
Item* Room::takeItem(char* itemName){     
     for(int i = 0; i < items.size(); i++){
          if(strcmp(items.at(i)->name, itemName) == 0){
               Item* returnItem = items.at(i);
               items.erase(items.begin()+i);
               return returnItem;            
          }
     }
}
