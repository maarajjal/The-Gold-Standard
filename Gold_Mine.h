#ifndef GOLD_MINE_H
#define GOLD_MINE_H
#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

class Gold_Mine: public Game_Object
{
 private:
  //char display_code;
  //int id_num;
  char state;
  double amount;
  //Cart_Point location;

 public:
  Gold_Mine();
  Gold_Mine(int inputId, Cart_Point inputLoc);
 // Cart_Point get_location();
  //int get_id();
  bool is_empty();
  bool depleted;
  double dig_gold(double amount_to_dig = 35.0);
  bool update();
  void show_status();
  ~Gold_Mine();
};

#endif
