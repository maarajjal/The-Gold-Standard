#ifndef MODEL_H
#define MODEL_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "View.h"
#include <iostream>

class Model
{
    
private:
    int time;
    int num_objects;
    int num_persons;
    int num_mines;
    int num_halls;
    Town_Hall* hall_ptrs[10];
    Game_Object* object_ptrs[10];
    Person* person_ptrs[10];
    Gold_Mine* mine_ptrs[10];
    int id_num;
    char state;
    

public:
    Model();
    ~Model();
    Person* get_Person_ptr(int);
    Gold_Mine* get_Gold_Mine_ptr(int);
    Town_Hall* get_Town_Hall_ptr(int);
    bool update();
    void display(View &view);
    void show_status();
   
    
};


#endif /* Model_h */
