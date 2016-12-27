#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

Game_Object::Game_Object() //The deafult constructor for Game_object (initialise member variables) 
{
    display_code= ' ';
    id_num=0;
    location=Cart_Point();
}

Game_Object::Game_Object(char in_code, int in_id)
{
  display_code=in_code;
  id_num=in_id;
  location=Cart_Point();
  cout<<"Game_Object default constructed."<<endl;
  
}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
  display_code=in_code;
  id_num=in_id;
  location=in_loc;
  cout<<"Game_Object constructed."<<endl;
}

Cart_Point Game_Object:: get_location() // fucntion to get the location of an object
{
    return location;
}

int Game_Object::get_id()// function to the id of an object.
{
  return id_num;
}

void Game_Object:: show_status() // outputs the current status of the object, using display_code ID and locatation
{
    cout<<this->display_code<<id_num<<" at "<<this->location; 

}

void Game_Object::drawself (char * ptr) // This function puts the display code at the character pointed to by ptr. and then displays the id_num (ASCII character)
{
    if (*ptr=='.')
    {
        *ptr=display_code;
        *(ptr+1)=get_id()+48; //0 is 48 in ASCII
    }
    else
    {
        *ptr='*'; // if more than one object exist at the same location it puts a * to indicate that.
        *(ptr+1)=' ';
    }
}

Game_Object::~Game_Object() // The destructor
{
    cout<<"Game_Object destructed."<<endl;
}

