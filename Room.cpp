#include <iostream>
#include <cstdlib>
#include <vector>
#include "Room.h"

using namespace std;

//Print out the exits
void printExits(){
     cout << "Exits: ";
     //Iterate over the map and find all the exits that exist and go ahead and print them out
     map<char*, Room*>::iterator it;
     for(it = Exits.begin(); it != Exits.end(); it++){
          cout << *(it->first) << " ";
     }
     cout << endl;
}
//Print out a description of the room
void printDescription(){
        cout << description;
        cout << endl;
}
//Constructor
Room::Room(char* newDescription){
     description = new char[80];
     strcpy(description, newDescription);
}
//Deconstructor
Room::~Room(){
     delete description;
    //Am I going to have to delete the char pointers in the map? 
}
//Print out all of the items in the room
void printItems(){
     cout << "Items: ";
     for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++){
          //Get the char array as a part of item that contains the description and go ahead and print it out
          cout << *(it->name) << " ";
     }
    cout << endl; 
}
//Sets the exit for the room
void setExit(char* direction, Room* room){
     char* newDirection = new char[80];
     strcpy(newDirection, direction);
     Exits[newDirection] = room;
}
//Do all the stuff with items
void addItem(Item*){

}
