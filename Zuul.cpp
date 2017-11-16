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

//Hold information about the items
struct Item{
     char* name;

}

void toLowerCase(char (&arr)[7]);

int main(){
     //Welcome the user to the game
     cout << "Welcome to the game of zuul. Your command words are 'take' 'go' 'drop' 'inventory' 'quit' and 'help'"<< endl;
     cout << "You slowly open your eyes and realize you are in a dungeon room with a torch attached to the wall." << endl;
     cout << "You have nothing with you and you have no idea where you are." << endl;
     
     
     
     //Main game loop
     while(true){
          char[80] input;
          cin << input;
          toLowerCase(input);
          //If they want to move to another room
          if(strcmp(input, "go") == 0){



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
