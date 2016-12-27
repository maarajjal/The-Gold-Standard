#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include <cmath>

using namespace std;

Miner::Miner():Person('M') // deafult constructor, a miner with display_code M. Miner class inherits from Person.
{
    amount=0;
    state='s';
    home=0;
    mine=0;
    cout<<"Miner default constructed."<<endl;
}

Miner::Miner(int in_id, Cart_Point in_loc):Person('M',in_id,in_loc)
{
    amount=0;
    mine=0;
    home=0;
    state='s';
    cout<<"Miner constructed."<<endl;
}

bool Miner::update() // Updates the status of a miner depending on the miner's current state. This is besically defining the different behaviours of the miner at different states. 
{
    switch(state)
    {
        case 's':
            break;
            
        case 'm':
            if (update_location()==true) // checks if the miner arrived, if it did it stops by setting the state to 's'.
            {
                state='s';
                return true;
            }
            else
                return false;
            break;
            
        case 'o':  // outbound to a mine
            if (update_location()==true) // if it arrived it means that it is getting gold (case g)
            {
                state='g';
                return true;
            }
            else
                return false;
            
        
        case 'd': // desposinting gold 
            cout<<this->display_code<<this->get_id()<<":"<<" Deposit "<<amount<<" of gold."<<endl;
            home->deposit_gold(amount);
            amount=0;
            if (mine->is_empty()) // if the gold_mine is depleted. 
            {
                state='s';
                cout<<this->display_code<<this->get_id()<<":"<<" More work?"<<endl;
                return true;
            }
            else
            {
                setup_destination(mine->get_location()); // Mining again.
                state='o'; //outbount to a mine.
                cout<<this->display_code<<this->get_id()<<":"<<" Going back for more"<<endl;
                return true;
                
            }
            
            
        case 'g':  // The miner is at the mine and is getting gold 
            amount=mine->dig_gold(35.0); //amount is increasing by the amount being dug (35)
            cout<<this->display_code<<get_id()<<":"<<" Got "<<this->amount<<" gold"<<endl;
            setup_destination(home->get_location()); //prepares the miner to start heading to town_hall where the miner willl be depositing gold.
            state='i';
            return true;
            
        case 'i': //inbound
            if(update_location()==true) // if it arrrvied to the townhall it deposits the gold. 
            {
                state='d'; //desposit gold. 
                return true;
            }
            else
                return false;
        default:
            return false;
     }
    return false;
    
    
    
    
}

void Miner::start_mining(Gold_Mine* inputMine,Town_Hall* inputHome) // Tells the miner to mine at the given mine, and put the gold at the given townhall. Pointers to the townhall and Goldmine are given to this function
{
    mine=inputMine;
    home=inputHome;
    Cart_Point mine_destination=mine->get_location(); // getting the location of the mine. 
    setup_destination(mine_destination); 
    state='o';
    cout<<"Miner "<<this->get_id()<<" mining at Gold_Mine "<<mine->get_id()<<" and depositing at Town_Hall "<<home->get_id()<<"."<<endl;
    cout<<this->display_code<<this->get_id()<<":"<<" Yes, my lord."<<endl;
   
    return;
    
}

Cart_Point Miner::get_location()
{
    return location;
}


void Miner::show_status() // the status of the miner depending on the state or behaviuor. (The way  this works is that the Miner show_status calls the person show status which calls the game_object show status. each show status function taking care of a specfic aspect. 
{
    
    cout<<"Miner status: ";
    //Person::show_status();
    
    switch (state)
    {
        case 's':
            Person::show_status();
            cout<<" is stopped."<<endl;
            break;
        case 'm':
            Person::show_status();
            break;
        case 'o':
            Person::show_status();
            cout<<" is outbound to a mine."<<endl;
            break;
        case 'g':
            Person::show_status();
            cout<<" is getting gold from mine."<<endl;
            break;
        case 'i':
            Person::show_status();
            cout<<" is inbound to home with load: "<<this->amount<<endl;
            break;
        case 'd':
            Person::show_status();
            cout<<" is depositing gold"<<endl;
            break;
    }
}


Miner::~Miner() // the destructor
{
    cout<<"Miner destructed"<<endl;
}



