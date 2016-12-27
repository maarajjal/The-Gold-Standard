#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include <math.h>

using namespace std;


Person::Person(char in_code):Game_Object (in_code,0) // it inhereits from Game_object
{
    speed=5;
    cout<<"Person default constructed."<<endl;
}

Person::Person(char in_code,int in_id, Cart_Point in_loc):Game_Object (in_code,in_id,in_loc)
{
    speed=5;
    cout<<"Person constructed."<<endl;
}


void Person::start_moving (Cart_Point dest) 
{
    setup_destination(dest); // prepares the destination for the person (miner) to start moving 
    state='m'; //sets the state to moving
    cout<<"Moving "<<this->get_id()<<" to "<<this->destination<<endl;
    if (isnan(delta.x)||isnan(delta.y)==1) // if the delta value is not a number, this means that a person is being asked to move to their current location.
    {
        cout<<this->display_code<<this->get_id()<<":"<<" I'm already there. see?"<<endl;
        state='s';
        return;
    }
    else
    {
    cout<<this->display_code<<this->get_id()<<":"<<" On my way."<<endl; // it starts moving. 
    }
    return;
}

void Person::stop() // stops whatever person is doing. 
{
    state='s';
    cout<<this->display_code<<this->get_id()<<":"<<" Stopped."<<endl;
}

void Person::show_status()
{
    if (state=='s')
    {
        Game_Object::show_status();
    }
    else
    {
     Game_Object::show_status();
        cout<<" moving at speed of "<<this->speed<<" towards "<<this->destination<<" at each step of "<<this->delta<<endl;
    }
    
   
}

bool Person::update_location()
{
    if ((fabs((destination-location).x)<=fabs(delta.x)) && (((fabs((destination-location).y)<=fabs((delta.y))))))
                                                           
    {
        location=destination;
        cout<<display_code<<this->get_id()<<":"<<" I'm there!"<<endl;
        //arrived=true;
        return true;
    }
  
    else
    {
        location=location+delta;
        cout<<display_code<<this->get_id()<<":"<<" step..."<<endl;
        //arrived=false;
        return false;
    }
}


double Person::get_speed() // returns the speed (same below for delta and destination).
{
    return speed;
}
                                    

void Person::setup_destination (Cart_Point dest) //sets up the destination by calculating the delta value based on the delta equation. 
{
    destination=dest;
    delta=(destination-location)*(speed/cart_distance(destination,location));
    return;
}



Cart_Vector Person::get_delta()
{
        return delta;
}
                                                             
Cart_Point Person::get_destination()
{
    return destination;
}


void Person:: start_mining(Gold_Mine* inputMine,Town_Hall* inputHome)
 {
  cout<<"Sorry, I can’t work a mine."<<endl;
 }

Person::~Person() // The destructor. 
{
    cout<<"Person destructed."<<endl;
}
                                                             
                                                             

                                                             






