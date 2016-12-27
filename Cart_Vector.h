#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include <iostream>
#include "Cart_Point.h"

using namespace std;
class Cart_Point;

class Cart_Vector
{
 public:
  double x;
  double y;
  double inputx;
  double inputy;
  Cart_Vector();
  Cart_Vector(double inputx,double inputy);
  friend ostream& operator<<(ostream& os, const Cart_Vector& v1);
  friend Cart_Vector operator*(const Cart_Vector &v1 ,double d);
  friend Cart_Vector operator/(const Cart_Vector &v1, double d); 
  // friend ostream& operator<<(ostream& os, const Cart_Point &a, const Cart_Point &b );
};



//ostream& operator<<(ostream& os, const Cart_Point& p1, const Cart_Point& p2);                                                                                                      

#endif
