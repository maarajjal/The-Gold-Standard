#ifndef TOWN_HALL_H
#define TOWN_HALL_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include <iostream>

using namespace std;

class Town_Hall: public Game_Object
{
    
private:
    //char display_code;
    char state;
    double amount;
    //Cart_Point location;
 
 public:
    Cart_Point get_location();
    //int get_id();
    void deposit_gold (double deposit_amount);
    bool update();
    bool upgraded;
    void show_status();
    Town_Hall();
    Town_Hall(int inputId, Cart_Point inputLoc);
    ~Town_Hall();
 
 
};


#endif
