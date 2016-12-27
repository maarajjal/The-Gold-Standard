#include <iostream>
#include "Game_Object.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Gold_Mine.h"
#include <iostream>

using namespace std;

Gold_Mine::Gold_Mine():Game_Object('G',0) //deafult constructor, it is inherting from Game_Object with an ID of G.
{
  depleted = false; // mine is not empty
  state='f';
  amount=100;
  cout<<"Gold_Mine default constructed."<<endl;
}

Gold_Mine:: Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G',inputId,inputLoc)
{
  depleted=false;
  state='f';
  amount=100;
  cout<<"Gold_Mine constructed."<<endl;
}


bool Gold_Mine:: is_empty() // Checks if a mine is empty
{
  if (amount==0)
    {
      return true;
    }
  else 
    {
      return false;
    }
}

double Gold_Mine::dig_gold(double amount_to_dig) // a function to dig gold, the deafult amount to dig is 35
{
  if(amount>=amount_to_dig) // if the amount at the gold_mine is greater than 35
    {
      amount=amount-amount_to_dig; // the amount is decreased by 35
      return amount_to_dig;
    }
  else // if the amount at the gold_mine is less than the amount to dig
    {
     amount_to_dig=amount; //the amount to dig is what ever remains in the gold_mine (it is being emptied)
     amount=0; //the amount is hence set to 0, to indicate the mine is empty.
     return amount_to_dig; // this is the amount dug. 
      
    }
}

bool Gold_Mine::update() // updates the gold_mine, by checking if it is empty
{
  if ((amount>0) && (depleted==true))
  {
      depleted=false;
  }
  else if ((amount==0) && (depleted==false))
    {
      state='e'; // sets the state to e to signify that the mine is empty
      display_code='g';
      cout<<"Gold Mine "<<this->get_id()<<" has been depleted."<<endl;
      depleted=true;
      return true;
    }
    return false;
}

void Gold_Mine::show_status() //outputs the current status of the mine, using its display code, id, location and the amount of gold it currently holds. (I use the get functions defined in Game_object)
{
  cout<<"Gold Mine status: "<<display_code<<get_id()<<" at location "<<this->location<<" Contains "<<this->amount<<"."<<endl;
  
}

Gold_Mine::~Gold_Mine() // the destructor. 
{
    cout<<"Gold_Mine destructed."<<endl;
}

