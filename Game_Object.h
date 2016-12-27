#ifndef GAME_OBJECT_H
#define  GAME_OBJECT_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <iostream>

using namespace std;

class Game_Object
{
 private:
  int id_num;
    
 protected:
  Cart_Point location;
  char display_code;
  char state;
    
 public:
  Game_Object(char in_code, int in_id);
  Game_Object(char in_code, int in_id, Cart_Point in_loc);
  Game_Object();
  Cart_Point get_location();
  int get_id();
  virtual void show_status();
  virtual ~Game_Object();
  virtual bool update()=0;
  void drawself(char * ptr);

};


#endif 


