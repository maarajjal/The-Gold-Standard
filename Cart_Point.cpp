#include <iostream>
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

Cart_Point::Cart_Point()
{
  x=0.0;
  y=0.0;
}

Cart_Point::Cart_Point (double inputx,double inputy)
{
  x=inputx;
  y=inputy;
}

double cart_distance (Cart_Point P1,Cart_Point P2) // the distancde between two points
{
  double xdistance = pow((P2.x - P1.x),2);
  double ydistance = pow((P2.y - P1.y),2);

  double distance = sqrt(xdistance + ydistance);
  return distance; 

}
  
ostream& operator<<(ostream& os, const Cart_Point& p1)  //I am overloading the output stream << operator
{  
  os <<'('<<p1.x << ',' << p1.y << ')';  
  return os;  
}

Cart_Point operator+(const Cart_Point &p1 ,const Cart_Vector &v1) //I am overloading the + operator (This one takes a Cart_point and a Cart_Vector
{
    Cart_Point addition; 
    addition.x=(p1.x + v1.x);
    addition.y=(p1.y+v1.y);
    return addition;
}

Cart_Point operator+(const Cart_Vector &v1,const Cart_Point &p1) // This is the same as the previous one but the order is switched
{
  Cart_Point addition;
  addition.x=(p1.x + v1.x);
  addition.y=(p1.y+v1.y);
  return addition;

}

Cart_Vector operator-(const Cart_Point &p1,const Cart_Point &v1) // I am overloading the - operator.
{
  Cart_Vector subtraction;
  subtraction.x=(p1.x -v1.x);
  subtraction.y=(p1.y-v1.y);
  return subtraction;
}

