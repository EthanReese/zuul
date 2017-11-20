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

int main(){
     //Welcome the user to the game
     cout << "Welcome to the game of zuul. Your command words are 'take' 'go' 'drop' 'inventory' 'quit' and 'help'"<< endl;
     cout << "You slowly open your eyes and realize you are in a dungeon room with a torch attached to the wall." << endl;
     cout << "You have nothing with you and you have no idea where you are." << endl;
    //Create an inventory to hold players items
    vector<Item*> items;
   //Create a list of rooms
   vector<Room*> rooms;
  //Make a variable that can keep track of the index of the room
  int index = 0; 
     





     //Create all of the rooms
     char* start = "barren room with a torch on the wall."
     Room* start = new Room(start);
     char* one = "junction in the dungeon. There is a black door to the West. You might need a key.";
     Room* one = new Room(one);
     char* two = "junction in the dungeon. You see nothing.";
     Room* two = new Room(two);
     Room* three = new Room(two);
     Room* four = new Room(two);
     char* fourB = "junction in the dungeon. There is a red door to the South. You might need a key.";
     Room* fourB = new Room(fourB);
     char* five = "junction in the dungeon. There is a blue door to the South. You might need a key.";
     Room* five = new Room(five);
     Room* six = new Room(two);
     char* seven = "junction in the dungeon. There is a gold door to the North. You might need a key.";
     Room* seven = new Room(seven);
     Room* eight = new Room(two);
     char* nine = "end of the dungeon, but you see a faint light coming a small corner in the west.";
     Room* nine = new Room(nine);
     char* ten = "end of this path. You should turn back.";
     Room* ten = new Room(ten);
     Room* eleven = new Room(two);
     Room* twelve = new Room(ten);
     char* thirteen = "in the middle of a hallway. You see some light coming from the South.";
     Room* thirteen = new Room(thirteen);
     char* fourteen = "a giant grassy field and your house in the distance.";
     Room* fourteen = new Room(fourteen);
     char* fifteen = "a room filled all the way with lava.";
     Room* fifteen = new Room(fifteen);

     //Set the exits for all the rooms
     start.setExit("west", three);
     start.setExit("east", one);
     start.setExit("north", two);
     start.setExit("south", four);
     one.setExit("north", six);
     one.setExit("south", five);
     one.setExit("west", start);
     two.setExit("east", six);
     two.setExit("west", seven);
     two.setExit("south", start);
     three.setExit("east", start);
     three.setExit("north", seven);
     three.setExit("south", fourB);
     four.setExit("north", start);
     four.setExit("east", five);
     four.setExit("west", fourB);
     fourB.setExit("north", three);
     fourB.setExit("west", four);
     five.setExit("north", one);
     five.setExit("west", four);
     six.setExit("west", two);
     six.setExit("south", one);
     seven.setExit("south", three);
     seven.setExit("east", two);
     eight.setExit("south", seven);
     eight.setExit("east", nine);
     nine.setExit("west", eight);
     nine.setExit("east", fifteen);
     ten.setExit("north", fourB);
     eleven.setExit("west", one);
     eleven.setExit("north", twelve);
     twelve.setExit("south", eleven);
     thirteen.setExit("north", five);
     thirteen.setExit("south", fourteen);
     
     //Make some items to put down in the room
     Item* torch = new Item();
     torch->name = "A Torch";
     start->addItem(torch);
     delete torch;
     Item* rKey = new Item();
     rKey->name = "A Red Key";
     nine->addItem(rKey);
     delete rKey;
     Item* bKey = new Item();
     bKey->name = "A Blue Key";
     twelve->addItem(bKey);
     delete bKey;
     Item* gKey = new Item();
     gKey->name = "A Gold Key";
     six->addItem(gKey);
     delete gKey;
     Item* bKey = new Item();
     bKey->name = "A Black Key";
     ten->addItem(bKey);
     delete bKey;

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


     //Main game loop
     while(true){
          char input[80];
          cin >> input;
          toLowerCase(input);
          //If they want to move to another room
          if(strcmp(input, "go") == 0){
               cout << "Please enter which exit you'd like to take";
          }
          //If they want to pick up an object thats in the room
          else if(strcmp(input, "take") == 0){

          }
          //If they want to drop an object that is in the room
          else if(strcmp(input, "drop") == 0){

          }
          //The person wants to list out the items in their inventory
          else if(strcmp(input, "inventory") == 0){

          }
          //The person needs some help
          else if(strcmp(input, "help") == 0){
               cout << "You are playing a dungeon adventure game. You have to try to get out of the dungeon." << endl;
               cout << "Your command words are go, help, inventory, quit, and take. Once you enter a command word you may be prompted for further input" << endl;
               cout << "Good luck!" << endl;
          }
          //The person wants to quit
          else if(strcmp(input, "quit")){
                  return 1;
          }
          //The input is invalid
          else{
                  cout << "Please enter one of the command words by itself. If there is further input required, you will be prompted." << endl;
          }


          //Print out a description of the room
          //Print out exits
          //Print out items

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
