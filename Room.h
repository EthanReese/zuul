#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Room{
     public:
          void printExits();
          void printItems();
          Room(char*);
          ~Room();
          void setExit(char*, Room*);
          void addItem(Item*);
          void takeItem(char*);
     private:
          vector<Item*> items;
          map<char*, Room*> Exits;
          char* description; 
     };
