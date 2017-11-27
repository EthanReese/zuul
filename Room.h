#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Item{
        char* name;
};

class Room{
     public:
          void printExits();
          void printItems();
          Room(char*);
          ~Room();
          void setExit(char*, Room*);
          void addItem(Item*);
          int takeItem(char*);
          Room* getExit(char*);
          vector<Item*> items;
          map<char*, Room*> Exits;
          char* description;
          char* getDescription();
          void printDescription();
     private:
     };
