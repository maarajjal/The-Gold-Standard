#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

using namespace std;

Town_Hall::Town_Hall():Game_Object('t',1) // inherits from game_object, this is its deafult constructor, the initial id for townhall is t (before its upgraded)
{

  state='o';
  amount=0;
  cout<<"Town_Hall deafult constructed."<<endl;
}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc):Game_Object('t',inputId,inputLoc)
{
  
  display_code='t';
  state='o';
  amount=0;
  upgraded=false;
  cout<<"Town_Hall constructed."<<endl;
}

Cart_Point Town_Hall::get_location()
{
  return location;
}



void Town_Hall::deposit_gold (double deposit_amount) //deposits gold at the townhall and updates the amount of gold at the townhall. 
{
  amount=amount+deposit_amount;
}

bool Town_Hall::update() // Updates the staus of the townhall
{
    
  if ((amount>=50) && (upgraded==false)) // It is upgraded if the amount of golf in it is greater than 50
    {
      state='u';
      display_code='T';
      cout<<this->display_code<<get_id()<<" has been upgraded "<<endl;
      upgraded=true;
      return true;
    }
  else
    {
    return false;
    }
  
}

void Town_Hall:: show_status() //outputs the current status of the townhall
{
    cout<<"Town Hall status: "<<this->display_code<<get_id()<<" at "<<location<<" contains "<<amount<<" of gold.";
  if (upgraded==false)
  {
    cout<<" Not yet upgraded. "<<endl;
  }
  else
  {
      cout<<" Upgraded."<<endl;
  }
}

Town_Hall::~Town_Hall() //The destructor.
{
    cout<<"Town_Hall destructed."<<endl;
}




