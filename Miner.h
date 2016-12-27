#ifndef MINER_H
#define MINER_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include <iostream>

class Miner: public Person
{
    private:
        //char display_code;
        int id_num;
        //char state;
        double amount;
        Cart_Point location;
        Gold_Mine* mine;
        Town_Hall* home;
    
    
    public:
        Miner();
        Miner(int in_id, Cart_Point in_loc);
        bool update();
        void start_mining (Gold_Mine* inputMine, Town_Hall* inputHome);
        Cart_Point get_location();
        void show_status();
        void stop();
        ~Miner();
};




#endif /* Miner_h */
