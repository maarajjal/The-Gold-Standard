#ifndef CART_POINT_H
#define CART_POINT_H
#include <iostream>
#include "Cart_Vector.h"

using namespace std;

class Cart_Vector;

class Cart_Point
{
 public:
  double x;
  double y;
  double inputx;
  double inputy;
   Cart_Point();
  Cart_Point(double inputx,double inputy);
  friend ostream& operator<<(ostream& os, const Cart_Point &a);
  friend Cart_Point operator+(const Cart_Vector &a,const Cart_Point &b);
  friend Cart_Point operator+(const Cart_Point &a, const Cart_Vector&b);
  friend Cart_Vector operator-(const Cart_Point &a,const Cart_Point &b);
};

double cart_distance(Cart_Point , Cart_Point);

//ostream& operator<<(ostream& os, const Cart_Point& p1, const Cart_Point& p2);  
  
//Cart_Point operator+(const Cart_Point &a ,const Cart_Point &b);

//friend Cart_Vector operator-(const Cart_Point &a,const Cart_Point &b);
  



#endif
