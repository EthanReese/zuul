/*
 * C++ version of the zuul text adventure game
 * Created by: Ethan Reese
 * November 7, 2017
 */


#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "Room.h"

using namespace std;


void toLowerCase(char (&arr)[80]);
int checkWinConditions(Room*);
void checkItemConditions(Item*, vector<Room*>);

int main(){
     //Welcome the user to the game
     cout << "Welcome to the game of zuul. Your command words are 'take' 'go' 'drop' 'inventory' 'look' 'quit' and 'help'"<< endl;
     cout << "You slowly open your eyes and realize you are in a dungeon room with a torch attached to the wall." << endl;
     cout << "You have nothing with you and you have no idea where you are." << endl;
    //Create an inventory to hold players items
    vector<Item*> items;
   //Create a list of rooms
   vector<Room*> rooms;
   //Keep track of what the current room is
   Room* currentRoom;
  //Make a variable that can keep track of the index of the room
  int index = 0; 
     





     //Create all of the rooms
     char* startc = "barren room with a torch on the wall.";
     Room* start = new Room(startc);
     char* onec = "junction in the dungeon. There is a black door to the east. You might need a key.";
     Room* one = new Room(onec);
     char* twoc = "junction in the dungeon. You see nothing.";
     Room* two = new Room(twoc);
     Room* three = new Room(twoc);
     Room* four = new Room(twoc);
     char* fourBc = "junction in the dungeon. There is a red door to the South. You might need a key.";
     Room* fourB = new Room(fourBc);
     char* fivec = "junction in the dungeon. There is a blue door to the South. You might need a key";
     Room* five = new Room(fivec);
     Room* six = new Room(twoc);
     char* sevenc = "junction in the dungeon. There is a gold door to the North. You might need a key.";
     Room* seven = new Room(sevenc);
     Room* eight = new Room(twoc);
     char* ninec = "end of the dungeon, but you see a faint light coming a small corner in the east.";
     Room* nine = new Room(ninec);
     char* tenc = "end of this path. You should turn back.";
     Room* ten = new Room(tenc);
     Room* eleven = new Room(twoc);
     Room* twelve = new Room(tenc);
     char* thirteenc = "in the middle of a hallway. You see some light coming from the South.";
     Room* thirteen = new Room(thirteenc);
     char* fourteenc = "a opening.";
     Room* fourteen = new Room(fourteenc);
     char* fifteenc = "a lava room.";
     Room* fifteen = new Room(fifteenc);
     
     //TODO: Delete all of the char arrays

     //Set the exits for all the rooms
     start->setExit("west", three);
     start->setExit("east", one);
     start->setExit("north", two);
     start->setExit("south", four);
     one->setExit("north", six);
     one->setExit("south", five);
     one->setExit("west", start);
     two->setExit("east", six);
     two->setExit("west", seven);
     two->setExit("south", start);
     three->setExit("east", start);
     three->setExit("north", seven);
     three->setExit("south", fourB);
     four->setExit("north", start);
     four->setExit("east", five);
     four->setExit("west", fourB);
     fourB->setExit("north", three);
     fourB->setExit("east", four);
     five->setExit("north", one);
     five->setExit("west", four);
     six->setExit("west", two);
     six->setExit("south", one);
     seven->setExit("south", three);
     seven->setExit("east", two);
     eight->setExit("south", seven);
     eight->setExit("east", nine);
     nine->setExit("west", eight);
     nine->setExit("east", fifteen);
     ten->setExit("north", fourB);
     eleven->setExit("west", one);
     eleven->setExit("north", twelve);
     twelve->setExit("south", eleven);
     thirteen->setExit("north", five);
     thirteen->setExit("south", fourteen);
     
     //Make some items to put down in the room
     Item* torch = new Item();
     torch->name = "Torch";
     start->addItem(torch);
     delete torch;
     Item* rKey = new Item();
     rKey->name = "Red Key";
     nine->addItem(rKey);
     delete rKey;
     Item* bKey = new Item();
     bKey->name = "Blue Key";
     twelve->addItem(bKey);
     delete bKey;
     Item* gKey = new Item();
     gKey->name = "Gold Key";
     six->addItem(gKey);
     delete gKey;
     Item* blKey = new Item();
     blKey->name = "Black Key";
     ten->addItem(blKey);
     delete blKey;

     //Now save all the rooms to the necesary vector
     rooms.push_back(start);
     rooms.push_back(one);
     rooms.push_back(two);
     rooms.push_back(three);
     rooms.push_back(four);
     rooms.push_back(fourB);
     rooms.push_back(five);
     rooms.push_back(six);
     rooms.push_back(seven);
     rooms.push_back(eight);
     rooms.push_back(nine);
     rooms.push_back(ten);
     rooms.push_back(eleven);
     rooms.push_back(twelve);
     rooms.push_back(thirteen);
     rooms.push_back(fourteen);
     rooms.push_back(fifteen);

     currentRoom = start;
     //Main game loop
     while(true){
          cout << "> ";
          char input[80];
          cin >> input;
          toLowerCase(input);
          //If they want to move to another room
          if(strcmp(input, "go") == 0){
               cout << "Please enter which exit you'd like to take: ";
               char dInput[80];
               cin >> dInput;
               toLowerCase(dInput);
               if(currentRoom->getExit(dInput) != NULL){
                    currentRoom  = currentRoom->getExit(dInput);
                       cout << endl;
                       currentRoom->printDescription();
                       currentRoom->printItems();
                       currentRoom->printExits();
                       if(checkWinConditions(currentRoom) == 1){
                               return 0;
                         }
                    }
               else{
                       cout << "Your exit was an invalid input. Please try again.";
               }
          }
          //If they want to pick up an object thats in the room
          else if(strcmp(input, "take") == 0){
               cout << "Which item would you like to take?"<< endl;
               char dInput[80];
               cin.ignore();
               cin.getline(dInput, 80);
               //check to make sure the item is in the room
               if(currentRoom->isItem(dInput) == 1){
                    //cout << items.at(0)->name;
                    //cout << items.at(0)->name;
                    Item* item = currentRoom->takeItem(dInput);
                    items.push_back(item);
                    //cout << items.at(0)->name;
                    checkItemConditions(item, rooms);
               }
               else{
                       cout << "That item isn't in this room" << endl;
               }
          }
          //If they want to drop an object that is in the room
          else if(strcmp(input, "drop") == 0){
               cout << "Which item would you like to drop?";
               char dInput[80];
               cin.ignore();
               cin.getline(dInput, 80);
               //check if that item is in their inventory
               for(int i = 0; i < items.size(); i++){     
                  if(strcmp(items.at(i)->name, dInput) == 0){
                         //Add the item back into the room
                          currentRoom->addItem(items.at(i));
                          items.erase(items.begin()+i);
                    }
               }
          }
          //The person wants to list out the items in their inventory
          else if(strcmp(input, "inventory") == 0){
               //Loop through the inventory and print out every item
               cout << "You have: " << endl;
               //cout << items.at(0)->name << endl;
               for(int i = 0; i < items.size(); i++){
                    cout << items.at(i)->name << endl;
               }
          }
          else if(strcmp(input, "look") == 0){
               currentRoom->printDescription();
               currentRoom->printItems();
               currentRoom->printExits();
          }
          //The person needs some help
          else if(strcmp(input, "help") == 0){
               cout << "You are playing a dungeon adventure game. You have to try to get out of the dungeon." << endl;
               cout << "Your command words are go, look, help, inventory, quit, and take. Once you enter a command word you may be prompted for further input" << endl;
               cout << "Good luck!" << endl;
          }
          //The person wants to quit
          else if(strcmp(input, "quit") == 0){
                  return 1;
          }
          //The input is invalid
          else{
                  cout << "Please enter one of the command words by itself. If there is further input required, you will be prompted." << endl;
          }

     }

     return 0;
}

//Function to make the elements of a character array lower case
void toLowerCase(char (&arr)[80]){
        //Loop through the character array and make every item lowercase
        for(int i = 0; i < 80; i++){
          arr[i] = tolower(arr[i]);
        }
}
//Function to check the winning and losing conditions
int checkWinConditions(Room* room){
     //Check if the room that they're in is the win condition
     if(strcmp(room->getDescription(),"a opening.") == 0){
          cout << "You step into a large grassy field." << endl;
          cout << "You can see your house in the distance." << endl;
          cout << "Congratulations! You Win!";
          return 1;
     }
     else if(strcmp(room->getDescription(),"a lava room.") == 0){
          cout << "You Die." << endl;
          cout << "You managed to lose one of the easiest games in existence. Nice job!" << endl;
          return 1;
     }
     return 0;

}
//Function to check if the items that the user picks up do anything
void checkItemConditions(Item* item, vector<Room*> rooms){
     if(strcmp(item->name, "Red Key") == 0){
          //Find room 10 in the array so I can set that in the exit
          int rmTenInd = 0;
          for(int i = 9; i< rooms.size(); i++){
               if(strcmp(rooms.at(i)->getDescription(), "end of this path. You should turn back.") == 0){
                    rmTenInd = i;
               }
          }
          //Find room four B and make an exit to room 10 bc the door opened.
          for(int i = 0; i < rooms.size(); i++){
               if(strcmp(rooms.at(i)->getDescription(),"junction in the dungeon. There is a red door to the South. You might need a key.") == 0){
                   // cout << "One" << endl;
                       rooms.at(i)->setExit("south", rooms.at(rmTenInd));
               }
          }
     }
     else if(strcmp(item->name, "Blue Key")== 0){
             //Find index of room 5 
          int rmTenInd = 0;
          for(int i = 0; i< rooms.size(); i++){
               if(strcmp(rooms.at(i)->getDescription(), "in the middle of a hallway. You see some light coming from the South") == 0){
                    rmTenInd = i;
               }
          }
          //Find room four B and make an exit to room 10 bc the door opened.
          for(int i = 0; i < rooms.size(); i++){ 
               if(strcmp(rooms.at(i)->getDescription(),"junction in the dungeon. There is a blue door to the South. You might need a key") == 0){
                    cout << "one" << endl;
                    rooms.at(i)->setExit("south", rooms.at(rmTenInd));
               }
          }
     }
     else if(strcmp(item->name, "Black Key") == 0){ 
             //Find index of room 5 
          int rmTenInd = 0;
          for(int i = 11; i< rooms.size(); i++){
               if(strcmp(rooms.at(i)->getDescription(),"junction in the dungeon. You see nothing.") == 0){
                    rmTenInd = i;
                    break;
               }
          }
          //Find room four B and make an exit to room 10 bc the door opened.
          for(int i = 0; i < rooms.size(); i++){ 
               if(strcmp(rooms.at(i)->getDescription(),"junction in the dungeon. There is a black door to the West. You might need a key.") == 0){
                    rooms.at(i)->setExit("east", rooms.at(rmTenInd));
               }
          }

     }
     else if(strcmp(item->name, "Gold Key") == 0){
             //Find index of room 8 
          int rmTenInd = 0;
          for(int i = 8; i< rooms.size(); i++){
               if(strcmp(rooms.at(i)->getDescription(), "junction in the dungeon. You see nothing.") == 0){
                    rmTenInd = i;
                    //cout << "one" << endl;
                    break;
               }
          }
          //Find room four B and make an exit to room 10 bc the door opened.
          for(int i = 0; i < rooms.size(); i++){
               if(strcmp(rooms.at(i)->getDescription(),"junction in the dungeon. There is a gold door to the North. You might need a key") == 0){
                    //cout << "Made it here" << endl;
                       rooms.at(i)->setExit("north", rooms.at(rmTenInd));
               }
          }
     }
}
