#ifndef PERSON_H
#define PERSON_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include <iostream>

class Person: public Game_Object
{
 private:
     double speed;
     Cart_Point destination;
     Cart_Vector delta;
    
public:
    Person();
    Person(char in_code);
    Person (char in_code,int in_id, Cart_Point in_loc);
    void start_moving(Cart_Point dest);
    void stop();
    void show_status();
    double get_speed();
    Cart_Vector get_delta();
    Cart_Point get_destination();
    virtual ~Person();
    virtual void start_mining(Gold_Mine* inputMine,Town_Hall* inputHome);
    bool arrived;
    
protected:
    bool update_location();
    void setup_destination (Cart_Point dest);
   
};



#endif /* Person_h */
